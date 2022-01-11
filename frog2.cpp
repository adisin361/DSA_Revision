#include<bits/stdc++.h>
using namespace std;
const int N = 10e5+9;
int k; int h[N];

int mini_cost(int n){
    if(n==0) return 0;
    int cost = INT_MAX;
    for(int j=1; j<=k; j++){
        if(n-j>=0)
            cost = min(cost, mini_cost(n-j)+abs(h[n]-h[n-j]));
    }
    return cost;
}

int main(){
    int n;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    cout<<mini_cost(n-1)<<endl;
    return 0;
}