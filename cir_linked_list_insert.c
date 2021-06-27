#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void traversal(struct Node* head)
{
    struct Node* ptr = head;
    do
    {
        printf("%d -> ", ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
    printf("HEAD");
}

struct Node* insert_at_head(struct Node* head, int value)
{
    struct Node* new = (struct Node*) malloc (sizeof(struct Node));
    new->data = value;
    struct Node* ptr = head;
    do
    {
        ptr=ptr->next;
    } while (ptr->next!=head);
    ptr->next=new;
    new->next=head;
    head=new;
    return head;
}

struct Node* insert_at_index(struct Node* head, int value, int index)
{
    struct Node* new = (struct Node*) malloc (sizeof(struct Node));
    new->data = value;
    struct Node* ptr = head;
    int i=0;
    while(i!=index-1)
    {
        ptr=ptr->next;
        i++;
    }
    new->next = ptr->next;
    ptr->next = new;
    return head;
}

struct Node* insert_at_end(struct Node* head, int value)
{
    struct Node* new=(struct Node*) malloc (sizeof(struct Node));
    new->data=value;
    struct Node* ptr = head->next;
    while(ptr->next!=head)
        ptr=ptr->next;
    ptr->next = new;
    new->next=head;
    return head;
}

struct Node* insert_after_node(struct Node* head, struct Node* node, int value)
{
    struct Node* new = (struct Node*) malloc (sizeof(struct Node));
    new->data=value;
    new->next=node->next;
    node->next=new;
    return head;
}

int main()
{
    struct Node* head = (struct Node*) malloc (sizeof(struct Node));
    struct Node* second = (struct Node*) malloc (sizeof(struct Node));
    struct Node* third = (struct Node*) malloc (sizeof(struct Node));
    struct Node* fourth = (struct Node*) malloc (sizeof(struct Node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = head;

    traversal(head);
    head = insert_at_head(head, 56);
    printf("\n");
    traversal(head);
    head = insert_at_index(head, 99, 3);
    printf("\n");
    traversal(head);
    head = insert_at_end(head, 100);
    printf("\n");
    traversal(head);
    head = insert_after_node(head, third, 755);
    printf("\n");
    traversal(head);
    return 0;
}