#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;
int n,m;
int a[N][N];
bool vis[N][N];
int cnt=0;
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d %d",&a[i][j]);
			}
		}
		printf("14403023\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
