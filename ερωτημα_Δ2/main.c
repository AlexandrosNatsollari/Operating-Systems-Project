#include <stdio.h>
#include <time.h>


int foo(int x);

int main ()
{
    time_t seconds;
    int start;

    seconds = time(&start);
    printf("Αρχική τιμή δευτερολέπτων:%d\n", start);

    return(0);

}


int foo(int x)
{
    x=0;
    x=x+10;
}
