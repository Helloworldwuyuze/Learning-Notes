#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

const int N = 80 + 10;
const int M = 2e5 + 10;

int n,m;
int a[N];
__int128 p[N];
__int128 ans;
__int128 f[N][N];

__int128 read(){
	__int128 x=0;
	int f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')	f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}

void write(__int128 x){
	if(x>9)	write(x/10);
	putchar(x%10+48);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<N;++i)	p[i]=p[i-1]*2;
	while(n--){
		for(int k=1;k<=m;++k)	cin>>a[k];
		memset(f,0,sizeof(f));
		for(int len=m-1;len>=0;--len){
			for(int i=1;i+len-1<=m;++i){
				int j=i+len-1;
				f[i][j]=max(f[i-1][j]+a[i-1]*p[m-len],f[i][j+1]+a[j+1]*p[m-len]);
			}
		}
		__int128 maxx=0;
		for(int i=1;i<=m+1;++i)	maxx=max(maxx,f[i][i-1]);
		ans+=maxx;
//		for(int len=m-1;len>=0;len--){
//			for(int i=1;i+len-1<=m;++i){
//				cout<<i<<" "<<i+len-1<<":";
//				write(f[i][i+len-1]);
//				putchar('\n');
//			}
//			putchar('\n');
//		}
	}
	write(ans);
	return 0;
}

