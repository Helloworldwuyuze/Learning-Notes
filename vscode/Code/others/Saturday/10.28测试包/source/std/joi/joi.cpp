#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,k,jc,oc,ic,jj[N],oo[N],ii[N];
char c[N];
int main(){
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>c+1;
	for(int i=1;i<=n;i++){
		if(c[i]=='J')jj[++jc]=i;
		if(c[i]=='O')oo[++oc]=i;
		if(c[i]=='I')ii[++ic]=i;
	}
	int ans=200005; 
	int i2=1,i3=1;
	for(int i1=k;i1<=jc;i1++){
		while(oo[i2]<jj[i1]&&i2<=oc-k)i2++;
		while(ii[i3]<oo[i2+k-1]&&i3<=ic-k)i3++;
		if(oo[i2]<jj[i1]||ii[i3]<oo[i2+k-1])break;
		if(i3+k-1<=ic)ans=min(ans,ii[i3+k-1]-jj[i1-k+1]-(3*k-1));
	}
	if(ans==200005)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
