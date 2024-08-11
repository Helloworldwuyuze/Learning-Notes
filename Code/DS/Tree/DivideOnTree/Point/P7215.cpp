#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n,k,city[N],minn=INF;
vector<int> g[N], col[N];

int sum, root, maxx[N], siz[N];
bool vis[N];
void calsiz(int x,int fa){
    maxx[x]=0, siz[x]=1;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(vis[y]||y==fa)   continue;
        calsiz(y,x);
        siz[x]+=siz[y], maxx[x]=max(maxx[x],siz[y]);
    }
    maxx[x]=max(maxx[x],sum-siz[x]);
    if(maxx[x]<maxx[root])  root=x;
}

bool flag[N];
int t[N],fa[N];
vector<int> sub;

void calcol(int x,int fat){
    fa[x]=fat; sub.pb(city[x]);
    t[city[x]]++;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fat||vis[y])   continue;
        calcol(y,x);
    }
}
queue<int> q;
int calans(int x){
    int ans=0;
    while(q.size()) q.pop();
    int nowcol=city[x];
    if(col[nowcol].size()>t[nowcol])    return -1;
    for(int i=0;i<col[nowcol].size();++i)
        q.push(col[nowcol][i]);
    flag[nowcol]=true;
    // for(int i=1;i<=k;++i)
    //     cout<<t[i]<<" ";
    // cout<<endl;
    while(q.size()){
        int now=q.front(); q.pop();
        nowcol=city[now];
        if(col[nowcol].size()>t[nowcol])    return -1;
        // cout<<now<<" "<<fa[now]<<" "<<flag[city[fa[now]]]<<endl;
        if(fa[now]<=0||flag[city[fa[now]]]) continue;
        ++ans;
        int nxtcol=city[fa[now]];
        flag[nxtcol]=true;
        for(int i=0;i<col[nxtcol].size();++i)
            q.push(col[nxtcol][i]);
        // cout<<now<<" "<<nxtcol<<endl;
    }
    // cout<<endl;
    return ans;
}
void dfz(int x){
    // cout<<"###"<<x<<"###"<<endl;
    vis[x]=true;
    sub.clear();calcol(x,0);
    int ans=calans(x);
    if(ans!=-1) minn=min(minn,ans);
    // cout<<ans<<endl;
    // cout<<"## sub ##"<<endl;
    for(int i=0;i<sub.size();++i)
        t[sub[i]]=0, flag[sub[i]]=0;
    // cout<<endl;
    sub.clear();
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(vis[y])   continue;
        sum=siz[y], maxx[root=0]=INF;
        calsiz(y,-1), calsiz(root,-1);
        dfz(root);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1,x,y;i<n;++i)    cin>>x>>y, g[x].pb(y), g[y].pb(x);
    for(int i=1;i<=n;++i)   cin>>city[i], col[city[i]].pb(i);
    // for(int i=1;i<=k;++i,cout<<endl)
    //     for(int j=0;j<col[i].size();++j)
    //         cout<<col[i][j]<<" ";
    sum=n, maxx[root=0]=INF;
    calsiz(1,-1), calsiz(root,-1);
    dfz(root);
    cout<<minn<<endl;
    return 0;
}