#include<bits/stdc++.h>
using namespace std;

//Minimum subset difference problem
//dp solution
//tabulation
int subset_sum(int arr[],int sum,int n,vector<vector<int>> &t){
    for(int i=0;i<n+1;i++){
        for (int j=0;j<sum+1;j++){
            if(i==0)
                t[i][j]=false;
            if(j==0)
                t[i][j]=true;

        }
    }
    for(int i=1;i<n+1;i++){
        for (int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int min_diff(int arr[],vector<int> &v,int n){
    int range=0;
    for(int i=0;i<n;i++){
        range+=arr[i];
    }
    vector<vector<int>> t(n+1,vector<int>(range+1));
    for(int i=0;i<=range/2;i++){
        if(subset_sum(arr,i,n,t)){
            v.push_back(i);
        }
    }
    int mini=INT_MAX;
    int mn=mini;
    for(int i=0;i<v.size();i++){
        mn=min(mini,range-2*v[i]);
    }
    return mn;
}


int main(){
    int arr[]={1,6,11,5};
    int n=4 ;
    vector<int> v;
    cout << min_diff(arr,v,n);
}
