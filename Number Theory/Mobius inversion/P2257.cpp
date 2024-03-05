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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e7 + 10;
const int M = 1e7;

int t,n,m;
int p[N],mu[N],s[N],cnt;

void init(){
    mu[1]=1;
    for(int i=2;i<=M;++i){
        if(!p[i])   mu[i]=-1, p[++cnt]=i;
        for(int j=1;j<=cnt&&p[j]*i<=M;++j){
            p[p[j]*i]=1;
            if(i%p[j]==0){ mu[i*p[j]]=0; break;}
            mu[i*p[j]]=-mu[i];
        }
    }
    for(int i=1;i<=cnt;++i)
        for(int j=1;j*p[i]<=M;++j)  s[j*p[i]]+=mu[j];
    for(int i=1;i<=M;++i)   s[i]+=s[i-1];
}

int query(int x,int y){
    int ans=0, z=min(x,y);
    for(int i=1;i<=z;++i){
        int j=min(x/(x/i),y/(y/i));
        ans+=(s[j]-s[i-1])*(x/i)*(y/i);
        i=j;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    init();
    cin>>t;
    while(t--){ cin>>n>>m; cout<<query(n,m)<<endl; }
    return 0;
}