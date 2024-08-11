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

int n, a[N], mx, mn = INF, ans = INF, id;
bitset<N> b;
bool flag[M], can[M];

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i], mx = max(mx, a[i]);
	sort(a+1, a+1+n);
	if(n<=5000){
		int tmp = 0;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				can[a[j] - a[i]] = true;
		for(int i=n;i<=mx+1;++i){
			bool f = false;
			for(int j=i;j<=mx+1;j+=i)
				f |= can[j];
			if(f)	continue;
			flag[i] = true;
			mn = min(mn, i);
		}
	}else{
		for(int i=1;i<=n;++i)	b[a[i]] = true;
		for(int i=mx+1;i>=n;--i){
			bool f = true;
			for(int j=i+i;j<=mx+1;j+=i)
				f &= flag[j];
			if(!f)	continue;
			if(((b>>i)&b).any()){
				flag[i] = false;
				continue;
			}
			flag[i] = true, mn = min(mn, i);
		}
	}
	cout<<mn<<endl;
	return 0;
}

