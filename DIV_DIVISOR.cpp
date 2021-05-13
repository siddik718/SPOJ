#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+1;
const int maxN = 240;

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

void NOD()
{
    for(int i = 1;i<=N;i++)
    {
        for(int j = i;j<=N;j+=i)
        {
            divisor[j]++;
        }
    }
}

bool ok(int n)
{
    int x = divisor[n];
    for(int i = 2;i<=x;i++)
    {
        if(p[i])
        {
            if(p[x/i] && (x%i == 0))
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
