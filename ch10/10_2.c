#include "../include/apuemain.h"
#include <pwd.h>

static void
my_alarm(int signo)
{
	struct passwd *rootptr;

	printf("in signal handler\n");
	if((rootptr = getpwnam("fengbojing") )== NULL)
			err_sys("getpwnam(fengbojing) error");
	alarm(1);
}

int 
main(void)
{
	struct passwd *ptr;
	signal (SIGALRM, my_alarm);
	alarm(1);
	for(;;) 
	{
		if((ptr = getpwnam("fengbojing")) == NULL)
			err_sys("getpwnam(fengbojing) error");
		if(strcmp(ptr->pw_name, "fengbojing")!=0)
				printf("return value corrupted!, pw_name = %s\n",ptr->pw_name);
	}
}
