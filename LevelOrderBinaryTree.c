#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left, * right;
};


struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

// Function to insert nodes in level order
struct Node* insertLevelOrder(int arr[], struct Node* root,int i, int n)
{
    // Base case for recursion
    if (i < n)
    {
        struct Node* temp = newNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr,root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr,root->right, 2 * i + 2, n);
    }
    return root;
}



void inOrder(struct Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d  ",root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node* root)
{
    if (root != NULL)
    {
        printf("%d  ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d  ",root->data);
    }
}



int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct Node* root = NULL;
    root = insertLevelOrder(arr, root, 0, n);
    printf("Inorder Traversal\n");
    inOrder(root);
    printf("\n");
    printf("Preorder Traversal\n");
    preOrder(root);
    printf("\n");
    printf("Postorder Traversal\n");
    postOrder(root);
    printf("\n");
}
