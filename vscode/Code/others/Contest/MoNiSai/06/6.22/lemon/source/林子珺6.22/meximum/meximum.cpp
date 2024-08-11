#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10;
const int INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp_make_pair
int n,a[N],mx[N];
int ans=0;
signed main(){
	freopen("meximum.in","r",stdin);
	freopen("meximum.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)mx[i]=max(mx[i+1],a[i]);
	for(int i=1;i<=n;i++){cerr<<i<<endl;
		set<int> s;
		for(int j=0;j<=n-i+1;j++)s.insert(j);
		for(int j=i;j<=n;j++){
			if(s.count(a[j]))s.erase(a[j]);
			if(s.size())ans+=*s.begin();
			else ans+=mx[i]+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

