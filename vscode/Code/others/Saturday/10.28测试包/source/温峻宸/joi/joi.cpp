#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
const int N=2e5+5,M=2e5+5;
int n,m,k,a[N],b[N],c[N],ans;
char s[N];
using namespace std;
int main(){
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='J')a[i]++;
		else if(s[i]=='O')b[i]++;
		else if(s[i]=='I')c[i]++;
		a[i]+=a[i-1];b[i]+=b[i-1];c[i]+=c[i-1];
		//printf("%d\n",i);
	}
	ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(s[i]!='O')continue;
		if(b[n]-b[i-1]<k)continue;
		if(a[i-1]<k)continue;
		//printf("%d \n",i);
		int x=lower_bound(b+i+1,b+1+n,k+b[i-1])-(b);
		if(c[n]-c[x-1]<k)continue;
		int e=lower_bound(c+x+2,c+1+n,k+c[x-1])-(c);
		int l=0,r=i-1,d=0;
		//printf("%d %d %d %d\n",d,i,x,e);
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i-1]-a[mid-1]>=k)l=mid+1;
			else r=mid-1;
			//if(i==5)printf("%d %d %d %d \n",l,mid,r,a[mid-1]);
		}
		d=l;
		//
		if(d==0)continue;
		if(a[i-1]-a[d-1]!=k)d--; 
		ans=min(ans,(e-d+1));
		//if((e-d+1)==133267+3*k)
		
	}
	printf("%d\n",ans==0x3f3f3f3f?-1:ans-3*k);
	return 0;
}

