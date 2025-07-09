#include <bits/stdc++.h>
using namespace std;
long long n,res=0;
bool check (long long a)
{
    long long t=0;
    while (a>0)
    {
        t+=a%10;
        a/=10;
    }
    if (t%2==0) return true;
    return false;
}
int main()
{
    if (fopen("SOCHAN.INP","r"))
    {
        freopen("SOCHAN.INP","r",stdin);
        freopen("SOCHAN.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    res=(n+1)/10*5;
    if (n>=9) res--;
    while (n%10!=9&&n>0)
    {
        if (check(n))res++;
        n--;
    }
    cout<<res;
    return 0;
}
