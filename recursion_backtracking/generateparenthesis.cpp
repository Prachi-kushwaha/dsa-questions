#include<iostream>
#include <vector>
using namespace std;

void GenerateParenthesis(int n, int left, int right, string&temp, vector<string>&ans){
    if (temp.length() == 2 * n){
        ans.push_back(temp);
        return;
    }
    if(left<n){
        temp.push_back('(');
        GenerateParenthesis(n, left+1, right, temp, ans);
        temp.pop_back();
    }
    if(right<left){
        temp.push_back(')');
        GenerateParenthesis(n, left, right+1, temp, ans);
        temp.pop_back();
    }
};

int main(){
    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;

    vector<string>ans;
    string temp;

    GenerateParenthesis(n, 0, 0, temp, ans);

    cout << "All subsequences:\n";
    for (auto &s : ans) {
    cout << s << endl;
    }cout<<endl;
    return 0;

}