//Producer Consumer Solution using semaphores
//Producer Consumer Problem -OS Lab

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>

int buf[5],f=0,r=0;
sem_t mutex,full,empty;
void *produce(void *arg)
{
        int item;
        sem_wait(&empty);
        sem_wait(&mutex);
        item=rand()%5;
        printf("produced item is %d\n",item);
        buf[(++r)%5]=item;
        sleep(1);
        sem_post(&mutex);
        sem_post(&full);
        printf("full %d\n",*((int*)&full));
}
void *consume(void *arg)
{
        int item;
        sem_wait(&full);
        printf("full %d\n",*((int*)&full));
        sem_wait(&mutex);
        item=buf[(++f)%5];
        printf("consumed item is %d\n",item);
        sleep(1);
        sem_post(&mutex);
        sem_post(&empty);
}
int main()
{
    pthread_t tidp[3],tidc[3];
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,5);
    int i;
    for(i=0;i<3;i++)
  {
    pthread_create(&tidp[i],NULL,produce,NULL);
    pthread_create(&tidc[i],NULL,consume,NULL);
  }
  for(i=0;i<3;i++)
  {
    pthread_join(tidp[i],NULL);
    pthread_join(tidc[i],NULL);
  }
    return 0;
}
