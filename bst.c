#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *left,*right;
};
//Create a node
struct node* create(int val){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = val;
    new->left = new->right = NULL;
    return new;
}
//insertion
 struct node* insert(struct node* root, int data)
    {
        if (root == NULL)    //If the tree is empty, return a new,single node
            return create(data);
        else
        {
            //Otherwise, recur down the tree
            if (data <= root->data)
                root->left  = insert(root->left, data);
            else
                root->right = insert(root->right, data);
            //return the (unchanged) root pointer
            return root;
        }
    }
//traversal
 void inorder(struct node*root)
    {
        if(root)
        {
            inorder(root->left);    //Go to left subtree
            printf("%d ",root->data);    //Printf root->data
            inorder(root->right);     //Go to right subtree
        }
    }

//deletion

struct node* successor(struct node* root){
    struct node* temp = root;

    //traverse all the way down to the bottom-left child

    while(temp->left!=NULL){

        temp = temp->left;

    }
    return temp;
}

struct node* deleteNode(struct node* root, int key){
    if(root==NULL){
        return root;
    }
    //key lies to the left
    if(root->data>key){
        root->left = deleteNode(root->left,key);
    }
    //key lies to the right
    else if(root->data<key){
        root->right= deleteNode(root->right,key);
    }
    //the node to be deleted
    else{
        //node has only one child or no children
        if(root->left==NULL){
            struct node*temp = root->right;
            free(root);
            return temp;

        }
        else if(root->right==NULL){
            struct node*temp = root->left;
            free(root);
            return temp;

        }
        //node has two children. Need to find the successor of the current node.
        struct node* temp =successor(root->right);
        //copy successor
        root->data = temp->data;
        //delete the inorder successor
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}

int main(){
    struct node* root =NULL;
    int x,ch;
    printf("1 to Insert\n2 to Delete\n3 to Display");
    while(1){
        printf("Choice:: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Value:: "); scanf("%d",&x);
                    root=insert(root,x);
                    inorder(root);
                    break;
            case 2: printf("Value:: "); scanf("%d",&x);
                    root=deleteNode(root,x);
                    inorder(root);
                    break;
            case 3: inorder(root);
                    break;
            default: printf("Invalid Option\n\n");
        }
    }

}
