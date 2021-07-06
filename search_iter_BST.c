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

struct Node* search_iter(struct Node* root, int val)
{
    while(root!=NULL)
    {
        if(root->data==val)
            return root;
        else if(val<root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
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
    
    struct Node* p=search_iter(root, 9);
    if(p!=NULL)
        printf("Found: %d\n", p->data);
    else
        printf("Not Found!");
    return 0;
}