#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int data){
    if(rear==MAX-1){
        printf("Queue is full\n");
    }
    else if(front==-1 && rear==-1){
        front=0;
        rear=0;
        queue[rear]=data;
    }
    else{
        rear++;
        queue[rear]=data;
    }
}



void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else{
        int element=queue[front];
        if(rear==front){
            front=rear=-1;
        }
        else{
            front++;
        }
        printf("\nDequeued element is %d",element);
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("\nQueue Underflow");
        return;
    }
    else{
        printf("\nQueue Elements:");
        for(int i=front;i<=rear;i++){
            printf("\n%d ",queue[i]);
        }
    }
}

void peek(){
    if(front==-1 && rear==-1){
        printf("\nQueue Underflow");
    }
    else{
        printf("\nThe front element is %d",queue[front]);
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    peek();
    dequeue();
    display();
}