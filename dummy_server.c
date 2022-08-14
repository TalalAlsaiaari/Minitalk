#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

int counter = 0;

void siggs(int sig)
{
    int bin[7];
    int x;
    int sum;
    
    x = 0;
    sum = 0;
    memset(bin, 0, 7*sizeof(int));
    if (sig == SIGUSR1)
        bin[counter] = 1;
    //else if (sig == SIGUSR2)
        //bin[counter] = 0;
    counter++;
    //printf("the value of bin is: %ls\n", bin);
    //printf("the value of counter is: %d\n", counter);
    if (counter == 7)
    {
        while (x < counter)
        {
            sum = (sum * 2) + bin[x];
            //printf("the value of sum in the loop is: %d\n", sum);
            x++;
        }
        counter = 0;
        //printf("the value of sum is: %d\n", sum);
        write(1, &sum, 1);
    }
}

int main ()
{
    struct sigaction sa;
    sa.sa_handler = &siggs;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    printf("PID: %d\n", getpid());
    while (1)
        pause();
}