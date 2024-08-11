#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+10;
int n,Q;
vector<int> e[N];
struct node{
    int u,k,id;
}q[N];
bool cmp(node a,node b){
    if(a.u==b.u) return a.k<b.k;
    return a.u<b.u;
}
int a[N],tmp[N],ans[N],lim;
void dfs(int u,int fa,int d){
    tmp[d]+=a[u];
    if(d==lim) return ;
    for(int v:e[u]){
        if(v==fa) continue;
        dfs(v,u,d+1);
    }
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>Q;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1,x,y;i<n;++i){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=Q;++i){
        cin>>q[i].u>>q[i].k,q[i].id=i;
    }
    sort(q+1,q+1+Q,cmp);
    int i=1;
    while(i<=Q){
        // cerr<<"Now: "<<i<<" "<<q[i].u<<endl;
        int now=q[i].u,cnt=1;
        lim=q[i].k;
        while(i+cnt<=Q&&q[i+cnt].u==now){
            lim=q[i+cnt].k;
            cnt++;
        }
        cnt--;
        // cerr<<cnt<<" "<<lim<<endl;
        dfs(now,0,0);
        for(int j=i;j<=i+cnt;++j){
            ans[q[j].id]=tmp[q[j].k];
        }
        i+=cnt+1;
        for(int j=0;j<=lim;++j) tmp[j]=0;
    }
    if(Q<=10000){
        for(int i=1;i<=Q;++i){
            cout<<ans[i]<<endl;
        }
    }
    else{
        int res=0;
        for(int i=1;i<=Q;++i){
            res^=i*ans[i];
        }
        cout<<res<<endl;
    }
    return 0;
}
