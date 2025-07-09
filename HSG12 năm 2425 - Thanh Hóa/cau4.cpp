#include <bits/stdc++.h>
using namespace std;
long long m,n,k,a[2005][2005],x,y,u,v,h[2005][2005],wl[2005][2005],wr[2005][2005],res=0;
string s;
int main()
{
    if (fopen("CAU4.INP","r"))
    {
        freopen("CAU4.INP","r",stdin);
        freopen("CAU4.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    while (k--)
    {
        cin>>x>>y>>u>>v;
        a[x][y]+=1;
        if (v<m) a[x][v+1]-=1;
        if (u<n) a[u+1][y]-=1;
        if (u<n&&v<m) a[u+1][v+1]+=1;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    for (int i=n;i>=1;i--)
    {
        for (int j=1;j<=m;j++)
        {
            if (i==n) h[i][j]=1;
            else
            {
                if (a[i][j]==a[i+1][j])
                    h[i][j]=h[i+1][j]+1;
                else h[i][j]=1;
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=m;j>=1;j--)
        {
            if (j==m) wl[i][j]=1;
            else
            {
                if (a[i][j]==a[i][j+1]&&h[i][j]<=h[i][j+1])
                    wl[i][j]=wl[i][j+1]+1;
                else wl[i][j]=1;
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (j==1) wr[i][j]=1;
            else
            {
                if (a[i][j]==a[i][j-1]&&h[i][j]<=h[i][j-1])
                    wr[i][j]=wr[i][j-1]+1;
                else wr[i][j]=1;
            }
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            res=max(res,max(min(wl[i][j],h[i][j]),min(wr[i][j],h[i][j])));
    cout<<res;
    return 0;
}
