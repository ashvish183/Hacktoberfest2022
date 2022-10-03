#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int info;
	struct node* link;
};
struct node* start = NULL;
void createList()
{
	if (start == NULL) 
	{
		int n;
		printf("\nENTER THE NUMBER OF NODES: ");
		scanf("%d", &n);
		if (n != 0) 
		{
			int data;
			struct node* newnode;
			struct node* temp;
			newnode = malloc(sizeof(struct node));
			start = newnode;
			temp = start;
			printf("ENTER THE NUMBER TO BE INSERTED: \n\n");
			scanf("%d", &data);
			start->info = data;
			for (int i = 2; i <= n; i++) 
			{
				newnode = malloc(sizeof(struct node));
				temp->link = newnode;
				printf("ENTER THE NUMBER TO BE INSERTED: \n\n");
				scanf("%d", &data);
				newnode->info = data;
				temp = temp->link;
			}
		}
		printf("\nTHE LIST IS CREATED.\n");
	}
	else
		printf("\nTHE LIST IS ALREADY CREATED.\n");
}
void traverse()
{
    struct node* temp;
    if (start == NULL)
        printf("THE LIST IS EMPTY\n\n");
    else 
	{
        temp = start;
        while (temp != NULL) 
		{
            printf("DATA = %d\n\n", temp->info);
            temp = temp->link;
        }
    }
}
void insertAtFront()
{
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	printf("\nENTER THE NUMBER TO BE INSERTED: ");
	scanf("%d", &data);
	temp->info = data;
	temp->link = start;
	start = temp;
}
void insertAtEnd()
{
	int data;
	struct node *temp, *head;
	temp = malloc(sizeof(struct node));
	printf("\nENTER THE NUMBER TO BE INSERTED : ");
	scanf("%d", &data);
	temp->link = 0;
	temp->info = data;
	head = start;
	while (head->link != NULL) 
	{
		head = head->link;
	}
	head->link = temp;
}
void insertAtPosition()
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));
	printf("\nENTER POSITION AND DATA: ");
	scanf("%d %d", &pos, &data);
	temp = start;
	newnode->info = data;
	newnode->link = 0;
	while (i < pos - 1) 
	{
		temp = temp->link;
		i++;
	}
	newnode->link = temp->link;
	temp->link = newnode;
}
void deleteFirst()
{
	struct node* temp;
	if (start == NULL)
		printf("\nTHE LIST IS EMPTY\n");
	else {
		temp = start;
		start = start->link;
		free(temp);
	}
}
void deleteEnd()
{
	struct node *temp, *prevnode;
	if (start == NULL)
		printf("\nTHE LIST IS EMPTY\n");
	else 
	{
		temp = start;
		while (temp->link != 0) 
		{			
			prevnode = temp;
			temp = temp->link;
		}
		free(temp);
		prevnode->link = 0;
	}
}
void deletePosition()
{
	struct node *temp, *position;
	int i = 1, pos;
	if (start == NULL)
		printf("\nTHE LIST IS EMPTY\n");

	else {
		printf("\nENTER THE INDEX: ");
		scanf("%d", &pos);
		position = malloc(sizeof(struct node));
		temp = start;
		while (i < pos - 1) {
			temp = temp->link;
			i++;
		}
		position = temp->link;
		temp->link = position->link;
		free(position);
	}
}
int main()
{
	int choice;
	while (1) {

		printf("PRESS 1 TO SEE THE LIST\n");
		printf("PRESS 2 FOR INSERTING AN ELEMENT AT THE STARTING\n");
		printf("PRESS 3 FOR INSERTING AN ELEMENT AT THE END\n");
		printf("PRESS 4 FOR INSERTING AN ELEMENT AT ANY POSITION\n");
		printf("PRESS 5 FOR DELETING THE FIRST ELEMENT\n");
		printf("PRESS 6 FOR DELETING THE LAST ELEMENT\n");
		printf("PRESS 7 FOR DELETING AN ELEMENT AT ANY POSITION\n");
		printf("PRESS 8 TO EXIT\n");
		printf("\nENTER CHOICE: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			deletePosition();
			break;
		case 8:
			exit(1);
			break;
		default:
			printf("INCORRECT CHOICE\n");
		}
	}
	return 0;
}