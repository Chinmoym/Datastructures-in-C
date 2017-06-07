#include <stdio.h>
#include <stdlib.h>

#define queuesize 10

int queue[queuesize];
int front =-1, rear=-1;

int isempty(){
	if (front==-1||front==rear+1)
		return 1;
	else 
		return 0;
}

int isfull(){
	if (rear==queuesize-1)
		return 1;
	else
		return 0;
}

void insert(int data){
	if(isfull()){
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1)
		front++;
	rear++;
	queue[rear]=data;
}

int del(){
	if(isempty()){
		printf("Queue Underflow\n");
		return;
	}
	front++;
	return queue[front-1];
}

int peek(){
	if(isempty()){
		printf("Queue Underflow\n");
		return;
	}
	return queue[front];
}

void display(){
	if(isempty()){
		printf("Queue is empty\n");
		return;
	}
	int i;
	for(i=front;i<=rear;i++)
		printf("\t%d",queue[i]);
	
	printf("\n");
}

int main(){
	int choice,data;
	while(1){
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display front element\n");
		printf("4. Display all elements\n");
		printf("0. Exit\n");
		printf("Enter your option:");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				exit(0);
				break;
			case 1:
				printf("Enter element to be inserted:");
				scanf("%d",&data);
				insert(data);
				break;
			case 2:
				data = del();
				if (data!=-1) printf("Deleted element = %d\n",data);
				break;
			case 3:
				data = peek();
				if (data!=-1) printf("Element at the front = %d\n",data);
				break;
			case 4:
				display();
				break;
			default:
				printf("Invalid option\n");
				break;
		}
	}
	return 0;
}
