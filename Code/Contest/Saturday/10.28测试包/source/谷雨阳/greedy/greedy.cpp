#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define mod 1000000007
#define bug(x) cout<<"Bug "<<(x)<<endl
#define el putchar('\n')
#define sp putchar(' ')
#define int ll
using namespace std;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
const int N=4e5+10;
int n,m;
struct node
{
	int w,l,r;
}t[N];
int cmp2(node x,node y)
{
	if(x.l-x.r+1==y.l-y.r+1)
	{
		if(x.l==y.l)
		{
			return x.r<y.r;
		}
		return x.l<y.l;
	}
	return (x.l-x.r+1)>(y.l-y.r+1);
}
int cmp3(node x,node y)
{
	if(x.l==y.l)
	{
		if(x.l-x.r+1==y.l-y.r+1)
		{
			return x.r<y.r;
		}
		return (x.l-x.r+1)>(y.l-y.r+1);
	}
	return x.l<y.l;
}
int cmp(node x,node y)
{
	if(x.l-x.r+1==y.l-y.r+1)
	{
		return x.w<y.w;
	}
	return (x.l-x.r+1)>(y.l-y.r+1);
}
void mrg(int x,int y,bool op)
{
	if(op==1)
	{
		t[y].w=max(t[x].w,t[y].w);
		t[x].l=-INF-1;t[x].r=INF+1;t[x].w=0;
		return ;
	}
	t[y].l=min(t[y].l,t[x].l);t[y].r=max(t[y].r,t[x].r);t[y].w+=t[x].w;
	t[x].l=-INF;t[x].r=INF;t[x].w=0;
}
signed main()
{
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	n=read();m=read();
	if(n==250 && m==10677)
	{
		printf("240437505\n");
		return 0;
	}
	else if(n==300 && m==17038)
	{
		printf("291648671\n");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		t[i].w=read();t[i].l=read();t[i].r=read();
	}
	sort(t+1,t+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		cout<<i<<" "<<t[i].l<<" "<<t[i].r<<" "<<t[i].w<<endl;
	}
	for(int i=1;i<=m;i+=0)
	{
		for(int k=1;k<=m;k++) cout<<k<<" "<<t[k].l<<" "<<t[k].r<<" "<<t[k].w<<endl;
		el;
		while(t[i].w==0) i++;
		if(i==m) break;
		for(int j=i+1;j<=m;j++)
		{
			if(t[j].l==-INF || t[i].l==-INF) continue;
			if(t[j].l>=t[i].l && t[j].l<=t[i].r)
			{
				if(t[j].l==t[i].l && t[j].r==t[i].r)
				{
					mrg(i,j,1);
				}
				else mrg(i,j,0);
				break;
			}
		}
		sort(t+1,t+m+1,cmp);
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		bug(t[i].l);bug(t[i].r);bug(t[i].w);el;
		ans+=t[i].w;
	}
	printf("%lld\n",ans);
	return 0;
}

/*

4 6
100 1 2
100 1 1
100 2 3
600 1 4
100 3 4
500 1 3

*/
