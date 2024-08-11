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
#include<random>

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

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 5e3 + 10;
const int M = 1e6 + 10;
const int MOD = 1e9;

int T,p[10];
string y;

int f(int x){ return x==0?0:(x+f(x/10));}

struct BigNum{
	int a[N], len;
	void print(char c){
		for(int i=len-1;i>=0;--i)	cout<<a[i];
		cout<<c;
	}
};
BigNum operator -(BigNum x,BigNum y) {
	BigNum ans;
	bool flag=0;
	int n=min(x.len,y.len);
	ans.len=max(x.len,y.len);
	for(int i=0;i<n;++i)
		if(x.a[i]>=y.a[i]+flag)	ans.a[i]=x.a[i]-y.a[i]-flag, flag=0;
		else	ans.a[i]=x.a[i]+10-y.a[i]-flag, flag=1;
	for(int i=n;i<ans.len;++i)
		ans.a[i]=x.a[i]-flag, flag=0;
	return ans;
}
bool operator %(BigNum x,int y){
	int now=0;
	for(int i=x.len-1;i>=0;--i)	now=now*10+x.a[i], now%=y;
	return now;
}
BigNum init(string s){
	BigNum a;
	int n=s.size(); a.len=n;
	for(int i=0;i<n;++i)	a.a[i]=s[n-i-1]-'0';
	return a;
}
string _(int x){
	string s;
	if(x==0)	return "0";
	while(x)	s+=x%10+'0', x/=10;
	for(int i=0,j=s.size()-1;i<j;++i,--j)	swap(s[i],s[j]);
	return s;
}
BigNum cntnum(BigNum x,bool f){
	int ans=0;
	for(int i=f;i<x.len;++i)	ans+=x.a[i];
	return init(_(ans));
}
BigNum div10(BigNum x){
	for(int i=0;i<x.len-1;++i)	x.a[i]=x.a[i+1];
	--x.len;
	return x;
}

BigNum j, x,xx;

void mian(){
	cin>>T; p[0]=1;
	for(int i=1;i<9;++i)	p[i]=p[i-1]*10;
	while(T--){
		cin>>y;
		x=init(y);

		if(x.len==1&&x.a[0]<10){	cout<<x.a[0]<<endl; continue;}
		else if(x.len==2&&x.a[1]==1&&x.a[2]==0){ cout<<-1<<endl; continue;}
		
		for(int i=0;i<=10;++i){
			j=init(_(i));
			xx=x-j;
			j.print(' ');
			xx.print('\n');
			cntnum(xx,0).print('\n');
			(xx-cntnum(xx,0)).print('\n');
			if((xx-cntnum(xx,0))%9==0){
				if(i==0)	cout<<-1<<endl;
				else	(x-div10(xx)).print('\n');
				break;
			}
			// for(int i=1;i<=n;++i)
		}
	}
	return ;
}

int main(){
	// ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	mian();
	return 0;
}