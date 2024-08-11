#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
#include<unordered_map>

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
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int T, B, n, l[N], r[N], minr[N], maxl[N], fa[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T>>B;
	while(T--){
		cin>>n;
		for(int i=2;i<=n;++i)	cin>>fa[i];
		for(int i=1;i<=n;++i)	cin>>l[i]>>r[i];
		int mx = 0, mn = INF, ans = 0;
		for(int i=1;i<=n;++i){
			if(fa[i])	minr[i] = min(minr[fa[i]], r[i]), maxl[i] = max(maxl[fa[i]], l[i]);
			else	minr[i] = r[i], maxl[i] = l[i];
			mx = max(mx, l[i]), mn = min(mn, r[i]);
			ans = max(ans, maxl[i] - minr[i]);
		}
		ans = max(ans, (mx - mn + 1)>>1);
		cout<<ans<<endl;
		if(B){
			if(mx <= mn){
				for(int i=1;i<=n;++i)	cout<<mx<<" ";
				cout<<endl;
				continue;
			}
			int mid = mx + mn >> 1;
			for(int i=1;i<=n;++i)	cout<<max(min(r[i], mid), l[i])<<" ";
			cout<<endl;
		}
	}
	return 0;
}