#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int M = 2e5 + 10;
#define int long long
#define endl '\n'
#define pb(x) push_back(x)
typedef pair<int,int> PII; 
const int INF = 1e18;

int T,n,t,a[N];
vector<int> v[N];
priority_queue<PII, vector<PII>, greater<PII> > q[N];

void dfs(int x,int fa){
	// cout<<x<<" "<<fa<<" "<<a[x]<<endl;
	for(auto y:v[x]){
		if(y==fa)	continue;
		dfs(y,x);
		if(q[y].size()>q[x].size())	swap(q[x],q[y]);
		while(!q[y].empty())	q[x].push(q[y].top()), q[y].pop();
	}
	// Print(q[x],x);
	if(a[x]>0)	q[x].push(make_pair(0,a[x]));
	if(a[x]<0){
		int cur=0, qr=-a[x], prf=a[x];
		while(!q[x].empty()&&(qr>q[x].top().first||prf<0)){
			PII p=q[x].top(); q[x].pop();
			if(cur<p.first)	qr+=p.first-cur, cur=p.first;
			cur+=p.second, prf+=p.second;
		}
		if(prf>0)	q[x].push(make_pair(qr,prf));
	}
	// Print(q[x],x);
}

void mian(){
	cin>>n>>t;
	for(int i=1;i<=n+1;++i)	v[i].clear();
	for(int i=1;i<=n+1;++i)	while(!q[i].empty())	q[i].pop();
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, v[x].pb(y), v[y].pb(x);
	++n;
	v[n].pb(t), v[t].pb(n); a[n]=INF;
	dfs(1,0);
	int cur=0;
	while(!q[1].empty()&&cur>=q[1].top().first)
		cur+=q[1].top().second, q[1].pop();
	if(cur*2>=INF)	cout<<"escaped"<<endl;
	else	cout<<"trapped"<<endl; 
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T; while(T--)	mian();
	return 0;
}

