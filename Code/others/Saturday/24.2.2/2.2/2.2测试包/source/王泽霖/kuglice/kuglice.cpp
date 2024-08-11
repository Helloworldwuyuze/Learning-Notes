#include<iostream>
#include<cstdio>
using namespace std;
int a[3005];
int dp[305][305][2];
int main(){
	freopen("kuglice.in","r",stdin);
	freopen("kuglice.out","w",stdout);
	int n,c=0,cc=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]),c+=(a[i]<=2),cc+=(a[i]<=20);
	if(c==n){
		if(a[1]!=a[n]){
			printf("1:1");
			return 0;
		}
		int id1=1,id2=n;
		while(a[id1]==a[1])id1++;
		while(a[id2]==a[n])id2--;
		int x=id1-1+n-id2;
		if((x&1)==0)printf("1:1");
		else printf("2:0");
	} 
	return 0;
}
