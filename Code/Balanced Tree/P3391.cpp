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
#define size(x) (x==null?0:x->siz)
struct node{
	node *son[2];
	int siz, cnt, val, key;
	bool tag;
	node(int val): siz(1), cnt(1), val(val), tag(false){ son[0]=son[1]=null, key=rand();}
	void pushup_siz(){
		siz=cnt;
		if(son[0]!=null)	siz+=son[0]->siz;
		if(son[1]!=null)	siz+=son[1]->siz;
	}
	void push_down(){
		if(!tag)	return ;
		swap(son[0], son[1]);
		if(son[0]!=null)	son[0]->tag^=1;
		if(son[1]!=null)	son[1]->tag^=1;
		tag=false;
	}
};
node *root;
pair<node*, node*> Split(node *root, int sz){
	if(root==null)	return mk(null, null);
	root->push_down();
	if(sz<=size(root->son[0])){
		auto tmp = Split(root->son[0], sz);
		root->son[0] = tmp.se, root->pushup_siz();
		return mk(tmp.fi, root);
	}else{
		auto tmp = Split(root->son[1], sz-size(root->son[0])-root->cnt);
		root->son[1] = tmp.fi, root->pushup_siz();
		return mk(root, tmp.se);
	}
}
node *merge(node* x,node* y){
	if(x==null&&y==null)	return null;
	if(x==null&&y!=null)	return y;
	if(x!=null&&y==null)	return x;
	x->push_down(), y->push_down();
	if(x->key<y->key){
		x->son[1] = merge(x->son[1], y);
		x->pushup_siz();
		return x;
	}else{
		y->son[0] = merge(x, y->son[0]);
		y->pushup_siz();
		return y;
	}
}
void insert(int x){
	auto tmp = Split(root, x);
	auto ltr = Split(tmp.fi, x-1);
	ltr.se = new node(x);
	root = merge(merge(ltr.fi, ltr.se), tmp.se);
}
void rev(int l,int r){
	auto tmp = Split(root, r);
	auto ltr = Split(tmp.fi, l-1);
	ltr.se->tag^=1;
	root=merge(merge(ltr.fi, ltr.se), tmp.se);
}
void print(node* root){
	if(root==null)	return ;
	root->push_down();
	print(root->son[0]);
	cout<<root->val<<" ";
	print(root->son[1]);
}

int n,m,l,r;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	insert(i);
	while(m--)	cin>>l>>r, rev(l,r);
	print(root); cout<<endl;
	return 0;
}