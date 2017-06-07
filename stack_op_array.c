#include <stdio.h>
#include <stdlib.h>

#define stacksize 10

int stack[stacksize];
int top = -1;

int isfull(){
	if(top==stacksize-1)
		return 1;
	else 
		return 0;
}

int isempty(){
	if(top==-1)
		return 1;
	else
		return 0;
}

void push(int data){
	if(isfull()){
		printf("Stack Overflow\n");
		return;
	}
	top++;
	stack[top] = data;
}
int pop(){
	if(isempty()){
		printf("Stack Underflow\n");
		return -1;
	}
	top--;
	return stack[top+1];
}

int peek(){
	if(isempty()){
		printf("Stack Underflow\n");
		return -1;
	}
	return stack[top];
}

void display(){
	int i;
	if(isempty()){
		printf("Stack is empty\n");
		return;
	}
	printf("Stack:\n");
	for(i=top;i>=0;i--)
		printf("\t\t%d\n",stack[i]);
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
