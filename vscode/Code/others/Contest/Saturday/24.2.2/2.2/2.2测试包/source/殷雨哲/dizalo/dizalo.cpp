#include<cstdio>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
int down[100005],a[100005];
long long ans=0;
stack<int>st;
int main()
{
	freopen("dizalo.in","r",stdin);
	freopen("dizalo.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>0;i--)st.push(a[i]);
	for(int i=1;i<=n;i++)
	{
		int lin[100005]={0},pos=0;
		while(st.top()!=i)
		{
			lin[pos]=st.top();
			st.pop();
			down[lin[pos]]++;
			pos++;
		}
		st.pop();
		down[i]++;
		sort(lin,lin+pos);
		for(int j=pos-1;j>=0;j--)
		{
			st.push(lin[j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans+=down[i];
	}
	cout<<ans<<" ";
	while(q--)
	{
		int x;
		cin>>x;
		ans-=down[a[x]];
		for(int i=1;i<x;i++)
		{
			if(a[i]>a[x]&&down[a[i]]!=0)
			{
				ans-=down[a[x]];
				down[a[i]]-=down[a[x]];
			}
		}
		down[a[x]]=0;
		cout<<ans<<" ";
	}
	return 0;
}
