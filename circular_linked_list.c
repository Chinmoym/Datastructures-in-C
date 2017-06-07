#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node * next;
};
struct node * create_list(struct node * last);
void display_list(struct node * last);
void search_list(struct node * last, int data);
struct node * addto_empty(struct node * last, int data);
struct node * addat_start(struct node * last, int data);
struct node * addat_end(struct node * last, int data);
struct node * add_after(struct node * last,int data, int after);
struct node * del(struct node * last, int data);
int main(){
	
	struct node * last  = NULL;
	int pos,data,after,before,choice;
	while(1){
		
		printf("0. Exit\n1. Create list\n2. Display list\n3. Add to empty list\n4. Search in list\n5. Insert at begining of list\n6. Insert at end of list\n");
		printf("9. Add after element\n10: Delete Element\nEnter your option:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				last = create_list(last);
				break;
			case 2:
				display_list(last);
				break;
			case 3:
				printf("Enter the element to be inserted:");
				scanf("%d",&data);
				last = addto_empty(last,data);
				break;
			case 4:
				printf("Enter the element to be searched:");
				scanf("%d",&data);
				search_list(last,data);
				break;
			case 5: 
				printf("Enter the element to be inserted at the begining of the list:");
				scanf("%d",&data);
				last = addat_start(last,data);
				break;
			case 6:
				printf("Enter the element to be inserted at the end of the list:");
				scanf("%d",&data);
				last = addat_end(last,data);
				break;
			case 9:
				printf("Enter the element to be inserted in the list:");
				scanf("%d",&data);
				printf("Enter after which element:");
				scanf("%d",&after);
				last = add_after(last,data,after);
				break;
			case 10:
				printf("Enter the element to be deleted:");
				scanf("%d",&data);
				last  = del(last,data);
				break;
			case 0:
				exit(0);
			default:
				printf("Invalid Command\n\n");		
		}
	}
	free(last);
	return 0;
}
struct node * create_list(struct node * last){
	int data,i,n;
	last = NULL;
	printf("Enter number of nodes:");
	scanf("%d",&n);
	if(n==0)
		return last;
	printf("Enter element to be inserted:");
	scanf("%d",&data);
	last = addto_empty(last,data);
	for(i=2;i<=n;i++){
		printf("Enter element to be inserted:");
		scanf("%d",&data);
		last = addat_end(last,data);
	}
	return last;
}
void display_list(struct node * last){
	if (last==NULL){
		printf("Empty list\n");
		return;
	}
	struct node *ptr;
	ptr = last->next;
	do{
		printf("-%d-",ptr->value);
		ptr=ptr->next;
	}while(ptr!=last->next);
}
void search_list(struct node * last, int data){
	if (last==NULL){
		printf("Empty list\n");
		return;
	}
	struct node *ptr;
	ptr = last->next;
	int count =0;
	do{
		count++;
		if(ptr->value==data){
			printf("Element found at position %d",count);
			return;
		}
		ptr=ptr->next;
	}while(ptr!=last->next);
}
struct node * addto_empty(struct node * last,int data){
	struct node * tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->value = data;
	last = tmp;
	last->next = last;
	return last;
}
struct node * addat_start(struct node * last, int data){
	struct node * tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->value=data;
	tmp->next = last->next;
	last->next = tmp;
	return last;
}
struct node * addat_end(struct node * last, int data){
	struct node * tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->value = data;
	tmp->next = last->next;
	last->next = tmp;
	last = tmp;
	return last;
}
struct node * add_after(struct node * last,int data, int after){
	struct node *tmp, *ptr;
	ptr = last->next;
	do{
		if(ptr->value==after){
			tmp = (struct node *)malloc(sizeof(struct node));
			tmp->value = data;
			tmp->next = ptr->next;
			ptr->next = tmp;
			if(ptr==last){
				last = ptr;
				return last;
			}
		}
		ptr = ptr->next;
	}while(ptr!=last->next);
	printf("Element not present\n");
	return last;
}
struct node * del(struct node * last, int data){
	struct node *tmp, *ptr;
	if (last==NULL){
		printf("Empty list\n");
		return last;
	}
	///delete 1st node
	if(last->next->value == data){
		//delete oly node
		if(last->next==last){
			tmp =last;
			last=NULL;
			free(tmp);
			return last;
		}
		tmp = last->next;
		last->next = tmp->next;
		free(tmp);
		return last;
	}
	//inbetween nodes
	ptr = last->next;
	while(ptr->next!=last){
		if(ptr->next->value==data){
			tmp = ptr->next;
			ptr->next = tmp->next;
			free(tmp);
			return last;
		}
	}
	//last node
	if(last->value==data){
		tmp = last;
		ptr->next = tmp->next;
		last = ptr;
		free(tmp);
		return last;
	}
	printf("Element not found\n");
	return last;
}

