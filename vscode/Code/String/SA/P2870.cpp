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
const int N = 5e5 + 10;
const int M = 1e6 + 10;

int n, top;
long long pre[N], suf[N], p[N];
const int MOD = 98244353;
const int base = 131;
char c[N], ans[N];

bool chk(int l,int r){
	int left=0, right=r-l+1;
	while(left<right){
		int mid=left+right+1>>1;
		// cout<<left<<" "<<right<<" "<<mid<<" "<<pre[l+mid]-pre[l-1]*p[mid]<<" "<<suf[r-mid]-suf[r+1]*p[mid]<<endl;
		if(((pre[l+mid-1]-pre[l-1]*p[mid]%MOD)%MOD+MOD)%MOD!=((suf[r-mid+1]-suf[r+1]*p[mid])%MOD+MOD)%MOD)	right=mid-1;
		else	left=mid;
	}
	// cout<<l<<" "<<r<<" "<<left<<endl<<endl;
	return c[l+left]<c[r-left];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>c[i];
	for(int i=1;i<=n;++i)
		pre[i]=(pre[i-1]*base+c[i])%MOD;
	for(int i=n;i;--i)
		suf[i]=(suf[i+1]*base+c[i])%MOD;
	p[0]=1;
	for(int i=1;i<=n+1;++i)	p[i]=p[i-1]*base%MOD;
	// cout<<endl;
	for(int l=1,r=n;l<=r;){
		if(c[l]<c[r])	ans[++top]=c[l++];
		else if(c[l]>c[r])	ans[++top]=c[r--];
		else if(chk(l,r))	ans[++top]=c[l++];
		else	ans[++top]=c[r--];
		// cout<<"###"<<l<<" "<<r<<"###"<<endl;
	}
	for(int i=1;i<=n;++i){
		cout<<ans[i];
		if(i%80==0)	cout<<endl;
	}
	return 0;
}
/*
51
AABBABBBBABABBABABAABBAABBBAAAABAABABAABBAAABBBBBBA
*/