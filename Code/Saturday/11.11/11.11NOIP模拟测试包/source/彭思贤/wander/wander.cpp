#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define mod 98244353
#define inf 0x3f3f3f3f
#define N 125005
using namespace std;
int n,m;
int d[505];
double e[N],a[505][505];
vector<int> ve[505];
struct node{
	int x,y;
}edge[N];
void gauss(){
	for(int i=1;i<=n-1;i++){
		int mc=i;
		for(int j=i+1;j<=n-1;j++){
			if(fabs(a[j][i])>fabs(a[mc][i])){
				mc=j;
			}
		}
		if(mc!=i){
			for(int j=1;j<=n;j++){
				swap(a[i][j],a[mc][j]);
			}
		}
		if(!a[i][i]){
			return;
		}
		for(int j=n;j>=i;j--){
			a[i][j]/=a[i][i];
		}
		for(int j=1;j<=n-1;j++){
			if(j!=i){
				double t=a[j][i];
				for(int k=i+1;k<=n;k++){
					a[j][k]-=a[i][k]*t;
				}
			}
		}
	}
}
int main(){
	freopen("wander.in","r",stdin);
	freopen("wander.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&edge[i].x,&edge[i].y);
		ve[edge[i].x].push_back(edge[i].y);
		ve[edge[i].y].push_back(edge[i].x);
		d[edge[i].y]++;
		d[edge[i].x]++;	
	}
	for(int i=1;i<=n-1;i++){
		if(i==1){
			a[i][n]=1.0*(-1);
		}
		a[i][i]=1.0*(-1);
		for(int j=0;j<ve[i].size();j++){
			int v=ve[i][j];
			if(v==n){
				continue;
			}
			a[i][v]=1.0/(1.0*d[v]);
		}
	}
	gauss();
	for(int i=1;i<=m;i++){
		int X=edge[i].x;
		int Y=edge[i].y;
		e[i]=a[X][n]/d[X]+a[Y][n]/d[Y];
	}
	sort(e+1,e+m+1);
	double ans=0.0;
	for(int i=1;i<=m;i++){
		ans=ans+1.0*(m-i+1)*e[i];
	}
	cout<<fixed<<setprecision(3)<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
