#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>

using namespace std;

const int N = 1e2 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;

int n,s,m,k;
int a[N],b[N];

struct Matrix{
	int a[N][N];
	int l,h;
}A,B,C,D;

void init(Matrix &x){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			x.a[i][j]=0;
}

void print(Matrix x){
	cout<<x.l<<" "<<x.h<<endl;
	for(int i=1;i<=n;++i,cout<<endl)
		for(int j=1;j<=n;++j)
			cout<<x.a[i][j]<<" ";
}

Matrix operator* (Matrix x,Matrix y){
	Matrix ans;
	ans.h=ans.l=n;
//	init(ans);
	memset(ans.a,0,sizeof(ans.a));
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				ans.a[i][j]+=x.a[i][k]*y.a[k][j];
			}
		}
	}
	return ans;
}

Matrix ksm(Matrix x,int m){
	Matrix ans;
//	m--;;
	init(ans);
	ans.h=ans.l=n;
	for(int i=1;i<=n;++i)
		ans.a[i][i]=1;
	while(m){
		if(m&1)	ans=ans*x;
//		print(ans);
		x=x*x; m>>=1;
	}
	return ans;
} 

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>s>>k;
	for(int i=1;i<=n;++i)	cin>>a[i];
	A.l=n; A.h=1;
	for(int i=1;i<=n;++i)	A.a[1][i]=a[i];
	for(int i=1;i<=n;++i)
		if(i!=s&&i!=m)	B.a[i][i]=1;
	B.l=B.h=n; B.a[s][m]=B.a[m][s]=1;
	for(int i=2;i<=n;++i)	C.a[i][i-1]=1;
	C.a[1][n]=1; C.h=C.l=n;
	D=B*C;
//	print(B), print(C);
//	print(D);
	D=ksm(D,k);
//	print(D);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			b[i]+=a[j]*D.a[j][i];
	for(int i=1;i<=n;++i)	cout<<b[i]<<" ";
	return 0;
}
