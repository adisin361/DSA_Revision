#include<bits/stdc++.h>
using namespace std;

# define rep(i,a,b) for(int i=a; i<b; i++)
# define vi vector<int>

int main()
{
    int n;
    cin>>n;

    vi a(n);
    rep(i, 0, n) cin>>a[i]; // denominations
    int x; cin>>x;
    sort(a.begin(), a.end(), greater<int>());
    int ans=0;
    rep(i,0,n)
    {
        ans+=x/a[i];
        x-=(x/a[i])*a[i];
    }
    cout<<ans<<endl;
    return 0;
}
