#include<bits/stdc++.h>
using namespace std;


int ks1(int arr[],int sum,int n,vector<vector<int>> &t){
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
int ks(int arr[],vector<int> &op,int s,int sum,int n,int ind){
    if(ind==n){
        if(sum==s){
            for(int i:op){
                cout<<i<<" ";
            }
            cout<<endl;
            return 1;
        }
        return 0;
    }
    op.push_back(arr[ind]);
    s+=arr[ind];
    int l=ks(arr,op,s,sum,n,ind+1);
    s-=arr[ind];
    op.pop_back();
    int r=ks(arr,op,s,sum,n,ind+1);

    return l+r;


}

int main(){
    int arr[]={1,8,9,5,5,2};
    int sum=10;
    int n=6
    ;
    vector<int> op;
    vector<vector<int>> t(n+1,vector<int>(sum+1));
    cout << ks(arr,op,0,sum,n,0);
}
