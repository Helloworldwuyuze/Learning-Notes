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
const int N = 200 + 10;
const int M = 5e3 + 10;
const int K = 50 + 10;

int v[N], w[N], f[M][K], n, k, m, tmp[K];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>k>>m>>n;
	memset(f, -0x3f, sizeof(f));
	f[0][1] = 0;
	for(int i=1;i<=n;++i)	cin>>w[i]>>v[i];
	for(int i=1;i<=n;++i)
		for(int j=m;j>=w[i];--j){
			int x = 1, y = 1, cnt = 0;
			while(cnt <= k){
				if(f[j-w[i]][y] + v[i] > f[j][x])	tmp[++cnt] = f[j-w[i]][y++]+v[i];
				else	tmp[++cnt] = f[j][x++];
			}
			// cout<<"###"<<j<<"###"<<endl;
			// for(int x=1;x<=k;++x)	cout<<tmp[x]<<" ";
			// cout<<endl;
			for(int x=1;x<=k;++x)	f[j][x] = tmp[x];
		}
	int ans = 0;
	for(int i=1;i<=k;++i)	ans += f[m][i];
	cout<<ans<<endl;
	return 0;
}