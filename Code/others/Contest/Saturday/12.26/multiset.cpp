#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int n,m,a[N],x,y,p[N],cnt,mpf[N];
int ans=1,sum[N];
multiset<int> s[N];

void prime(){
	mpf[1]=1;
	for(int i=2;i<N;++i){
		if(!p[i])	p[++cnt]=i, mpf[i]=i;
		for(int j=1;j<=cnt&&i*p[j]<N;++j){
			p[i*p[j]]=1;
			mpf[i*p[j]]=p[j];
			if(i%p[j]==0)	break;
		}
	}
}

void PrimeFact(int i,int x){
	while(x>1){
		int y=mpf[x];
		if(s[y].find(i)==s[y].end())	++sum[y];
		s[y].insert(i);
		if(sum[y]==n){
			for(int i=1;i<=n;++i){
				s[y].erase(s[y].find(i));
				if(s[y].find(i)==s[y].end())	--sum[y];
			}
			ans=ans*y%MOD;
		}
		x/=y;
	}
} 

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	multiset<int> s;
	s.insert(1), s.insert(1);
	s.insert(2);
	s.erase(s.find(1));
	multiset<int>::iterator it=s.begin();
	while(it!=s.end()){
		cout<<(*it)<<endl;
		++it;
	}
	return 0;
}
