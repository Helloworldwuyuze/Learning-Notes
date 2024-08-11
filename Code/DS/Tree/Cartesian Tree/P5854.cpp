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
const int N = 1e7 + 10;
const int M = 1e6 + 10;

int n, w[N], st[N], top, k, ls[N], rs[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>w[i];
	for(int i=1;i<=n;++i){
		k = top;
		while(k && w[st[k]] > w[i])	--k;
		if(k)	rs[st[k]] = i;
		if(k != top)	ls[i] = st[k+1];
		top = k; st[++top] = i;
	}
	int ans1 = 0, ans2 = 0;
	for(int i=1;i<=n;++i)	ans1 ^= i*(ls[i]+1), ans2 ^= i*(rs[i]+1);
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}