
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
//using namespace std;
const int N = 3e5+10,M=5e5+10;
int n,a[N],m,b[N],c[N];
signed main(){
	infile("triangle.in");
	outfile("triangle.out");
	
	re(n);re(m);
	f(i,1,m){
		re(b[i]);re(c[i]);
		a[b[i]]++;a[c[i]]++;
	}
	ll ans=n*(n-1)*(n-2)/6,ans1=0,ans2=0,ans3=0;
//	wr(ans);_
	f(i,1,m){
		ans1+=n-1-a[c[i]]+n-1-a[b[i]];
	}
	ans1/=2;
	wr(ans-ans1);
	return 0;
}
