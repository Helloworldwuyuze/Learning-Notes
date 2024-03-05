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
const int N = 5e4 + 10;
const int M = 5e4;

int n,a[N],m,c[N];
int mu[N],p[N],cnt,s[N];

void init(){
    mu[1]=1;
    for(int i=2;i<=M;++i){
        if(!p[i])   p[++cnt]=i, mu[i]=-1;
        for(int j=1;j<=cnt&&i*p[j]<=M;++j){
            p[i*p[j]]=1;
            if(i%p[j]==0)   break;
            mu[i*p[j]]=-mu[i];
        }
    }
    for(int i=1;i<=M;++i)   mu[i]*=i;
    for(int i=1;i<=M;++i)
        for(int j=i;j<=M;j+=i)  s[j]+=mu[i];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>m;
    init();
    for(int i=1;i<=m;++i)   cin>>a[i], n=max(n,a[i]), c[a[i]]++;
    int ans=0;
    for(int T=1;T<=n;++T){
        int res=0, nn=n/T;
        for(int i=1;i<=n/T;++i) res+=c[i*T]*i;
        ans+=T*s[T]*res*res;
    }
    cout<<ans<<endl;
    return 0;
}