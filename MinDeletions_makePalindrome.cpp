#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int m, int n) {
	int t[m + 1][n + 1];

	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++)
			if (i == 0 || j == 0)
				t[i][j] = 0;

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i - 1] == b[j - 1]) // when last character is same
				t[i][j] = 1 + t[i - 1][j - 1];
			else // when last character is not same -> pick max
				t[i][j] = max(t[i][j - 1], t[i - 1][j]);
    return t[m][n];
}
int MinDeletionsToMakePalindrome(string s1,int m,int n){
        string s2=s1;
        reverse(s1.begin(),s1.end());
        return m-LCS(s1,s2,m,n);
}

int main(){
    string s1="agbcba";
    int m=s1.size();
    cout<<MinDeletionsToMakePalindrome(s1,m,m);
}
