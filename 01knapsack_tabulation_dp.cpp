#include<bits/stdc++.h>
using namespace std;

int static t[100][1000];

int ks(int wt[],int v[],int w,int n){
    for(int i=0;i<n+1;i++){
        for (int j=0;j<w+1;j++){
            if(i==0||j==0)
                t[i][j]=0;
        }
    }

    for(int i=1;i<n+1;i++){
        for (int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                t[i][j]=max(v[i-1]+ t[n-1][w-wt[i-1]],t[n-1][w]);

            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[n][w];

}

int main(){
    int wt[]={1,2,3};
    int v[]={4,5,6};
    int w=3;
    int n=3;
    cout << ks(wt,v,w,n);
}
