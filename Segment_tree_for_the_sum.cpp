#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define ms(a,b) memset(a,b,sizeof(a))
#define mx 1000005
using namespace std;
long long A[mx],st[3*mx];
void build(int p,int L,int R){
    if(L==R)
        st[p]=A[L];
    else{
        int mid= (L+R)/2;
        int left= 2*p;
        int right= 2*p+1;
        build(left,L,mid);
        build(right,mid+1,R);
        long long p1=st[left],p2=st[right];
        st[p]= p1+p2;
    }
}
long long RSQ(int p,int L,int R,int i,int j){
    if(i>R || j<L)
        return 0;
    if(L>=i && R<=j)
        return st[p];
    int mid= (L+R)/2;
    int left= 2*p;
    int right= 2*p+1;
    long long p1=RSQ(left,L,mid,i,j);
    long long p2=RSQ(right,mid+1,R,i,j);
    return p1+p2;
}
void update(int p,int L,int R,int pos,long long new_val){
    if(L==R){
        st[p]=new_val;
    }
    else{
        int mid=(L+R)/2;
        int left= 2*p;
        int right= 2*p+1;
        if(pos<=mid)
            update(left,L,mid,pos,new_val);
        else
            update(right,mid+1,R,pos,new_val);
        st[p]=st[left]+st[right];
    }
}

int main(){
    long long n,m;
    cin>>n>>m;
    R(i,0,n,1){
        cin>>A[i];
    }
    build(1,0,n-1);
    int op,a,b;
    while(m--){
        cin>>op>>a>>b;
        if(op==1){
            update(1,0,n-1,a,b);
        }
        else{
            cout<< RSQ(1,0,n-1,a,b-1)<<endl;
        }
    }
}
