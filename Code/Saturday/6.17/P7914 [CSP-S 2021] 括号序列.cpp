#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

const int N = 500 + 10;
const int M = 2e5 + 10;
const int MOD = 1e9 + 7;
#define int long long

int n,k,f[N][N][6];
char c[N];

/*
dp_l,r,0 ***
dp_l,r,1 (...)
dp_l,r,2 (...)***(...)***
dp_l,r,3 (...)***(...)***(...)
dp_l,r,4 ***(...)***(...)
dp_l,r,5 ***(...)***(...)***
*/

inline bool chk(int x,int y){
	return (c[x]=='('||c[x]=='?')&&(c[y]==')'||c[y]=='?');
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>k;
	cin>>c+1;
	for(int i=1;i<=n;++i)	f[i][i-1][0]=1;
	for(int len=1;len<=n;++len){
		for(int i=1;i+len-1<=n;++i){
			int j=i+len-1;
			if(len<=k)	f[i][j][0]=f[i][j-1][0]&&(c[j]=='*'||c[j]=='?');
			if(len>=2){
				if(chk(i,j))	f[i][j][1]=(f[i+1][j-1][0]+f[i+1][j-1][2]+f[i+1][j-1][3]+f[i+1][j-1][4])%MOD;
				for(int k=i;k<j;++k){
					f[i][j][2]=(f[i][j][2]+f[i][k][3]*f[k+1][j][0])%MOD;
    	            f[i][j][3]=(f[i][j][3]+(f[i][k][2]+f[i][k][3])*f[k+1][j][1])%MOD;
    	            f[i][j][4]=(f[i][j][4]+(f[i][k][4]+f[i][k][5])*f[k+1][j][1])%MOD;
    	            f[i][j][5]=(f[i][j][5]+f[i][k][4]*f[k+1][j][0])%MOD;
				}
			}
			f[i][j][3]=(f[i][j][3]+f[i][j][1])%MOD;
			f[i][j][5]=(f[i][j][5]+f[i][j][0])%MOD;
		}
	}
	cout<<f[1][n][3];
	return 0;
}

