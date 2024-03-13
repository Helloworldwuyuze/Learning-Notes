#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int>G[200005],V[200005];
bool del[200005];
int siz[200005],mx[200005],zx=0,ans,n,k,sizz;
int mn[1000006],dis[200005];
vector<int>vec1,vec2;
void ddd(int x,int fa){
	sizz++;
	for(int i=0; i<G[x].size(); i++){int y=G[x][i];if(y==fa||del[y]){continue;}ddd(y,x);}
}
void dfs(int x,int fa){
	siz[x]=1;
	mx[x]=0;
	for(int i=0; i<G[x].size(); i++){
		int y=G[x][i];
		if(y==fa||del[y]){continue;}
		dfs(y,x);
		siz[x]+=siz[y];
		mx[x]=max(mx[x],siz[y]);
	}for(int i=0; i<G[x].size(); i++){
		int y=G[x][i];
		if(y==fa||del[y]){continue;}
		if(max(mx[y],sizz-siz[y])<ans){
			ans=max(mx[y],sizz-siz[y]);
			zx=y;
		}
	}
}void qdis(int x,int fa,long long len,int bs){
	for(int i=0; i<G[x].size(); i++){
		int y=G[x][i];
		if(y==fa||del[y]){continue;}
		long long ll=len+1ll*V[x][i];
		int bss=bs+1;
		if(ll<=k){//if(len<=1ll*k)
			mn[ll]=min(mn[ll],bss);
			vec1.push_back(ll),vec2.push_back(bss);
		}
		qdis(y,x,ll,bss); 
	}
}int anss=1000000000,cnt=0,dep;
void dfz(int rt,int d){
	sizz=0;
	ddd(rt,rt);
	zx=0;
	ans=1000000000;
	dfs(rt,rt);
	if(mx[rt]<ans)zx=rt;
	rt=zx;
	vec1.clear(),vec2.clear();
	qdis(rt,rt,0,1);
	for(int i=0; i<vec1.size(); i++){
		int len1=vec1[i],bs=vec2[i];
		anss=min(anss,mn[k-len1]+bs);
		if(len1==k)anss=min(anss,bs);
	}for(int i=0; i<vec1.size(); i++)mn[vec1[i]]=1000000000;
	del[rt]=1;
	dep=max(dep,d);
	for(int i=0; i<G[rt].size(); i++){
		int y=G[rt][i];
		if(del[y]){continue;}
		dfz(y,d+1);
	}
}
int main(){
//	freopen("P4149_1.in","r",stdin);
//	freopen("")
	for(int i=1; i<=1000000; i++)mn[i]=1000000000;
	scanf("%d%d",&n,&k);
	for(int i=1; i<n; i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);a++,b++;
		G[a].push_back(b);
		G[b].push_back(a);
		V[a].push_back(c);
		V[b].push_back(c);
	}dfz(1,1);
	if(anss==1000000000)cout<<-1;
	else cout<<anss;
	return 0;
}/*
10 10
0 1 3
0 3 4
2 1 3
4 5 8
 
*/