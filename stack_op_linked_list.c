#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node * next;
};

struct node * tos = NULL;

int isempty(){
	if(tos==NULL)
		return 1;
	else
		return 0;
}

void addat_start(int data){
	struct node * tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	if(tmp == NULL){
		printf("Stack Overflow\n");
		return;
	}
	tmp->value = data;
	tmp->next = tos;
	tos = tmp;
}

void push(int data){
	addat_start(data);
}

int rem_start(){
	struct node * tmp;
	int data;
	tmp = tos;
	tos = tos->next;
	data = tmp->value;
	free(tmp);
	return data;
}

int pop(){
	if(isempty()){
		printf("Stack Underflow\n");
		return -1;
	}
	return rem_start();
}

int peek(){
	if(isempty()){
		printf("Stack Underflow\n");
		return -1;
	}
	return tos->value;
}

void display(){
	if(isempty()){
		printf("Stack empty\n");
	}
	struct node * tmp;
	tmp = tos;
	printf("Stack:\n");
	while(tmp!=NULL){
		printf("\t\t%d\n",tmp->value);
		tmp=tmp->next;
	}	
}

int main(){
	int choice,data;
	while(1){
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display top of stack\n");
		printf("4. Display entire stack\n");
		printf("0. Exit\n");
		printf("Enter your option:");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				exit(0);
			case 1:
				printf("Enter the element to be pushed into stack:");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				data = pop();
				if(data!=-1)
					printf("Data popped = %d\n",data);
				break;
			case 3:
				data = peek();
				if(data!=-1)
					printf("Top of stack = %d\n",data);
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
