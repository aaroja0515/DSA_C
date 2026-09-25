#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
  char url[100];
  struct Node *prev;
  struct Node *next;
};
struct Node *current = NULL;
void visitPage(char url[])
{
 struct Node *newNode;
 struct Node *temp;
 if (current != NULL && current->next != NULL)
 {
temp = current->next;
while (temp != NULL)
{
struct Node *deleteNode = temp;
temp = temp->next;
free(deleteNode);
}
current->next = NULL;
}

newNode = (struct Node *)malloc(sizeof(struct Node));
strcpy(newNode->url, url);
newNode->prev = current;
newNode->next = NULL;

if (current != NULL)
{
current->next = newNode;
}

current = newNode;
printf("Visited: %s\n", current->url);
}

void goBack()
{
if (current == NULL || current->prev == NULL)
{
printf("Cannot go back.\n");
}
else
{
current = current->prev;
printf("Moved back to: %s\n", current->url);
}
}

void goForward()
{
if (current == NULL || current->next == NULL)
{
printf("Cannot go forward.\n");
}
else
{
current = current->next;
printf("Moved forward to: %s\n", current->url);
}
}

void displayPage()
{
if (current == NULL)
{
printf("No page visited yet.\n");
}
else
{
printf("Current Page: %s\n", current->url);
}
}

int main()
{
int choice;
char url[100];
do
{
printf("\n--- Browser ---\n");
printf("1. Visit New Page\n");
printf("2. Go Back\n");
printf("3. Go Forward\n");
printf("4. Display Current Page\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice); 
switch (choice)
{
case 1:
printf("Enter URL: ");
scanf("%s", url);
visitPage(url);
break;
case 2:
goBack();
break;
case 3:
goForward();
break;
case 4:
displayPage();
break;
case 5:
printf("Exiting Browser...\n");
break;
default:
printf("Invalid choice.\n");
}
} while (choice != 5);
return 0;
}
