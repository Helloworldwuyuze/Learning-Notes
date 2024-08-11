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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

#define null nullptr
struct node{
	node *son[2];
	int siz, cnt, val, key;
	node(int val): val(val), siz(1), key(rand()), cnt(1) { son[0]=son[1]=null; }
	void push_up(){
		siz=cnt;
		if(son[0]!=null)	siz+=son[0]->siz;
		if(son[1]!=null)	siz+=son[1]->siz;
	}
};
node *root;

pair<node*, node*> Split(node *root, int val){
	if(root==null)	return mk(null, null);
	if(val<root->val){
		auto tmp = Split(root->son[0], val);
		root->son[0] = tmp.se, root->push_up();
		return mk(tmp.fi, root);
	}else{
		auto tmp = Split(root->son[1], val);
		root->son[1] = tmp.fi, root->push_up();
		return mk(root, tmp.se);
	}
}
tuple<node*, node*, node*> splitrk(node* root, int sz){
	if(root==null)	return {null, null, null};
	int lsiz = root->son[0]==null?0:root->son[0]->siz;
	if(sz<=lsiz){
		node *l, *mid, *r;
		tie(l, mid, r) = splitrk(root->son[0], sz);
		root->son[0] = r, root->push_up();
		return {l, mid, root};
	}else if(sz<=lsiz+root->cnt){
		node *l = root->son[0], *r = root->son[1];
		root->son[0] = root->son[1] = null;
		return {l, root, r};
	}else{
		node *l, *mid, *r;
		tie(l, mid, r) = splitrk(root->son[1], sz - lsiz - root->cnt);
		root->son[1] = l, root->push_up();
		return {root, mid, r};
	}
}
node* merge(node *x,node *y){
	if(x==null&&y==null)	return null;
	if(x==null&&y!=null)	return y;
	if(x!=null&&y==null)	return x;
	if(x->key<y->key)	return x->son[1] = merge(x->son[1], y), x->push_up(), x;
	else	return y->son[0] = merge(x, y->son[0]), y->push_up(), y;
}
void insert(int val){
	auto tmp = Split(root, val);
	auto ltr = Split(tmp.fi, val-1);
	if(ltr.se==null)	ltr.se = new node(val);
	else	ltr.se->cnt++, ltr.se->push_up();
	root = merge(merge(ltr.fi, ltr.se), tmp.se);
}
int GetValueByRank(int rk){
	node *l, *mid, *r;
	tie(l, mid, r) = splitrk(root, rk);
	int res = mid->val;
	root=merge(merge(l, mid), r);
	return res;
}
void print(node *root){
	if(root==null)	return ;
	print(root->son[0]);
	cout<<root->val<<" ";
	print(root->son[1]);
}

int n, x, tag, mn, ans;
char op;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>mn;
	while(n--){
		cin>>op>>x;
		if(op=='I'){
			x-=tag;
			if(x<mn-tag)	continue;
			insert(x);
		}else if(op=='A')	tag+=x;
		else if(op=='S'){
			tag-=x;
			auto tmp = Split(root, mn-tag-1);
			root = tmp.se;
			if(tmp.fi!=null)	ans+=tmp.fi->siz;
		}else{
			if(root==null||root->siz<x)	cout<<-1<<endl;
			else	cout<<GetValueByRank(root->siz-x+1)+tag<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}