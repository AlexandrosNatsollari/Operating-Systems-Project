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
Semaphore *synch3;
int main (int argc, char **argv)
{
    int i;
    pid_t pid;

	system("clear");

    synch1 = sem_open ("Sem1", O_CREAT | O_EXCL, 0644, 0);
    synch2 = sem_open ("Sem2", O_CREAT | O_EXCL, 0644, 0);
    synch3 = sem_open ("Sem3", O_CREAT | O_EXCL, 0644, 0);


    pid = fork ();


if (pid > 0)
	{
	    printf("--ls--\n");
        system("ls"); //D1

        sem_post (synch1);



        sem_unlink ("Sem1");
        sem_close(synch1);
        sem_unlink ("Sem2");
        sem_close(synch2);
        sem_unlink ("Sem3");
        sem_close(synch3);

    }
else if (pid == 0)
	{
		sem_wait (synch1);
		printf("--ls -l--\n");
	    system("ls -l"); //D2

		printf("--ls -i--\n");
        system("ls -i");   //D3


		sem_post (synch2);
		sem_post (synch1);


		sem_wait (synch1);
		sem_wait (synch2);
		printf("--ls -r--\n");
		system("ls -r");//D4
		sem_post (synch3);
		printf("--ls --vesrion--\n");
		system("ls --version"); //D5

		sem_wait (synch3);
		printf("--ls -R--\n");
		system("ls -R"); //D6

        wait(NULL);

    }
else
	{
        sem_unlink ("Sem1");
        sem_close(synch1);
        sem_unlink ("Sem2");
        sem_close(synch2);
        sem_unlink ("Sem3");
        sem_close(synch3);

        printf ("Fork error.\n");
    }
    sleep(3);
    return (0);

}
