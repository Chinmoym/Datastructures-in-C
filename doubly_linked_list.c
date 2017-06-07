#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *prev;
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
struct node * create_list(struct node * head){
	int n,data,i;
	head = NULL;
	printf("Enter number of element to be inserted:");
	scanf("%d",&n);
	if (n==0)
		return head;
	printf("Enter element to be inserted:");
	scanf("%d",&data);
	head = addat_start(head,data);
	for(i=2;i<=n;i++){
		printf("Enter element to be inserted:");
		scanf("%d",&data);
		head = addat_end(head,data);
	}
	return head;
}
void display_list(struct node * head){
	if(head==NULL){
		printf("Empty List\n");
		return;
	}
	struct node * ptr;
	ptr = head;
	while(ptr != NULL){
		printf("%d <-> ",ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
}
void search_list(struct node * head, int data){
	if(head==NULL){
		printf("Empty List\n");
		return;
	}
	int count=0;
	struct node * ptr;
	ptr = head;
	while(ptr->next!=NULL){
		count++;
		if(ptr->value==data){
			printf("Element found at position %d\n",count);
			return;
		}
		ptr=ptr->next;
	}
}
void count_element(struct node * head){
	if(head==NULL){
		printf("Empty List\n\n");
		return;
	}
	struct node * ptr;
	ptr = head;
	int count=1;
	while(ptr->next!=NULL){
		count++;
		ptr=ptr->next;
	}
	printf("Number of elements = %d\n",count);
}
struct node * addat_start(struct node * head, int data){
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->value = data;
	
	if (head==NULL){
		tmp->prev = NULL;
		tmp->next = NULL;
		head = tmp;
		return head;
	}
	tmp->prev = NULL;
	tmp->next = head;
	head->prev = tmp;
	head = tmp;
	return head;
}
struct node * addat_end(struct node * head, int data){
	struct node *tmp, *ptr;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->value = data;
	tmp->next = NULL;
	ptr = head;
	while(ptr->next !=NULL)
		ptr = ptr->next;
	ptr->next = tmp;
	tmp->prev = ptr;
	return head;	
}
struct node * addat_pos(struct node * head, int data, int pos){
	if (pos==1){
		head = addat_start(head,data);
		return head;
	}
	int i;
	struct node *p, *q;
	p = head;
	for(i=1;i<pos-1;i++)
		p = p->next;
	if(p==NULL){
		printf("less number of nodes than provided\n");
		return head;
	}
	q = p->next;
	
	struct node * tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->value = data;
	p->next = tmp;
	tmp->prev = p;
	tmp->next = q;
	q->prev = tmp;
	return head;	
}
struct node * add_before(struct node * head, int data, int before){
	if(head==NULL){
		printf("Empty list\n");
		return head;
	}
	struct node *p,*q,*tmp;
	q = head;
	if (q->value==before){
		q = addat_start(q,data);
		head=q;
		return head;
	}
	q = q->next;
	while(q!=NULL){
		if (q->value == before){
			p = q->prev;
			tmp = (struct node *)malloc(sizeof(struct node));
			tmp->value = data;
			tmp->prev = p;
			p->next = tmp;
			tmp->next = q;
			q->prev = tmp;
			return head;
		}
		q = q->next;
	}
	printf("Element not found\n");
	return head;
}
struct node * add_after(struct node * head,int data, int after){
	if(head==NULL){
		printf("Empty list\n");
		return head;
	}
	struct node *p,*q,*tmp;
	p = head;
	while(p->next!=NULL){
		if(p->value==after){
			q = p->next;
			tmp = (struct node *)malloc(sizeof(struct node));
			tmp->value = data;
			tmp->prev = p;
			tmp->next = q;
			p->next = tmp;
			q->prev = tmp;
			return head;
		}
		p= p->next;
	}
	if(p->value==after){
		printf("ok");
		head = addat_end(head,data);
		return head; 
	}
	printf("Element not found\n");
	return head;	 
}
struct node * del(struct node * head, int data){
	if(head == NULL){
		printf("Empty list");
		return head;
	}
	//delete first element
	struct node *tmp;
	if(head->value == data){
		tmp = head;
		if (head->next==NULL){
			head = NULL;
			free(tmp);
			return head;
		}
		head =  head->next;
		head->prev = NULL;
		free(tmp);
		return head;
	}
	//delete other element
	tmp = head->next;
	while(tmp->next!=NULL){
		if (tmp->value==data){
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free(tmp);
			return head;
		}
		tmp = tmp->next;
	}
	//delete last node
	if(tmp->value==data){
		tmp->prev->next=NULL;
		free(tmp);
		return head;
	}
	printf("Element not found\n");
	return head;
}
struct node * reverse(struct node * head){
	if (head ==NULL){
		printf("List Empty\n");
		return head;
	}
	struct node * prev, *next, *ptr;
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
