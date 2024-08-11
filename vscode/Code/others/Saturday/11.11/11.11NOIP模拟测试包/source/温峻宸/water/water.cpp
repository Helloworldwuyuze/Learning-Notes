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
#define mp std::make_pair
#define ll long long
#define ull unsigned long long
#define __ putchar('\n')
#define _ putchar(' ')
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl
#define CLOSE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

#define ft for(int i=(h[u]),v;(i);i=(nxt[i]),v=(to[i]))
#define min(i,j) ((i)<(j)?(i):(j))
#define max(i,j) ((i)>(j)?(i):(j))
#define swap(x,y) (x)^=(y)^=(x)^=(y)
#define f(i,j,k) for(int i=(j),K=(k);i<=(K);i++)
#define uf(i,j,k) for(int i=(k),J=(j);i>=(J);i--)
#define mem(t, v) memset ((t) , v, sizeof(t))
#define rand(i,j) ((rnd()%((j)-(i)+1))+(i))

#define pi acos(-1)
#define md (1000000007)
#define eps (1e-8)
#define inf (0x3f3f3f3f)

//std::mt19937 rnd(time(0));
void re(ll &x) {x = 0;char ch = getchar();int f = 1;while(!isdigit(ch)){if(ch == '-')f = -1;ch = getchar();}while(isdigit(ch)){x=(x<<1)+(x<<3)+ (ch^48); ch = getchar();}x *= f;}
void __write(ll arg){ll x = arg;if(x < 0) {putchar('-'); x =- x;}if(x > 9) {__write(x / 10);}putchar(x % 10 + '0');}
void wr(ll x,char p){__write(x);putchar(p);}
ll qpow(ll a,ll k) {ll s=1;for(;k;k>>=1,a=(ll)a*a%md)if(k&1)s=(ll)s*a%md;return s;}

const int N = 200+10,M=2e5+10;
ll n,m,a[N][N],s[N][N],b[N][N],t,vis[N][N],cnt[N][N];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
void dfs(int x,int y,int k){
	vis[x][y]=k;
	s[x][y]=1;
	f(i,0,3){
		int xx=fx[i]+x,yy=fy[i]+y;
		if(xx<1||xx>n||yy<1||yy>m){
			s[x][y]=-1;
			break;
		}
		if(b[xx][yy]==2)continue;
		if(b[xx][yy]==1&&vis[xx][yy]!=k)dfs(xx,yy,k);
		if(s[xx][yy]==-1){
			s[x][y]=-1;
			break;
		}
	}
	if(s[x][y]==-1)
	f(i,0,3){
		int xx=fx[i]+x,yy=fy[i]+y;
		s[xx][yy]=-1;
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
//	
	re(t);
	while(t--){
		re(n);re(m);
		int minn=0x3f3f3f3f,maxx=-1;
		f(i,1,n)f(j,1,m)re(a[i][j]),minn=min(minn,a[i][j]),maxx=max(maxx,a[i][j]);
		ll ans=0;
		f(k,minn,maxx){
			f(i,1,n)f(j,1,m)if(a[i][j]>=k)b[i][j]=2;else b[i][j]=1;
			f(i,1,n)f(j,1,m)if(vis[i][j]!=k&&b[i][j]==1)dfs(i,j,k);
			
			f(i,1,n)f(j,1,m)if(s[i][j]==1)ans++,cnt[i][j]++;//,printf("%d:%d %d\n",k,i,j);
		
		
		}
		
		wr(ans,'\n');
	}
	//
	return 0;
}

/*
1
5 10
391 156 171 58 347 296 9 201 469 83 
307 82 115 61 133 203 381 248 301 217 
381 292 404 436 496 147 426 178 441 61 
201 193 141 31 252 262 19 141 498 273 
338 252 23 393 62 340 262 450 348 313 

*/
