#include<bits/stdc++.h>
using namespace std;

bool ks(int arr[],int sum,int n,vector<vector<int>> &t){
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
bool f(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0)
        return false;
    else if(sum%2==0){
        vector<vector<int>> t(n+1,vector<int>(sum+1));
        return ks(arr,sum/2,n,t);
    }
}


int main(){
    int arr[]={3,5,9,5};
    int sum=0;
    int n=4;

    cout << f(arr,n);
}
