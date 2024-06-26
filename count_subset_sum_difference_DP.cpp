#include<bits/stdc++.h>
using namespace std;


int count_subset_sum(int arr[],int sum,int n,vector<vector<int>> &t){
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
                t[i][j]=t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int count_diff(int arr[],int n,int diff){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if ((diff + sum) % 2 != 0) {
            return 0;
    }
    else{
        int sum_s1=(diff+sum)/2;
        vector<vector<int>> t(n+1,vector<int>(sum_s1+1));
        return count_subset_sum(arr,sum_s1,n,t);
    }
}

int main(){
    int arr[]={1,1,2,3};
    int n=4 ;
    int diff=1;

    cout<<count_diff(arr,n,diff);
}
