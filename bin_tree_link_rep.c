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

int main()
{
    struct Node* root = create_node(1);
    struct Node* second = create_node(2);
    struct Node* third = create_node(3);

    root->left=second;
    root->right=third;
    
    return 0;
}