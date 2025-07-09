#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b[100005],res=0,l=1,r=2,j;
int main()
{
    if (fopen("CHIEUSANG.INP","r"))
    {
        freopen("CHIEUSANG.INP","r",stdin);
        freopen("CHIEUSANG.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+1+n); sort(b+1,b+1+m);
    if (a[1]<b[1]) res=max(res,b[1]-a[1]);
    if (a[n]>b[m]) res=max(res,a[n]-b[m]);
    j=lower_bound(a+1,a+1+n,b[1])-a;
    while(r<=m&&j<=n)
    {
        while (a[j]<b[l]||a[j]>b[r])
        {
            l++;
            r++;
        }
        if (r>m) break;
        if (b[l]<=a[j]&&a[j]<=b[r])
            res=max(res,min(a[j]-b[l],b[r]-a[j]));
        j++;
    }
    cout<<res;
    return 0;
}
