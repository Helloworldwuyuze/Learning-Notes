#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[20005],n,m,l[20005],r[20005];
int chuan[20005];
long long ans=0;
int fla=0;
signed main(){
	freopen("intervals.in","r",stdin);
	freopen("intervals.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%lld%lld%lld",&l[i],&r[i],&a[i]);
		if(a[i]>0)fla=1;
	}
	if(fla==0){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=m;++i)
		for(int j=l[i];j<=r[i];++j)chuan[j]+=a[i];
//		for(int i=1;i<=m;++i)cout<<chuan[i]<<" ";
	for(int i=1;i<=m;++i)
		if(chuan[i]>=0){
			int maxx=0,zuobiao=0;
			for(int j=l[i];j<=r[i];++j){
				if(maxx<chuan[j]){
					zuobiao=j;
					maxx=chuan[j];
				}
			}
			if(maxx==0&&zuobiao==0)continue;
			for(int j=1;j<=m;++j){
				if(l[j]<=zuobiao&&r[j]>=zuobiao){
					ans+=a[j];
					for(int k=l[j];k<=r[j];++k)chuan[k]-=a[i];
				}
			}
		}
		printf("%lld\n",ans);
	return 0;
} 
