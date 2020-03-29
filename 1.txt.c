//1.Write a C program to print preorder, inorder, and postorder traversal on Binary Tree.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int DATA;
    struct node* LEFT;
    struct node* RIGHT;
};
void inorder(struct node* root)
{
    if(root == NULL) return;
    inorder(root->LEFT);
    printf("%d ->", root->DATA);
    inorder(root->RIGHT);
}
void preorder(struct node* root)
{
    if(root == NULL) return;
    printf("%d ->", root->DATA);
    preorder(root->LEFT);
    preorder(root->RIGHT);
}
void postorder(struct node* root)
{
    if(root == NULL) return;
    postorder(root->LEFT);
    postorder(root->RIGHT);
    printf("%d ->", root->DATA);
}
struct node* createNode(value)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->DATA = value;
    newNode->LEFT = NULL;
    newNode->RIGHT = NULL;

    return newNode;
}
struct node* insertLeft(struct node *root, int value)
{
    root->LEFT = createNode(value);
    return root->LEFT;
}
struct node* insertRight(struct node *root, int value)
{
    root->RIGHT = createNode(value);
    return root->RIGHT;
}
int main(){
    struct node* root = createNode(1);
    insertLeft(root, 12);
    insertRight(root, 9);

    insertLeft(root->LEFT, 5);
    insertRight(root->LEFT, 6);

    printf("Inorder traversal \n");
    inorder(root);

    printf("\nPreorder traversal \n");
    preorder(root);

    printf("\nPostorder traversal \n");
    postorder(root);
}
