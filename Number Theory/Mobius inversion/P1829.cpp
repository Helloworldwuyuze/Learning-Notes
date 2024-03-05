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
const int MOD = 20101009;

int p[N],cnt,n,m,mu[N],ans;

void init(){
    mu[1]=1;
    for(int i=2;i<=m;++i){
        if(!p[i])   mu[i]=-1, p[++cnt]=i;
        for(int j=1;j<=cnt&&p[j]*i<=m;++j){
            p[p[j]*i]=1;
            if(i%p[j]==0){ mu[i*p[j]]=0; break;}
            mu[i*p[j]]=-mu[i];
        }
    }
    for(int i=1;i<=m;++i)   mu[i]=(i*i%MOD*mu[i]+MOD)%MOD;
    for(int i=1;i<=m;++i)   mu[i]=(mu[i]+mu[i-1])%MOD;
}

int sum(int x){ return (1+x)*x/2%MOD;}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    if(n>m) swap(n,m);
    init();
    for(int i=1;i<=n;++i){
        int nn=n/i, mm=m/i, res=0, ii=min(n/(n/i),m/(m/i));
        for(int j=1;j<=nn;++j){
            int jj=min(nn/(nn/j),mm/(mm/j));
            res=(res+(mu[jj]-mu[j-1])*sum(nn/j)%MOD*sum(mm/j)%MOD)%MOD;
            j=jj;
        }
        ans=(ans+(sum(ii)-sum(i-1))*res%MOD)%MOD;
        i=ii;
        // cout<<i<<" "<<ans<<" "<<res<<endl;
    }
    cout<<(ans+MOD)%MOD<<endl;
    return 0;
}