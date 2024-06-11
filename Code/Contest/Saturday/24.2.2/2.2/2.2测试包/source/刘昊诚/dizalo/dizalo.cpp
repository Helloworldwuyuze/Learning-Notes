#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
const int N=1e5+10;
int n,q,a[N],ans[N],tot,p[N],c[N],arr[N];
bool del[N];
signed main()
{
	ios::sync_with_stdio(false);
	freopen("dizalo.in","r",stdin);
	freopen("dizalo.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i],p[a[i]]=i;
	int lastpos=p[1],res=p[1],cnt=1;
	for(int i=2;i<=n;i++)
	{
		if(p[i]<lastpos)res++,cnt++,c[i]=1;
		else res+=p[i]-cnt,lastpos=p[i],cnt++,c[i]=p[i]-cnt;
	}
	ans[++tot]=res;
	for(int i=1;i<=q;i++)
	{
		int x,ttot=0;cin>>x;
		for(int i=1;i<=n;i++)if(i!=x)arr[++ttot]=a[i];
		for(int i=1;i<=ttot;i++)if(arr[i]>a[x])arr[i]--;
		n=ttot;
		for(int i=1;i<=n;i++)a[i]=arr[i],p[a[i]]=i;
		lastpos=p[1],res=p[1],cnt=1;
		for(int i=2;i<=n;i++)
		{
			if(p[i]<lastpos)res++,cnt++;
			else res+=p[i]-cnt,lastpos=p[i],cnt++;
		}
		ans[++tot]=res;
	}
	for(int i=1;i<=tot;i++)cout<<ans[i]<<" ";
	return 0;
}
/*
5 2 
3 4 1 2 5 
3 2
*/
