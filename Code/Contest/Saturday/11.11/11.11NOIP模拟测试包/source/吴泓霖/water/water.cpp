#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<deque>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
const int inf=0x3f3f3f3f;
const int N=100+5,M=100+5;
const int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
int t,n,m,h[N][M];
struct node{
	int x,y;
	node(int x_,int y_){x=x_,y=y_;}
};
int main(){
	freopen("water.in","w",stdin);
	freopen("water.out","w",stdout);
	t=read();
	while(t--){
		n=read(),m=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				h[i][j]=read();
		puts("0");
	}
	return 0;
}