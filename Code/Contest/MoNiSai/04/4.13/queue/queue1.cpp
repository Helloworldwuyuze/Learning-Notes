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
#include<unordered_map>

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
const int N = 1e6 + 10;
const int M = 2e5 + 10;
const int K = 50 + 5;
const int MOD = 998244353;

int n, m, op, k, x, y;
string s;
int a[M], nxt[N], pre[N], head[N];
// unordered_map<unsigned long long, int> ma;
unsigned long long h[K*2], p[K*2], H[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i], a[i]-='1', nxt[i]=-1, pre[i]=-1;
	p[0]=1;
	for(int i=1;i<=100;++i)	p[i]=p[i-1]*6;
	while(m--){
		cin>>op;
		if(op==3){
			cin>>s>>k;
			int len=s.size(), ans=1;
			H[0]=s[0]-'1';
			for(int i=1;i<len;++i)
				H[i]=H[i-1]*6+(s[i]-'1');
			for(int i=0;i+k<=len;++i)
				// ans=ans*ma[H[i+k-1]-H[i]*p[k]];
			cout<<ans<<endl;
		}else if(op==2){
			cin>>x;
			memset(h,0,sizeof(h));
			int L=50, R=49;
			for(int y=pre[x];L&&y!=-1;y=pre[y])
				h[--L]=a[y];
			for(int y=x;R<99&&y!=-1;y=nxt[y])
				h[++R]=a[y];
			for(int i=L+1;i<=R;++i)
				h[i]=h[i-1]*6+h[i];
			for(int len=2;len<=50;++len){
				for(int l=49;l>=L&&l+len>50;--l){
					int r=l+len-1;
					// ma[h[r]-h[l-1]*p[r-l]]--;
				}
			}
			nxt[pre[x]]=-1; pre[x]=-1;
		}else if(op==1){
			cin>>x>>y;
			nxt[x]=y, pre[y]=x;
			memset(h,0,sizeof(h));
			int L=50, R=49;
			for(int z=x;L&&z!=-1;z=pre[z])
				h[--L]=a[z];
			for(int z=y;R<99&&z!=-1;z=pre[z])
				h[++R]=a[z];
			for(int i=L+1;i<=R;++i)
				h[i]=h[i-1]*6+h[i];
			for(int len=2;len<=50;++len){
				for(int l=49;l>=L&&l+len>50;--l){
					int r=l+len-1;
					// ma[h[r]-h[l-1]*p[r-l]]++;
				}
			}
		}
		cout<<"###"<<m<<"###"<<endl;
		for(int i=1;i<=n;++i)
			cout<<pre[i]<<" "<<nxt[i]<<endl;
		cout<<endl;
	}
	return 0;
}
