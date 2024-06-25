#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countSubsets(vector<int>& nums, int n, int sum)
    {
        int t[n+1][sum+1];

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }

        //t[0][0] = 1;

        for(int i=1; i<=n; i++)
        {   //make j=0 change for all previous related problems.
            for(int j=0; j<=sum; j++) //note that u need to fill from j=0 to account for permutations possible with 0s
            {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }

        return t[n][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
         target=abs(target); //neednt do this if ur checking if (sum+target <0)
         int n=nums.size();
         int sum=0;

         for(int i=0; i<n; i++)
             sum+=nums[i];

        int sum_s1=(sum+target)/2;
        if(sum<target||(sum+target)%2!=0)
            return 0;
        /* OR
        if(sum+target<0||(sum+target)%2!=0)
            return 0;
        */
         return countSubsets(nums, n, sum_s1);
    }
};

int main(){
    Solution S;
    vector<int> nums={0,0,0,0,0,0,0,1};
    int target=1;
    cout<<S.findTargetSumWays(nums,target);
}
