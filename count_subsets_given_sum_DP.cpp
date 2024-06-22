#include<bits/stdc++.h>
using namespace std;


int ks(int arr[],int sum,int n,vector<vector<int>> &t){
    for(int i=0;i<n+1;i++){
        for (int j=0;j<sum+1;j++){
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;

        }
    }
    for(int i=1;i<n+1;i++){
        for (int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] + t[i-1][j]; //significant
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}


int main(){
    int arr[]={1,8,9,5,5,2};
    int sum=10;
    int n=6;
    vector<vector<int>> t(n+1,vector<int>(sum+1));
    cout << ks(arr,sum,n,t);
}
