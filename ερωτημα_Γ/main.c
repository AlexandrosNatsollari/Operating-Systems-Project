#include <stdio.h>
#include <stdlib.h>


int main (void)
{
    int pid;
    int i;
    int status;
    pid = fork();
    for (i=0; i <10; i++)
    {

        if (pid ==0) {
            printf("child: %d, my parent is: %d\n", getpid(), getppid());
            pid = fork();
        }
       else if (pid>0){

          wait( &status);
        }
    }

}
