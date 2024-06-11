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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e5 + 10;
const int M = 1e7 + 10;
const int MOD = 1e9 + 7;

int T,a,b,c,d;
int p[M], cnt;
void init(){
	for(int i=2;i<=M-10;++i){
		if(!p[i])   p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<=M-10;++j){
			p[p[j]*i]=1;
			if(i%p[j]==0)   break;
		}
	}
}
int ksm(int x,int m){
	int ans=1;
	while(m){
		if(m&1) ans=ans*x%MOD;
		x=x*x%MOD; m>>=1;
	}
	return ans;
}

signed main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	cin>>T;
	while(T--){
		cin>>a>>b>>c>>d;
		int ans=1, mx=max(b,d);
		for(int i=1;i<=cnt&&p[i]<=mx;++i){
			int cnt1=0,cnt2=0,cnt3=0,cnt4=0,aa=a-1,bb=b,cc=c-1,dd=d;
			while(aa>0)	cnt1+=aa/p[i], aa/=p[i];
			while(bb>0)	cnt2+=bb/p[i], bb/=p[i];
			while(cc>0)	cnt3+=cc/p[i], cc/=p[i];
			while(dd>0)	cnt4+=dd/p[i], dd/=p[i];
			ans=ans*ksm(p[i],min(cnt2-cnt1,cnt4-cnt3))%MOD;
			// cout<<p[i]<<" "<<ans<<" "<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<cnt4<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
