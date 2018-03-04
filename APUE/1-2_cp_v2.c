#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>


int is_file_exist(const char *file_path)
{
	if(file_path == NULL)
		return -1;
	if(access(file_path, F_OK) == 0)
		return 0;
	return -1;
}

static void _mkdir(const char *dir) {
        char tmp[256];
        char *p = NULL;
        size_t len;

        snprintf(tmp, sizeof(tmp),"%s",dir);
        len = strlen(tmp);
        if(tmp[len - 1] == '/')
                tmp[len - 1] = 0;
        for(p = tmp + 1; *p; p++)
                if(*p == '/') {
                        *p = 0;
                        mkdir(tmp, S_IRWXU);
                        *p = '/';
                }
        mkdir(tmp, S_IRWXU);
}

int main(int argc, char **argv)
{
	struct stat buff1, buff2;
	int fd1, fd2;
	int num;
	char buf[10];
	char str[256];
	char param1[256];
	//判断源文件是否存在
	if(is_file_exist(argv[1]) != 0)
	{
		printf("source file does not exist\n");
		_exit(0);
	}
	stat(argv[1], &buff1);

	//判断源文件是否为目录文件
	if(S_ISDIR(buff1.st_mode))
	{
		printf("source file is a directory\n");
		_exit(0);
	}

	//提取源文件名（不包含路径名）
	else
	{
		size_t len4;
		int count = 0;
		int j = 0;
		len4 = strlen(argv[1]);
		for(; argv[1][len4 - 1] != '/' && len4 > 0; len4--)
		{
			count++;	
		}
		len4 = strlen(argv[1]);
		int i = len4 - count;
		for(; i < len4; i++)
		{
			param1[j++] = argv[1][i];			
		}	
		param1[j] = '\0';
	}

	//根据stat的返回值reno(return number)判断目标文件是否存在，0为存在，-1为不存在
	int reno = stat(argv[2], &buff2);

	//当目标文件存在时，reno=0，目标文件可以是普通文件或目录文件
	if(reno == 0)
	{
		
		//当目标文件为目录文件且存在时，则将源文件复制到该目录下
		if(S_ISDIR(buff2.st_mode))
		{
			size_t len;
			len = strlen(argv[2]);
			if(argv[2][len - 1] != '/')
				strcat(argv[2], "/");	
			strcat(argv[2], param1);
			fd2 = open(argv[2], O_CREAT|O_RDWR, 0664);
		}

		//当目标文件为普通文件且已经存在，给出提示选择覆盖(Y)/追加(A)/取消复制(N)
		else
		{
			char choice;
			printf("file %s exists, overwrite or append?(Y/A/N)", argv[2]);
			scanf("%c",&choice);	
			switch(choice)
			{
				//choice = Y
				case 'Y':
				case 'y':
					fd2 = open(argv[2], O_TRUNC|O_RDWR);
					break;
				//choice = A
				case 'A':
				case 'a':
					fd2 = open(argv[2], O_APPEND|O_RDWR);
					break;
				//choice = N
				case 'N':
				case 'n':
					_exit(0);
					break;
			}
		}
	}

	//目标文件不存在，reno=-1
	else if(reno = -1)
	{	
		size_t len3;
		len3 = strlen(argv[2]);

		//(绝对路径)目标文件是目录且该目录不存在,则创建该目录，并将源文件复制到该目录
		if(argv[2][0] == '/' && argv[2][len3 - 1] == '/')
		{
			_mkdir(argv[2]);
			size_t len2;
			len2 = strlen(argv[2]);
			if(argv[2][len2 - 1] != '/')
				strcat(argv[2], "/");	
			strcat(argv[2], param1);
			fd2 = open(argv[2], O_CREAT|O_RDWR, 0664);
		}

		//(相对路径)目标文件是普通文件且目录不存在，则创建该目录，并将源文件复制到该目录
		else if(argv[2][len3 - 1] == '/')
		{
                        _mkdir(argv[2]);
                        size_t len2;
                        len2 = strlen(argv[2]);
                        if(argv[2][len2 - 1] != '/')
                                strcat(argv[2], "/");
                        strcat(argv[2], param1);
                        fd2 = open(argv[2], O_CREAT|O_RDWR, 0664);
		}
		//目标文件是普通文件且不存在,则在当前目录创建目标文件，并将源文件内容复制到目标文件
		//分为绝对路径和相对路径，均需要先分离路径和文件名，按照路径创建目录，在新创建的目录下创建新文件
		else
		{
			size_t len5;
			char pathname[256];
			int k = 0;	
			int count2 = 0;
			len5 = strlen(argv[2]);
			for(; argv[2][len5 - 1] != '/' && len5 > 0; len5--)
	                {
                        	count2++;
                	}
                	len5 = strlen(argv[2]);
			int l = 0;
			for(; l < len5 - count2; l++)
			{
				pathname[k++] = argv[2][l];
			}
			pathname[l] = '\0';
			_mkdir(pathname);
			fd2 = open(argv[2], O_CREAT|O_RDWR, 0664);
		}
	}
	fd1 = open(argv[1], O_RDONLY);

	//使用循环读入源文件的内容到缓冲区，每次读取10个字节，并写入目标文件
	do
	{
		num = read(fd1, buf, 10);
		if(num != 0)
			write(fd2, buf, num);
	}while(num == 10);
	return 0;
}
