#include <bits/stdc++.h>
using namespace std;
long long n,dp[3][1000005];
char a[1000005];
int main()
{
    if (fopen("DEN.INP","r"))
    {
        freopen("DEN.INP","r",stdin);
        freopen("DEN.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n; cin>>a[1]; dp[1][1]=1; dp[0][1]=0;
    for (int i=2;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]!=a[i-1])
        {
            dp[0][i]=min(dp[0][i-1],dp[1][i-1]);
            dp[1][i]=min(dp[0][i-1],dp[1][i-1])+1;
        }
        else
        {
            dp[0][i]=dp[1][i-1];
            dp[1][i]=dp[0][i-1]+1;
        }
    }
    cout<<min(dp[0][n],dp[1][n]);
    return 0;
}
