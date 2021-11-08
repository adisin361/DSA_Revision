#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define rep(i,a,b) for(int i=a; i<b; i++)
const int N = 1e5+2;
vi adj[N];

signed main(){
    int n, m; // n = no. of nodes, m = no. of edges
    cin>>n>>m;
    // adjacency matrix
    vvi adjm(n+1, vi(n+1, 0));

    rep(i,0,m){
        int x, y;
        cin>>x>>y;

        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }

    cout<<"Adjacency Matrix of above graph is given here: "<<endl;
    rep(i,1,n+1){
        rep(j,1,n+1)
            cout<<adjm[i][j]<<" ";
        cout<<endl;
    }

    // checking if an edge is present or not
    if(adjm[3][7] == 1)
        cout<<"Edge Present"<<endl;
    else
        cout<<"Edge NOT Present"<<endl;
    cout<<endl<<endl;
    
    // adjacency list
    cin>>n>>m;
    rep(i,0,m){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"Adjacency List given below: "<<endl;
    rep(i,1,n+1){
        cout<<i<<"->";
        vector<int> :: iterator it;
        for(it=adj[i].begin(); it!=adj[i].end(); it++)
        {
            cout<<*it<< " ";
        }
        cout<<endl;
    }    
    return 0;
}
