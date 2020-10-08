#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
bitset<10000010>bs;
vi Primes,Composites;
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
  for(ll i=4;i<=sieve_size;i++)
    if(!bs[i]) Composites.push_back(i);
}
int main(){
  ll N;
  sieve(1000005);
  cin>>N;
  for(int i=0;i<Composites.size();i++){
    if(!bs[N-Composites[i]]){
      cout<<Composites[i]<<" "<<N-Composites[i]<<endl;
      break;
    }
  }
}
