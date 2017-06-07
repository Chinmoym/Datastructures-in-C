#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node * next;
};

struct node * front = NULL, * rear = NULL;

int isempty(){
	if(front==NULL)
		return 1;
	else 
		return 0;
}

void insert(int data){
	struct node * tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	if(tmp==NULL){
		printf("Queue Overflow");
		return;
	}
	tmp->value = data;
	tmp->next = NULL;
	if (front==NULL)
		front = tmp;
	else
		rear->next = tmp;
	rear = tmp;
}

int del(){
	if(isempty()){
		printf("Queue empty\n");
		return -1;
	}
	int data = front->value;
	struct node * tmp;
	tmp = front;
	front = front->next;
	free(tmp);
	return data;
}

int peek(){
	if(isempty()){
		printf("Queue empty\n");
		return -1;
	}
	return front->value;
}

void display(){
	if(isempty()){
		printf("Queue Empty\n");
		return;
	}
	struct node * ptr;
	ptr = front;
	while(ptr!=NULL){
		printf("\t%d",ptr->value);
		ptr = ptr->next;
	}
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
