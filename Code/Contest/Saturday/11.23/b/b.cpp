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
#define endl '\n'
#define int long long

int x,y,n,m,phi,a,b;

struct mat{
	int a[3][3];
	mat(){ memset(a,0,sizeof(a));}
}A;

void PHI(){
	int nn=m;
	phi=m;
	for(int i=2;i*i<=m;++i){
		bool flag=false;
		while(nn%i==0)	flag=true, nn/=i;
		if(flag)	phi=phi*(i-1)/i;
	}
	if(nn!=1)	phi=phi*(nn-1)/nn;
}

mat operator* (mat x,mat y){
	mat ans;
	for(int i=1;i<=2;++i)
		for(int j=1;j<=2;++j){
			for(int k=1;k<=2;++k)
				ans.a[i][j]=ans.a[i][j]+x.a[i][k]*y.a[k][j];
			ans.a[i][j]%=phi;
		}
	return ans;
}

mat ksm(mat x,int m){
	mat ans=x; m--;
	while(m>0){
		if(m&1)	ans=ans*x;
		x=x*x; m>>=1;
	}
	return ans;
}

int nksm(int x,int n){
	int ans=1;
	while(n){
		if(n&1)	ans=ans*x%m;
		x=x*x%m; n>>=1;
	}
	return ans;
}

void init(){
	PHI();
	A.a[2][2]=0; A.a[1][2]=A.a[2][1]=A.a[1][1]=1;
	A=ksm(A,n-3);
}

int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}

void solve(){
	int aa,bb;
	if(gcd(a,m)==1){
		aa=nksm(x,a%phi);
	}else if(a>=phi){
		aa=nksm(x,a%phi+phi);
	}else	aa=nksm(x,a);
	if(gcd(b,m)==1){
		bb=nksm(y,b%phi);
	}else if(b>=phi){
		bb=nksm(y,b%phi+phi);
	}else	bb=nksm(y,b);
	cout<<aa*bb%m<<endl;
}

signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
//	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>x>>y>>n; m=10; 
//	if(n==1)	cout<<x%m<<endl;
//	else if(n==2)	cout<<y%m<<endl;
//	else{
		init();
		b=A.a[1][1]+A.a[2][1], a=A.a[1][2]+A.a[2][2];
		solve();
//	}
	return 0;
}
//17 29 100000 1000000
