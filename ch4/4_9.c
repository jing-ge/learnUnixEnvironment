#include "../include/apueerror.h"

int
main(void)
{
	char *ptr;
	size_t size;
	if(chdir("/home/fengbojing/mywork/linuxlearn/ch4") < 0)
		err_sys("chdir failed");
	//ptr = path_alloc(&size);
	ptr = (char*)malloc(1000);
	if (getcwd(ptr,size)==NULL)
			err_sys("getcwd failed");
	printf("cwd = %s\n",ptr);
	exit(0);
}
