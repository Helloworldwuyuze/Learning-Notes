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
const int N = 4e5 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

char c[N];
int oldrk[N], rk[N], sa[N], w;
bool vis[N];

bool cmp(int x,int y){
    return rk[x]==rk[y]?rk[x+w]<rk[y+w]:rk[x]<rk[y];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>(c+1); int m=strlen(c+1), n=m<<1;
    for(int i=1;i<=m;++i)   sa[i]=i, rk[i]=c[i], c[i+m]=c[i], sa[i+m]=i+m, rk[i+m]=c[i];
    for(w=1;w<=n;w<<=1){
        sort(sa+1,sa+1+n,cmp);
        memcpy(oldrk,rk,sizeof(oldrk));
        for(int p=0,i=1;i<=n;++i)
            if(oldrk[sa[i]]==oldrk[sa[i-1]]&&oldrk[sa[i]+w]==oldrk[sa[i-1]+w])  rk[sa[i]]=p;
            else    rk[sa[i]]=++p;
    }
    // for(int i=1;i<=m;++i)
    //     cout<<sa[i]<<endl;
    for(int i=1;i<=n;++i){
		if(sa[i]<=m)	cout<<c[sa[i]-1+m];
	}
    cout<<endl;
    return 0;
}