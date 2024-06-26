#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:

    int uks(int price[],int n){
        vector<vector<int>> t(n+1,vector<int>(n+1,0));

        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
               if(i<=j){
                   t[i][j]=max(price[i-1]+t[i][j-i],t[i-1][j]);
               }
               else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][n];

    }
    int cutRod(int price[], int n) {
        return uks(price,n);

    }
};

int main(){
    int n=8;
    int price[] = {3, 5, 8, 9, 10, 17, 17, 20};
    Solution S;
    cout << S.cutRod(price,n);
}
