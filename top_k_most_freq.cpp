#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for(int i=a; i<b; i++)

signed main()
{
    int n;
    cout<<"Size: ";
    cin>>n;
    vi a(n);
    cout<<"Enter " << n << " elements: "<<endl;
    rep(i, 0, n)
        cin>>a[i];
    int k;
    cout<<"K: ";
    cin>>k;
    map<int, int>freq;
    rep(i, 0, n)
    {
        int present_size = freq.size();
        if(present_size==k && freq[a[i]] == 0)
            break;
        freq[a[i]]++;
    }
    vii ans;
    map<int, int> :: iterator it;
    for(it = freq.begin(); it!=freq.end(); ++it)
    {
        if(it->ss!=0)
        {
            pii p;
            p.ff = it->ss;
            p.ss = it->ff;
            ans.push_back(p);
        }
    }
    sort(ans.begin(), ans.end(), greater<pii>());
    vii :: iterator it1;
    for(it1=ans.begin(); it1!=ans.end(); ++it1)
    {
        cout<<it1->ss<<" "<<it1->ff<<endl;
    }
    return 0;
}