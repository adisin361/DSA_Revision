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

void inorder(struct Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int isBST(struct Node* root)
{
    static struct Node* prev = NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
            return 0;
        if(prev!=NULL && root->data <= prev->data)
            return 0;
        prev=root;
        return isBST(root->right);
    }

    else
        return 1;
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

    inorder(root);
    printf("\n");
    printf("%d", isBST(root));
    return 0;
}