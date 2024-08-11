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
const int N = 1e6 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n, id[N], sa[N], rk[N], oldrk[N], cnt[N], m=127, p=0, i, w, key[N];
char c[N];

inline bool cmp(int x,int y){ return oldrk[x]==oldrk[y]&&oldrk[x+w]==oldrk[y+w];}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>(c+1); n=strlen(c+1);
    for(i=1;i<=n;++i)   ++cnt[rk[i]=c[i]];
    for(i=1;i<=m;++i)   cnt[i]+=cnt[i-1];
    for(i=n;i;--i)  sa[cnt[rk[i]]--]=i;
    for(w=1;p<n;w<<=1, m=p){
        memset(cnt,0,m*sizeof(int));
        for(i=n, p=0;i>n-w;--i) id[++p]=i;
        for(i=1;i<=n;++i)
            if(sa[i]>w) id[++p]=sa[i]-w;
        for(i=1;i<=n;++i)   ++cnt[key[i]=rk[id[i]]];
        for(i=1;i<=m;++i)   cnt[i]+=cnt[i-1];
        for(i=n;i;--i)  sa[cnt[key[i]]--]=id[i];
        memcpy(oldrk+1, rk+1, n*sizeof(int));
        for(i=1, p=0;i<=n;++i)
            rk[sa[i]]=cmp(sa[i],sa[i-1])?p:++p;
    }
    for(int i=1;i<=n;++i)
        cout<<sa[i]<<" ";
    cout<<endl;
    return 0;
}