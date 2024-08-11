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
#define md (19260817)
#define eps (1e-8)
#define inf (0x3f3f3f3f)
void pc(char *s) {for(int i=1,j=(strlen(s+1));i<=(j);i++)putchar(s[i]);puts("");}
int rea(char *s){int tot=1;char ch = getchar();while(ch==' '||ch=='\n'||ch==0)ch=getchar();while(ch!=' '&&ch!='\n'&&ch!=0){s[tot++]=ch;ch=getchar();}return tot-1;}
void re(int &x){x=0;bool f=0;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=1;ch=getchar();}while(ch>=48&&ch<=57){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}if(f)x=-x;return ;}int nu[30];
void wr(ll x,char p=' '){register int tot=1;if(x<0)putchar('-'),x=-x;nu[1]=x%10;x=x/10;for(;x;x=x/10)nu[++tot]=x%10;for(;tot;--tot)putchar(nu[tot]+'0');putchar(p);return ;}
ll qpow(ll a,ll k) {ll s=1;for(;k;k>>=1,a=a*a%md)if(k&1)s=s*a%md;return s;}
//using namespace std;
const int N = 1e5+10,M=1e5;
struct node{
	#define ls (p<<1)
	#define rs (p<<1|1)
	#define mid ((l+r)>>1)
	#define lp L,R,ls,l,mid
	#define rp L,R,rs,mid+1,r
	int tr[(M<<2)+10],tag[(M<<2)+10];
	void pushdown(int p,int l,int r){
		
		int v=tag[p];
		tr[ls]=(tr[ls]+v*(mid-l+1))%md;
		tr[rs]=(tr[rs]+v*(r-mid))%md;
		tag[ls]=(tag[ls]+v)%md;
		tag[rs]=(tag[rs]+v)%md;
		tag[p]=0;
	}
	void upd(int v,int L,int R,int p=1,int l=1,int r=M){
		if(L<=l&&r<=R){
			tr[p]=(tr[p]+v*(r-l+1))%md;
			tag[p]=(tag[p]+v)%md;
			return ;
		}
		pushdown(p,l,r);
		if(L<=mid)upd(v,lp);
		if(mid<R)upd(v,rp);
		tr[p]=(tr[ls]+tr[rs])%md;
//		p4(p,l,r,tr[p]);
	}
	int que(int L,int R,int p=1,int l=1,int r=M){
		if(L<=l&&r<=R){
//			p4(p,l,r,tr[p]);
			return tr[p];
		}
		pushdown(p,l,r);
		ll res=0;
		if(L<=mid)res=(res+que(lp))%md;
		if(mid<R)res=(res+que(rp))%md;
		return res;
	}
}T,Tb;

int n,m,a[N],b[N],c[N];
signed main(){
	infile("travel.in");
	outfile("travel.out");
	re(n);re(m);
	f(i,1,n)re(c[i]),T.upd(c[i],i,i);
	int lst=0;
	while(m--){
		int op,l,r,v;
		re(op);re(l);re(r);
		l^=lst;r^=lst;
//		p2(l,r);
		if(op==1){
			ll ans=T.que(l,r),ansb=0;
//			f(i,l,r)ansb=(ansb+T.que(i,i))%md;
//			pa(c,l,r);
			wr(ans,'\n');
			lst=ans;
		}
		else if(op==2){
			re(v);v^=lst;
//			f(i,l,r)c[i]=(c[i]+v)%md;
			T.upd(v,l,r);
		}
		else if(op==3){
			re(v);v^=lst;
//			f(i,l,r)b[i]=(b[i]+v)%md;
			Tb.upd(v,l,r);
//			p3(v,l,r);
//			wr(Tb.que(2,2));_
		}
		else {
//			f(i,l,r)c[i]=(c[i]+b[i])%md;
			f(i,l,r){
//				if(b[i]!=Tb.que(i,i))p3(b[i],Tb.que(i,i),9999);
				T.upd(Tb.que(i,i),i,i);
			}
		}
	}
	return 0;
}

