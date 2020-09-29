#include "../include/apueerror.h"

int 
main(void)

{
	printf("uid = %d, gid = %d\n",getuid(),getgid());
	exit(0);
	return 0;
}
