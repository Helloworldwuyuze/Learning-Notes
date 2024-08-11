#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
#define N 200005
int n,k,sum[N][3],ans=0x3f3f3f3f;
char str[N];
vector<int> O;
int main(){
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	scanf("%d%d%s",&n,&k,str+1);
	int l=0,r=n-1;
	while(str[l]!='J')l++;
	while(str[r]!='I')r--;
	if(l>r){
		cout<<"-1\n";
		return 0;
	}
	for(int i=l;i<=r;i++){
		sum[i][0]=sum[i-1][0]+(str[i]=='J'?1:0);
		sum[i][1]=sum[i-1][1]+(str[i]=='O'?1:0);
		sum[i][2]=sum[i-1][2]+(str[i]=='I'?1:0);
		if(str[i]=='O')O.push_back(i);
	}
	int tmpj,tmpo,tmpoo,tmpi;
	for(auto i:O){
		if(sum[i][0]<2)continue;
		if(sum[r][2]-sum[i-1][2]<2)continue;
		int res,cntj=0,cnto=1,cnti=0;
		int JJ,OO,II;
		for(int j=i-1;j>=1;j--){
			if(str[j]=='J')cntj++,JJ=j;
			if(cntj==k)break;
		}
		if(cntj<k)continue;
		for(int j=i+1;j<=n;j++){
			if(str[j]=='O')cnto++,OO=j;
			if(cnto==k)break;
		}
		if(cnto<k)continue;
		for(int j=OO+1;j<=n;j++){
			if(str[j]=='I')cnti++,II=j;
			if(cnti==k)break;
		}
		if(cnti<k)continue;
		res=(i-JJ-k)+(OO-i-k+1)+(II-OO-k);
		ans=min(ans,res);
		if(res==ans)tmpj=JJ,tmpo=i,tmpoo=OO,tmpi=II;
	}
	printf("%d\n",ans);
	return 0;
}
