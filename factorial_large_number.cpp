#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node(int n){
        data = n;
        prev = NULL;
    }
};

void multiply(Node* tail, int n){
    Node* temp = tail;
    Node* prevNode = tail;
    int carry = 0;
    while(temp!=NULL){
        int data = (temp->data)*n+carry;
        temp->data = data%10;
        carry = data/10;
        prevNode = temp;
        temp=temp->prev;
    }

    while(carry!=0){
        prevNode->prev=new Node((int)(carry%10));
        carry = carry/10;
        prevNode=prevNode->prev;
    }
}

void print(Node* tail){
    if(tail==NULL)
        return;
    print(tail->prev);
    cout<<tail->data;
}

int main(){
    int n = 10;
    Node tail(1);
    for(int i=2; i<=n; i++){
        multiply(&tail, i);
    }
    print(&tail);
    cout<<endl;
    return 0;
}