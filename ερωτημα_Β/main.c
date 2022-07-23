#include <stdio.h>
#include <stdlib.h>

int main()
{
int i;
printf( "parent pid is: %d\n", getpid() );
for ( i = 0; i < 10; i++ )
    if ( fork() == 0 )
    {
        printf( "child pid is: %d parent pid is: %d\n", getpid(), getppid() );
        exit( 0 );
    }
    for (  i = 0; i < 10; i++ )
        wait( NULL );
}
