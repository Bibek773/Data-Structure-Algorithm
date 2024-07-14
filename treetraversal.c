#include <stdio.h>
#include <stdlib.h>

struct node{
    int item;
    struct node* left;
    struct node* right;
};

void inorderTraversal(struct node* root)
{
    if(root==NULL)return;
    inorderTraversal(root->left);
    printf("%d ->",root->item);
    inorderTraversal(root->right);
}

void preorderTraversal(struct node *root){
    if(root == NULL) return;
    printf("%d ->",root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct node* root){
    if (root ==NULL )return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d->",root->item);
}

struct node* createNode(int value)
{
    struct node* newNode =malloc (sizeof(struct node));
    newNode->item=value;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;

};

struct node* insertLeft(struct node* root, int value){
    root->left =createNode(value);
    return root->left;
};

struct node* insertRight(struct node* root, int value){
    root->right =createNode(value);
    return root->right;
};

int main() {
    int p,l,r,sll, srl, srr, slr;
    printf("\n Enter the value for the parent node\n");
    scanf("%d",&p);
    printf("Enter the value for the left child root\n");
    scanf("%d",&l);
    printf("Enter the value for the right child root\n");
    scanf("%d",&r);
    printf("Enter the value for the left sub-root of left child root\n");
    scanf("%d",&sll);
    printf("Enter the value for the right sub-root of left child root\n");
    scanf("%d",&srl);
    printf("Enter the value for the left sub-root of right child root\n");
    scanf("%d",&slr);
    printf("Enter the value for the right sub-root of right child root\n");
    scanf("%d",&srr);
    struct node* root =createNode(p);

    insertLeft(root, l);
    insertRight(root,r);

    insertLeft(root->left, sll);
    insertRight(root->left, srl);
    insertLeft(root->right, slr);
    insertRight(root->right, srr);

    printf("Inorder traversal\n");
    inorderTraversal(root);

    printf("\nPreorder traversal \n");
    preorderTraversal(root);

    printf("\nPostorder traversal \n");
    postorderTraversal(root);
    return 0;
}

