#include <sys/types.h>  
#include <sys/stat.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <time.h>  
#include <errno.h>  
#include <dirent.h>  
#include <grp.h>  
#include <pwd.h> 
#include <sys/wait.h>

//color support for different type
#define COLOR_R (char *)"\33[0m"  
#define COLOR_D (char *)"\33[01m\33[34m"  
#define COLOR_L (char *)"\33[01m\33[36m"  
#define COLOR_P (char *)"\33[40m\33[33m"  
#define COLOR_B (char *)"\33[40m\33[33m"  
#define COLOR_C (char *)"\33[40m\33[33m"  
#define COLOR_S (char *)"\33[02m\33[35m"  
#define RESET_COLOR (char *)"\33[0m"  

#define MAXNAME 256

#define PARAM_N 0x0000 //N for none parameter
#define PARAM_L 0x0001 //L for long list
#define PARAM_A 0x0010 //A for all files
#define PARAM_P 0x0100 //P(..) for previous directory
#define PARAM_K 0x1000 //K for sotf link
int flag = PARAM_N;

char *color;

int optioncode;

void ls(char *);
void ls_l(char *);

char *get_name_from_path(char *path)
{
	int i = 0;
	int j = 0;
	char *name = (char *)malloc(MAXNAME);
	for(; i < strlen(path); i++) {
		if(path[i] == '/') {
			j = 0;
			continue;
		}
		name[j++] = path[i];
	}
	name[j] = '\0';
	return name;
}

char check_type(char *path)
{
	struct stat buf;
	stat(path, &buf);
	if(S_ISREG(buf.st_mode)) {
		color = COLOR_R;
		return '-';
	}
	if(S_ISDIR(buf.st_mode)) {
		color = COLOR_D;
		return 'd';
	}
	if(S_ISCHR(buf.st_mode)) {
		color = COLOR_C;
		return 'c';
	}
	if(S_ISBLK(buf.st_mode)) {
		color = COLOR_B;
		return 'b';
	}
	if(S_ISFIFO(buf.st_mode)) {
		color = COLOR_P;
		return 'p';
	}
	if(S_ISLNK(buf.st_mode)) {
		color = COLOR_L;
		return 'l';
	}
	if(S_ISSOCK(buf.st_mode)) {
		color = COLOR_S;
		return 's';
	}
	color = COLOR_R;
	return '-';
}

char *check_perm(char *path)
{
	struct stat buf;
	stat(path, &buf);
	char *perm = (char *)malloc(sizeof(char)*10);
	int i;
	mode_t bit;
	for(i = 3; i > 0; --i) {
		bit = buf.st_mode & 0x01;
		perm[i * 3 - 1] = (1 == bit ? 'x' : '-');
		buf.st_mode >>= 1;

		bit = buf.st_mode & 0x01;
		perm[i * 3 - 2] = (1 == bit ? 'w' : '-');
		buf.st_mode >>= 1;

		bit = buf.st_mode &0x01;
		perm[i * 3 - 3] = (1 == bit ? 'r' : '-');
		buf.st_mode >>= 1;
	}
	perm[9] = '\0';
	return perm;
}

void show_miscellaneous(char *path)
{
	struct stat buf;
	stat(path, &buf);
	struct passwd *own = getpwuid(buf.st_uid);
	struct group *grp = getgrgid(buf.st_gid);
	fprintf(stdout, " %2d", buf.st_nlink);
	fprintf(stdout, " %s", own->pw_name);
	fprintf(stdout, " %s", grp->gr_name);
	fprintf(stdout, "  %8ld", buf.st_size);
	char buf_time[32];
	strcpy(buf_time, ctime(&buf.st_mtime));
    	buf_time[strlen(buf_time) - 1] = '\0';
    	fprintf(stdout, "  %s", buf_time);
	fprintf(stdout, " ");
}

void show_filename(char *path)
{
	char *name = get_name_from_path(path);
	check_type(path);
	fprintf(stdout, "%s", color);
	fprintf(stdout, "%s", name);	
	fprintf(stdout, RESET_COLOR);
}

void get_option(const char *opt)
{
	int i, j, k = 0;
	i = strlen(opt);
	for(j = 1; j < i; j++) {
		switch(opt[j]) {
			case 'l':
				flag |= PARAM_L;
				break;
			case 'a':
				flag |= PARAM_A;
				break;
			case 'k':
				flag |= PARAM_K;
				break;
			case 'p':
				flag |= PARAM_P;
				break;
			default:
				printf("invalid option -%c\n", opt[j]);
				exit(1);
		}
	}	
}

void ls(char *path)
{
	DIR *dir;
	struct dirent *ent;
	char type;
	char *perm;
	int i, len;
	char path2[256];
	if(flag & 0x1000) {
		char buff[256];
		int path_len = readlink(path, buff, 256);
		buff[path_len] = '\0';
		ls_l(buff);
		exit(0);
	}
	if(flag & 0x0100) {
		len = strlen(path);
		for(i = len - 1; i > 0; i--) {
			if(path[i] == '/') {
				path[i] = '\0';
				break;
			}	
		}	
	flag &= 0x1011;
	}
	
	dir = opendir(path);

	if(flag == 0x0011) {
                while((ent = readdir(dir))) {
			strcpy(path2, path);
			strcat(path2, "/");
			strcat(path2, ent->d_name);
			ls_l(path2);
                }
	}
	else if(flag == 0x0010) {
		while((ent = readdir(dir))) {
			strcpy(path2, path);
			strcat(path2, "/");
			strcat(path2, ent->d_name);
			show_filename(path2);
			fprintf(stdout, "\n");
     		}
	}
	else if(flag == 0x0001) {
                while((ent = readdir(dir))) {
                        if(ent->d_name[0] == '.')
                                continue;
			strcpy(path2, path);
			strcat(path2, "/");
			strcat(path2, ent->d_name);
			ls_l(path2);
                }
	}
	else {
		while((ent = readdir(dir))) {
			if(ent->d_name[0] == '.')
				continue;
			strcpy(path2, path);
			strcat(path2, "/");
			strcat(path2, ent->d_name);
			show_filename(path2);
			fprintf(stdout, "\n");
		}	
	}
     	closedir(dir);
}

void ls_l(char *path)
{
	char type;
	char *perm;	
	type = check_type(path);
	fprintf(stdout, "%c", type);
	perm = check_perm(path);
	fprintf(stdout, "%s", perm);
	show_miscellaneous(path);
	show_filename(path);
	fprintf(stdout, "\n");
}

int main(int argc, char **argv)
{
	if(argc == 1)
		ls(getcwd(NULL, 0));
	else if(argc == 2) {
		if(argv[1][0] == '-') {
			get_option(argv[1]);
			ls(getcwd(NULL, 0));
		}
		else if(argv[1][0] == '/') {
			ls(argv[1]);	
		}
		else {
			char *path = getcwd(NULL, 0);
			strcat(path, "/");
			strcat(path, argv[1]);
			ls(path);
		}
	}
	else if(argc == 3) {
		if(argv[1][0] == '-') {
			get_option(argv[1]);
			ls(argv[2]);
		}
		else {
			get_option(argv[2]);
			ls(argv[1]);
		}
	}
	
	return 0;
}
