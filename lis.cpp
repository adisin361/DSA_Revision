#include<bits/stdc++.h>
using namespace std;
const int N = 25e2+10;
vector<int>a(N); int dp[N];
int lis(int i){
    if(dp[i]!=-1) return dp[i];
    int maxlis = 1;
    for(int j=0; j<i; j++){
        if(a[i]>a[j])
            maxlis = max(maxlis, lis(j)+1);
    }
    return dp[i] = maxlis;
}
int main(){
    memset(dp, -1, sizeof(dp));
    int n; cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    int maxi = 0;
    for(int i=0; i<n; i++){
        maxi = max(maxi, lis(i));
    }
    cout<<maxi;
    return 0;
}