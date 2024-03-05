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

int mu[N],p[N],s[N],a,b,c,d,e,cnt,t;

void prime(){
    mu[1]=1;
    for(int i=2;i<=M;++i){
        if(!p[i])   p[++cnt]=i, mu[i]=-1;
        for(int j=1;j<=cnt&&p[j]*i<=M;++j){
            p[i*p[j]]=1;
            if(i%p[j]==0){ mu[i*p[j]]=0; break; }
            mu[i*p[j]]=-mu[i];
        }
    }
    for(int i=1;i<=M;++i)   s[i]=mu[i]+s[i-1];
}

int query(int l,int r){
    int ans=0, n=min(l,r);
    for(int i=1;i<=n;++i){
        int j=min(l/(l/i),r/(r/i));
        ans+=(s[j]-s[i-1])*(l/i)*(r/i);
        i=j;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    prime();
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>e;
        cout<<query(b/e,d/e)-query((a-1)/e,d/e)-query(b/e,(c-1)/e)+query((a-1)/e,(c-1)/e)<<endl;
    }
    return 0;
}