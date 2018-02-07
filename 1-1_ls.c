#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *ent;
	char *path;
	if(1 == argc){
		//how to get rid of the warning?
		//warning: initialization makes pointer from integer without a cast
		char *path = getcwd(NULL, 0);
		dir = opendir(path);
	}
	else if(2 == argc){
		dir = opendir(argv[1]);
	}
	else{
		printf("Usage: ./1-1_ls <pathname>");
		exit(1);
	}
	while(ent = readdir(dir)) {
		printf("%s\n", ent->d_name);
	}
	return 0;
}
