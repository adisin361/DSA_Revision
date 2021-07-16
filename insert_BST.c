#include<stdio.h>
#include<malloc.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(int val)
{
    struct Node* new = (struct Node*) malloc (sizeof(struct Node));
    new->data = val;
    new->left=NULL;
    new->right=NULL;
    return new;
}

void insert_node(struct Node* root, int key)
{
    struct Node* prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(key==root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if(key<root->data)
            root=root->left;
        else
            root=root->right;
    }
    struct Node* new=create_node(key);
    if(key<prev->data)
        prev->left=new;
    else
        prev->right=new;
}

int main()
{
    struct Node* root = create_node(9);
    struct Node* second = create_node(4);
    struct Node* third = create_node(11);
    struct Node* fourth = create_node(2);
    struct Node* fifth = create_node(7);
    struct Node* sixth = create_node(15);
    struct Node* seventh = create_node(5);
    struct Node* eighth = create_node(8);
    struct Node* nineth = create_node(14); 

    root->left = second;
    root->right = third;

    second->left=fourth;
    second->right=fifth;

    fifth->left=seventh;
    fifth->right=eighth;

    third->right=sixth;

    sixth->left=nineth;

    insert_node(root, 100);
    printf("%d", root->right->right->right->data);


    return 0;
}