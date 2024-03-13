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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,a[N],x,y,z,sum,root;
vector<PII> g[N];
int maxx[N],siz[N],d[N],fa[N],ans;
int sonu[N],sond[N],allu[N],alld[N],csu,csd,cau,cad,dis[N];
bool vis[N];

void calsiz(int x,int fat){
    siz[x]=1, maxx[x]=0;
    fa[x]=fat;
    if(fat!=-1) d[x]=a[x]+d[fat];
    else    d[x]=a[x];
    for(PII y:g[x])
        if(y.fi!=fat&&!vis[y.fi]){
            calsiz(y.fi,x);
            siz[x]+=siz[y.fi], maxx[x]=max(maxx[x],siz[y.fi]);
        }
    maxx[x]=max(maxx[x],sum-siz[x]);
    if(maxx[x]<maxx[root])  root=x;
}

void caldis(int x,int fat,int pre){
    if(d[x]-dis[x]>=pre)    allu[++cau]=d[x]-dis[x], sonu[++csu]=d[x]-dis[x];
    alld[++cad]=min(alld[fat],d[fat]-dis[x]); sond[++csd]=min(allu[fat],d[fat]-dis[x]);
    for(PII y:g[x])
        if(y.fi!=fat&&!vis[y.fi])   dis[y.fi]=dis[x]+y.se, caldis(y.fi,x,max(pre,d[x]-dis[x]));
}

void dfz(int x,int fat){
    vis[x]=true; cau=cad=0;
    int res=0;
    cout<<"###"<<x<<"###"<<endl;
    for(PII y:g[x]){
        if(y.fi!=fat&&!vis[y.fi]){
            csu=csd=0; dis[y.fi]=y.se;
            caldis(y.fi,x,0);
            sort(sonu+1,sonu+1+csu);
            sort(sond+1,sond+1+csd);
            for(int i=1,j=csu+1;i<=csd;++i){
                while(sonu[j-1]+sond[i]>=0&&j>=2) --j;
                res+=(csu-j+1);
            }
            cout<<"##"<<y.fi<<"##"<<endl;
            for(int i=1;i<=csu;++i) cout<<sonu[i]<<" ";
            cout<<endl;
            for(int i=1;i<=csd;++i) cout<<sond[i]<<" ";
            cout<<endl;
            cout<<res<<endl;
        }
    }
    sort(allu+1,allu+1+cau);
    sort(alld+1,alld+1+cad);
    for(int i=1,j=cau;i<=cad;++i){
        while(allu[j-1]+alld[i]>=0&&j>=2) --j;
        ans+=(cau-j+1);
    }
    ans-=res; ans+=cau;
    cout<<ans<<endl;
    cout<<"###End"<<x<<"###"<<endl;
    for(PII y:g[x]){
        if(!vis[y.fi]&&y.fi!=fat){
            root=0; maxx[root]=INF; sum=siz[y.fi];
            calsiz(y.fi,x), calsiz(root,-1);
            dfz(root,x);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>a[i];
    for(int i=1;i<n;++i)    cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    root=0, maxx[root]=N, sum=n;
    calsiz(1,-1), calsiz(root,-1);
    cout<<root<<endl;
    for(int i=1;i<=n;++i)   cout<<i<<" "<<siz[i]<<" "<<maxx[i]<<" "<<d[i]<<" "<<fa[i]<<endl;
    dfz(root,-1);
    cout<<ans<<endl;
    return 0;
}