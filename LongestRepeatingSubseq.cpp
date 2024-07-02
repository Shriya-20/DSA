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
			if ((a[i - 1] == b[j - 1])&&(i!=j)) //ensure that u are ot matching same char of str with itself
				t[i][j] = 1 + t[i - 1][j - 1];
			else // when last character is not same -> pick max
				t[i][j] = max(t[i][j - 1], t[i - 1][j]);

    return t[m][n];

}
int LongestRepeatingSubsequence(string a,int m){
    return LCS(a,a,m,m);
}
int main(){
    string s="AABEBCDD"; //ABD
    int m=s.size();
    cout<<LongestRepeatingSubsequence(s,m);
}
