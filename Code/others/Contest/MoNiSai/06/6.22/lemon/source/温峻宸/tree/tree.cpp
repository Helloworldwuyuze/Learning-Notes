#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#include<queue>
#include<stack>
#include<map>
#include<set>
#include<deque>
#include<vector>
#include<bitset>

#include<cassert>
#include<cstdlib>
#include<complex>
#include<ctime>

#define p1(x) wr(x,' ')
#define p2(x,y) wr(x,' '),wr(y,'\n')
#define p3(x,y,z) wr(x,' '),wr(y,' '),wr(z,'\n')
#define p4(x,y,z,i) wr(x,' '),wr(y,' '),wr(z,' '),wr(i,'\n')
#define p5(x,y,z,i,j) wr(x,' '),wr(y,' '),wr(z,' '),wr(i,' '),wr(j,'\n')
#define pf(x) printf("%f\n",x)
#define pa(a,nn,n) {for(int ____=(nn),___=(n);____<=___;____++)wr(a[____]);puts("");}
#define paa(a,nn,mm,n,m) {for(int ____=(nn),______=(mm),_______=(n),________=(m);____<=_______;____++){for(int _____=______;_____<=________;_____++)wr(a[____][_____]);puts("");}}
#define cout std::cout
#define _ putchar('\n');
#define __ putchar(' ');

#define fi first
#define se second
#define pb push_back
#define pt putchar
#define mk std::make_pair
#define pii std::pair<int,int>
#define db double
#define ll long long
#define ull unsigned long long
#define DBG printf("DBG! line:%d func:%s\n",__LINE__,__FUNCTION__);
#define CLOSE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define infile(x)  freopen(x,"r",stdin);
#define outfile(x) freopen(x,"w",stdout);


#define ft for(int i=(h[u]),v=(to[i]);(i);i=(nxt[i]),v=(to[i]))
#define min(i,j) (std::min((i),(j)))
#define cmin(i,j) (i)=min((i),(j))
#define max(i,j) (std::max((i),(j)))
#define cmax(i,j) (i)=max((i),(j))
#define swap(x,y) (std::swap(x,y))
#define f(i,j,k) for(register int i=(j),K=(k);i<=(K);i++)
#define F(i,j,k,l) for(register int i=(j);k;l)
#define uf(i,j,k) for(register int i=(k),J=(j);i>=(J);i--)
#define mem(t,v) memset((t),v,sizeof(t))
#define rand(i,j) ((rnd()%((j)-(i)+1))+(i))
#define int ll
#define md (1000000007)
#define eps (1e-8)
#define inf (0x3f3f3f3f)
void pc(char *s) {for(int i=1,j=(strlen(s+1));i<=(j);i++)putchar(s[i]);puts("");}
int rea(char *s){int tot=1;char ch = getchar();while(ch==' '||ch=='\n'||ch==0)ch=getchar();while(ch!=' '&&ch!='\n'&&ch!=0){s[tot++]=ch;ch=getchar();}return tot-1;}
void re(int &x){x=0;bool f=0;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=1;ch=getchar();}while(ch>=48&&ch<=57){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}if(f)x=-x;return ;}int nu[30];
void wr(ll x,char p=' '){register int tot=1;if(x<0)putchar('-'),x=-x;nu[1]=x%10;x=x/10;for(;x;x=x/10)nu[++tot]=x%10;for(;tot;--tot)putchar(nu[tot]+'0');putchar(p);return ;}
ll qpow(ll a,ll k) {ll s=1;for(;k;k>>=1,a=a*a%md)if(k&1)s=s*a%md;return s;}
using namespace std;
const int N = 1e6+10,M=5e5+10;
int h[N],to[N<<1],nxt[N<<1],tot;
void add(int u,int v){
	to[++tot]=v;
	nxt[tot]=h[u];
	h[u]=tot;
}
int fa[N][22],het[N],son[N];
void dfsa(int u,int fu){
	fa[u][0]=fu;
	ft if(v!=fu){
		dfsa(v,u);
		if(het[v]>het[son[u]])son[u]=v;
	}
	het[u]=het[son[u]]+1;
}
int fat(int u,int k){
	uf(i,0,20)if(k>=(1<<i))k-=(1<<i),u=fa[u][i];
	return u;
}
vector<pii> q[N];
int n,m,a[N],ans[N<<1];
vector<int> dp[N];
void dfsb(int u){
	if(son[u]){
		dfsb(son[u]);
		swap(dp[son[u]],dp[u]);
	}
	dp[u].pb(a[u]);
	ft if(v!=fa[u][0]&&v!=son[u]){
		dfsb(v);
		int cnt=0;
		uf(j,0,dp[v].size()-1){
			cnt++;
			dp[u][het[u]-cnt-1]+=dp[v][j];
		}
	}
	f(i,0,q[u].size()-1){
		if(q[u][i].fi<=het[u]-1)ans[q[u][i].se]+=dp[u][het[u]-q[u][i].fi-1];
//		if(q[u][i].se==1||q[u][i].se==1+n)p3(q[u][i].se,u,q[u][i].fi);
	}
}
signed main(){
	infile("tree.in");
	outfile("tree.out");
	
	re(n);re(m);
	f(i,1,n)re(a[i]);
	f(i,2,n){
		int u,v;re(u);re(v);
		add(u,v);add(v,u);
	}
	dfsa(1,0);
	f(j,1,20)f(i,1,n)
		fa[i][j]=fa[fa[i][j-1]][j-1];
	f(i,1,m){
		int u,k;
		re(u);re(k);
		q[u].pb(mk(k,i));k--;
		while(k!=-1&&fa[u][0]){
			if(k!=0)q[u].pb(mk(k-1,i+m));
			q[fa[u][0]].pb(mk(k,i));
			k--;u=fa[u][0];
		}
		
//		q[u].pb(mk(k,i));
//		q[fa[u][0]].pb(mk(k-1,i));
//		if(i==1)p4(u,k,het[u],fa[u][4]);
//		if(k!=0)ans[i]+=a[fat(u,k)];
	}
	dfsb(1);
	if(m<=10000)
		f(i,1,m)wr(ans[i]-ans[i+m],'\n');
	else{
		ll res=0;
		f(i,1,m)res^=(ans[i]-ans[i+m])*i;
		wr(res);
	}
	return 0;
}
/*
4 4
1 2 3 4
1 2
1 3
1 4
1 0
1 1
2 1
4 100

*/
