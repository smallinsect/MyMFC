#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	//const char *string1 = "needle in haystack";
	//const char *string2 = "hay";
	//const char *p = strstr(string1, string2);

	char str1[] = "ddddd";
	char str2[] = "fffff";
	char *const p = str1;
	//p = str2;

	//printf("%s\n", p);
	system("pause");
	return 0;
}