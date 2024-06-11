#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
int n,m,q,a[N];
// void pushup(int p){
//     u[p]=u[p<<1]+u[p<<1|1];
//     v[p]=max(v[p<<1],v[p<<1|1]);
//     w[p]=min(w[p<<1],w[p<<1|1]);
// }
// void build(int p,int l,int r){
//     if(l==r){
//         u[p]=1;
//         v[p]=w[p]=a[l];
//         return;
//     }
//     int mid=(l+r)>>1;
//     build(p<<1,l,mid);
//     build(p<<1|1,mid+1,r);
//     pushup(p);
// }
// void update(int p,int l,int r,int x){
//     if(x==l&&r==x){
//         u[p]=0;
//         v[p]=-inf;
//         w[p]=inf;
//         return;
//     }
//     int mid=(l+r)>>1;
//     if(x<=mid)update(p<<1,l,mid,x);
//     else update(p<<1|1,mid+1,r,x);
//     pushup(p);
// }
// int queryCount(int p,int l,int r,int x,int y){
//     if(x<=l&&r<=y)return u[p];
//     int mid=(l+r)>>1,res;
//     if(x<=mid)res=queryCount(p<<1,l,mid,x,y);
//     if(mid<y)res=res+queryCount(p<<1|1,mid+1,r,x,y);
//     return res;
// }
// int queryMax(int p,int l,int r,int x,int y){
//     if(x<=l&&r<=y)return v[p];
//     int mid=(l+r)>>1,res;
//     if(x<=mid)res=queryMax(p<<1,l,mid,x,y);
//     if(mid<y)res=max(res,queryMax(p<<1|1,mid+1,r,x,y));
//     return res;
// }
// int queryMin(int p,int l,int r,int x,int y){
//     if(x<=l&&r<=y)return w[p];
//     int mid=(l+r)>>1,res;
//     if(x<=mid)res=queryMin(p<<1,l,mid,x,y);
//     if(mid<y)res=max(res,queryMin(p<<1|1,mid+1,r,x,y));
//     return res;
// }
// bool check(int x){
//     return queryMax(1,1,n,1,x)>queryMin(1,1,n,x+1,n);
// }
// void solve(int m){
//     int L=1,R=n-1,ans=0;
//     while(L<R){
//         cerr<<L<<","<<R<<endl;
//         int l=L,r=R,res=0;
//         while(l<=r){
//             int mid=(l+r)>>1;
//             cerr<<l<<","<<r<<"=>"<<mid<<endl;
//             if(check(mid))r=mid-1,res=mid;
//             else l=mid+1;
//         }
//         if(res==0){
//             cout<<ans+m<<" ";
//             return;
//         }
//         ans+=queryCount(1,1,n,1,res);
//         L=res+2;
//     }
// }
int lowbit(int x){return x&-x;}
int c[N];
void add(int x){
    while(x<=n){
        c[x]++;
        x+=lowbit(x);
    }
}
int query(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void solve(){
    vector<int>s;
    vector<int>res;
    int mx=0,ans=0;
    for(int i=1;i<=n;i++)c[i]=0;
    for(int i=1;i<=n;i++){
        if(!a[i])continue;
        if(a[i]<mx){
            while(!s.empty()&&a[s.back()]>a[i]){
                ans-=res.back();
                s.pop_back();
                res.pop_back();
            }
            int tmp=i-query(a[i])-1;
            ans+=tmp;
            s.push_back(i);
            res.push_back(tmp);
        }
        add(a[i]);
        mx=max(mx,a[i]);
    }
    cout<<ans+m<<" ";
}
int main(){
    freopen("dizalo.in","r",stdin);
    freopen("dizalo.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    m=n;
    for(int i=1;i<=n;i++)cin>>a[i];
    solve();
    while(q--){
        int x;
        cin>>x;
        a[x]=0;
        m--;
        solve();
    }
    return 0;
}