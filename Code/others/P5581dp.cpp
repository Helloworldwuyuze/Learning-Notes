#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
char ST;
const int xx=1000005;
int n,m,a[xx];
char b[xx],vis[xx];
struct info
{
	vector<int>A;
};
vector<int>v[xx];
vector<info>cir;
vector<int>B;
namespace s1
{
	int lim;
	vector<int>sum;
	int lb(int x){return (x&(-x));}
	void add(int x,int y){++x;for(;x<=lim;x+=lb(x))sum[x]=min(sum[x],y);}
	int ask(int x){++x;int ans=1e9;for(;x;x-=lb(x))ans=min(ans,sum[x]);return ans;}
	int bin(int y)//第一个小于等于 y 的 
	{
		int x=0;
		for(int i=__lg(lim);i>=0;i--)
			if(x+(1<<i)<=lim&&sum[x+(1<<i)]>y)x+=(1<<i);
		return x+1 -1;
	}
	void Set(int x){vector<int>(x+1,1e9).swap(sum),lim=x;}
}
namespace s2
{
	int lim;
	vector<int>sum;
	int lb(int x){return (x&(-x));}
	void add(int x,int y){++x;for(;x<=lim;x+=lb(x))sum[x]=min(sum[x],y);}
	int ask(int x){++x;int ans=1e9;for(;x;x-=lb(x))ans=min(ans,sum[x]);return ans;}
	int bin(int y)//第一个小于等于 y 的 
	{
		int x=0;
		for(int i=__lg(lim);i>=0;i--)
			if(x+(1<<i)<=lim&&sum[x+(1<<i)]>y)x+=(1<<i);
		return x+1 -1;
	}
	void Set(int x){vector<int>(x+1,1e9).swap(sum),lim=x;}
}


char ED;
int main(){
//	freopen("a.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
//	n=1e6;
//	for(int i=1;i<=n;i++)a[i]=1e6;
	m=read();
//	m=1e6-1;
	for(int i=1;i<=m;i++)
	{
		char c;
		while((c=getchar())!='P'&&c!='W');
		if(c=='W')b[i]=1;
		else b[i]=-1;
	}
//	for(int i=1;i<=m;i++)
//	{
//		b[i]=i%100==0?1:-1;
////		char c;
////		while((c=getchar())!='P'&&c!='W');
////		if(c=='W')b[i]=1;
////		else b[i]=-1;
//	}
	int te=0;
	for(int i=1;i<=m;i++)
	{
		if(vis[i])continue;
		int j=i;
		while(!vis[j])vis[j]=1,j+=n,j=(j-1)%m+1;
		++te;
	}
	for(int i=1;i<=m;i++)vis[i]=0;
	cir.resize(te),te=0;
	for(int i=1;i<=m;i++)
	{
		if(vis[i])continue;
		int j=i;
		vector<int>v;
		while(!vis[j])
		{
			vis[j]=1;
			v.push_back(j);
			j+=n,j=(j-1)%m+1;
		}
		v.shrink_to_fit();
		cir[te++]={v};
	}
// 105 MB 。 
//	cir.shrink_to_fit();
//	return 0;
	for(int i=1;i<=n;i++)
		v[(i-1)%m+1].push_back(i);
//	for(int i=1;i<=m;i++)v[i].shrink_to_fit();
	ll mn=1e18;
	for(auto &it:cir)
	{
		int sz=it.A.size();
		
		B.resize(it.A.size());
		for(int i=0;i<sz;i++)B[i]=b[it.A[i]]+(i!=0?B[i-1]:0);
		s1::Set(sz+1),s2::Set(sz+1);
		for(int i=0;i<sz;i++)s1::add(i,B[i]);
		for(int i=sz-1;i>=0;i--)
		{
			s2::add(i,B[i]);
			for(auto itv:v[it.A[i]])
			{
				int sm=B[sz-1];
				int msuf=min(s2::ask(sz)-(i==0?0:B[i-1]),s1::ask(i)+B[sz-1]-(i==0?0:B[i-1]));
				int lun=1e9;
				if(a[itv]+msuf<=0)lun=0;
				else if(sm<0)lun=(a[itv]+msuf+(-sm)-1)/((-sm));
				if(lun==1e9)continue;
				a[itv]+=lun*sm;
				int pos=0;
				if(a[itv]+s2::ask(sz)-(i==0?0:B[i-1])<=0)
					pos=s2::bin(-(a[itv]-(i==0?0:B[i-1])))-i+1;
				else if(a[itv]+s1::ask(i)+B[sz-1]-(i==0?0:B[i-1])<=0)
					pos=s1::bin(-(a[itv]+B[sz-1]-(i==0?0:B[i-1])))+sz-i+1;//注意 
				else assert(0);
//				for(auto It:it.A)cerr<<It<<" ";
//				cerr<<"\n";
//				cerr<<"\n";
//				cerr<<lun<<" "<<sm<<" "<<itv<<" "<<lun<<" "<<pos<<" "<<(1ll*lun*sz+pos-1)*n+itv<<" "<<msuf<<" "<<s2::ask(sz)-(i==0?0:B[i-1])<<" "<<i<<"@\n";
				mn=min(mn,(1ll*lun*sz+pos-1)*n+itv);
			}
		}
	}
	if(mn>=1e18)puts("-1");
	else cout<<mn<<"\n";
	
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}