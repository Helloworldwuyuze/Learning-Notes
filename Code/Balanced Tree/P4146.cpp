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
// #define endl '\n'

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

#define null nullptr
struct node{
	node *son[2];
	int siz, val, cnt, key, tag, maxx;
	bool rev;
	node(int val): val(val), maxx(-INF), tag(0), key(rand()*rand()), cnt(1), siz(1), rev(false) {son[0] = son[1] = null;}
	void push_up(){
		siz=cnt; maxx=val;
		if(son[0]!=null)	maxx=max(maxx, son[0]->maxx), siz+=son[0]->siz;
		if(son[1]!=null)	maxx=max(maxx, son[1]->maxx), siz+=son[1]->siz;
	}
	void push_down(){
		if(tag){
			// maxx += tag, val += tag;
			if(son[0]!=null)	son[0]->tag+=tag, son[0]->maxx += tag, son[0]->val += tag;
			if(son[1]!=null)	son[1]->tag+=tag, son[1]->maxx += tag, son[1]->val += tag;
			tag=0;
		}if(rev){
			swap(son[0], son[1]);
			if(son[0]!=null)	son[0]->rev^=1;
			if(son[1]!=null)	son[1]->rev^=1;
			rev=false;
		}
		push_up();
	}
};
node *root;

pair<node*, node*> Split(node *root, int sz){
	if(root==null)	return mk(null, null);
	root->push_down();
	int lsiz = root->son[0]==null?0:root->son[0]->siz;
	if(sz<=lsiz){
		auto tmp = Split(root->son[0], sz);
		root->son[0] = tmp.se, root->push_up();
		return mk(tmp.fi, root);
	}else{
		auto tmp = Split(root->son[1], sz - lsiz - 1);
		root->son[1] = tmp.fi, root->push_up();
		return mk(root, tmp.se);
	}
}
node* merge(node *x, node* y){
	if(x==null&&y==null)	return null;
	if(x==null&&y!=null)	return y;
	if(x!=null&&y==null)	return x;
	x->push_down(), y->push_down();
	if(x->key<y->key)	return x->son[1] = merge(x->son[1], y), x->push_up(), x;
	else	return y->son[0] = merge(x, y->son[0]), y->push_up(), y;
}
void insert(int val){
	auto tmp = Split(root, val);
	node *nw = new node(0);
	root = merge(merge(tmp.fi, nw), tmp.se);
}
void Reverse(int l,int r){
	auto tmp = Split(root, r), ltr = Split(tmp.fi, l-1);
	ltr.se->rev ^= 1;
	root = merge(merge(ltr.fi, ltr.se), tmp.se);
}
void Update(int l,int r,int x){
	auto tmp = Split(root, r), ltr = Split(tmp.fi, l-1);
	ltr.se->tag += x; ltr.se->maxx += x, ltr.se->val += x;
	root = merge(merge(ltr.fi, ltr.se), tmp.se);
}
int Query(int l,int r){
	auto tmp = Split(root, r), ltr = Split(tmp.fi, l-1);
	// ltr.se->push_down();
	int res = ltr.se->maxx;
	// cout<<"QUERY::"<<res<<endl;
	return root = merge(merge(ltr.fi, ltr.se), tmp.se), res;
}
void print(node *root){
	if(root==null)	return ;
	root->push_down();
	print(root->son[0]);
	cout<<root->val<<" ";
	print(root->son[1]);
}

int n,m,op,l,r,x;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	insert(i);
	while(m--){
		cin>>op>>l>>r;
		if(op==1)	cin>>x, Update(l, r, x);
		else if(op==2)	Reverse(l, r);
		else	cout<<Query(l, r)<<endl;
		// print(root), cout<<endl<<endl;
	}
	return 0;
}