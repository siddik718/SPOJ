#include <bits/stdc++.h>
#define N 31624
using namespace std;
vector <bool> ar(N+1,true);
vector <int> v;
void sieve(){
for(int i= 2;i*i<=N;i++){
    if(ar[i])
        for(int j = i*i;j<=N;j+=i)
        ar[j] = false;
}
for(int i = 2;i<=N;i++)
    if(ar[i])
   v.push_back(i);
}
void seg_sieve(int L,int R){
vector <int> seg;
int Size = R-L+1;
for(int i = L;i<=R;i++)
    seg.push_back(i);
if(L == 0){
    seg[1] = 0;
}else if(L==1){
seg[0] = 0;
}
for(int i:v){
   int start = i*i;
    if(start < L)
        start = ((L+i-1)/i)*i;
    for(int j = start;j<=R;j += i)
        seg[j-L] = 0;
}

for(int i = L;i<=R;i++){
    if(seg[i-L] != 0)
        cout << i << "\n";
}
cout << endl;
}
int main(){
sieve();
int t;
cin >> t;
while(t--){
int l,r;
cin >> l >> r;
seg_sieve(l,r);
}
return 0;
}
