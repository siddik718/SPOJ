#include<bits/stdc++.h>
#define ll long long int

using namespace std;
const ll maxN = 1000001;

ll phi[maxN+5];
ll res[maxN+5];
ll cum[maxN+5];
void solve()
{
    for(ll i = 1;i<=maxN;i++)
        phi[i] = i;

    for(ll i = 2;i<=maxN;i++)
    {
        if(phi[i] == i)
        {
            for(ll j = i;j<=maxN;j+=i)
            {
                phi[j] -= phi[j]/i;
            }
        }
        for(ll k = 1;k*i<=maxN;k++)
        {
            res[k*i] += k*phi[i];
        }
    }
    for(ll i = 2;i<=maxN;i++)
    {
        cum[i] = cum[i-1] + res[i];
    }
}
int main()
{
    solve();
   ll n;
   while(cin >> n,n)
    cout << cum[n] << "\n";

   return 0;
}


