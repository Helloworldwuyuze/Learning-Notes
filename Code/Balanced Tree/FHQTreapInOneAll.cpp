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
	node(int val): siz(1), cnt(1), val(val){ son[0]=son[1]=null; key = rand();}
	void pushup_siz(){
		siz=cnt;
		if(son[0]!=null)	siz+=son[0]->siz;
		if(son[1]!=null)	siz+=son[1]->siz;
	}
};
node* root;
typedef pair<node*, node*> PNN;

PNN Split(node* root, int val){
	if(root==null)  return mk(null, null);
	if(root->val<=val){
		auto tmp = Split(root->son[1], val);
		root->son[1] = tmp.fi;
		root->pushup_siz();
		return mk(root, tmp.se);
	}else{
		auto tmp = Split(root->son[0], val);
		root->son[0] = tmp.se;
		root->pushup_siz();
		return mk(tmp.fi, root);
	}
}
tuple<node*, node*, node*> SplitByRank(node *root, int rk){
	if(root==null)	return {null, null, null};
	int lsiz = root->son[0]==null?0:root->son[0]->siz;
	if(rk<=lsiz){
		node *l, *mid, *r;
		tie(l, mid, r) = SplitByRank(root->son[0], rk);
		root->son[0] = r, root->pushup_siz();
		return {l, mid, root};
	}else if(rk<=lsiz+root->cnt){
		node *l = root->son[0], *r = root->son[1];
		root->son[0] = root->son[1] = null;
		return {l, root, r};
	}else{
		node *l, *mid, *r;
		tie(l, mid, r) = SplitByRank(root->son[1], rk-lsiz-root->cnt);
		root->son[1] = l, root->pushup_siz();
		return {root, mid, r};
	}
}
node* merge(node *x,node *y){
	if(x==null&&y==null)	return null;
	if(x==null&&y!=null)	return y;
	if(x!=null&&y==null)	return x;
	if(x->key<y->key){
		x->son[1]=merge(x->son[1], y);
		x->pushup_siz();
		return x;
	}else{
		y->son[0]=merge(x, y->son[0]);
		y->pushup_siz();
		return y;
	}
}

void insert(int val){
	auto tmp = Split(root, val);
	auto ltr = Split(tmp.fi, val-1);
	if(ltr.se==null){
		ltr.se = new node(val);
	}else{
		ltr.se->cnt++;
		ltr.se->pushup_siz();
	}
	node* nwltr = merge(ltr.fi, ltr.se);
	root = merge(nwltr, tmp.se);
}
void Delete(int val){
	auto tmp = Split(root, val);
	auto ltr = Split(tmp.fi, val-1);
	if(ltr.se->cnt>1){
		ltr.se->cnt--;
		ltr.se->pushup_siz();
		ltr.fi = merge(ltr.fi, ltr.se);
	}else{
		if(tmp.fi==ltr.se)	tmp.fi = null;
		delete ltr.se;
		ltr.se = null;
	}
	root = merge(ltr.fi, tmp.se);
}
int GetRankByValue(node* root, int val){
	auto tmp = Split(root, val-1);
	int res = tmp.fi==null?1:(tmp.fi->siz+1);
	root = merge(tmp.fi, tmp.se);
	return res;
}
int GetValueByRank(node* root, int rk){
	node *l, *mid, *r;
	tie(l, mid, r) = SplitByRank(root, rk);
	int res = mid->val;
	root = merge(merge(l, mid), r);
	return res;
}
int pre(int val){
	auto tmp = Split(root, val-1);
	int res = GetValueByRank(tmp.fi, tmp.fi->siz);
	root = merge(tmp.fi, tmp.se);
	return res;
}
int suf(int val){
	auto tmp = Split(root, val);
	int res = GetValueByRank(tmp.se, 1);
	root = merge(tmp.fi, tmp.se);
	return res;
}

#define endl '\n'
int n, op, x;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	while(n--){
		cin>>op>>x;
		// cout<<op<<" "<<x<<endl;
		if(op==1)	insert(x);
		else if(op==2)	Delete(x);
		else if(op==3)	cout<<GetRankByValue(root, x)<<endl;
		else if(op==4)	cout<<GetValueByRank(root, x)<<endl;
		else if(op==5)	cout<<pre(x)<<endl;
		else	cout<<suf(x)<<endl;
		// cout<<root->val<<endl;
	}
	return 0;
}