#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>

using namespace std;

const int N = 3e2 + 10;
const int M = 1e5 + 10;
const int INF = 1e9;
const int MOD = 998244353;
#define int long long
int n,m,A,B,C,D,E,F,ans;
int x[M],y[M];
map<int,bool> ma;
int f[N][N][N];

int get_num(int x,int y){
	return x*INF+y;
}
pair<int,int> get_coor(int a,int b,int c){
	return make_pair(a*A+b*C+c*E,a*B+b*D+c*F);
} 

signed main(){
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>A>>B>>C>>D>>E>>F;
	for(int i=1;i<=m;++i){
		cin>>x[i]>>y[i];
		ma[get_num(x[i],y[i])]=true;
	}
	f[0][0][0]=1;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			for(int k=0;k<=n;++k){
				if(i==0&&j==0&&k==0||i+j+k>n)	continue;
				pair<int,int> coor=get_coor(i,j,k);
				if(ma[get_num(coor.first,coor.second)])	continue;
				if(i>0)	f[i][j][k]=(f[i][j][k]+f[i-1][j][k])%MOD;
				if(j>0)	f[i][j][k]=(f[i][j][k]+f[i][j-1][k])%MOD;
				if(k>0)	f[i][j][k]=(f[i][j][k]+f[i][j][k-1])%MOD;
				if(i+j+k==n)	ans=(ans+f[i][j][k])%MOD;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}


