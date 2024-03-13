#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=1e5+10;
int n,q;
int a[N],x[N];

int pos[N];

bool vis[N];
void solve1(){
	int ans=0;
	stack<int> st;
	for(int i=n;i>=1;i--){
		if(!vis[a[i]])st.push(a[i]);
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vector<int> v;
		while(st.top()!=i){
			ans++;
			v.push_back(st.top());
			st.pop();
		}
		ans++;st.pop();
		sort(v.begin(),v.end(),greater<int>());
		for(int t:v)st.push(t);
	}
	cout<<ans<<' ';
}

signed main(){
	freopen("dizalo.in","r",stdin);
	freopen("dizalo.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=i;
	}
	for(int i=1;i<=q;i++)cin>>x[i];
	solve1();
	for(int i=1;i<=q;i++){
		vis[a[x[i]]]=1;
		solve1();
	}
	return 0;
}
