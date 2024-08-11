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
const int N = 3e4 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int t, n, T;
int base[N];

struct SufArr{
    char c[N];
    int sa[N], rk[N], id[N], oldrk[N], key[N], cnt[N], w, p, m, i, st[N][16], height[N];
    inline bool cmp(int x,int y){ return oldrk[x]==oldrk[y]&&oldrk[x+w]==oldrk[y+w]; }
    inline void build(){
        for(i=1;i<=n;++i)
            cnt[i]=height[i]=0;
        m=127; p=n-1;
        for(i=1;i<=n;++i)   ++cnt[rk[i]=c[i]];
        for(i=1;i<=m;++i)   cnt[i]+=cnt[i-1];
        for(i=n;i;--i)  sa[cnt[rk[i]]--]=i;
        for(w=1;p<n;w<<=1, m=p){
            memset(cnt,0,sizeof(cnt));
            for(p=0, i=n;i>n-w;--i)  id[++p]=i;
            for(i=1;i<=n;++i)
                if(sa[i]>w) id[++p]=sa[i]-w;
            for(i=1;i<=n;++i)   ++cnt[key[i]=rk[id[i]]];
            for(i=1;i<=m;++i)   cnt[i]+=cnt[i-1];
            for(i=n;i;--i)  sa[cnt[key[i]]--]=id[i];
            memcpy(oldrk,rk,sizeof(oldrk));
            for(p=0, i=1;i<=n;++i)
                rk[sa[i]]=cmp(sa[i],sa[i-1])?p:++p;
        }
        for(i=1;i<=n;++i){
            if(!rk[i])  continue;
            int k=height[rk[i-1]];
            if(k)   --k;
            while(c[i+k]==c[sa[rk[i]-1]+k]) ++k;
            height[rk[i]]=st[rk[i]][0]=k;
        }
        // for(int i=1;i<=n;++i)   cout<<height[i]<<" ";
        // cout<<endl;
        for(int j=1;j<=t;++j)
            for(i=1;i+(1<<j)-1<=n;++i)
                st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
    inline int query(int l,int r){
        l=rk[l], r=rk[r];
        if(l>r) swap(l,r); ++l;
        int t=base[r-l+1];
        return min(st[l][t],st[r-(1<<t)+1][t]);
    }
}sa[2];

int a[N], b[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    base[0]=-1;
    for(int i=1;i<=N-10;++i)    base[i]=base[i/2]+1;
    cin>>T;
    while(T--){
        cin>>(sa[0].c+1); n=strlen(sa[0].c+1); t=log(n)/log(2);
        for(int i=1;i<=n;++i)   sa[1].c[i]=sa[0].c[n-i+1];
        sa[0].build(); sa[1].build();
        memset(a,0,sizeof(a)), memset(b,0,sizeof(b));
        for(int len=1;len<=n/2;++len){
            for(int i=len;i<=n;i+=len){
                int l=i, r=i+len;
                int L=n-r+2, R=n-l+2;
                int lcp=min(len,sa[0].query(l,r));
                int lcs=min(len-1,sa[1].query(L,R));
                if(lcp+lcs>=len){
                    b[i-lcs]++, b[i+lcp-len+1]--;
                    a[r-lcs+len-1]++, a[r+lcp]--;
                }
            }
        }
        for(int i=1;i<=n;++i)   a[i]+=a[i-1], b[i]+=b[i-1];
        for(int i=1;i<=n;++i)   cout<<a[i]<<" ";
        cout<<endl;
        for(int i=1;i<=n;++i)   cout<<a[i]<<" ";
        cout<<endl;
        long long ans=0;
        for(int i=1;i<n;++i)   ans+=a[i]*b[i+1];
        cout<<ans<<endl;
    }
    return 0;
}