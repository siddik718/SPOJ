#include<bits/stdc++.h>
#define N 99998955
#define ll long long int
using namespace std;
bool arr[N];
vector <ll> primes;
void sieve(){
memset(arr,1,sizeof(arr));
for(ll i = 2;i<=N;i++){
    if(arr[i])
        for(ll j= i*i;j<=N;j+=i)
        arr[j] = 0;
}
for(ll i = 2;i<=N;i++){
    if(arr[i])
        primes.push_back(i);
}
for(ll i = 0;i<primes.size();i+=100){
    printf("%lld\n",primes[i]);
}
}
int main(){
sieve();
return 0;
}
