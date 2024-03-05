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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int h,w,n,f[N],pre[N];
PIII a[N];

int dfs(int x){
    if(~f[x]) return f[x];
    f[x]=0;
    for(int i=1;i<=n;++i)
        if(a[i].fi.fi>a[x].fi.fi&&a[i].fi.se>a[x].fi.se&&f[x]<dfs(i))   f[x]=f[i], pre[x]=i;
    return ++f[x];
}
void write(int x){
    cout<<x<<" ";
    if(pre[x])  write(pre[x]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    memset(f,-1,sizeof(f));
    cin>>n>>h>>w;
    a[0]=mk(mk(h,w),0);
    for(int i=1;i<=n;++i)   cin>>a[i].fi.fi>>a[i].fi.se, a[i].se=i;
    dfs(0);
    cout<<(--f[0])<<endl;
    if(f[0])    write(pre[0]);  
    return 0;
}