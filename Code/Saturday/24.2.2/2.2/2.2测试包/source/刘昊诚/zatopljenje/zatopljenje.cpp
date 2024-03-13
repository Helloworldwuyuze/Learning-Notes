#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int n,q,h[N];
struct queries{int l,r,x;}que[N];
int check()
{
	bool flag=true;
	for(int i=2;i<=n;i++)if(h[i]<h[i-1])flag=false;
	if(flag)return 1; 
	flag=true;
	for(int i=n-1;i>=1;i--)if(h[i]<h[i+1])flag=false;
	if(flag)return n;
	flag=true;
	vector<int> pos;
	for(int i=2;i<n;i++)if(h[i]<=h[i-1]&&h[i]<=h[i+1])pos.push_back(i);
	for(auto v:pos){
		for(int i=1;i<v;i++)if(h[i]<h[i+1])flag=false;
		for(int i=v+1;i<n;i++)if(h[i]>h[i+1])flag=false;
		if(flag)return v;
	}
	return -1;
}
int main()
{
	freopen("zatopljenje.in","r",stdin);
	freopen("zatopljenje.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=q;i++)cin>>que[i].l>>que[i].r>>que[i].x;
	if(check()!=-1)
	{
		int p=check();
		for(int l,r,x,i=1;i<=q;i++)
		{
			l=que[i].l,r=que[i].r,x=que[i].x;
			if(r<=p)cout<<(h[l]>x?1:0)<<"\n";
			else if(l>=p)cout<<(h[r]>x?1:0)<<"\n";
			else
			{
				if(h[l]>x&&h[r]<x)cout<<"1\n";
				else if(h[l]<x&&h[r]>x)cout<<"1\n";
				else if(h[l]<x&&h[r]<x)cout<<"0\n";
				else cout<<(h[p]<x?2:1)<<"\n";
			}
		}
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		bool ok=false;
		for(int j=que[i].l;j<=que[i].r;j++)
		{
			if(h[j]>que[i].x&&!ok)ok=true;
			if(h[j]<=que[i].x&&ok)ans++,ok=false;
		}
		if(ok)ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
/*
7 2
10 9 7 4 6 8 12
1 7 9
1 7 5
*/
