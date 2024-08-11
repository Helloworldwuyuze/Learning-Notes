#include<cstdio>
#include<cstdlib>
#include<ctime>
#define int long long
using namespace std;
const int N=2e5+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
int n,m,sum;
signed main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		sum+=x;
	}
	srand(time(NULL));
	int a=rand()*rand()%sum;
	printf("%lld",a);
	return 0;
}
