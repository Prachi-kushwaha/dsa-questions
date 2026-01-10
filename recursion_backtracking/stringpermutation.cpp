#include<iostream>
#include<vector>
using namespace std;

void strpermut(string &s, vector<string> &ans, string &temp, vector<bool>& visited){
    if(visited.size() == temp.length()){
        ans.push_back(temp);
        return;
    }
    for(int i=0; i<visited.size(); i++){
        if(visited[i]==0){
            visited[i] = 1;
            temp.push_back(s[i]);
            strpermut(s, ans, temp, visited);
            visited[i]=0;
            temp.pop_back();
        }
    }
}

int main(){
    string s;
    cout<<"enter the value of s"<<endl;
    cin>>s;
    vector<string> ans;
    string temp;
    vector<bool> visited(s.length(), 0);

    strpermut(s, ans, temp, visited);

    for (auto &s : ans) {
    cout << s << endl;
    }cout<<endl;
    return 0;
}