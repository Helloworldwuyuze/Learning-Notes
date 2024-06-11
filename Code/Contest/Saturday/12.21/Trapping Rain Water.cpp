#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;
typedef set<int> SI;

int t,n,m,a[N],ans,pos,maxx,x,y,sum;
SI pre,suf;

void Print(SI s){
	for(SI::iterator it=s.begin();it!=s.end();++it){
		cout<<(*it)<<" ";
	}
	cout<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		pre.clear(), suf.clear();
		cout<<"----------------------------------"<<endl;
		cin>>n;
		for(int i=1;i<=n;++i)	cin>>a[i], maxx=max(maxx,a[i]), sum+=a[i];
		for(int i=1;i<=n;++i){
			if(a[pos]==maxx&&a[i]==maxx)	pre.insert(i), pos=i;
			else if(a[pos]!=maxx&&a[i]>a[pos])	pre.insert(i), pos=i;
		}
		pos=n+1;
		for(int i=n;i;--i)
			if(a[i]>a[pos])	suf.insert(i), pos=i;
		SI::iterator it=pre.begin();
		int lst=*it,nw=*(++it);
		while(it!=pre.end()){
			ans+=min(a[lst],a[nw])*(nw-lst);
			lst=*it,nw=*(++it);
		}
		it=suf.begin();
		lst=*it,nw=*(++it);
		while(it!=suf.end()){
			ans+=min(a[lst],a[nw])*(lst-nw);
			lst=*it,nw=*(++it);
		}
		cin>>m;
		while(m--){
			cin>>x>>y;
			if(y>maxx)
		}
	}
	return 0;
}
