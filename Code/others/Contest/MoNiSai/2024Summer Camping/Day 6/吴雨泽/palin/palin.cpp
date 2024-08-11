#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>

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
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int MOD = 998244353;

char s[N];
vector<PII> g;
int n, fa[N], ans = 1;

int find(int x){ return fa[x] == x ? fa[x] : fa[x] = find(fa[x]); }

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>(s+1); n = strlen(s+1);
	for(int i=1;i<=n;++i)	fa[i] = i;
	for(int len=1;len<=n;++len){
		for(int i=1;i+len-1<=n;++i){
			bool flag = true;
			for(int j = i+len-1, k=i; k<j; ++k, --j)
				if(s[j] != s[k])	flag = false;
			if(flag){
				for(int j=i+len-1, k=i; k<j; ++k, --j){
					int fx = find(j), fy = find(k);
					if(fx == fy)	continue;
					fa[fx] = fy;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		if(find(i) == i)	ans = 1ll*ans*26%MOD;
	cout<<ans<<endl;
	return 0;
}

