#include <bits/stdc++.h>
using namespace std;
long long n,m,l=0,ds[200],dt[200],res=0,need=0;
string s,t;
bool check=true;
int main()
{
    if (fopen("CAU3.INP","r"))
    {
        freopen("CAU3.INP","r",stdin);
        freopen("CAU3.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>t>>s;
    for (int i=0;i<n;i++) dt[t[i]]++;
    for (int i=0;i<n;i++) ds[s[i]]++;
    for (int i='a';i<='z';i++)
    {
        if (ds[i]>dt[i])
        {
            check=false;
            break;
        }
        need+=(dt[i]-ds[i]);
    }
    if (check&&need==ds['*']) res++;
    for (int i=1;i+n-1<m;i++)
    {
        need=0; check=true;
        ds[s[i-1]]--;
        ds[s[i+n-1]]++;
        for (int i='a';i<='z';i++)
        {
            if (ds[i]>dt[i])
            {
                check=false;
                break;
            }
            need+=(dt[i]-ds[i]);
        }
        if (check&&need==ds['*']) res++;
    }
    cout<<res;
    return 0;
}
