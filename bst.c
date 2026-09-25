#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};


struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}


struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}


struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}


struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else {
        
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        
        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
    }
void preorder(struct Node*root){
    if(root==NULL)
       return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
    }
    
void postorder(struct Node*root){
    if( root==NULL)
        return;   
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);   
    } 



int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n\n--- BST MENU ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);

                if (search(root, value))
                    printf("Value found\n");
                else
                    printf("Value not found\n");
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
                
            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
                
            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
