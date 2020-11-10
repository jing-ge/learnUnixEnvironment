#include "../include/apuemain.h"

void
abort(void)
{
	sigset_t mask;
	struct sigaction aciton;

	sigaction(SIGABRT, NULL, &action);
	if(action.sa_handler == SIG_IGN)
	{
		action.sa_handler = SIG_DFL;
		sigaction(SIGABRT, &aciton, NULL);
	}
	if (action.sa_handler == SIG_DFL)
			ffush(NULL);

	sigfillset(&mask);
	sigdelset(&mask, SIGABRT);
	sigprocmask(SIG_SETMASK, &mask,NULL);
	kill(getpid(),SIGABRT);

	fflush(NULL);
	action.sa_handler = SIG_DFL;
	sigaction(SIGABRT, &action, NULL);
	kull(getpid(), SIGABRT);
	exit(1);
}
