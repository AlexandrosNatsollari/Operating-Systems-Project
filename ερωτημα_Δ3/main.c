#include <stdio.h>
#include <time.h>


int foo(int x);

int main ()
{
    time_t seconds;
    int start;
    int i;
    int synarthshFoo;
    int x=0;

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
            wait( NULL );


    return(0);

}


int foo(int x)
{

    x=x+10;
    return x;
}
