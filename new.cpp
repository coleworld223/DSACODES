#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int maxvalue(int W,int wt[],int val[],int n,long long dp[1005][1005])
    {
        if(dp[n][W]!=-1)return dp[n][W];
        if(n<0 || W==0)
        {
            return 0;
        }
        if(wt[n]<=W)
        {
            return dp[n][W] = max(val[n]+maxvalue(W-wt[n],wt,val,n-1,dp),
            maxvalue(W,wt,val,n-1,dp));
        }
        else return dp[n][W] = maxvalue(W,wt,val,n-1,dp);
    }

    int knapSack(int W, int wt[], int val[], int n) 
    { 
        long long dp[1005][1005];
        for(int i=0;i<1005;i++)
        {
            for(int j=0;j<1005;j++)
            {
                dp[i][j]=-1;
            }
        }
        return maxvalue(W,wt,val,n-1,dp);
    
    }
int main()
{
    int n;
    cin>>n;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++)cin>>wt[i];
    for(int i=0;i<n;i++)cin>>val[i];

    knapSack(W,wt,val,n);
}