#include<bits/stdc++.h>
#define ll long long int
#define N 1000005

using namespace std;

vector <bool> ar(N+2,true);

void sieve()
{
    ar[2] = true;
    ar[0] = ar[1]= false;

    for(int i = 4;i<=N;i+=2)
        ar[i] = false;

    for(int i = 3;i*i<=N;i+=2)
    {
        if(ar[i])
        {
            for(int j = i*i;j<=N;j+=i+i)
            {
                ar[j] = false;
            }
        }
    }
}

ll ex(ll n,ll x)
{
    for(ll i = 1;i<=x;i++)
        n *= 10;
    return n/10;
}

bool is_afraid(ll n)
{
    ll cnt = 0;
    ll k = n;
    while(n)
    {
        if(n%10 == 0)
            return false;
        cnt++;
        n/=10;
    }
    ll x = cnt-1;
    n = k;
    for(ll i = ex(10,x) ; i>= 10 ;i/=10)
    {
        ll m = n%i;
        if(!ar[m])
            return false;
    }
    return true;
}

ll arr[N+2];
void solve()
{
    for(ll i = 2;i<=1000000;i++)
    {
        if(ar[i] && is_afraid(i))
            arr[i] = arr[i-1] + 1;
        else
            arr[i] = arr[i-1] ;
    }
}

int main()
{
    sieve();
    solve();
    ll t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << arr[n] << "\n";
    }

    return 0;
}
