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
#include<random>

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
const int N = 3e5 + 10;
const int M = 1e6 + 10;

int T,n,m,x[N],y[N],k;
vector<PII> g[N];
int step[N],s[N],G[10][10];
bool f[10][10];

void BFS(){
    queue<int> q;
    step[1]=1;
    q.push(1);
    while(!q.empty()){
        int p=q.front(); q.pop();
        for(PII y:g[p])
            if(!step[y.fi])    step[y.fi]=step[p]+y.se, q.push(y.fi), f[p][y.fi]=true;
    }
}

void BFS1(){
    queue<int> q;
    step[1]=1;
    q.push(1);
    while(!q.empty()){
        int p=q.front(); q.pop();
        for(int i=1;i<=n;++i)
            if(G[p][i]&&!step[i])    step[i]=step[p]+G[p][i], q.push(i);
    }
}

bool fflag=false;
void dfs(int u){
    if(fflag)   return ;
    if(u==m+1){
        BFS1();
        for(int i=1;i<=n;++i)   s[i]=0;
        for(int i=1;i<=n;++i)
            for(PII j:g[i])
                if(step[i]+G[i][j.fi]==step[j.fi])    ++s[j.fi];
        bool flag=true;
        for(int i=1;i<=n;++i)
            if(s[i]>1){flag=false; break;}
        if(flag)    fflag=true;
        return ;
    }
    for(int i=1;i<=k;++i){
        G[x[u]][y[u]]=i;
        dfs(u+1);
        if(fflag)   return ;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        for(int i=1;i<=n;++i)   g[i].clear(), step[i]=0;
        for(int i=1;i<=m;++i)   cin>>x[i]>>y[i], g[x[i]].pb(mk(y[i],1));
        if(m==n-1){
            cout<<"Yes"<<endl;
            for(int i=1;i<=m;++i)   cout<<1<<" ";
            cout<<endl;
        }else if(k==1){
            BFS();
            for(int i=1;i<=n;++i)   s[i]=0;
            for(int i=1;i<=n;++i)
                for(PII j:g[i])
                    if(step[i]+j.se==step[j.fi])  ++s[j.fi];
            bool flag=false;
            for(int i=2;i<=n;++i)
                if(s[i]!=1){flag=true; break;}
            if(!flag){
                cout<<"Yes"<<endl;
                for(int i=1;i<=m;++i)   cout<<1<<" ";
                cout<<endl;
            }else   cout<<"No"<<endl;
        }else{
            for(int i=1;i<=n;++i)
                for(PII j:g[i]) G[i][j.fi]=j.se;
            fflag=false;
            if(k>=n){
                for(int i=1;i<=m;++i)   f[x[i]][y[i]]=false;
                cout<<"Yes"<<endl;
                BFS();
                for(int i=1;i<=m;++i)
                    if(f[x[i]][y[i]])   cout<<1<<" ", f[x[i]][y[i]]=false;
                    else    cout<<k<<" ";
                cout<<endl;
            }else{
                dfs(1);
                if(fflag){
                    cout<<"Yes"<<endl;
                    for(int i=1;i<=m;++i)   cout<<G[x[i]][y[i]]<<" ";
                    cout<<endl;
                }else   cout<<"No"<<endl;
            }
        }
        // BFS();
    }
    return 0;
}