#include<bits/stdc++.h>
using namespace std;
vector <int> primes;
const int MAX = 1e3+10;
void sieve(){
bool isprime[MAX] = {};
for(int i = 3;i*i<=MAX;i+=2){
    if(isprime[i] == 0){
        for(int j = i*i;j<=MAX;j+=2*i){
            isprime[j] = true;
        }
    }
}
primes.push_back(2);
for(int i = 3;i<=MAX;i+=2){
    if(isprime[i] == 0)
        primes.push_back(i);
}
}
int factor(int n){
int cnt = 0;
for(int i = 0;primes[i]*primes[i]<=n;i++){
    if(n%primes[i] == 0){
        cnt++;
        while(n%primes[i] ==0 ){
            n/=primes[i];
        }
    }
}
if(n>1) cnt++;
return cnt;
}
int store[1000005];
int cumsum[20][1000005];
void solve(){
for(int i = 2;i<=1000000;i++)
    store[i] = factor(i);
cumsum[0][1] = 1;
for(int i = 2;i<11;i++)
    cumsum[i][1] = 0;
for(int i = 2;i<=1000000;i++){
    int x = store[i];
    for(int j = 0;j<11;j++){
        if(x == j){
            cumsum[j][i] = cumsum[j][i-1] + 1;
        }else
            cumsum[j][i] = cumsum[j][i-1];
    }
}
}
int main(){
sieve();
solve();
	int t,a,b,n;
	scanf("%d",&t);
	while(t--){
        scanf("%d%d%d",&a,&b,&n);
		cout<< cumsum[n][b]-cumsum[n][a-1] <<endl;
	}
}
