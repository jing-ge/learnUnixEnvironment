#include <signal.h>
#include <unistd.h>

static jmp-buf env_alrm;

static void
sig_alrm (int signo)
{
	
}

static void
sig_alrm2 (int signo)
{
	longjmp(env_alrm, 1);	
}

unsigned int
sleep1(unsigned int seconds)
{
	if (signal(SIGALRM, sig_alrm)==SIG_ERR)
			return (seconds);
	alarm(seconds);
	pause();
	return (alarm(0));
}

unsigned int
sleep2(unsigned int seconds)
{
	if (signal(SIGALRM, sig_alrm2) == SIG_ERR)
			return (seconds);
	if (setjmp(env_alrm) == 0)
	{
		alarm(seconds);
		pause();
	}
	return (alarm(0));
}
