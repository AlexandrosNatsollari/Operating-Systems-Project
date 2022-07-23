#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <errno.h>
#include <semaphore.h>
#include <fcntl.h>


typedef sem_t Semaphore;



Semaphore *synch1;
Semaphore *synch2;
int main (int argc, char **argv)
{
    int i;
    pid_t pid;

	system("clear");

    synch1 = sem_open ("Sem1", O_CREAT | O_EXCL, 0644, 0);
    synch2 = sem_open ("Sem2", O_CREAT | O_EXCL, 0644, 0);


    pid = fork ();


if (pid > 0)
	{
	    printf("--ls--\n");
        system("ls"); //P1
        printf("--ls -l--\n");
	    system("ls -l"); //P2

        sem_post (synch1);



        sem_unlink ("Sem1");
        sem_close(synch1);
        sem_unlink ("Sem2");
        sem_close(synch2);

    }
else if (pid == 0)
	{
		sem_wait (synch1);
		printf("--ls -i--\n");
        system("ls -i");   //P3


		sem_post (synch2);
		sem_post (synch1);


		sem_wait (synch1);
		sem_wait (synch2);
		printf("--ls -r--\n");
		system("ls -r");//P4
		printf("--ls --vesrion--\n");
		system("ls --version"); //P5
        wait(NULL);

    }
else
	{
        sem_unlink ("Sem1");
        sem_close(synch1);
        sem_unlink ("Sem2");
        sem_close(synch2);

        printf ("Fork error.\n");
    }
    sleep(3);
    return (0);

}
