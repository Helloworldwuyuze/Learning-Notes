#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define ll long long
#define inf 0x3f3f3f3f
#define mod 998244353
#define N 200005
using namespace std;
int n,k,l,r;
char a[N];
struct node{
	int j,o,i;
}re[N],fr[N];
vector<int> vej,vei;
int main(){
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	scanf("%d %d",&n,&k);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		fr[i].j=fr[i-1].j;
		fr[i].o=fr[i-1].o;
		fr[i].i=fr[i-1].i;
		if(a[i]=='J'){
			fr[i].j++;
			vej.push_back(i);
		}
		if(a[i]=='O'){
			fr[i].o++;
		}
		if(a[i]=='I'){
			fr[i].i++;
		}
	}
	for(int i=n;i>=1;i--){
		re[i].j=re[i+1].j;
		re[i].o=re[i+1].o;
		re[i].i=re[i+1].i;
		if(a[i]=='J'){
			re[i].j++;
		}
		if(a[i]=='O'){
			re[i].o++;
		}
		if(a[i]=='I'){
			re[i].i++;
			vei.push_back(i);
		}
	}
	while(l<vej.size()&&r<vei.size()&&vej[l]<vei[r]){
		int x=vej[l+1];
		int y=vei[r+1];
		int lll=l;
		int rrr=r;
		if(re[x].o>=k&&re[x].i>=k&&re[x].o-re[vei[r]].o>=k){
			l++;
		}
		if(fr[y].o>=k&&fr[y].j>=k&&fr[y].o-fr[vej[l]].o>=k){
			r++;
		}
		if(lll==l&&rrr==r){
			break;
		}
	}
	if(vej[l]>=vei[r]||l+1<k||r+1<k){
		printf("-1\n");
	}
	else{
		int cnt=n-k*3;
		l=l-k+1;
		r=r-k+1;
		int x=vej[l];
		int y=vei[r];
		int sum=(x-1)+(n-y);
		printf("%d\n",cnt-sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
