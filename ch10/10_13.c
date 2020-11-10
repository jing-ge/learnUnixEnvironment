#include "../include/apuemain.h"

static void sig_int(int);

int
main(void)
{
	sigset_t newmask,oldmask, waitmask;

	printf("program start: \n");

	if(signal(SIGINT, sig_int) == SIG_ERR)
			err_sys("signal(SIGINT) error");
	sigemptyset(&waitmask);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);

	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
			err_sys("SIG_BLOCK error");

	printf("in critical region:\n");

	if(sigsuspend(&waitmask) != -1)
			err_sys("sigsuspend error");

	printf("after return from sigsuspend: \n");

	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
			err_sys("SIG_SETMASK error");
	printf("program exit: \n");

	exit(0);
}

static void
sig_int(int signo)
{
	printf("\n in sig_int:\n");
}
