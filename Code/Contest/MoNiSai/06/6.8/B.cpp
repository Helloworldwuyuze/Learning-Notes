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
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,a[N],f[N],maxx=0,s[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>a[i], s[a[i]]+=a[i];
    f[1] = s[1];
    for(int i=2;i<=N-10;++i){
        f[i] = max(f[i-1], f[i-2]+s[i]);
    }
    // for(int i=1;i<=N-10;++i)   maxx=max(maxx,f[i]);
    // for(int i=1;i<=n;++i)   cout<<f[i]<<" ";
    // cout<<endl;
    cout<<f[N-10]<<endl;
	return 0;
}