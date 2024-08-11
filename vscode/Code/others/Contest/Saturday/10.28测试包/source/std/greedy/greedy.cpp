#include<iostream>
#include<cstdio>
using namespace std;
const int N=305,M=90000;
int m,n;
int p[N][N][N],f[N][N]; 
int main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int w,l,r;
		scanf("%d%d%d",&w,&l,&r);
		for(int j=l;j<=r;j++)p[j][l][r]=w;
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i>0;i--){
			for(int j=k;j<=n;j++){
				p[k][i-1][j]=max(p[k][i-1][j],p[k][i][j]);
				p[k][i][j+1]=max(p[k][i][j+1],p[k][i][j]);
			}
		}
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if(j==i)f[i][j]=p[i][i][i];
			else for(int k=i;k<=j;k++){
				f[i][j]=max(f[i][j],f[i][k-1]+f[k+1][j]+p[k][i][j]);
			}
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}
