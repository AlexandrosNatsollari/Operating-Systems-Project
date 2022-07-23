#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int foo(int x);

int main ()
{

    int i;
    int synarthshFoo;
    int x=0;
    int pid;

    clock_t start = clock();
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



    clock_t end = clock();

	printf("Teliki timi deuteroleptwn: %f\n",(double)(end - start) / CLOCKS_PER_SEC);
	printf("Mesos xronos dimiourgias: %f\n",((double)(end - start) / CLOCKS_PER_SEC)/100);




    return 0;

}


int foo(int x)
{

    x=x+10;
    return x;
}

