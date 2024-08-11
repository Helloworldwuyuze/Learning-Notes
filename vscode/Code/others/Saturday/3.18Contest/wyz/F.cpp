#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>

using namespace std;

const int N = 3000 + 10;
const int MOD = 1e9;
typedef pair<int,int> PII;
int n,m;
char a[N][N];

struct bigint{
	int len;
	int a[2];
	void init(int l,int A){
		len=l;
		a[len]=A;
		memset(a,0,sizeof(a));
	}
	void writee(){
		printf("%d",a[len]);
		for(int j=len-1;j;--j){
			printf("%09d",a[j]);
		}
	}
}f[N][N],cnt[N<<1][26];

bigint operator +(bigint a,bigint b){
	bigint c;
	c.len=max(a.len,b.len);
	int F=0,maxlen=c.len;
	for(int i=1;i<=maxlen;++i){
		c.a[i]=a.a[i]+b.a[i]+F;
		F=c.a[i]/MOD, c.a[i]%=MOD;
	}
	if(F)	c.len++, c.a[c.len]=1;
	return c;	
}

bigint maxx(bigint a,bigint b){
	if(a.len!=b.len)	return a.len>b.len?a:b;
	for(int i=a.len;i;--i){
		if(a.a[i]!=b.a[i])	return a.a[i]>b.a[i]?a:b;
	}
	return a;
}

signed main(){
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
//	bigint x,y;
//	x.len=1;
//	y.len=1;
//	x.a[1]=999999999;
//	x.a[2]=12;
//	y.a[1]=1;
//	y.a[2]=99;
//	bigint z=x+y;
//	z.writee();
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	f[1][1].a[1]=1;
	f[1][1].len=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(i==1&&j==1)	continue;
			if(a[i-1][j]==a[i][j-1])	f[i][j]=f[i-1][j]+f[i][j-1];
			else	f[i][j]=maxx(f[i-1][j],f[i][j-1]);
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j){
//			f[i][j].writee();
//			cout<<" ";
//		}
//		cout<<endl;
//	}
//	for(int i=1;i<=n+m-1;++i){
//		for(int j=0;j<26;++j){
//			cnt[i][j].init(1,0);
//		}
//	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cnt[i+j-1][a[i][j]-'a']=maxx(cnt[i+j-1][a[i][j]-'a'],f[i][j]);
		}
	}
//	for(int i=0;i<26;++i){
//		cout<<char(i+'a')<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n+m-1;++i){
//		for(int j=0;j<26;++j){
//			cnt[i][j].writee();
//			cout<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<cnt[n+m-1][a[n][m]-'a']<<endl;
	int l=cnt[n+m-1][a[n][m]-'a'].len;
	if(l>1||cnt[n+m-1][a[n][m]-'a'].a[l]>=3)	cout<<"YES";
	else	cout<<"NO";
	return 0;
}
