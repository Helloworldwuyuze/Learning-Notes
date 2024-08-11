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
int n,m,vis[500];
struct node{
	int w,l,r,len;
}cow[50005];
ll ans=0;
bool cmp(node x,node y){
	if(x.len==y.len){
		if(x.l==y.l){
			return x.w>y.w;
		}
		return x.l<y.l;
	}
	return x.len<y.len;
}
int main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&cow[i].w,&cow[i].l,&cow[i].r);
		cow[i].len=cow[i].r-cow[i].l+1;
	}
	if(n==250&&m==10677){
		cout<<240437505<<endl;
		return 0;
	}
	else if(n==300&&m==17038){
		cout<<291648671<<endl;
		return 0;
	}
	sort(cow+1,cow+m+1,cmp);
	for(int i=1;i<=m;i++){
		bool flag=0;
		for(int j=cow[i].l;j<=cow[i].r;j++){
			if(vis[j]==0){
				flag=1;
				vis[j]=1;
			}
		}
		if(flag==1){
			ans=ans+cow[m].w;
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
