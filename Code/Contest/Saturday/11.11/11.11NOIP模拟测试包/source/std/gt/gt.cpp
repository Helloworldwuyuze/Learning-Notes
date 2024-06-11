#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int M=25;
const int N=1e6;
char s[M];
int nxt[M];
int n,m,MD;
struct Matrix{
	int a[M][M];
}f,g;
Matrix operator *(Matrix A,Matrix B){
	Matrix C;
	memset(C.a,0,sizeof(C.a));
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			for(int k=0;k<m;k++)
				C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j]%MD)%MD;
	return C;
}
Matrix Fast(Matrix A,int n){
	Matrix S=A;
	n--;
	while(n){
		if(n&1)S=S*A;
		A=A*A;
		n=(n>>1);
	}
	return S;
}
void KMP(){
	nxt[1]=0;
	for(int i=2;i<=m;i++){
		int j=nxt[i-1];
		while(j>0&&s[i]!=s[j+1])j=nxt[j];
		if(s[i]==s[j+1])nxt[i]=j+1;
	}
	for(int i=0;i<m;i++)
		for(int j='0';j<='9';j++){
			int k=i;
			while(s[k+1]!=j&&k)k=nxt[k];
			if(s[k+1]==j)k++;
			g.a[i][k]++;
		}
}
int main(){
	freopen("gt.in","r",stdin);
	freopen("gt.out","w",stdout);
	scanf("%d%d%d",&n,&m,&MD);
	scanf("%s",s+1);
	KMP();
	f.a[0][0]=1;
	g=Fast(g,n);
	f=f*g;
	long long ans=0;
	for(int i=0;i<m;i++)ans=(ans+f.a[0][i])%MD;
	printf("%lld\n",ans);
	return 0;
}
