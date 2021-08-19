#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

int
	main(void)
{
	char	c;
	struct termios term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	while (read(0, &c, sizeof(c)) > 0)
		printf("input : %c\n", c);
}

// void
// 	interrupt(int signo)
// {
// 	printf("this program will be exited in 3 seconds...\n");
// 	sleep(3);
// 	exit(0);
// }

// int
// 	main(void)
// {
// 	signal(SIGINT, interrupt);
// 	printf("input ctrl+c\n");
// 	while (1);
// }