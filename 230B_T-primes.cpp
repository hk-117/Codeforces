#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
bitset<10000010>bs;
vi Primes;
void sieve(ll upb){
  ll sieve_size=upb+1;
  bs.set();
  bs[0]=bs[1]=0;
  for(ll i=2;i<=sieve_size;i++){
    if(bs[i]){
      for(ll j=i*i;j<=sieve_size;j+=i) 
        bs[j]=0;
      Primes.push_back(i);
    }
  }
}
bool numDiv(ll N){
  long long nm= sqrt(N);
  if(nm*nm != N) return false;
  if(bs[nm]) return true;
  else return false;
}
int main(){
  int N,nm;
  long long X;
  cin>>N;
  sieve(1000005);
  while(N--){
    cin>>X;
    if(X<4) puts("NO");
    else if(numDiv(X)) puts("YES");
    else puts("NO");
  }
}
