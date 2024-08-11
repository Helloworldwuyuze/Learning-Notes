#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define il inline
#define M 25
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') {f=-1;} c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int K;
struct Matrix {
	int a[25][25];
	Matrix() {
		for(int i=0;i<25;i++) for(int j=0;j<25;j++) a[i][j]=0;
	}
};
int n,m,fail[M];
char s[25],t[100];
Matrix I,A;
int vis[10];
Matrix operator *(Matrix A,Matrix B) {
	Matrix Ans;
	for(int i=1;i<m;i++) {
		for(int j=1;j<m;j++) {
			for(int k=1;k<m;k++) Ans.a[i][j]=(Ans.a[i][j]+A.a[i][k]*B.a[k][j])%K;
		}
	}
	return Ans;
}
il Matrix qpow(Matrix A,int b) {
	Matrix Ans=I;
	while(b) {
		if(b&1) Ans=Ans*A;
		A=A*A;
		b>>=1;
	}
	return Ans;
}
int main() {
	freopen("gt.in","r",stdin);
	freopen("gt.out","w",stdout);
	n=read(),m=read(),K=read();
	scanf("%s",s+1);
	//scanf("%s",t+1);
	int p=0;
	for(int i=2;i<=m;i++) {
		while(p!=0&&s[p+1]!=s[i]) p=fail[p];
		if(s[p+1]==s[i]) p++;
		fail[i]=p;
	}
	//p=0;
	/*for(int i=1;i<=n;i++) {
		while(p!=0&&s[p+1]!=t[i]) p=fail[p];
		if(s[p+1]==t[i]) p++;
		if(p==m) cout<<i-m+1<<endl;
	}*/
	for(int i=1;i<=m;i++) I.a[i][i]=1;
	for(int i=0;i<=m-1;i++) {
		if(i==0) {
			A.a[i+1][1]=9,A.a[i+1][2]=1;
			continue;
		}
		for(int j=0;j<=9;j++) vis[j]=0;
		p=i;
		while(p!=0) {
			if(vis[s[p+1]-'0']==0) {
				vis[s[p+1]-'0']=1;
				A.a[i+1][p+2]=1;
			}
			p=fail[p];
		}
		if(!vis[s[1]-'0']) {
			vis[s[1]-'0']=1;
			A.a[i+1][2]=1;
		}
		int cnt=0;
		for(int j=0;j<=9;j++) if(!vis[j]) cnt++;
		A.a[i+1][1]=cnt;
	}
	A.a[m][1]=9;
	A=qpow(A,n-1);
	int ans=0;
	for(int i=1;i<=m;i++) ans=(ans+A.a[1][i])%K;
	cout<<ans<<endl;
	return 0;
}

