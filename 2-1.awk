#!/usr/bin/awk -f
BEGIN {
	printf("#include <stdio.h>\n")
	printf("#include <stdlib.h>\n")
	printf("#include <unistd.h>\n")
	printf("#include <limits.h>\n")
	printf("#include <errno.h>\n")
	printf("\n")
	printf("static void show_sysconf(char *, int);\n")
	printf("\n")
	printf("int main(void)\n")
	printf("{\n")
	FS="\t+"
	while(getline <"sysconf.sym" > 0) {
		printf("#ifdef %s\n", $1)
		printf("\tprintf(\"%s defined to be %%d\\n\", %s+0);\n", $1, $1)
		printf("#else\n")
		printf("\tprintf(\"no symbol for %s\\n\");\n", $1)
		printf("#endif\n")
		printf("#ifdef %s\n", $2)
		printf("\tshow_sysconf(\"%s\", %s);\n", $1, $2)
		printf("#else\n")
		printf("\tprintf(\"no symbol for %s\\n\");\n", $2)
		printf("#endif\n")
	}
	close("sysconf.sym")
	exit
}
END {
	printf("\texit(0);\n")
	printf("}\n\n")
	printf("static void show_sysconf(char *str, int name)\n")
	printf("{\n")
	printf("\tlong val;\n")
	printf("\terrno = 0;\n")
	printf("\tif(val = sysconf(name) < 0) {\n")
	printf("\t\tif(errno == 0) {\n")
	printf("\t\t\tprintf(\"no limit\\n\");\n")
	printf("\t\t}\n")
	printf("\t\telse {\n")
	printf("\t\t\terrno = EINVAL;\n")
	printf("\t\t\tprintf(\"not supported\\n\");\n")
	printf("\t\t}\n")
	printf("\t}\n")
	printf("\telse {\n")
	printf("\t\tprintf(\"%%s = %%ld\\n\", str, val);\n")
	printf("\t}\n")
	printf("}\n")
}
