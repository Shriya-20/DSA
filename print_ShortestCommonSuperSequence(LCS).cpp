#include<bits/stdc++.h>
using namespace std;
//different aproach than the one used for finding length of shortest LCS
string PrintShortestSuperSequence(string a, string b, int m, int n) {
	int t[m + 1][n + 1];

	for (int i = 0; i <= m; i++){
		for (int j = 0; j <= n; j++){
			if (i == 0)
				t[i][j] = j;
            if(j==0)
                t[i][j]=i;
		}
    }

	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (a[i - 1] == b[j - 1]) // when last character is same
				t[i][j] = 1 + t[i - 1][j - 1];
			else // when last character is not same -> pick max
				t[i][j] = 1 + min(t[i][j - 1], t[i - 1][j]);
		}
	}

	string s;
	int i=m,j=n;
	while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            s.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                s.push_back(a[i-1]);
                i--;
            }
            else{
                s.push_back(b[j-1]);
                j--;
            }
        }
	}
	while(i>0){ //Adding leftover chars
        s.push_back(a[i-1]);
        i--;
	}
	while(j>0){
        s.push_back(b[j-1]);
        j--;
	}
	reverse(s.begin(),s.end());
    return s;
}


int main(){
    string s1="AGGTAB";
    string s2="GXTXAYB";
    //AGXGTXAYB
    //AGGXTXAYB
    int m=s1.size();
    int n=s2.size();
    cout<<PrintShortestSuperSequence(s1,s2,m,n);
}
