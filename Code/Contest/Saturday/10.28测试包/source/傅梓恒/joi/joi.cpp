#include<cstdio>
#include<iostream>
using namespace std;
const int N=2e5+100;
int n,k;
char c[N];
int c1,c2,c3;
int cj[N],co[N],ci[N];
int sj[N],si[N];
int fj[N],fi[N];
int main(){
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",c+1);
	for(int i=1;i<=n;i++){
		sj[i]=sj[i-1];
		si[i]=si[i-1];
		if(c[i]=='J'){
			cj[++c1]=i;
			sj[i]++;
			fj[sj[i]]=i;
		}
		if(c[i]=='O'){
			co[++c2]=i;
		}
		if(c[i]=='I'){
			ci[++c3]=i;
			si[i]++;
			fi[si[i]]=i;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<sj[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<si[i]<<" ";
//	}
//	cout<<endl;
	int ans=0x3f3f3f3f;
	for(int i=k;i<=c2;i++){
		int j=i-k+1;
		//cout<<j<<" "<<i<<" "<<co[j]<<" "<<co[i]<<endl;
		if(sj[co[j]]>=k&&si[n]-si[co[i]]>=k){
			int k1=fj[sj[co[j]]-k+1];
			int k2=fi[si[co[i]]+k];
			//cout<<k1<<" "<<k2<<endl; 
			ans=min(ans,k2-k1+1-3*k);
		}
	}
	if(ans==0x3f3f3f3f) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
