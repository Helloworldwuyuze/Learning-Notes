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

int n, w[N], m[N], t, f[N], g[N];
int tail, head, q[N], num[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>t;
	for(int i=1;i<=n;++i)	cin>>w[i];
	for(int i=1;i<=n;++i)	cin>>m[i];
	memset(f, 0x3f, sizeof(f));
	memset(g, 0x3f, sizeof(g));
	f[0] = 0;
	for(int i=1;i<=n;++i){
		int rest = min(m[i], 2*t/w[i]);
		for(int d=0;d<w[i];++d){
			int lim = (2*t-d)/w[i];
			head = 1, tail = 0;
			for(int j=0;j<=lim;++j){
				while(head<=tail && f[j*w[i]+d] - j <= q[tail])	--tail;
				q[++tail] = f[j*w[i]+d]-j, num[tail] = j;
				while(head<=tail && num[head]+rest < j)	++head;
				f[j*w[i]+d] = min(f[j*w[i]+d], q[head]+j);
			}
		}
	}
	g[0] = 0;
	for(int i=1;i<=n;++i)
		for(int j=w[i];j<=2*t;++j)
			g[j] = min(g[j], g[j-w[i]]+1);
	int ans = INF;
	for(int i=t;i<=2*t;++i)	ans = min(ans, f[i] + g[i-t]);
	if(ans == INF)	cout<<-1<<endl;
	else	cout<<ans<<endl;
	return 0;
}