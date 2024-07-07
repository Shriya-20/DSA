#include <bits/stdc++.h>

using namespace std;

int static t[1001][1001];

int mcm(int arr[],int i,int j){

    if(i>=j){ //base condition
        t[i][j]=0;
        return 0;
    }

    if(t[i][j]!=-1)
        return t[i][j];

    int mn=INT_MAX;
    int temp;

    for(int k=i;k<=j-1;k++){ //moving from k= i to j
        temp=mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        mn=min(temp,mn); //calculate ans from temp
    }

    return t[i][j]=mn;
}

int main() {
    int arr[]={40,20,30,10,30};
    int i=1;
    int k=sizeof(arr) / sizeof(arr[0]);
    memset(t,-1,sizeof(t));
    cout<<mcm(arr,i,k-1);

    return 0;
}
