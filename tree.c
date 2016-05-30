#include "stdio.h"
#include "stdlib.h"

struct node
{
	struct node *left;
	int data;
	struct node *right;
	struct node *parent;
};

struct node *head = NULL;
struct node *current = NULL;
struct node *parent = NULL;

void addLeft(int data, struct node *current, struct node *parent) {
	current->left = (struct node*)malloc(sizeof(struct node));
	parent = current;
	current = current->left;
	addData(data, current, parent);
	printf("\n Element [ %d ] has been added to the left node \n", current->data);
}

void addRight(int data, struct node *current, struct node *parent) {
	current->right = (struct node*)malloc(sizeof(struct node));
	parent = current;
	current = current->right;
	addData(data, current, parent);
	printf("\n Element [ %d ] has been added to the right node \n", current->data);
}

void addData(int data, struct node *current, struct node *parent) {

	if(current == NULL) {
		printf("\n Node creation failed..\n");
	}
	current->left = NULL;
	current->data = data;
	current->right = NULL;
	current->parent = parent;
}

void createTree() {
	int ch = 1, data;
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter Root Element: ");
	scanf("%d", &data);
	head = current;
	addData(data, current, parent);

	while(ch != 0) {
		printf("\n---CREATING BINARY TREE OPTIONS---\n");
		printf("\n1-->Create Left Node:");
		printf("\n2-->Create Right Node:");
		printf("\n3-->Branch to left Node:");
		printf("\n4-->Branch to Right Node:");
		printf("\n5-->Branch to Parent Node:");
		printf("\n6-->Branch to Root Node:");
		printf("\n0-->Go Back\n");

		printf("\n VALUE OF CURRENT NODE : %d\n", current->data);
		printf("\n Enter your Choice: ");

		

		scanf("%d", &ch);

		switch(ch) {

			case 1:
				printf("\nEnter left Element: ");
				scanf("%d", &data);
				addLeft(data, current, parent);
			break;

			case 2:
				printf("\nEnter right Element: ");
				scanf("%d", &data);
				addRight(data, current, parent);
			break;

			case 3:
				printf("Branching to left node:\n");
				if(current->left != NULL) {
					current = current->left;
					printf("Left Node is now Selected\n");
					printf("Element at left Node is --> %d\n", current->data);
				} else {
					printf("Left Node doesn't exist...please create one ;D\n");
				}
			break;

			case 4:
				printf("Branching to right node:\n");
				if(current->right != NULL) {
					current = current->right;
					printf("Right Node is now Selected\n");
					printf("Element at right Node is --> %d\n", current->data);
				} else {
					printf("Right Node doesn't exist...please create one ;D\n");
				}
			break;

			case 5:
				printf("Branching to parent node..:\n");
				if(current->parent != NULL) {
					current = current->parent;
					printf("Parent Node is now Selected\n");
					printf("Element at Parent Node is --> %d\n", current->data);
				} else {
					printf("Root Node is selected..No Parent NODE..\n");
				}
				
			break;

			case 6:
				printf("Branching to root node:\n");
				if(head != NULL) {
					current = head;
					printf("Root Node is now Selected\n");
					printf("Element at Root Node is --> %d\n", current->data);
				} else {
					printf("Root Node doesn't exist...please create one ;D\n");
				}				
			break;

			default:
			break;
		}
	}
}

void displayPreOrder(struct node *node) {

	if(node != NULL) {	
		printf("%d, ", node->data);
		displayPreOrder(node->left);
		displayPreOrder(node->right);
	}

}

void displayInOrder(struct node *current) {
	
	if(current != NULL) {
		displayInOrder(current->left);
		printf("%d, ", current->data);
		displayInOrder(current->right);
	}
	
}

void displayPostOrder(struct node *current) {
	
	if(current != NULL) {
		displayPostOrder(current->left);
		displayPostOrder(current->right);
		printf("%d, ", current->data);
	}
	
}




void main() {

	int choice = 1;
	
	head = (struct node*)malloc(sizeof(struct node));


	while(choice != 0) {
		printf("\n------------------------");
		printf("\n     OPTIONS     \n");
		printf("------------------------\n");
		printf("\n1-->Create a Tree:\n");
		printf("\n2-->Display Pre-Order:\n");
		printf("\n3-->Display In-Order:\n");
		printf("\n4-->Display Post-Order:\n");
		printf("\n0-->EXIT\n");
		printf("\n------------------------\n");
		printf("\n Enter your Choice: ");
		
		scanf("%d", &choice);

		switch(choice) {

			case 1:
				printf("\nBinary Tree Constructing..\n");
				createTree();
			break;

			case 2:
				printf("\nTree in Pre-Order:\n");
				displayPreOrder(head);
			break;

			case 3:
				printf("\nTree in In-Order:\n");
				displayInOrder(head);
			break;

			case 4:
				printf("\nTree in Post-Order:\n");
				displayPostOrder(head);
			break;

			case 0: 
				printf("BYE! :-)\n");
				exit(0);
			break;
			default:
				printf("----OOPS!...INVALID CHOICE----\n");
			break;
		}
	}	

	
}



