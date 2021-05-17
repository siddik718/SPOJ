#include<bits/stdc++.h>
#define ll long long int

using namespace std;
void solve(int a,int b)
{
    ll res = 1;
    while(b>0)
    {
        if(b&1)
            res = (res*a)%10;
        a = (a*a)%10;
        b >>= 1;
    }
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,a,b;
    cin >> t;

    while(t--)
    {
        cin >> a >> b;
        solve(a,b);
    }

    return 0;
}

