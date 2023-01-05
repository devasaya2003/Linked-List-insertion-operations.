#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*next;
};

void printLL(struct node*ptr){
	int i=1;
	while(ptr != NULL){
		printf("Data at node %d = %d\n",i,ptr->data);
		ptr = ptr->next;
		i++;
	}
}

struct node*insert_at_start(struct node*head, int data){
	
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr->next = head;
	ptr->data = data;
	return ptr;
}

struct node*insert_at_index(struct node*head, int data, int index){
	
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	struct node* p = head;
	
	int i = 0;
	
	while(i!=index-1){
		p = p->next;
		i++;
	}
	
	ptr->next = p->next;
	p->next = ptr;
	ptr->data = data;
	return head;
}

struct node*insert_at_end(struct node*head, int data){
	
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	struct node* p = head;
	while(p->next != NULL){
		p = p->next;
	}
	
	p->next = ptr;
	ptr->next = NULL;
	ptr->data = data;
	return head;
}

struct node*insert_after_node(struct node*head, struct node*prev, int data){
	
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	
	ptr->data = data;
	ptr->next = prev->next;
	prev->next = ptr;
	
	return head;
}

int main(){
	struct node*head;
	struct node*second;
	struct node*third;
	struct node*fourth;
	
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	fourth = (struct node*)malloc(sizeof(struct node));
	
	head->data = 10;
	head->next = second;
	second->data = 20;
	second->next = third;
	third->data = 30;
	third->next = fourth;
	fourth->data = 40;
	fourth->next = NULL;
	
	printf("Linked List:\n");
	printLL(head);
	printf("\n\n");

	int choice, d, index, prev_node;
	
	printf("Performing Insertion:\n");
	printf("Type '1' for insertion at start.\n");
	printf("Type '2' for insertion at index.\n");
	printf("Type '3' for insertion at end.\n");
	printf("Type '4' for insertion after a node.\n");
	
	printf("Please Choose : ");
	scanf("%d",&choice);
	printf("\n\n");
	
	
	switch(choice){
		
		case 1:
			printf("Enter the data to be stored : ");
			scanf("%d",&d);
			head = insert_at_start(head,d);
			printf("\nLinked List after insertion:\n");
			printLL(head);
			break;
		
		case 2:
			printf("Enter the data to be stored : ");
			scanf("%d",&d);
			printf("\nEnter the index : ");
			scanf("%d",&index);
			head = insert_at_index(head,d,index);
			printf("\nLinked List after insertion:\n");
			printLL(head);
			break;
		
		case 3:
			printf("Enter the data to be stored : ");
			scanf("%d",&d);
			head = insert_at_end(head,d);
			printf("\nLinked List after insertion:\n");
			printLL(head);
			break;
			
		case 4:
			printf("Enter the data to be stored : ");
			scanf("%d",&d);
			printf("\nEnter the previous node :\n");
			printf("1 for first\n");
			printf("2 for second.\n");
			printf("3 for third.\n");
			printf("4 for fourth.\n");
			printf("Please type : ");
			scanf("%d",&prev_node);
			switch(prev_node){
				
				case 1:
					head = insert_after_node(head, head, d);
					printf("\nLinked List after insertion:\n");
					printLL(head);
					break;
				case 2:
					head = insert_after_node(head, second, d);
					printf("\nLinked List after insertion:\n");
					printLL(head);
					break;
				case 3:
					head = insert_after_node(head, third, d);
					printf("\nLinked List after insertion:\n");
					printLL(head);
					break;
				case 4:
					head = insert_after_node(head, fourth, d);
					printf("\nLinked List after insertion:\n");
					printLL(head);
					break;
				
			}
		
		default:
			printf("Either you are a dumb fuck or you don't know how to read...!");
			
	}
	
	
	return 0;
}