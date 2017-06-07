#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node * next;
};

struct node * create_list(struct node * head);
void display(struct node * head){
	if(head ==NULL){
		printf("Empty list\n");
		return;
	}
	struct node * ptr = head;
	while(ptr!=NULL){
		printf("%d-",ptr->value);
		ptr=ptr->next;
	}
}
void sel_sort_ed(struct node * head);
void bs_sort_ed(struct node * head);
//void sel_sort_r(struct node * head);
//void bs_sort_r(struct node * head);

int main(){
	struct node * head = NULL;
	head = create_list(head);
	printf("Entered list\n");
	display(head);
	printf("sorted list\n");
	sel_sort_ed(head);
	display(head);
	bs_sort_ed(head);
	display(head);
//	sel_sort_r(head);
//	display(head);
//	bd_sort_r(head);
//	display(head);
	return 0;
}

struct node * addto_start(struct node * head,int data){
	struct node * tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->value = data;
	tmp->next = head;
	head = tmp;
	return head;
}

struct node * addto_end(struct node * head, int data){
	struct node *tmp, *ptr;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->value = data;
	tmp->next = NULL;
		
	ptr = head;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	
	ptr->next = tmp;
	return head;
}

struct node * create_list(struct node * head){
	int data,i,n;
	head =NULL;
	printf("Enter number of nodes:");
	scanf("%d",&n);
	if(n==0)
		return head;
	
	printf("Enter the element to be inserted:");
	scanf("%d",&data);
	head = addto_start(head,data);
	for(i=2;i<=n;i++){
		printf("Enter the element to be inserted:");
		scanf("%d",&data);
		head = addto_end(head,data);		
	}
	return head;
}

void sel_sort_ed(struct node * head){
	struct node *p, *q;
	int tmp;
	
	printf("Merge sort\n");
	p = head;
	for(p=head;p->next!=NULL;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if(p->value > q->value){
				tmp= p->value;
				p->value = q->value;
				q->value = tmp;
			}
		}
	}
}

void bs_sort_ed(struct node * head){
	struct node *p, *q, *end;
	int tmp;
	printf("Bubble sort\n");
	for(end = NULL;end!=head->next;end=q){
		for(p=head;p->next!=end;p=p->next){
			q=p->next;
			if(p->value > q->value){
				tmp = p->value;
				p->value = q->value;
				q->value = tmp;
			}
		}
	}
}


