#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
#include<unordered_map>

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
#define endl '\n'

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e5 + 10;
const int M = 1e6 + 10;
const int MOD = 1e8;

int n,a[N], sum;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i], sum+=a[i];
	int ans=0;
	sort(a+1,a+1+n); a[n+1]=INF;
	for(int i=1;i<=n;++i){
		int l=i+1, r=n+1;
		while(l<r){
			int mid=l+r>>1;
			if(a[mid]+a[i]>=MOD)	r=mid;
			else	l=mid+1;
		}
		ans+=n-r+1;
		// cout<<r<<endl;
	}
	// cout<<ans<<endl;
	cout<<sum*(n-1)-ans*MOD<<endl;
	return 0;
}