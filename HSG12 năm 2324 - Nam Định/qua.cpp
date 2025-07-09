#include <bits/stdc++.h>
using namespace std;
long long t,n,s,a[105],dp[1000005],w,maxs,maxd,tempo[1000005];
vector<long long> prime[1005],v;
int main()
{
    if (fopen("QUA.INP","r"))
    {
        freopen("QUA.INP","r",stdin);
        freopen("QUA.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i=2;i<=1000;i++)
    {
        if (prime[i].size()==0)
        {
            for (int j=i+i;j<=1000;j+=i)
                prime[j].push_back(i);
        }
    }
    while ((cin>>n))
    {
        maxs=0, maxd=0; t=0;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            t+=a[i];
        }
        cin>>s; s=min(s,t);
        if (t<=s)
        {
            cout<<t<<" "<<0<<'\n';
            continue;
        }
        for (int i=1;i<=s;i++) dp[i]=LLONG_MAX;
        dp[0]=0;
        for (int i=1;i<=n;i++)
        {
            v.erase(v.begin(),v.end());
            for (int j=s;j>=a[i];j--)
            {
                if (dp[j-a[i]]!=LLONG_MAX)
                {
                    tempo[j]=min(dp[j],dp[j-a[i]]);
                    v.push_back(j);
                }
            }
            for (auto j:prime[a[i]])
            {
                w=a[i]/j;
                for (int k=s;k>=w;k--)
                {
                    if (dp[k-w]!=LLONG_MAX)
                    {
                        tempo[k]=min(dp[k],dp[k-w]+1);
                        v.push_back(k);
                    }
                }
            }
            for (int j:v)
            {
                dp[j]=min(dp[j],tempo[j]);
                tempo[j]=LLONG_MAX;
            }
        }
        for (int i=0;i<=s;i++)
        {
            if (dp[i]==LLONG_MAX) continue;
            maxs=i;
            maxd=dp[i];
        }
        cout<<maxs<<" "<<maxd<<'\n';
    }
    return 0;
}
