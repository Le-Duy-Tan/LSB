#include <bits/stdc++.h>
using namespace std;
long long n,m,a,b,c,res;
int main()
{
    if (fopen("PETS.INP","r"))
    {
        freopen("PETS.INP","r",stdin);
        freopen("PETS.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>a>>b>>c;
    res=min(n,a)+min(m,b)+c;
    res=n+m-min(res,n+m);
    cout<<res;
    return 0;
}
