#include<bits/stdc++.h>
using namespace std;
void combinations(string s, string output, vector<string>&ans, int index, string mapping[]){
    if(index>=s.length())
    {
        ans.push_back(output);
        return;
    }

    int value = s[index]-'0';
    string letters = mapping[value];

    for(int i=0; i<letters.length(); i++){
        output.push_back(letters[i]);
        combinations(s, output, ans, index+1, mapping);
        output.pop_back();
    }

}

int main(){
    string mapping[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "xyz"};
    string s;
    cout<<"Enter the digits: ";
    cin>>s;
    vector<string>ans;
    string output;
    combinations(s, output, ans, 0, mapping);
    for(auto it:ans)
        cout<<it<<endl;
    return 0;
}