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
const int N = 2e5 + 10;
const int S = 5e2 + 10;
const int M = 1e6 + 10;

int n, m, x[N], y[N], f[N], cnt[S][S], b[N], t, ans;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m; t = sqrt(m);
	for(int i=1;i<=n;++i)	cin>>x[i]>>y[i];
	for(int i=1;i<=m;++i){
		int op, p; cin>>op>>p;
		if(op == 1){
			f[p] = i;
			if(x[p] + y[p] > t)
				for(int j=i;j<=m;){
					j += x[p];
					if(j > m)	break;
					++b[j], j+=y[p];
					if(j > m)	break;
					--b[j];
				}
			else	--cnt[x[p]+y[p]][i%(x[p]+y[p])], ++cnt[x[p]+y[p]][(i+x[p])%(x[p]+y[p])], ++ans;
		}else{
			if((i-f[p])%(x[p]+y[p]) == 0)	--ans;
			if((i-f[p])%(x[p]+y[p]) > x[p])	--ans;
			if(x[p] + y[p] > t)
				for(int j=f[p];j<=m;){
					j += x[p];
					if(j > m)	break;
					--b[j], j+=y[p];
					if(j > m)	break;
					++b[j];
				}
			else	++cnt[x[p]+y[p]][f[p]%(x[p]+y[p])], --cnt[x[p]+y[p]][(f[p]+x[p])%(x[p]+y[p])];
//			cerr<<"QAQ"<<endl;
		}
		ans += b[i];
		for(int j=1;j<=t;++j)
			ans += cnt[j][i%j];
		cout<<ans<<endl;
	}
	return 0;
}

