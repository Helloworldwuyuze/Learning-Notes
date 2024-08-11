#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,q,h[200005],l,r,t;
int main()
{
	freopen("zatopljenje.in","r",stdin);
	freopen("zatopljenje.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>h[i];
	while(q--)
	{
		cin>>l>>r>>t;
		int ans=0;
		for(int i=l;i<=r;i++)
		{
			if(h[i-1]<=t&&h[i]>t)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
