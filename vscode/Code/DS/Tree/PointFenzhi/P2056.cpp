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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,m;
vector<int> g[N];
bool state[N];

namespace tc{
    int son[N],siz[N],top[N],fa[N],dep[N];
    void dfs1(int x,int fat){
        fa[x]=fat, siz[x]=1, dep[x]=dep[fat]=1;
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(y==fat)   continue;
            dfs1(y,x);
            siz[x]+=siz[y];
            if(siz[y]>siz[son[x]])  son[x]=y;
        }
    }
    void dfs2(int x,int tp){
        top[x]=tp;
        if(son[x])  dfs2(son[x],tp);
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(y==fa[x]||y==son[x]) continue;
            dfs2(son[x],son[x]);
        }
    }
    int lca(int x,int y){
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]]) swap(x,y);
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])   swap(x,y);
        return x;
    }
    int dis(int x,int y){
        int l=lca(x,y);
        return dep[x]+dep[y]-2*dep[l];
    }
}

struct Heap{
    priority_queue<int> heap,del;
    void Del(){ while(!del.empty()&&del.top()==heap.top())  heap.pop(), del.pop(); }
    void push(int x){ Del(); heap.push(x); }
    void pop(int x){ del.push(x); Del();}
    int top(){ Del(); return heap.top(); }
}q1[N],q2[N],ans;

namespace build{
    int maxx[N],siz[N],sum,root,dfa[N];
    bool vis[N];
    void calsiz(int x,int fa){
        siz[x]=1, maxx[x]=0;
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(y==fa||vis[y])   continue;
            calsiz(y,x);
            siz[x]+=siz[y]; maxx[x]=max(maxx[x],siz[y]);
        }
        maxx[x]=max(maxx[x],sum-siz[x]);
        if(maxx[x]<maxx[root])  root=x;
    }
    void dfs(int x,int fa){
        int dis1 = tc::dis(x,root), dis2 = tc::dis(dfa[x],root);
        q1[root].push(dis1), q2[root].push(dis2);
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(y==fa||vis[y])   continue;
            dfs(y,x);
        }
    }
    void dfz(int x){
        vis[x]=true;
        dfs(x,-1);
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(vis[y])  continue;
            maxx[root=0]=INF, sum=siz[y];
            calsiz(y,-1), calsiz(root,-1);
            dfa[root]=x;
            dfz(root);
        }
        // if(q1[x].heap.size()>=2){
            // int res=q1[root].top();
            // ans.push()
        // }
    }
}

void update(int x,bool k){
    if(k==1){

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=0,x,y;i<n;++i)    cin>>x>>y, g[x].pb(y), g[y].pb(x);
    tc::dfs1(1,0), tc::dfs2(1,1);

    build::sum = n, build::maxx[build::root = 0] = INF;
    build::calsiz(1, -1), build::calsiz(build::root, -1);
    int root=build::root;
    build::dfz(build::root);

    cin>>m;
    while(m--){
        char op; int x;
        cin>>op;
        if(op=='G'){
            int ans=q1[root].top(); q1[root].pop(ans);
            cout<<q1[root].top()+ans<<endl;
            q1[root].push(ans);
        }else{
            cin>>x;
            update(x,!state[x]); state[x]=!state[x];
        }
    }
    return 0;
}