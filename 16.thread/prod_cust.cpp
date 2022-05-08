#include<stdio.h>
#include <pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t mutex;

struct Node
{
    int num;
    Node *next;
};

Node * head = NULL;

void* producer(void * arg){
    while(1){
        pthread_mutex_lock(&mutex);
        Node * newNode = (Node *) malloc(sizeof(Node));
        newNode->next = head;
        head = newNode;
        newNode->num = rand() % 1000;
        printf("add node, num : %d, tid : %ld\n", newNode->num, pthread_self());
        pthread_mutex_unlock(&mutex);
        usleep(100);
    }
    return NULL;
};

void* customer(void * arg){
    while(1){
        pthread_mutex_lock(&mutex);
        Node * tmp = head;
        if(head!=NULL){
            head = head->next;
            printf("add node, num : %d, tid : %ld\n", tmp->num, pthread_self());
            free(tmp);

            usleep(100);
            pthread_mutex_unlock(&mutex);
        }else{
            pthread_mutex_unlock(&mutex);
        }
    }
    return NULL;
};



int main(){
    pthread_mutex_init(&mutex, NULL);
    pthread_t pids[5], cids[5];
    for(int i=0; i<5; i++){
        pthread_create(&pids[i], NULL, producer, NULL);
        pthread_create(&cids[i], NULL, customer, NULL);
    }

    for(int i=0; i<5; i++){
        pthread_detach(pids[i]);
        pthread_detach(cids[i]);
    }

    while(1){
        sleep(10);
    }

    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
    return 0;
}