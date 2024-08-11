#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,a[N],vis[N],sum=0,maxx=0;
int main(){
	freopen("meximum.in","r",stdin);
	freopen("meximum.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),maxx=max(maxx,a[i]);
	for(int i=1;i<=n;i++){
		ll k=0;
		for(int j=0;j<=maxx;j++) vis[j]=0;
		for(int j=i;j<=n;j++){
			vis[a[j]]++;
			while(vis[k]) k++;
			sum+=k;
		}
	}
	printf("%lld\n",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4
1 2 3 4
1 2
1 3
1 4
1 0
1 1
2 1
4 100
*/
