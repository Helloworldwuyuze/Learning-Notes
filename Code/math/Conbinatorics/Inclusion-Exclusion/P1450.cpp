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
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int f[N], d[5], c[5], n, s;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>c[1]>>c[2]>>c[3]>>c[4]>>n;
	f[0] = 1;
	for(int i=1;i<=4;++i)
		for(int j=c[i];j<=N-10;++j)
			f[j] += f[j-c[i]];
	while(n--){
		cin>>d[1]>>d[2]>>d[3]>>d[4]>>s;
		int ans = 0;
		for(int i=1;i<16;++i){
			int m = s, k = 0;
			for(int j=1;j<=4;++j)
				if((i>>j-1)&1){
					m -= (d[j]+1)*c[j];
					++k;
				}
			if(m>=0)	ans += (k%2*2-1) * f[m];
		}
		cout<<f[s] - ans<<endl;
	}
	return 0;
}