#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+10;
int n,q;
int h[N];
struct ask{
	int id,l,r,x;
}ask[N];

signed main(){
	freopen("zatopljenje.in","r",stdin);
	freopen("zatopljenje.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	int l,r;
	for(l=1;h[l+1]>h[l];l++);
	for(r=n;h[r-1]>h[r];r--);
	for(int i=1;i<=q;i++){
		cin>>ask[i].l>>ask[i].r>>ask[i].x;
		ask[i].id=i;
	}
	if(l==r){
		for(int i=1;i<=q;i++){
			if(ask[i].l>=l){
				if(h[ask[i].l]>ask[i].x)cout<<"1\n";
				else cout<<"0\n";
			}else if(ask[i].r<=l){
				if(h[ask[i].r]>ask[i].x)cout<<"1\n";
				else cout<<"0\n";
			}else{
				if(h[l]>ask[i].x)cout<<"1\n";
				else cout<<"0\n";
			}
		}
		return 0;
	}else{
		for(int i=1;i<=q;i++){
			int cnt=0;
			for(int j=ask[i].l;j<=ask[i].r;j++){
				if(j==ask[i].l&&h[j]>ask[i].x)cnt++;
				else if(h[j]>ask[i].x&&h[j-1]<=ask[i].x)
					cnt++;
			}
			cout<<cnt<<'\n';
		}
	}
	return 0;
}

