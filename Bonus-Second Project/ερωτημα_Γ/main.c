#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


#define MAX_NUM 50




sem_t sem1, sem2;
FILE *fp;
void *f1(void* p)
{


  int i;
  sem_wait(&sem1);
  for(i=1; i<=MAX_NUM; i++)
  {
    int a[51];

        a[i]=i;
        fp = fopen("test.txt", "r+");
        printf("To arxeio diavastike:%d fores\n",a[i]);

  }



    sem_post(&sem2);

}

void *f2(void* p)
{

  sem_wait(&sem2);

        fprintf(fp,"random keimeno gia thn eggrafh sto arxeio\n");
        fclose(fp);


     sem_post(&sem1);
}



int main()
{
   pthread_t p1, p2;
   sem_init(&sem1, 0, 1);
   sem_init(&sem2, 0, 0);


  pthread_create(&p1, NULL, f1,  (void*)NULL);
  pthread_create(&p2, NULL, f2,  (void*)NULL);

  pthread_join(p1, NULL);
  pthread_join(p2, NULL);


  return 0;

}
