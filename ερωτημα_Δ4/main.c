#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int foo(int x);

int main ()
{
    time_t seconds;
    int start;
    int i;
    int synarthshFoo;
    int x=0;
    int pid;
    seconds = time(&start);
    printf("Αρχική τιμή δευτερολέπτων:%d\n", start);


    while(i<100)
    {

        if ( fork() == 0 )
            {
                printf( "child pid is: %d parent pid is: %d\n", getpid(), getppid() );

                exit( 0 );

            }
        x=foo(x);

        printf("%d synarthshFoo:%d\n",i,x);
        i++;
    }
            for (  i = 0; i < 100; i++ )
            {
               waitpid(pid,NULL,0);
            }


    return(0);

}


int foo(int x)
{

    x=x+10;
    return x;
}
