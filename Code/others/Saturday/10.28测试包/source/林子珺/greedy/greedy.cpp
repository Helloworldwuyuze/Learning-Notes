#include <bits/stdc++.h>
using namespace std;

const int N=310;
int n,m;
int w[N],l[N],r[N];

int ans=0;
bool vis[N];
int cur[N];

int query(int l,int r){
	int cnt=0;
	for(int i=l;i<=r;i++)
		if(!vis[i])
			cnt++;
	return cnt;
}

int update(int l,int r){
	for(int i=l;i<=r;i++)
		vis[i]=1;
}

int main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>w[i]>>l[i]>>r[i];
	for(int i=1;i<=m;i++)cur[i]=i;
	do{
		int s=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++){
			int re=query(l[cur[i]],r[cur[i]]);
			if(re<=0)break;
			update(l[cur[i]],r[cur[i]]);
			s+=w[cur[i]];
		}
		ans=max(ans,s);
	}while(next_permutation(cur+1,cur+1+m));
	cout<<ans<<endl;
	return 0;
}
