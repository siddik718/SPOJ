#include<bits/stdc++.h>
#define ll long long int
#define N 90000001
using namespace std;
vector <bool> primes(N+1,true);
vector <int> v;
void sieve(){
primes[0] = primes[1]= false;
for(int i = 2;i*i<N;i++){
    if(primes[i]){
    for(int j= i*i;j<N;j+=i){
    primes[j] = false;
    }
    }
}
for(int i = 2;i<N;i++){
    if(primes[i]){
    v.push_back(i);
    }
}
}

int main(){
    sieve();
int t,k;
scanf("%d",&t);
while(t--){
scanf("%d",&k);
printf("%d\n",v[k-1]);
}
return 0;
}

