#include <bits/stdc++.h>
using namespace std;
long long n,a,b;
int main()
{
    if (fopen("CAU1.INP","r"))
    {
        freopen("CAU1.INP","r",stdin);
        freopen("CAU1.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    cout<<n/(a*b/__gcd(a,b));
    return 0;
}
