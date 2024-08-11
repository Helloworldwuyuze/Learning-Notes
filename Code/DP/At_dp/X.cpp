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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 2e5 + 10;
const int MOD = 1e9 + 7;

struct node{
    int w,s,v;
}a[N];
bool operator<(node x,node y){
    return x.s+x.w<y.s+y.w;
}
int n,f[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>a[i].w>>a[i].s>>a[i].v;
    sort(a+1,a+1+n);
    memset(f,-1,sizeof(f));
    f[0]=0;
    for(int i=1;i<=n;++i)
        for(int j=a[i].s;j>=0;--j)
            f[j+a[i].w]=max(f[j+a[i].w],f[j]+a[i].v);
    int ans=0;
    for(int i=0;i<=N-10;++i)    ans=max(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}