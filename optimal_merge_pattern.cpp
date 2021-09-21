#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    priority_queue<int, vector<int>, greater<int> > minheap;
    for(int i=0; i<n; i++) minheap.push(a[i]);
    int ans=0;
    while(minheap.size()>1)
    {
        int res1 = minheap.top();
        minheap.pop();        
        int res2 = minheap.top();
        minheap.pop();
        ans+=res1+res2;
        minheap.push(res1 + res2);
    }
    cout<<ans<<endl;
    return 0;
}