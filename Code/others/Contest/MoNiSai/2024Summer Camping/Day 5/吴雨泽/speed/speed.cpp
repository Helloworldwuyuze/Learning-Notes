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
const int N = 2e2 + 10;
const int M = 1e6 + 10;

int n, m, k, a[N], ans, cnt;
int ch[N], unch[N], nc, nu, b[N], pre[N];
priority_queue<PII, vector<PII>, greater<PII> > q;

int main(){
	freopen("speed.in","r",stdin);
	freopen("speed.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int s=1;s<(1<<n);++s){
		nc = nu = 0;
		for(int i=1;i<=n;++i)
			if((s>>i-1)&1)	ch[++nc] = a[i];	
			else	unch[++nu] = a[i];
		
		int rest = m*k;
		for(int i=1;i<=nc;++i)	q.push(mk(ch[i], m));
		nc = 0;
		while(q.size() && rest)
			if(q.top().se)	q.push(mk(q.top().fi+1, q.top().se-1)), q.pop(), --rest;
			else	ch[++nc] = q.top().fi, q.pop();
		while(q.size())	ch[++nc] = q.top().fi, q.pop();
		for(int i=1;i<=nu;++i)	q.push(mk(unch[i], m));
		nu = 0;
		while(q.size() && rest)
			if(q.top().se)	q.push(mk(q.top().fi+1, q.top().se-1)), q.pop(), --rest;
			else	unch[++nu] = q.top().fi, q.pop();
		while(q.size())	unch[++nu] = q.top().fi, q.pop();
		
		int maxx = 0, minn = INF;
		for(int i=1;i<=nc;++i)	minn = min(minn, ch[i]);
		for(int i=1;i<=nu;++i)	maxx = max(maxx, unch[i]);
		
		if(minn >= maxx){
			++ans;
		}
	} 
	cout<<ans<<endl;
	return 0;
}

