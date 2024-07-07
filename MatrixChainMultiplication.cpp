#include <bits/stdc++.h>

using namespace std;

int mcm(int arr[],int i,int j){
    if(i>=j) //base condition
        return 0;

    int mn=INT_MAX;
    int temp;

    for(int k=i;k<=j-1;k++){ //moving from k= i to j
        temp=mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        mn=min(temp,mn); //calculate ans from temp
    }

    return mn;
}

int main() {
    int arr[]={40,20,30,10,30};
    int i=1;
    int k=sizeof(arr) / sizeof(arr[0])-1;
    cout<<mcm(arr,i,k);

    return 0;
}
