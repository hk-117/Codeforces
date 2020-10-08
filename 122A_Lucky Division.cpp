#include<bits/stdc++.h>
using namespace std;
bool isLucky(int N){
  while(N){
    int dig=N%10;
    if(dig==4 || dig==7){
      //nothing
    }
    else return false;
    N=N/10;
  }
  return true;
}
int main(){
  int N;
  cin>>N;
  if(!isLucky(N)){
    if(N%4==0||N%7==0||N%47==0)
      puts("YES");
    else
      puts("NO");
  }
  else puts("YES");
}
