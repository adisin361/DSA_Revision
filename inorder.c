#include<stdio.h>
#include<malloc.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(int value)
{
    struct Node* p = (struct Node*) malloc (sizeof(struct Node));
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void inorder(struct Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node* root = create_node(4);
    struct Node* second = create_node(1);
    struct Node* third = create_node(6);
    struct Node* fourth = create_node(5);
    struct Node* fifth = create_node(2);

    root->left=second;
    root->right=third;

    second->left = fourth;
    second->right = fifth;
    
    inorder(root);
    return 0;
}