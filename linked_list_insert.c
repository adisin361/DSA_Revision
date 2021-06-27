#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct Node *insert_at_first(struct Node* head, int value)
{
    struct Node* new = (struct Node*) malloc (sizeof(struct Node));
    new -> data = value;
    new->next = head->next;
    return new;
}

struct Node* insert_at_index(struct Node* head, int index, int value)
{
    struct Node *new = (struct Node*) malloc (sizeof(struct Node));
    new -> data = value;
    struct Node *p = head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    new->next = p->next;
    p->next = new;
    return head;
}

struct Node *insert_at_end(struct Node* head, int value)
{
    struct Node* new = (struct Node*) malloc (sizeof(struct Node));
    new->data=value;
    struct Node* p=head;
    while(p->next!=NULL)
        p=p->next;
    p->next=new;
    new->next=NULL;
    return head;
}

struct Node* insert_after_node(struct Node* head, struct Node* prev_node, int value)
{
    struct Node* new = (struct Node*) malloc (sizeof(struct Node));
    new -> data=value;
    new->next=prev_node->next;
    prev_node->next=new;
    return head;
}

int main()
{
    struct Node *head = (struct Node*) malloc (sizeof(struct Node));
    struct Node *second = (struct Node*) malloc (sizeof(struct Node));
    struct Node *third = (struct Node*) malloc (sizeof(struct Node));
    struct Node *fourth = (struct Node*) malloc (sizeof(struct Node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = NULL;

    traversal(head);
    // struct Node* newHead = insert_at_first(head, 45);
    // traversal(newHead);
    // struct Node* newHead2 = insert_at_index(head, 2, 90);
    // traversal(newHead2);
    // struct Node* newHead3 = insert_at_end(head, 99);
    // traversal(newHead3);
    struct Node* newHead4 = insert_after_node(head, second, 100);
    traversal(newHead4);
    return 0;
}