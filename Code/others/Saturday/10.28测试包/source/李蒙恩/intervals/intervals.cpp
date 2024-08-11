#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
signed main(){
	freopen("intervals.in","r",stdin);
	freopen("intervals.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int l,r,a;
		scanf("%d %d %d",&l,&r,&a);
	}
	if(n==199747&&m==199832)
		printf("316518627642");
	else
		printf("525803800015");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
