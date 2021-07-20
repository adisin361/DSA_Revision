#include<stdio.h>
#include<malloc.h>

struct Node
{
    struct Node* right;
    struct Node* left;
    int data;
};

struct Node* create_node(int val)
{
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->left=NULL;
    new->right=NULL;
    new->data=val;
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

struct Node* in_order_predecessor(struct Node* root)
{
    root=root->left;
    while(root->right!=NULL)
        root=root->right;
    return root;
}

struct Node* del_node(struct Node* root, int key)
{
    struct Node* iPre;
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(key>root->data)
        root->right=del_node(root->right, key);
    else if(key<root->data)
        root->left=del_node(root->left, key);
    else
    {
        iPre=in_order_predecessor(root);
        root->data=iPre->data;
        root->left=del_node(root->left, iPre->data);
    }
    return root;
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
    root=del_node(root, 7);
    printf("\n");
    inorder(root);
    return 0;
}