#include<bits/stdc++.h>
using namespace std;
void permutations(string s, int index, vector<string>&ans){
    if(index>=s.length())
    {
        ans.push_back(s);
        return;
    }

    for(int i=index; i<s.length(); i++){
        swap(s[i], s[index]);
        permutations(s, index+1, ans);
        swap(s[i], s[index]);
    }
}

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    vector<string>ans;
    string output;
    permutations(s, 0, ans);
    for(auto it: ans)
        cout<<it<<endl;
    return 0;
}