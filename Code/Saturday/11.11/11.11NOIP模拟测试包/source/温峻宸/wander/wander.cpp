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
//#define swap(x,y) (x)^=(y)^=(x)^=(y)
#define f(i,j,k) for(int i=(j),K=(k);i<=(K);i++)
#define uf(i,j,k) for(int i=(k),J=(j);i>=(J);i--)
#define mem(t, v) memset ((t) , v, sizeof(t))
#define rand(i,j) ((rnd()%((j)-(i)+1))+(i))

#define pi acos(-1)
#define md (1000000007)
#define eps (1e-8)
#define inf (0x3f3f3f3f)

//std::mt19937 rnd(time(0));
void re(int &x) {x = 0;char ch = getchar();int f = 1;while(!isdigit(ch)){if(ch == '-')f = -1;ch = getchar();}while(isdigit(ch)){x=(x<<1)+(x<<3)+ (ch^48); ch = getchar();}x *= f;}
void __write(ll arg){ll x = arg;if(x < 0) {putchar('-'); x =- x;}if(x > 9) {__write(x / 10);}putchar(x % 10 + '0');}
void wr(ll x,char p){__write(x);putchar(p);}
ll qpow(ll a,ll k) {ll s=1;for(;k;k>>=1,a=(ll)a*a%md)if(k&1)s=(ll)s*a%md;return s;}
using namespace std;
const int N = 1000+10,M=2e5+10;
int n,m,g[N][N],t,e[N][N],u,v,du[N],tot;
double a[N][N],b[N],c[2500010];
void gau(){
	f(i,1,n){
		int maxx=i;
		f(j,i+1,n)if(fabs(a[j][i])>fabs(a[maxx][i]))maxx=j;
		if(maxx!=i)f(j,1,n+1)swap(a[i][j],a[maxx][j]);
		double k=a[i][i];
		uf(j,i,n+1)a[i][j]/=k;
		

		
		f(j,1,n){
			if(i==j)continue;
			double k=a[j][i];
			f(q,1,n+1)a[j][q]-=k*a[i][q];
		}
		
		
		
		
	}
}
int main(){
	freopen("wander.in","r",stdin);
	freopen("wander.out","w",stdout);
	re(n);re(m);
	f(i,1,m)re(u),re(v),e[u][v]=e[v][u]=1,du[u]++,du[v]++; 
	f(i,1,n)a[i][i]=-1;
	a[1][n+1]=-1;
	
	f(i,1,n){
		f(j,1,n){
			if(i==n||j==n)continue ; 
			if(e[i][j])a[i][j]+=1.0/du[j];
		}
	}
	//puts("!");
	
	gau();/*
	f(tmc,1,n){
		f(hsg,1,n+1)printf("%.2f ",a[tmc][hsg]);
		puts("");
	}*/
	f(i,1,n)b[i]=a[i][n+1];
	b[n]=0;
	f(i,1,n){
		f(j,i+1,n){
			if(e[i][j])c[++tot]=b[i]/du[i]+b[j]/du[j];
		}
	}
	sort(c,c+1+m);
	double an=0;
	f(i,1,m)an+=1.0*(m-i+1)*c[i];
	//f(i,1,m)printf("%lf\n",c[i]);
	
	
	printf("%.3f ",an);
	return 0;
}


