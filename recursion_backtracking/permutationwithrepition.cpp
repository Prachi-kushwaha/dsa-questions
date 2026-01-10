#include<iostream>
#include<vector>
using namespace std;

void repitedPermut(vector<int>&arr, vector<vector<int>>&ans, int index){
    vector<bool> used(21,0);
    if(index == arr.size()){
        ans.push_back(arr);
        return;
    }

    for(int i=index; i<arr.size(); i++){
        if(used[arr[i]+10] == 0){
            swap(arr[index], arr[i]);
            repitedPermut(arr, ans, index+1);
            swap(arr[index], arr[i]);
            used[arr[i]+10] = 1;
        }
    }
};

int main(){
    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the value of element"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }cout<<endl;

    vector<vector<int>> ans;
    repitedPermut(arr, ans, 0);

    cout<<"your permutations are: "<<endl;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j];
        }cout<<endl;
    }

    return 0;
}