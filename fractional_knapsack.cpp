#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a; i<b; i++)

bool compare(pii a, pii b)
{
    double v1 = (double)a.ff/a.ss;
    double v2 = (double)b.ff/b.ss;
    
    return v1>v2;
} 

int main()
{
    int n;
    cin>>n;
    vii a(n);
    rep(i, 0, n)
        cin>>a[i].ff>>a[i].ss;
    int w; cin>>w;
    sort(a.begin(), a.end(), compare);
    int ans = 0;
    rep(i,0,n)
    {
        if(w>=a[i].ss)
        {
            ans+=a[i].ff;
            w-=a[i].ss;
            continue;
        }
        double vw = (double) a[i].ff/a[i].ss;
        ans+=w*vw;
        w=0;
        break;
    }
    cout<<ans<<endl;
    return 0;
}