#include<bits/stdc++.h>
using namespace std;
//print shortest common supersequence
string printSCS(string a, string b, int m, int n) {
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

    string s="";
    int i=m;int j=n; //start from bottom corner
    while(i>0 && j>0){ //stop when i or j becomes 0
        if(a[i-1]==b[j-1]){ //id char matches
            s.push_back(a[i-1]);
            i--; //move diagonally
            j--;
        }
        else{ //choosing max of the two options, t[i,j-1] & t[i-1,j]
            if(t[i][j-1]>t[i-1][j]){
                s.push_back(b[j-1]);
                j--;
            }
            else{
                s.push_back(a[i-1]);
                i--;
            }
        }
    }
    while(i>0){ //if u reach the edge , j=0 , add the leftover chars to 's'
        s.push_back(a[i-1]);
        i--;
    }
    while(j>0){ //if u reach the other edge, i=0
        s.push_back(a[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    return s;

}
int main(){
    string s1="ABCDGH";
    string s2="AEBDFHR";
    int m=s1.size();
    int n=s2.size();
    cout<<printSCS(s1,s2,m,n);
}
