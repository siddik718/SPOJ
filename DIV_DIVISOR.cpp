#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+1;
const int maxN = 240; // Highest divisor of a number [1,10^6] is 240.So,prime under 240 is enough.

vector <bool> p(maxN+2,true);

void sieve()
{
    p[0] = p[1] = false;
    for(int i = 4;i<=maxN;i+=2)
    {
        p[i] = false;
    }
    for(int i = 3;i*i<=maxN;i+=2)
    {
        if(p[i])
        {
            for(int j = i*i;j<=maxN;j+=i+i)
            {
                p[j] = false;
            }
        }
    }
}

int divisor[N+2];

void NOD() // using sieve for number of divisors of numbers under n .
{
    for(int i = 1;i<=N;i++)
    {
        for(int j = i;j<=N;j+=i)
        {
            divisor[j]++;
        }
    }
}

bool ok(int n) // checking if the number is d(n) = p*q.
{
    int x = divisor[n];
    for(int i = 2;i<=x;i++)
    {
        if(p[i]) // here p[i] == prime[p]
        {
            if(p[x/i] && (x%i == 0)) // p[x/i] == prime[x/q] && as x/q could give unwanted value like 2.564 to 2 so ans could be different so checking if x%p == 0.
                if(i != x/i)
                    return true;
        }
    }
    return false;
}

vector <int> v;

void solve()
{
    int cnt = 0;
    for(int i = 1;i<=N;i++)
    {
        if(ok(i))
        {
            cnt++;
            if(cnt%9 == 0)
                cout << i << "\n";
        }
    }

}
int main()
{
    sieve();
    NOD();
    solve();
    return 0;
}
