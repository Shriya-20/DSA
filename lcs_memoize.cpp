#include<bits/stdc++.h>
using namespace std;

int static t[1001][1001];
int LCS(string s1, string s2, int m, int n){
    //vector<vector<int>> t(m+1,vector<int>(n+1,-1));
    if(m==0 || n==0)
        t[m][n]=0;

    if(t[m][n]!=-1){
        return t[m][n];
    }
    // when last character is same
    if(s1[m-1]==s2[n-1]){
        return t[m][n]=1+LCS(s1,s2,m-1,n-1);
    }// when last character is not same -> pick max
    else
        return t[m][n]=max(LCS(s1,s2,m-1,n),LCS(s1,s2,m,n-1));
}
int main(){
    string s1="ABCDGH";
    string s2="AEDFHR";
    int m=s1.size();
    int n=s2.size();
    memset(t,-1,sizeof(t));
    cout<<LCS(s1,s2,m,n);
}
