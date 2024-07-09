#include <bits/stdc++.h>
using namespace std;

int t[501][501];
bool isPalindrome(string s,int i,int j){

    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;

}
int Solver(string s,int i, int j){
    if(i>=j || isPalindrome(s,i,j)){
            return 0;
        }
        if(t[i][j]!=-1){
            return 0;
        }
        int mn =INT_MAX;

        for(int k = i;k<=j-1;k++){
            int left ,right;

            if(t[i][k]==-1){
                left = Solver(s,i,k);
            }
            else{
                left = t[i][k];
            }
            if(t[k+1][j]==-1){
                right = Solver(s,k+1,j);
            }
            else{
                right = t[k+1][j];
            }
            int temp = 1+left+right;

            mn= min(mn,temp);
        }

    return t[i][j]=mn;
}


int main() {
    string s="geek";
    int n=s.size();
    memset(t,-1,sizeof(t));
    cout<<Solver(s,0,n-1);

    return 0;
}
