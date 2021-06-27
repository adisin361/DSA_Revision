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
    }while(ptr!=head);
    printf("HEAD");
}

struct Node* delete_head(struct Node* head)
{
    struct Node* ptr=head;
    struct Node* p = head;
    do
    {    
        ptr=ptr->next;
    }
    while (ptr->next!=head);
    ptr->next = head->next;
    head=head->next;
    free(p);
    return head;
}

struct Node* delete_at_end(struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->next;
    int i=0;
    do
    {
        p=p->next;
        q=q->next;
        i++;
    }while(q->next!=head);
    p->next = head;
    free(q);
    return head;
}

struct Node* delete_after_node(struct Node* head, struct Node* node)
{
    struct Node* p = node->next;
    node->next=node->next->next;
    free(p);
    return head;
}

struct Node* delete_index(struct Node* head, int index)
{
    struct Node* p = head;
    struct Node* q = head->next;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}


int main()
{
    struct Node* head = (struct Node*) malloc (sizeof(struct Node));
    struct Node* second = (struct Node*) malloc (sizeof(struct Node));
    struct Node* third = (struct Node*) malloc (sizeof(struct Node));
    struct Node* fourth = (struct Node*) malloc (sizeof(struct Node));
    struct Node* fifth = (struct Node*) malloc (sizeof(struct Node));
    
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=fourth;
    fourth->data=4;
    fourth->next=fifth;
    fifth->data=5;
    fifth->next=head;
    traversal(head);
    head = delete_head(head);
    printf("\n");
    traversal(head);
    printf("\n");
    head = delete_index(head, 2);
    traversal(head);
    printf("\n");
    head = delete_at_end(head);
    traversal(head);
    printf("\n");
    head = delete_after_node(head, second);
    traversal(head);
    return 0;
}