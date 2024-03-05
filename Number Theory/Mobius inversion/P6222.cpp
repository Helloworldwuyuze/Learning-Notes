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

#define int unsigned int
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e7 + 10;
const int M = 1e6 + 10;

int t,maxn,k;
long long n;
int p[N/10],f[N<<1],s[N<<1],cnt;
bitset<N<<1> chk;

int ksm(int x,int m){
    int ans=1;
    while(m){
        if(m&1) ans=ans*x;
        x=x*x; m>>=1;
    }
    return ans;
}

void init(){
    f[1]=s[1]=chk[1]=1;
    for(int i=2;i<=maxn;++i){
        if(!chk[i])   p[++cnt]=i, f[i]=i-1, s[i]=ksm(i,k);
        for(int j=1;j<=cnt&&i*p[j]<=maxn;++j){
            chk[i*p[j]]=1, s[i*p[j]]=s[i]*s[p[j]];
            if(i%p[j]==0){
                if(i/p[j]%p[j]) f[i*p[j]]=-p[j]*f[i/p[j]];
				break;
            }
            f[i*p[j]]=(p[j]-1)*f[i];
        }
    }
    for(int i=2;i<=maxn;++i)   f[i]=(f[i-1]+f[i]*s[i]), s[i]=(s[i]+s[i-1]);
    for(int i=2;i<=maxn;++i)   s[i]=(s[i]+s[i-1]);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t>>maxn>>k; maxn<<=1;
    init();
    // for(int i=1;i<=10;++i)   cout<<p[i]<<" "<<s[i]<<" "<<f[i]<<endl;
    while(t--){
        cin>>n;
        int ans=0;
        for(int i=1,j;i<=n;i=j+1){
            // cout<<i<<" "<<n<<endl;
            j=n/(n/i);
            ans+=(f[j]-f[i-1])*(s[(n/i)<<1]-(s[n/i]<<1));
        }
        cout<<ans<<endl;
    }
    return 0;
}