#include<iostream>
#include<vector>
using namespace std;

void permut(int arr[], vector<vector<int>>& ans, vector<int>& temp, vector<bool>& visited){

    int n = visited.size();
    if(n == temp.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=0; i<n; i++){
        if(visited[i]==0){
            visited[i]=1;
            temp.push_back(arr[i]);
            permut(arr, ans, temp, visited);
            visited[i] = 0;
            temp.pop_back();
        }
    }
};

int main(){
    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the value of element"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }cout<<endl;

    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(n,0);

    permut(arr, ans, temp, visited);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j];
        }cout<<endl;
    }

    return 0;
}