#include<iostream>
using namespace std;

void subsequenceSum(int arr[], int index, vector<vector<int>>&ans, vector<int>&temp){
    int n = arr.size();
    if(index >= n){
        ans.push_back(temp);
    }
    int sum = 0;
    subsequenceSum(arr, index+1, ans, temp);
    sum = sum+arr[index];
    subsequenceSum(arr, index+1, ans, temp);
    temp.push_back(sum);
    temp.pop_back();

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

    subsequenceSum(arr, 0, 0, ans, temp);
    cout << "All subsequences sum:\n";
    for (auto &v : ans) {
        cout << "{ ";
        for (int x : v) cout << x << " ";
        cout << "}";
    }cout<<endl;
    return 0;
}