#include <bits/stdc++.h>
using namespace std;
long long n,q,a[100005],x,y,posstem,posend;
string s;
int main()
{
    if (fopen("CUOCTHI.INP","r"))
    {
        freopen("CUOCTHI.INP","r",stdin);
        freopen("CUOCTHI.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    while (q--)
    {
        cin>>x>>y;
        posstem=lower_bound(a+1,a+1+n,x)-a-1;
        posend=upper_bound(a+1,a+1+n,y)-a-1;
        cout<<posend-posstem<<'\n';
    }
    return 0;
}
