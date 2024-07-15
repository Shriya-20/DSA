#include <bits/stdc++.h>
using namespace std;

int solve(string s,int i,int j,bool isTrue){
    if(i>j)
        return false;
    if(i==j){
        if(isTrue)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    int ans=0;

    for(int k=i+1;k<=j-1;k=k+2){
        int lt=solve(s,i,k-1,true); //left true
        int lf=solve(s,i,k-1,false); //left false
        int rt=solve(s,k+1,j,true); //right true
        int rf=solve(s,k+1,j,false);

        if(s[k]=='&'){
            if(isTrue==true)
                ans+=lt*rt;
            else
                ans+=lt*rf+lf*rt+lf*rf;
        }
        else if(s[k]=='|'){
            if(isTrue==true)
                ans+=lt*rf+lt*rt+lf*rt;
            else
                ans+=lf*rf;
        }
        else if(s[k]=='^'){
            if(isTrue==true)
                ans+=lt*rf+lf*rt;
            else
                ans+=lt*rt+lf*rf;
        }

    }
    return ans;
}

int main() {
    string s="T|T&F^T";//op : 4
    cout<<solve(s,0,6,true);

    return 0;
}
