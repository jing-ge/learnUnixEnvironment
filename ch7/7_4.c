#include <../include/apuemain.h>

extern char **environ;

int
main()
{
	int i;
	for(i = 0; environ[i] != NULL;i++)
	{
		printf("argc[%d]: %s\n",i,environ[i]);
	}
	exit(0);
}
