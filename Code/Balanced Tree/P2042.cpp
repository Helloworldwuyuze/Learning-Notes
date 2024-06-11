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
const int N = 5e5 + 10;
const int M = 1e6 + 10;

struct node;

node *null;
struct node{
	node *son[2];
	int siz, key, val, sum, ls, rs, ms, tag;
	int rev;
	node(int val): val(val), sum(val), ls(val), rs(val), ms(val), siz(1), key(rand()), tag(INF + 1), rev(false) { son[0] = son[1] = null;}
	void push_up(){
		siz = son[0]->siz + son[1]->siz + 1;
		ls = max(son[0]->ls, max(son[0]->sum + val, son[0]->sum + val + son[1]->ls));
		rs = max(son[1]->rs, max(son[1]->sum + val, son[1]->sum + val + son[0]->rs));
		ms = max(max(son[0]->ms, son[1]->ms), max(max(son[0]->rs + val, son[1]->ls + val), son[0]->rs + son[1]->ls + val));
		sum = son[0]->sum + son[1]->sum + val;
	}
	void push_down(){
		if(rev){
			swap(son[0], son[1]);
			son[0]->rev ^= 1, son[1]->rev ^= 1;
			rev = false;
		}if(tag!=INF+1){
			val = tag, sum = tag * siz;
			if(tag<0)	ls = rs = ms = tag;
			else	ls = rs = ms = tag * siz;
			son[0]->tag = son[1] -> tag = 1;
			tag = INF+1;
		}
	}
};
node *addition(node *x, node *y){ return x==null?y:x;}
node *root;

pair<node*, node*> Split(node *root, int val){
	if(root==null)	return {null, null};
	root->push_down();
	if(val<root->val){
		auto tmp = Split(root->son[0], val);
		root->son[0] = tmp.se; root->push_up();
		return {tmp.fi, root};
	}else{
		auto tmp = Split(root->son[1], val);
		root->son[1] = tmp.se; root->push_up();
		return {root, tmp.se};
	}
}
node *merge(node *x, node *y){
	if(x==null||y==null)	return addition(x, y);
	x->push_down(), y->push_down();
	if(x->key<y->key)	return x->son[1] = merge(x->son[1], y), x->push_up(), x;
	else	return y->son[0] = merge(x, y->son[0]), y->push_up(), y;
}
void insert(int loca, int val){
	auto tmp = Split(root, loca);
	// cerr<<tmp.fi->val<<" "<<tmp.se->val<<endl;
	root = merge(merge(tmp.fi, new node(val)), tmp.se);
}
void Delete(int loca){
	auto tmp = Split(root, loca), ltr = Split(tmp.fi, loca-1);
	delete ltr.se;
	root = merge(ltr.fi, tmp.se);
}
void update(int l,int r,int val){
	auto tmp = Split(root, r), ltr = Split(tmp.fi, l-1);
	ltr.se->tag = val;
	root = merge(merge(ltr.fi, ltr.se), tmp.se);
}
void Reverse(int l,int r){
	auto tmp = Split(root, r), ltr = Split(tmp.fi, l-1);
	ltr.se->rev ^= 1;
	root = merge(merge(ltr.fi, ltr.se), tmp.se);
}
int QuerySum(int l,int r){
	auto tmp = Split(root, r), ltr = Split(tmp.fi, l-1);
	return root = merge(merge(ltr.fi, ltr.se), tmp.se), ltr.se->sum;
}
int QueryMS(int l,int r){
	auto tmp = Split(root, r), ltr = Split(tmp.fi, l-1);
	return root = merge(merge(ltr.fi, ltr.se), tmp.se), ltr.se->ms;
}

int n,m,tot,x,pos,c;
string op;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	root = null = new node(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>x, insert(i, x);
	}
	while(m--){
		cin>>op;
		if(op=="INSERT"){
			cin>>pos>>tot;
			for(int i=1;i<=tot;++i)	cin>>x, insert(pos+i-1, x);
		}else if(op=="DELETE"){
			cin>>pos>>tot;
			while(tot--)	Delete(pos);
		}else if(op=="MAKE-SAME"){
			cin>>pos>>tot>>c;
			update(pos, pos+tot-1, c);
		}else if(op=="REVERSE"){
			cin>>pos>>tot;
			Reverse(pos, pos+tot-1);
		}else if(op=="GET-SUM")	cin>>pos>>tot, cout<<QuerySum(pos, pos+tot-1)<<endl;
		else	cin>>pos>>tot, cout<<QueryMS(pos, pos+tot-1)<<endl;
	}
	return 0;
}