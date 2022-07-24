#include<iostream>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

using namespace std;

pthread_cond_t cond_t;
pthread_cond_t cond_t_full;
pthread_mutex_t mutex_t;

int maxListNode = 20;

struct Node{
    int num;
    Node* next;
};

Node* head = NULL;

int getListNodeNum(){
    int num = 0;
    Node* cur = head;
    while(cur){
        num++;
        cur = cur->next;
    }
    return num;
}


void* customer(void* args){
    // 消费者
    while(true){
        pthread_mutex_lock(&mutex_t);
        Node* tmp = head;
        if(head == NULL){
            // 说明当前没有产品供消费
            pthread_cond_wait(&cond_t, &mutex_t);
            pthread_mutex_unlock(&mutex_t);
        }else{
            // 当前有产品，将这个产品从链表移除
            head = head->next;
            // tmp->next = NULL;
            cout << "消费者消耗一件产品，已从链表删除\t 产品id为：" << tmp->num << "，当前仓库容量为：" << getListNodeNum() << endl;
            delete tmp;
            pthread_cond_signal(&cond_t_full);
            pthread_mutex_unlock(&mutex_t);
            usleep(100);
        }
        
    }
    return NULL;
}

void* producter(void* args){
    // 生产者
    while (true){
        pthread_mutex_lock(&mutex_t);
        if(getListNodeNum() < maxListNode){
            Node * newPro = (Node *) malloc(sizeof(Node));
            newPro->num = rand() % 10000;
            newPro->next = head;
            head = newPro;
            cout << "生产者生产一件产品，已插入链表\t 产品id为：" << newPro->num << "，当前仓库容量为：" << getListNodeNum() << endl;
            pthread_cond_signal(&cond_t);
            pthread_mutex_unlock(&mutex_t);
            usleep(100);
        }else{
            pthread_cond_wait(&cond_t_full, &mutex_t);
            pthread_mutex_unlock(&mutex_t);
            usleep(100);
        }
        
    }
    return NULL;
}

int main(){
    pthread_mutex_init(&mutex_t, NULL);
    pthread_cond_init(&cond_t, NULL);
    pthread_cond_init(&cond_t_full, NULL);
    // 5个消费者线程、5个生产者线程
    pthread_t prod[5];
    pthread_t cust[5];
    for(int i = 0; i < 5; i++){
        pthread_create(&prod[i], NULL, producter, NULL);
        pthread_create(&cust[i], NULL, customer, NULL);
    }
    for(int i = 0; i < 5; i++){
        pthread_detach(prod[i]);
        pthread_detach(cust[i]);
    }
    pthread_mutex_destroy(&mutex_t);
    pthread_cond_destroy(&cond_t);
    pthread_cond_destroy(&cond_t_full);
    pthread_exit(NULL);
    return 0;
}