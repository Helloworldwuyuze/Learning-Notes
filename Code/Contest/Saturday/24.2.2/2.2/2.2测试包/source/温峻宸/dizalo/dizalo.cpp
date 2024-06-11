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
int n,m,a[N],b[N],s[N],vis[N],t,mid,as[N],c[N];
int trax[N<<2],trin[N<<2],trct[N<<2];
#define ls p<<1,l,mid
#define rs p<<1|1,mid+1,r
void pup(int p){
	trax[p]=max(trax[p<<1],trax[p<<1|1]);
	trin[p]=min(trin[p<<1],trin[p<<1|1]);
	trct[p]=trct[p<<1]+trct[p<<1|1];
}
void add(int p,int l,int r,int x,int c){
	if(l==r){
		trax[p]=trin[p]=c,trct[p]=1;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(ls,x,c);
	else add(rs,x,c);
	pup(p);
}
int que2(int p,int l,int r,int x){
	//printf("%d %d %d\n",p,l,r);
	if(x<trin[p])return trct[p];
	if(x>trax[p])return 0;
	int mid=(l+r)>>1;
	return que2(ls,x)+que2(rs,x);
}
int que1(int p,int l,int r,int L,int R,int x){
	
	if(L<=l&&r<=R){
		return que2(p,l,r,x);
	}
	int mid=(l+r)>>1,s=0;
	if(L<=mid)s+=que1(ls,L,R,x);
	if(mid<R)s+=que1(rs,L,R,x);
	return s;
}
int que4(int p,int l,int r,int x){
	//printf("!!%d %d %d %d %d %d\n",x,l,r,trin[p],trax[p],trct[p]);
	if(x>trax[p])return trct[p];
	if(x<trin[p])return 0;
	int mid=(l+r)>>1;
	return que4(ls,x)+que4(rs,x);
}
int que3(int p,int l,int r,int L,int R,int x){
	
	if(L<=l&&r<=R){
		return que4(p,l,r,x);
	}
	int mid=(l+r)>>1,s=0;
	if(L<=mid)s+=que3(ls,L,R,x);
	if(mid<R)s+=que3(rs,L,R,x);
	return s;
}
int que3x(int p,int l,int r,int L,int R,int x){
	int cmt=0;
	f(i,L,R)if(c[i]!=0&&c[i]<x)cmt++;
	return cmt;
}
int que1x(int p,int l,int r,int L,int R,int x){
	int cmt=0;
	f(i,L,R)if(c[i]!=0&&c[i]>x)cmt++;
	return cmt;
}
int main(){
	freopen("dizalo.in","r",stdin);
	freopen("dizalo.out","w",stdout);
	re(n);re(m);
	f(i,1,n)re(a[i]),b[a[i]]=i;
	f(i,1,m)re(s[i]),vis[s[i]]=1;
	if(n>=10000){
		int ans=0;
		f(i,1,n)
		if(!vis[i]){
			//puts("!");
			add(1,1,n,i,a[i]);
			//
			//wr(i,'\n');
			
		}
		f(i,1,n)if(!vis[i]){
			ans++; 
			if(i==1||(que3(1,1,n,i+1,n,a[i])>0));
			else ans+=que1(1,1,n,1,i-1,a[i]);
			//if(i!=1)printf("%d \n",que3(1,1,n,i+1,n,a[i]));
			//else puts("0");
		}
		
		
		
		as[++t]=ans;
		//wr(ans,'\n');
		for(int q=m;q>=1;q--){
			int i=b[a[s[q]]];
			
			add(1,1,n,i,a[i]);
			ans++;
			
			
			if(i!=n){
				int s1=que3(1,1,n,i+1,n,a[i]);
				if(s1==0)ans+=que1(1,1,n,1,i-1,a[i]);
				else ans++;
				wr(s1,'\n');
			}
			else ans+=que1(1,1,n,1,i-1,a[i]);
			
			as[++t]=ans;
		}
		for(int i=t;i>=1;i--)wr(as[i],' ');
	}
	else if(m==0){
		int ans=0;
		f(i,1,n)
		if(!vis[i]){
			//puts("!");
			add(1,1,n,i,a[i]);
			//
			//wr(i,'\n');
			
		}
		f(i,1,n)if(!vis[i]){
			ans++; 
			if(i==1||(que3(1,1,n,i+1,n,a[i])>0));
			else ans+=que1(1,1,n,1,i-1,a[i]);
			//if(i!=1)printf("%d \n",que3(1,1,n,i+1,n,a[i]));
			//else puts("0");
		}
		
		wr(ans,'\n');
	}
	else{
		int ans=0;
		f(i,1,n)if(!vis[i])
			c[i]=a[i];
		f(i,1,n)if(!vis[i]){
			ans++; 
			
			if(i==1||(que3x(1,1,n,i+1,n,a[i])>0));
			else ans+=que1x(1,1,n,1,i-1,a[i]);
			
		}
		as[++t]=ans;
		//wr(ans,'\n');
		for(int q=m;q>=1;q--){
			int i=b[a[s[q]]];
			c[i]=a[i];
			ans++;
			
			
			ans+=que1x(1,1,n,1,i-1,a[i])+que3x(1,1,n,i+1,n,a[i]);
			
			as[++t]=ans;
		}
		for(int i=t;i>=1;i--)wr(as[i],' ');
	}
	return 0;
}


