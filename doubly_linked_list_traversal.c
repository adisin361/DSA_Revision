#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void traversal(struct Node* head)
{
    struct Node* ptr = head;
    while(ptr!=NULL)
    {
        printf("%d -> ", ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

void rev_traversal(struct Node* head)
{
    struct Node* ptr = head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    while(ptr!=NULL)
    {
        printf("%d -> ", ptr->data);
        ptr=ptr->prev;
    }
    printf("NULL");
}

int main()
{
    struct Node* head = (struct Node*) malloc (sizeof(struct Node));
    struct Node* second = (struct Node*) malloc (sizeof(struct Node));
    struct Node* third = (struct Node*) malloc (sizeof(struct Node));
    struct Node* fourth = (struct Node*) malloc (sizeof(struct Node));

    head->data = 1;
    head->prev = NULL;
    head->next = second;
    second->data = 2;
    second->prev = head;
    second->next = third;
    third->data = 3;
    third->prev = second;
    third->next = fourth;
    fourth->data = 4;
    fourth->prev = third;
    fourth->next = NULL;

    traversal(head);
    printf("\n");
    rev_traversal(head);
    return 0;

}