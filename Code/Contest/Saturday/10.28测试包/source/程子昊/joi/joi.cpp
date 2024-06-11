#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],J[200005],O[200005],I[200005],cnt=0,cntj=0,cnto=0,cnti=0;
char x;
int ans=0x3f3f3f3f;
int main(){
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	scanf("%d%d",&n,&k);
	x=getchar();
	while(x!='J'&&x!='O'&&x!='I')x=getchar();
	while((x=='J'||x=='O'||x=='I')&&cnt<n){
		++cnt;
		if(x=='J')J[++cntj]=cnt;
		if(x=='O')O[++cnto]=cnt;
		if(x=='I')I[++cnti]=cnt;
		x=getchar();
	}
	int zz=0,za=0,flj=0,flo=0;
	for(int i=1;i<=cntj+1-k;++i){
		zz=1;
		flj=0,flo=0;
		while(O[zz]<J[i+k-1]){
			if(zz>=cnto-k+1){
				flj=1;
				break;
			}
			++zz;
		}
		if(flj)break;
		za=1;
		while(I[za]<O[zz+k-1]){
			if(za>=cnti-k+1){
				flo=1;
				break;
			}
			++za;
		}
		if(flo)break;
		ans=min(ans,I[za+k-1]-J[i]+1-3*k);
		if(ans==0)break;
	}
	if((flj||flo)&&ans==0x3f3f3f3f)printf("-1");
	else printf("%d",ans);
	return 0;
}
