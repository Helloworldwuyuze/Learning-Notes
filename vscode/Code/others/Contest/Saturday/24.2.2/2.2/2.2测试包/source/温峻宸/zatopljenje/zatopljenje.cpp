#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#define mp std::make_pair
#define pii std::pair<int,int>
#define ll long long
#define __ putchar('\n')
#define _ putchar(' ')
#define min(i,j) (std::min((i),(j)))
#define max(i,j) (std::max((i),(j)))
#define swap(x,y) (x)^=(y)^=(x)^=(y)
#define f(i,j,k) for(int i=(j),K=(k);i<=(K);i++)
#define md (1000000007)
#define inf (0x3f3f3f3f)

//std::mt19937 rnd(time(0));
void re(int &x) {x = 0;char ch = getchar();int f = 1;while(!isdigit(ch)){if(ch == '-')f = -1;ch = getchar();}while(isdigit(ch)){x=(x<<1)+(x<<3)+ (ch^48); ch = getchar();}x *= f;}
void __write(ll arg){ll x = arg;if(x < 0) {putchar('-'); x =- x;}if(x > 9) {__write(x / 10);}putchar(x % 10 + '0');}
void wr(ll x,char p){__write(x);putchar(p);}
ll qpow(ll a,ll k) {ll s=1;for(;k;k>>=1,a=a*a%md)if(k&1)s=(ll)s*a%md;return s;}
//using namespace std;
const int N = 1e5+10,M=2e5+10;
int n,m,a[N],l[N],r[N],x[N],t,ans[N];
int main(){
	freopen("zatopljenje.in","r",stdin);
	freopen("zatopljenje.out","w",stdout);
	re(n);re(m);
	f(i,1,n)re(a[i]);
	f(i,1,m){
		re(l[i]);re(r[i]);re(x[i]);
		t=0;
		bool fl=0;
		f(j,l[i],r[i]){
			if(fl==0&&a[j]>x[i])fl=1,t++;
			else if(fl==1&&a[j]<=x[i])fl=0;
		}
		wr(t,'\n');
	} 

	
	return 0;
}


