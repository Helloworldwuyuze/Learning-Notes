#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,q;
int a[N];
struct node
{
	int v,nxt;
}e[N<<1];
int h[N],tot;
int fa[N][25];
int p2[N];
int za[N];
int anss=0;
void add(int x,int y){
	e[++tot].nxt=h[x];
	e[tot].v=y;
	h[x]=tot;
}
void dfs(int u,int u_fa)
{
	fa[u][0]=u_fa;
	//cout<<u<<" ::"<<u_fa<<" "<<fa[u][0]<<endl;
	for(int i=h[u];~i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==u_fa) continue;
		dfs(v,u);
	}
}
void fa_fa()
{
	for(int j=1;j<24;j++)
	{
		for(int i=1;i<=n;i++)
		{
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
}
int fd(int x,int y)
{ 
	int p=20;
	for(int i=23;i>=0;i--)
	{
	//	cout<<p2[i]<<" "<<y<<" "<<fa[x][i]<<endl;
		if(p2[i]<=y&&fa[x][i]!=0) y-=p2[i],x=fa[x][i];
	}
//	cout<<y<<" ::y"<<" "<<x<<endl;
	if(y==0)
	return a[x];
	else return 0;
}
void init()
{
	p2[0]=1;
	for(int i=1;i<=25;i++) p2[i]=2*p2[i-1];
	
}
void qan(int u,int k)
{
//	cout<<u<<" "<<k<<endl;
	if(k==0)
	{
		anss+=a[u];
		return ;
	}
	for(int i=h[u];~i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa[u][0]) continue;
		qan(v,k-1);
	}
	return ;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	init();
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);	
	}
//	cout<<tot<<endl;
	dfs(1,0);
//	for(int i=1;i<=n;i++) cout<<i<<" "<<fa[i][0]<<endl;
	fa_fa();
//	for(int i=1;i<=n;i++) cout<<i<<" "<<fa[i][0]<<endl;
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		anss=0;
		int t=fd(x,y);
	//	cout<<t<<endl;
		if(y!=0) qan(x,y);
	//	cout<<anss<<endl;
		if(q<=10000) printf("%d\n",t+anss);
		else
		{
			za[i]=anss+t;
		}
	}
	if(q>10000)
	{
		anss=0;
		for(int i=1;i<=q;i++) anss^=i*za[i];
		printf("%d\n",anss);
	}
	
	return 0;
}
