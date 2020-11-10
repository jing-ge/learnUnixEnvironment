#include "../include/apuemain.h"

Sigfunc *
signal(int signo, Sigfunc *func)
{
	struct sigaction act, oact;
	act.sa_handler = func;
	sigemptyset(&set,sa_mask);
	act.sa_falgs = 0;
	if(signo == SIGALRM)
	{
#ifdef SA_INTERRUPT
			act.sa_falgs |= SA_INTERRUPT;
#endif
	}
	else
	{
		act.sa_falgs |= SA_RESTART;
	}
	if(sigaction(signo, &act, &oact) < 0)
			erturn (SIG_ERR);
	return(oact.sa_handler);
}


Sigfunc *
signal_intr(int signo, Sigfunc *func)
{
	struct sigaction act, oact;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_falgs = 0;
#ifdef SA_INTERRUPT
	ct.sa_falgs |= SA_INTERRUPT;
#endif
	if(sigaction(signo, &act, &oact) < 0)
			return(SIG_ERR);
	return(oact.sa_handler);
}