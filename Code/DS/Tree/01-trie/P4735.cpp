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
const int N = 6e5 + 10;
const int M = 1e6 + 10;
const int MAXH = 29;

int n, a[N], pre[N], l, r, x, tmp[50], ans, m; 
int t[N<<5][2], w[N<<5], idx, root[N];
char op;

void update(int &p, int q, int x){
	p = ++idx;
	t[p][0] = t[q][0], t[p][1] = t[q][1], w[p] = w[q] + 1;
	if(x == -1)	return ;
	update(t[p][tmp[x]], t[q][tmp[x]], x-1);
}
int query(int p,int q,int x){
	if(x == -1)	return 0;
	// cout<<"QUERY! "<<x<<" "<<p<<" "<<q<<" "<<w[t[p][tmp[x]^1]]<<" "<<w[t[q][tmp[x]^1]]<<" "<<tmp[x]<<" "<<t[p][tmp[x]]<<" "<<t[q][tmp[x]]<<" "<<t[p][tmp[x^1]]<<" "<<t[q][tmp[x]^1]<<" "<<endl;
	if(w[t[p][tmp[x]^1]] - w[t[q][tmp[x]^1]] > 0)	return query(t[p][tmp[x]^1], t[q][tmp[x]^1], x-1) + (1<<x);
	else	return query(t[p][tmp[x]], t[q][tmp[x]], x-1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	update(root[0], root[0], MAXH);
	for(int i=1;i<=n;++i)	cin>>a[i], pre[i] = pre[i-1] ^ a[i];
	for(int i=1;i<=n;++i){
		for(int j=0;j<=MAXH;++j)	tmp[j] = (pre[i]>>j)&1;
		update(root[i], root[i-1], MAXH);
	}
	while(m--){
		cin>>op;
		if(op == 'A'){
			cin>>x, a[++n] = x, pre[n] = pre[n-1] ^ a[n];
			for(int i=0;i<=MAXH;++i)	tmp[i] = (pre[n]>>i)&1;
			update(root[n], root[n-1], MAXH);
		}else{
			cin>>l>>r>>x;
			for(int i=0;i<=MAXH;++i)	tmp[i] = ((x^pre[n])>>i)&1;
			// cout<<(x^pre[n])<<endl;
			// for(int i=1;i<=n;++i)	cout<<pre[i]<<" ";
			// cout<<endl;
			cout<<query(root[r-1], l-2<=0 ? 0:root[l-2], MAXH)<<endl;
		}
	}
	// for(int i=1;i<=n;++i)	cout<<root[i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=idx;++i)
	// 	cout<<i<<" "<<t[i][0]<<" "<<t[i][1]<<" "<<w[i]<<endl;
	return 0;
}