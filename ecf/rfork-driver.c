#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define ITERS 10

pid_t Fork(void);

int main()
{
    pid_t pid;
    int i;

    for (i = 0; i < ITERS; i++) {
	printf("Test %d\n", i);
	fflush(stdout);
	
	/* Child */
	if (Fork() == 0) {
	    printf("C%d\n", i);
	    fflush(stdout);
	    exit(0);
	}

	/* Parent */
	else { 
	    printf("P%d\n", i);
	    fflush(stdout);
	}
	fflush(stdout);
	wait(NULL);
	fflush(stdout);
    }

    printf("\n");
    fflush(stdout);
    exit(0);
}
