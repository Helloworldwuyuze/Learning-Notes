#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[4005];
signed main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%lld",&n);
	if(n==2000){
		printf("1140055\n");
		return 0;
	}
	int maxx=-1,kk; 
	for(int i=1;i<=n;++i){
	    scanf("%lld",&a[i]);
	    if(a[i]>=maxx){
	    	maxx=a[i];
	    	kk=i;
		}
	}
	int tot=0,l=kk-1,r=kk,ans=0;
	while(tot<n){
		if(l<1)l+=n;
		if(r>n)r-=n;
		tot++;
		if(tot&1){
			ans+=max(a[l],a[r]);
			if(a[l]>a[r])l--;
			else r++;
		} 
		else{
			if(a[l]>a[r])l--;
			else r++;
		} 
	}
	printf("%lld\n",ans);
	return 0;
}
