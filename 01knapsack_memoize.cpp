#include<bits/stdc++.h>
using namespace std;

//by default static and initialized with 0. Didnt have to declare static//
// Global variable, automatically has static storage duration

/*
 * When a variable is declared as static within a function, it retains its value between function calls.
 * The variable is initialized only once, and its value persists across multiple calls to the function.
 *
 * When a variable is declared as static outside any function (at the file level), its scope is limited
 * to the file in which it is declared. This means it cannot be accessed from other files, even if they
 * are part of the same program.
 *
 * In a class, a static member variable is shared among all instances of the class. There is only one copy
 * of the variable, regardless of how many objects of the class are created.
 */

int static t[100][1000];
int ks(int wt[],int v[],int w,int n){
    if(n==0||w==0){
        return 0;
    }
    if(t[w][n]!= -1){
        return t[w][n];
    }
    if(wt[n-1]<=w){
        return t[w][n]=max(v[n-1]+ks(wt,v,w-wt[n-1],n-1),ks(wt,v,w,n-1));
    }
    else{
        return t[w][n]=ks(wt,v,w,n-1);
    }
}

int main(){
    int wt[]={1,2,3};
    int v[]={4,5,6};
    int w=3;
    int n=3;
    memset(t,-1,sizeof(t));
    cout << ks(wt,v,w,n);
}
