#include<cstdio>
#include<iostream>
using namespace std;
const int N=5e4+100;
const int M=2*N;
int n,m;
int head[N],tot;
struct kkk{
	int x,y;
}r[M];
struct node{
	int ver,nxt;
}e[M];
struct road{
	int x,y,z;
}a[M];
void add(int x,int y){
	e[++tot]={y,head[x]};
	head[x]=tot; 
}
int k1,k2;
int col[N];
void dfs(int x,int fa,int color){
	col[x]=color;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].ver;
		if(y==fa) continue;
		if((x==k1&&y==k2)||(x==k2&&y==k1)) continue;
		dfs(y,x,color);
	}
}
int main(){
	freopen("disruption.in","r",stdin);
	freopen("disruption.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d",&r[i].x,&r[i].y);
		add(r[i].x,r[i].y);
		add(r[i].y,r[i].x);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	for(int i=1;i<n;i++){
		k1=r[i].x;
		k2=r[i].y;
		dfs(k1,0,1);
		dfs(k2,0,2);
		int res=0x3f3f3f3f;
		for(int j=1;j<=m;j++){
			int x=a[j].x,y=a[j].y;
			if(col[x]!=col[y]) res=min(res,a[j].z);
		}
		if(res!=0x3f3f3f3f) printf("%d\n",res);
		else printf("-1\n");
	}
	return 0;
}
