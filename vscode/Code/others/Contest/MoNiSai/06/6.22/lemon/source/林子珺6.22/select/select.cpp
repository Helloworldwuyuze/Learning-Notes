#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=20+10;
const int INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp_make_pair
int n;
bool b[N];
int solve(int n){
	int ans=0;
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1)))b[j]=1;
			else b[j]=0;
		}
		bool f=1;
		for(int j=1;j<=n;j++){
			if(b[j]){
				if(2*j<=n&&b[2*j]){
					f=0;
					break;
				}
				if(3*j<=n&&b[3*j]){
					f=0;
					break;
				}
			}
		}
		if(f)ans++;
	}
	return ans;
}
signed main(){
	freopen("select.in","r",stdin);
	freopen("select.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	cout<<solve(n)<<endl;
	return 0;
}

