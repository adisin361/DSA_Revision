#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second

struct Node
{
    int key;
    Node* right;
    Node* left;
};

Node* newNode(int key)
{
    Node* newNode = new Node();
    newNode -> key = key;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void verticalOrder(Node* root, int hdis, map<int, vi> &m)
{
    if(root==NULL)
        return;
    m[hdis].push_back(root->key);
    verticalOrder(root->left, hdis-1, m);
    verticalOrder(root->right, hdis+1, m);
}
 
signed main()
{
    Node* root = newNode(10);
    root -> left = newNode(7);
    root ->right = newNode(4);
    root->left->left = newNode(3);
    root->left->right = newNode(11);
    root->right->left = newNode(14);
    root->right->right = newNode(6);

    map<int, vi>m;
    int hdis = 0;
    verticalOrder(root,hdis,m);
    map<int, vi> :: iterator it;
    for(it = m.begin(); it!=m.end(); ++it)
    {
        for(int i=0; i<(it->ss).size(); i++)
        {
            cout<<(it->ss)[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}