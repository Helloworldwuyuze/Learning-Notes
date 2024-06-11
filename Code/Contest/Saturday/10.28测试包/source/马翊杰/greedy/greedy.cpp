#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long ans;
int main()
{
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		long long a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		ans+=a;
	}
	printf("%d\n",ans);
	return 0;
}

