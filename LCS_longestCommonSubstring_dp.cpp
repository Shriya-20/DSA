#include<bits/stdc++.h>
using namespace std;
//longest common substring
int LCS(string X, string Y, int n, int m) {
	int t[n + 1][m + 1];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				t[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				t[i][j] = 1 + t[i - 1][j - 1];
			else // when last character is not same -> reset to 0
				t[i][j] = 0; //note

    int mx =0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			mx = max(mx, t[i][j]);


	return mx;
}
int main(){
    string s1="ABCDGHijk";
    string s2="ABCDFHRijk";
    int m=s1.size();
    int n=s2.size();
    cout<<LCS(s1,s2,m,n);
}
