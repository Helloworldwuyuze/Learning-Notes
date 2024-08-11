#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1

#define pi acos(-1)
#define eps (1e-8)
#define int __int128

using namespace std;

const int INF = 123456789123456789;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n;
int a[N],b[N];

int gcd(int x,int y){ return y==0?x:gcd(y,x%y); }
void exgcd(int a,int b,int &x,int &y){
	if(b==0){ x=1, y=0; return ;}
	exgcd(b,a%b,x,y);
	int tmp=x;
	x=y, y=tmp-a/b*y;
}

void Print(int x,int y){
	DBG;
//	cout<<"x = "<<x<<" (mod "<<y<<" )"<<endl;
}

void write(int x){
	if(x<0)	putchar('-'), write(-x);
	if(x>=10)	write(x/10);
	putchar(x%10+'0');
}
void read(int &x){
	int f=1; x=0;
	char c=getchar();
	while(c<'0'||c>'9')	f=(f==-1|c=='-')?-1:1, c=getchar();
	while(c>='0'&&c<='9')	x=x*10+c-'0', c=getchar();
	x=x*f;
}

int EXCRT(){
	int u=a[1], v=b[1], x, y;
	for(int i=2;i<=n;++i){
//		Print(v,u);
		int d=gcd(u,a[i]), lcm=u*a[i]/d;
		exgcd(u/d,a[i]/d,x,y);
		x=(x%(a[i]/d)+a[i]/d)%(a[i]/d);
		v=((v+(b[i]-v)/d*u%lcm*x%lcm)%lcm+lcm)%lcm; u=u*a[i]/d;
//		write(u), putchar(' '); write(v); putchar('\n');
	}
//	Print(v,u);
	return (v%u+u)%u;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    read(n);
    for(int i=1;i<=n;++i)	read(b[i]), read(a[i]);
    write(EXCRT());
    return 0;
}
