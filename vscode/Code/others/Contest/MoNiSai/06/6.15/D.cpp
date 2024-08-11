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
// #define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n, a[N], premin[N], premax[N], sufmin[N], sufmax[N], p, q, r;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>p>>q>>r;
    for(int i=1;i<=n;++i)   cin>>a[i];
    premin[0] = INF, sufmin[n+1] = INF; premax[0] = -INF, sufmax[n+1] = -INF;
    for(int i=1;i<=n;++i){
        premin[i] = min(premin[i-1], a[i]);
        premax[i] = max(premax[i-1], a[i]);
    }
    for(int i=n;i;--i){
        sufmin[i] = min(sufmin[i+1], a[i]);
        sufmax[i] = max(sufmax[i+1], a[i]);
    }
    int ans = -INF;
    for(int i=1;i<=n;++i){
        int s = a[i] * q;
        if(p>0) s += p * premax[i];
        else    s += p * premin[i];
        if(r>0) s += r * sufmax[i];
        else    s += r * sufmin[i];
        ans = max(ans, s);
    }
    cout<<ans<<endl;
	return 0;
}