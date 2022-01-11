#include<bits/stdc++.h>
using namespace std;
const int N = 10e5+9;
int h[N]; int dp[N];
int minimum_cost(int n){
    if(n==0){
        return 0;
    }

    if(dp[n]!=-1) 
        return dp[n];

    int cost = INT_MAX;

    cost = min(cost, minimum_cost(n-1)+abs(h[n]-h[n-1]));

    if(n>1)
        cost = min(cost, minimum_cost(n-2)+abs(h[n]-h[n-2]));
    
    return dp[n] = cost;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    cout<<minimum_cost(n-1)<<endl;
    return 0;
}