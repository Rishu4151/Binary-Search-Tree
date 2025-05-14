#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

struct Node* findSmallest(struct Node* root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* findLargest(struct Node* root) {
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

void deleteTree(struct Node* node) {
    if (node == NULL)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
}

int main() {
    struct Node *root = NULL, *temp;
    int choice, val, key;

    do {
        printf("\n----------------------------------------");
        printf("\nBinary Search Tree Menu");
        printf("\n----------------------------------------");
        printf("\n0. Quit\n1. Create\n2. In-Order Traversal\n3. Pre-Order Traversal\n4. Post-Order traversal\n5. Search\n6. Find Smallest Element\n7. Find Largest Element\n8. Deletion of Tree\n");
        printf("----------------------------------------\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                deleteTree(root);
                printf("Exiting...\n");
                break;

            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                printf("In-order Traversal: ");
                inorder(root); 
                printf("\n"); 
                break;

            case 3:
                printf("Pre-order Traversal: ");
                preorder(root); 
                printf("\n"); 
                break;

            case 4:
                printf("Post-order Traversal: ");
                postorder(root); 
                printf("\n"); 
                break;

            case 5:
                printf("Enter element to search: ");
                scanf("%d", &key);
                temp = search(root, key);
                if (temp != NULL)
                    printf("Element %d found.\n", key); 
                else
                    printf("Element not found.\n");
                break;

            case 6:
                temp = findSmallest(root); 
                if(temp != NULL)
                    printf("Smallest Element: %d\n", temp->data); 
                else
                    printf("Tree is empty.\n");
                break;

            case 7:
                temp = findLargest(root); 
                if(temp != NULL)
                    printf("Largest Element: %d\n", temp->data); 
                else
                    printf("Tree is empty.\n");
                break;

            case 8:
                deleteTree(root); 
                root=NULL; 
                printf("Tree deleted successfully.\n"); 
                break;

            default:
                printf("Invalid choice!\n");
        }
        
    } while(choice != 0);

return 0;
}
