#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* delete_at_first(struct Node* head)
{
    struct Node* ptr = head;
    head=head->next;
    free(ptr);
    return head;
}

struct Node* delete_at_index(struct Node* head, int index)
{
    struct Node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next=q->next;
    free(q); 
    return head;
}

struct Node* delete_at_last(struct Node* head)
{
    struct Node *p=head;
    while(p->next->next!=NULL)
        p=p->next;
    struct Node *q = p->next;
    p->next = NULL;
    free(q);
    return head;
}

struct Node* delete_given_value(struct Node* head, int value)
{
    struct Node *p = head;
    
    while(p->next->data!=value)
        p=p->next;
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

void traversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
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
    fourth->next = NULL;

    traversal(head);
    // struct Node* head2 = delete_at_first(head);
    // traversal(head2);

    // struct Node* head3 = delete_at_index(head, 2);
    // traversal(head3);

    // struct Node* head4 = delete_at_last(head);
    // traversal(head4);

    struct Node* head5 = delete_given_value(head, 3);
    traversal(head5);

    return 0;

}