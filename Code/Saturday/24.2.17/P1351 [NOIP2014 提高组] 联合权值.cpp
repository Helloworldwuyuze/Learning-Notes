#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int M = 4e5 + 10;
const int MOD = 10007;

typedef pair<int,int> PII;

vector<int> g[N];
int n,x,y,w[N],sum,maxx,exmaxx;
priority_queue<PII> q;
int ans1,ans2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<n;++i)	cin>>x>>y, g[x].push_back(y), g[y].push_back(x);
	for(int i=1;i<=n;++i)	cin>>w[i];
	for(int i=1;i<=n;++i){
		maxx=exmaxx=sum=0;
		for(int v:g[i]){
			if(w[v]>maxx)	exmaxx=maxx, maxx=w[v];
			else if(w[v]>exmaxx)	exmaxx=w[v];
			sum=(sum+w[v])%MOD;
		}
		ans2=max(ans2,maxx*exmaxx);
		for(int v:g[i]){
			ans1=(ans1+w[v]*(sum-w[v])%MOD)%MOD;
		}
	}
	cout<<ans2<<" "<<ans1<<endl;
	return 0;
}
