#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n;
int a[N];
int co[N],c;
int main()
{
	freopen("kuglice.in","r",stdin);
	freopen("kuglice.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(co[a[i]]==0) c++;
		co[a[i]]++;
	}
	int k=(c+1)/2;
	printf("%d:%d\n",k,c-k); 
	return 0;
}
 

