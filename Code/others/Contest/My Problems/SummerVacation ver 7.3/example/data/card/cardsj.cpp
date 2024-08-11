#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int MAXN = 1e5;
const int MAXM = MAXN-1;
#define endl '\n'

int sorted[N], n, m;
map<pair<int,int>, bool> ma;
vector<pair<int,int> > g;
int a[N];

unsigned int Rand(){
	return (rand()<<16)+rand();
}

int main(){
	freopen("c20.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	srand((unsigned)time(NULL));
	n = MAXN, m = MAXM;
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;++i)	a[i]=i;
	random_shuffle(a+1,a+1+n);
	int nn = (n-1)/3;
	for(int i=2;i<=nn;++i)	g.push_back({a[i], a[1]});
	for(int i=nn+1;i<=n;++i)	g.push_back({a[i], a[(i-nn-1)/2+1]});
	random_shuffle(g.begin(), g.end());
	for(pair<int,int> e:g){
		if(rand()%2)	cout<<e.first<<" "<<e.second<<endl;
		else	cout<<e.second<<" "<<e.first<<endl;
	}
//	for(int i=2;i<=n;++i){
//		int x = rand()%(i-1)+1;
//		cout<<i<<" "<<x<<endl;
//		ma[make_pair(i,x)]=true;
//	}
//	m-=n-1;
//	for(;m;){
//		int x = rand()%n+1, y = rand()%n+1;
//		if(ma[make_pair(x,y)])	continue;
//		ma[make_pair(x,y)] = true;
//		cout<<x<<" "<<y<<endl; --m;
//	}
	return 0;
}
