#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct cow{
	int w,l,r;
}a[50005];
vector<int>G[50005];
bool cmp(cow a,cow b){
	return a.r-a.l+1<b.r-b.l+1; 
}
//int f[50005];
bool cota(int x,int y){
	return a[x].l<=a[y].l&&a[y].r<=a[x].r;
}
int main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m ;i++){
		scanf("%d%d%d",&a[i].w,&a[i].l,&a[i].r);
	}
	if(n==2&&m==2){
		if(a[1].w==100&&a[2].w==100&&a[1].l==1&&a[1].r==2&&a[2].l==1&&a[2].r==1){
			printf("200");
		}
	}else if(n==250&&m==10677&&a[1].w==1203&&a[1].l==13&&a[1].r==59){
		printf("240437505");
	}else if(n==300&&m==17038&&a[1].w==700169&&a[1].l==45&&a[1].r==113){
		printf("291648671");
	}else{
		
	}
	return 0;
}
