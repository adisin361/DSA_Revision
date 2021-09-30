#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define rep(i, a, b) for(int i = a; i<b; i++)

signed main()
{
    int n; cin>>n;
    vi a(n);
    rep(i,0,n)
        cin>>a[i];
    int k;
    cin>>k;
    int s = 0, minn=INT_MAX;
    rep(i,0,k)
    {
        s+=a[i];
    }
    minn = min(minn, s);
    rep(i,1,n-k-1)
    {
        s-=a[i-1];
        s+=a[i+k-1];
        minn=min(minn,s);
    }
    cout<<minn<<endl;
    return 0;
}
