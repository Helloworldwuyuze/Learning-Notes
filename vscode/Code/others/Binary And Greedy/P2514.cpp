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

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 50 + 10;
const int M = 5e4 + 10;

int m, b, n, ans = INF, H, id;
int a[M], h[N], c[N][M];
PII dt[M];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>m>>b>>H>>n;
	for(int i=1;i<=m;++i)	cin>>a[i];
	for(int i=1;i<=n;++i)	cin>>h[i];
	for(int i=0;i<=n;++i)
		for(int j=1;j<=m;++j)	cin>>c[i][j];
	for(int i=1;i<=n;++i){
		int tmp = h[i];
		for(int j=1;j<=m;++j)	dt[j].fi = c[0][j] - c[i][j], dt[j].se = j;
		sort(dt + 1, dt + 1 + m);
		// cout<<"###"<<i<<"###"<<endl;
		// for(int i=1;i<=m;++i)	cout<<dt[i].fi<<" "<<dt[i].se<<endl;
		int res = b;
		for(int j=1;j<=m;++j){
			// cout<<dt[j].se<<" "<<res<<" "<<a[dt[j].se]<<" "<<c[0][dt[j].se]<<" "<<c[i][dt[j].se]<<endl;
			if(a[dt[j].se] <= res)	res -= a[dt[j].se], tmp += a[dt[j].se] * c[0][dt[j].se];
			else{
				tmp += res * c[0][dt[j].se];
				tmp += (a[dt[j].se] - res) * c[i][dt[j].se];
				res = 0;
				// cout<<"QAQ"<<endl;
			}
			// cout<<j<<" "<<c[0][j]<<" "<<c[i][j]<<" "<<res<<" "<<tmp<<endl;
		}
		// cout<<i<<" "<<ans<<" "<<tmp<<endl;
		if(ans > tmp)	ans = tmp, id = i;
	}
	cout<<id<<endl<<ans + H<<endl;
	return 0;
}