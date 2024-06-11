#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
const int N = 1e5 + 10;
int T;
int n,a,b,na,nb,deepest;
int Next[N<<1],head[N],ver[N<<1],tot=-1;
int de[N],fa[N][20];

void add(int x,int y){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}

void dfs(int x,int fat){
	de[x]=de[fat]+1;
	fa[x][0]=fat;
	if(de[x]>de[deepest])	deepest=x;
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		if(y==fat)	continue;
		dfs(y,x);
	}
}

int LCA(int x,int y){
	if(de[x]<de[y])	swap(x,y);
	int l=log(n)/log(2);
	for(int i=l;i;--i)
		if(de[fa[x][i]]>=de[y])	x=fa[x][i];
	if(x==y)	return x;
	for(int i=l;i;--i)
		if(fa[x][i]!=fa[y][i])	x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int main(){
	scanf("%d",&T);
	while(T--){
		tot=-1;
		memset(head,-1,sizeof(head));
		memset(fa,0,sizeof(fa));
		scanf("%d%d%d%d%d",&n,&a,&b,&na,&nb);
		for(int i=1;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y), add(y,x);
		}
		dfs(1,0);
		de[deepest]=0, fa[0][0]=0, de[0]=-1;
		dfs(deepest,0);
		int len=de[deepest];
		int l=log(n)/log(2)+1;
		for(int j=1;j<=l;++j){
			for(int i=1;i<=n;++i){
				fa[i][j]=fa[fa[i][j-1]][j-1];
			}
		}
		int lca=LCA(a,b);
		cout<<lca<<endl;
		if(na>=de[a]+de[b]-2*de[lca])	printf("Alice\n");
		else if(len<na*2)	printf("Alice\n");
		else if(nb<=na*2)	printf("Alice\n");
		else	printf("Bob\n");
	}
	return 0;
} 
