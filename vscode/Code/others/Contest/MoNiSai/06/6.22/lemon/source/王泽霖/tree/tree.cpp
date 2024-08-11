#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int>G[100005];
int a[100005];
long long tt=0;
void dfs(int x,int fa,int d,int k){
	if(d==k){
		tt+=a[x];
		return;
	}for(int i=0; i<G[x].size(); i++){
		int y=G[x][i];
		if(y==fa){continue;}
		dfs(y,x,d+1,k);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout); 
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)scanf("%lld",&a[i]);
	for(int i=1; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}bool t=(m<=10000);
	long long ans=0;
	while(m--){
		int x,k;
		scanf("%d%d",&x,&k);
		tt=0;
		dfs(x,x,0,k);
		if(t)printf("%lld\n",tt);
		else ans^=tt;
	}if(!t)printf("%lld\n",tt);
	return 0;
}/*
4 4
1 2 3 4
1 2
1 3
1 4
1 0
1 1
2 1
4 100

*/
