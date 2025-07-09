#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10000005],d[10000005],cnt=0,l=1,res=LLONG_MAX;
int main()
{
    if (fopen("MAU.INP","r"))
    {
        freopen("MAU.INP","r",stdin);
        freopen("MAU.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int r=1;r<=n;r++)
    {
        d[a[r]]++;
        if (d[a[r]]==1) cnt++;
        while (cnt==m)
        {
            res=min(res,r-l+1);
            d[a[l]]--;
            if (d[a[l]]==0) cnt--;
            l++;
        }
    }
    if (res==LLONG_MAX) res=0;
    cout<<res;
    return 0;
}
