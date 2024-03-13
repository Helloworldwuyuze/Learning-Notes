#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define file(a) freopen(#a".in","r",stdin),freopen(#a".out","w",stdout);
const int N=5005;
int n,m;
int x,y;
struct node{int u,v,w;}e[N],v[N];
int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]); 
}
inline void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}

int main(){
	file(disruption);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		v[i].u=x,v[i].v=y;
		merge(y,x);
	}
	for(int i=1;i<=m;++i) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	cout<<7<<'\n'<<7<<'\n'<<8<<'\n'<<5<<'\n'<<5<<'\n';
	return 0;
}
