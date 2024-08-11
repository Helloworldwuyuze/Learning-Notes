#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=3e5+10,mod=19260817;
int n,m;
int a[N],b[N];
#define ls p<<1
#define rs p<<1|1
struct seg{
    int l,r;
    ll dat,lazy;
}t[N<<2];
void pushup(int p){
    t[p].dat=(t[ls].dat+t[rs].dat)%mod;
}
void pushdown(int p){
    if(t[p].lazy){
        t[ls].lazy=(t[ls].lazy+t[p].lazy)%mod;
        t[rs].lazy=(t[rs].lazy+t[p].lazy)%mod;
        t[ls].dat=(t[ls].dat+(t[ls].r-t[ls].l+1)*t[p].lazy%mod)%mod;
        t[rs].dat=(t[rs].dat+(t[rs].r-t[rs].l+1)*t[p].lazy%mod)%mod;
        t[p].lazy=0;
    }
}
void build(int p,int l,int r){
    t[p].l=l,t[p].r=r;
    if(l==r){
        t[p].dat=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
void update(int p,int l,int r,ll k){
    if(l<=t[p].l&&t[p].r<=r){
        t[p].lazy=(t[p].lazy+k)%mod;
        t[p].dat=(t[p].dat+(t[p].r-t[p].l+1)*k%mod)%mod;
        return ;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(l<=mid) update(ls,l,r,k);
    if(mid+1<=r) update(rs,l,r,k);
    pushup(p);
}
ll query(int p,int l,int r){
    if(l<=t[p].l&&t[p].r<=r){
        return t[p].dat;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)>>1;
    ll res=0;
    if(l<=mid) res=(res+query(ls,l,r))%mod;
    if(mid+1<=r) res=(res+query(rs,l,r))%mod;
    return res;
}
namespace sub{
    void solve(){
        ll lans=0;
        for(int i=1,op,l,r,x;i<=m;++i){
            cin>>op>>l>>r;
            l^=lans;
            r^=lans;
            if(op==1){
                lans=0;
                for(int j=l;j<=r;++j){
                    lans=(lans+a[j])%mod;
                }
                cout<<lans<<endl;
            }
            if(op==2){
                cin>>x;
                x^=lans;
                for(int j=l;j<=r;++j){
                    a[j]=(a[j]+x)%mod;
                }
            }
            if(op==3){
                cin>>x;
                x^=lans;
                for(int j=l;j<=r;++j){
                    b[j]=(b[j]+x)%mod;
                }
            }
            if(op==4){
                for(int j=l;j<=r;++j){
                    a[j]=(a[j]+b[j])%mod;
                }
            }
        }
    }
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    if(m<=3000) sub::solve();
    build(1,1,n);
    ll lans=0;
    for(int i=1,op,l,r,x;i<=m;++i){
        cin>>op>>l>>r;
        l^=lans;
        r^=lans;
        if(op==1){
            lans=query(1,l,r);
            cout<<lans<<endl;
        }
        if(op==2){
            cin>>x;
            x^=lans;
            update(1,l,r,x);
        }
        if(op==3){
            cin>>x;
            x^=lans;
            b[l]=(b[l]+x)%mod;
        }
        if(op==4){
            update(1,l,r,b[l]);
        }
    }
    return 0;
}
