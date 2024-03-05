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

int t,n,m;
int p[N],mu[N],s[N],cnt;

void init(){
    mu[1]=1;
    for(int i=2;i<=M;++i){
        if(!p[i])   p[++cnt]=i, mu[i]=-1;
        for(int j=1;j<=cnt&&p[j]*i<=M;++j){
            p[p[j]*i]=1;
            if(i%p[j]==0){ mu[p[j]*i]=0; break;}
            mu[p[j]*i]=-mu[i];
        }
    }
    for(int i=1;i<=M;++i){
        int l,r;
        for(l=1;l<=i;l=r+1){
            r=i/(i/l);
            s[i]+=(r-l+1)*(i/l);
        }
        mu[i]+=mu[i-1];
    }
}

int query(int x,int y){
    if(x>y) swap(x,y);
    int ans=0;
    for(int i=1;i<=x;++i){
        int j=min(x/(x/i),y/(y/i));
        ans+=(mu[j]-mu[i-1])*s[x/i]*s[y/i];
        i=j;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    init();
    while(t--){
        cin>>n>>m;
        cout<<query(n,m)<<endl;
    }
    return 0;
}