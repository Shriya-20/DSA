#include<bits/stdc++.h>
using namespace std;

int ks(int wt[],int v[],int w,int n){
    if(n==0||w==0){
        return 0;
    }
    if(wt[n-1]<=w){
        return max(v[n-1]+ks(wt,v,w-wt[n-1],n-1),ks(wt,v,w,n-1));
    }
    else{
        return ks(wt,v,w,n-1);
    }
}

int main(){
    int v[]={1,2,3};
    int wt[]={4,5,6};
    int w=3;
    int n=3;
    cout << ks(wt,v,w,n);
}
