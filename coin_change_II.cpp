#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX-1
class Solution {
public:
    int f(vector<int> &coins,int sum, int n){
        vector<vector<int>> t(n+1,vector<int>(sum+1));
        for (int i = 0; i <= n; i++) {
		    for (int j = 0; j <= sum; j++) {
			    if (j == 0)
				    t[i][j] = 0;
			    if (i == 0)
				    t[i][j] = INF;
			    if (i == 1) {
				    if (j % coins[i - 1] == 0)
					    t[i][j] = j / coins[i - 1];
				    else
					    t[i][j] = INF;
			    }
		    }
	    }
        t[0][0] = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= sum; j++){
                if (coins[i - 1] <= j)
                    t[i][j] = min(t[i - 1][j], 1 + t[i][j - coins[i - 1]]);
                else
                    t[i][j] = t[i - 1][j];
            }
        }
    return t[n][sum];

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        return f(coins,amount, n);
    }
};

int main(){
    int amount=11;
    vector<int> coins={1,2,5};
    Solution S;
    cout << S.coinChange(coins,amount);
}
