#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct node * create_list(struct node * head);
void display_list(struct node * head);
void search_list(struct node * head, int data);
void count_element(struct node * head);
struct node * addat_start(struct node * head, int data);
struct node * addat_end(struct node * head, int data);
struct node * addat_pos(struct node * head, int data, int pos);
struct node * add_before(struct node * head, int data, int before);
struct node * add_after(struct node * head,int data, int after);
struct node * del(struct node * head, int data);
struct node * reverse(struct node * head);


int main(){
	
	struct node * head  = NULL;
	int pos,data,after,before,choice;
	while(1){
		
		printf("0. Exit\n1. Create list\n2. Display list\n3. Count elements\n4. Search in list\n5. Insert at begining of list\n6. Insert at end of list\n");
		printf("7. Insert at position\n8. Add before element\n9. Add after element\n10: Delete Element\n11. Reverse the list\n\nEnter your option:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				head = create_list(head);
				break;
			case 2:
				display_list(head);
				break;
			case 3:
				count_element(head);
				break;
			case 4:
				printf("Enter the element to be searched:");
				scanf("%d",&data);
				search_list(head,data);
				break;
			case 5: 
				printf("Enter the element to be inserted at the begining of the list:");
				scanf("%d",&data);
				head = addat_start(head,data);
				break;
			case 6:
				printf("Enter the element to be inserted at the end of the list:");
				scanf("%d",&data);
				head = addat_end(head,data);
				break;
			case 7:
				printf("Enter the element to be inserted in the list:");
				scanf("%d",&data);
				printf("Enter the position at which to insert:");
				scanf("%d",&pos);
				head = addat_pos(head,data,pos);
				break;
			case 8:
				printf("Enter the element to be inserted in the list:");
				scanf("%d",&data);
				printf("Enter before which element:");
				scanf("%d",&before);
				head = add_before(head,data,before);
				break;
			case 9:
				printf("Enter the element to be inserted in the list:");
				scanf("%d",&data);
				printf("Enter after which element:");
				scanf("%d",&after);
				head = add_after(head,data,after);
				break;
			case 10:
				printf("Enter the element to be deleted:");
				scanf("%d",&data);
				head  = del(head,data);
				break;
			case 11:
				head = reverse(head);
				break;
			case 0:
				exit(0);
			default:
				printf("Invalid Command\n\n");		
		}
	}
	free(head);
	return 0;
}
void display_list(struct node * head){
	if (head==NULL){
		printf("List is empty\n\n");
		return;
	}
	struct node * ptr;
	ptr = head;
	while(ptr != NULL){
		printf("%d->",ptr->value);
		ptr = ptr->next;
	}
	printf("\n\n");
}
void search_list(struct node * head, int data){
	if (head==NULL){
		printf("List is empty\n\n");
		return;
	}

	struct node * ptr;
	int pos=0;
	ptr = head;
	while(ptr!=NULL){
		pos++;
		if(ptr->value==data)
			printf("Item found at position %d\n",pos);
		ptr=ptr->next;
	}
}
void count_element(struct node * head){
	if (head==NULL){
		printf("List is empty\n\n");
		return;
	}
	
	struct node * ptr;
	int count = 1;
	ptr = head;
	while(ptr->next!=NULL){
		count++;
		ptr=ptr->next;
	}
	printf("No of elements: %d\n\n",count);
}

struct node * addat_start(struct node * head, int data){
	if (head==NULL){
		printf("List is empty adding first element\n\n");
	}

	struct node * ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->value = data;
	ptr->next = head;
	head = ptr;
	printf("Element added\n\n");
	return head;
}
struct node * addat_end(struct node * head, int data){
	if (head==NULL){
		printf("List is empty\n\n");
		return head;
	}

	struct node * ptr;
	ptr = head;
	while(ptr->next!=NULL)
		ptr=ptr->next;
		
	struct node * tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->value = data;
	tmp->next=NULL;
	
	ptr->next = tmp;
	printf("Element added\n\n");
	return head;
}
struct node * addat_pos(struct node * head, int data, int pos){
	
	struct node *ptr, *tmp;
	int i;
	
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->value = data;
	if (pos==1){
		tmp->next = head;
		head = tmp;
		return head;
	}
	
	ptr = head;
	for(i=1;i<pos-1;i++)
		ptr = ptr->next;
	
	if (ptr==NULL)
		printf("Less number of nodes ");
	else{
		tmp->next = ptr->next;
		ptr->next = tmp;
	}
	return head;
}
struct node * add_before(struct node * head, int data, int before){
	if (head==NULL){
		printf("List is empty\n\n");
		return head;
	}

	struct node * ptr;
	ptr = head;
	if (ptr->value==before){
		head = addat_start(ptr,data);
		return head;
	}
	else{
		
		while (ptr->next!=NULL){
			
			if(ptr->next->value == before)
				break;
			ptr = ptr->next;
			if(ptr->next==NULL){
				printf("End of list\n\n");
				return head;
			}
		}
		
		struct node * tmp;
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->value = data;
		tmp->next = ptr->next;
		ptr->next = tmp;
	}
	printf("Element added\n\n");
	return head;
}
struct node * add_after(struct node * head,int data, int after){
	if (head==NULL){
		printf("List is empty\n\n");
		return;
	}
	
	struct node * ptr;
	ptr = head;
	
	while(ptr->next!=NULL){
		
		if(ptr->value==after){
			
			if(ptr->next==NULL){
				printf("Adding to end of list\n\n");
				head = addat_end(ptr,data);
				return head;
			}	
			struct node * tmp;
			tmp = (struct node *)malloc(sizeof(struct node));
			tmp->value = data;
			tmp->next = ptr->next;
			ptr->next = tmp;
			
			
			printf("Element added\n\n");
			return head;
		}
		
		ptr=ptr->next;
		if(ptr->next==NULL){
			printf("End of list\n\n");
			return head;
		}
	}
	return head;
}
struct node * create_list(struct node * head){
	int n,i,data;
	printf("Enter number of nodes:");
	scanf("%d",&n);	
	head = NULL;
	if (n==0)
		return head;
	printf("Enter the element to be inserted:");
	scanf("%d",&data);
	head = addat_start(head,data);
	for(i=2;i<=n;i++){
		printf("Enter the element to be inserted:");
		scanf("%d",&data);
		head = addat_end(head,data);
	}
	return head;
}
struct node * del(struct node * head, int data){
	if (head==NULL){
		printf("List is empty\n\n");
		return head;
	}
	struct node * tmp;
	//delete first node
	if (head->value==data){
		tmp = head;
		head = head->next;
		free(tmp);
		return head;	
	}
	//delete inbetween or end node
	struct node * ptr;
	ptr = head;	
	while(ptr->next!=NULL){
		if(ptr->next->value==data){
			tmp = ptr->next;
			ptr->next = tmp->next;
			free(tmp);
			return head;
		}
		ptr = ptr->next;
	}
	printf("Element not found\n");
	return head;
}
struct node * reverse(struct node * head){
	if (head==NULL){
		printf("List is empty\n\n");
		return head;
	}
	struct node *prev, *ptr, *next;
	prev = NULL;
	ptr = head;
	while(ptr!=NULL){
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
	}
	head = prev;
	return head;
}
