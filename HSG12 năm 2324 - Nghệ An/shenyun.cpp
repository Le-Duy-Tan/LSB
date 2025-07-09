#include <bits/stdc++.h>
using namespace std;
long long n,x,y;
int main()
{
    if (fopen("SHENYUN.INP","r"))
    {
        freopen("SHENYUN.INP","r",stdin);
        freopen("SHENYUN.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>x>>y;
    cout<<n/(x/__gcd(x,y)*y);
    return 0;
}
