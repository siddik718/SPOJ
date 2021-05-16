#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD = 1e9+7;
const ll maxN = 1e6;

int phi[maxN+2];

void totient()
{
    for(int i = 1;i<=maxN;i++)
        phi[i] = i;

    for(int i = 2;i<=maxN;i++)
    {
        if(phi[i] == i)
        {
            for(int j = i;j<=maxN;j+=i)
            {
                phi[j] -= phi[j]/i;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    totient();
    int t,n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        cout << phi[n] << "\n";

    }

    return 0;
}
