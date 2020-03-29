/*2.Program to construct tree from inorder traversal */
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* LEFT;
    struct node* RIGHT;
};
int max(int inorder[], int strt, int end);
struct node* newNode(int data);
struct node* buildTree (int inorder[], int start, int end)
{
    if (start > end)
        return NULL;
    int i = max (inorder, start, end);
    struct node *root = newNode(inorder[i]);
    if (start == end)
        return root;
    root->LEFT  = buildTree (inorder, start, i-1);
    root->RIGHT = buildTree (inorder, i+1, end);
    return root;
}
int max (int arr[], int strt, int end)
{
    int i, max = arr[strt], maxind = strt;
    for(i = strt+1; i <= end; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            maxind = i;
        }
    }
    return maxind;
}
struct node* newNode (int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->LEFT = NULL;
    node->RIGHT = NULL;
    return node;
}
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder (node->LEFT);
    printf("%d ", node->data);
    printInorder (node->RIGHT);
}
int main()
{
    int inorder[] = {5, 10, 40, 30, 28};
    int len = sizeof(inorder)/sizeof(inorder[0]);
    struct node *root = buildTree(inorder, 0, len - 1);
    printf("Inorder traversal of the constructed tree is \n");
    printInorder(root);
    return 0;
}
