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
#define endl '\n'
#define null nullptr

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

struct node{
	node  *son[2];
	int siz, cnt, val, key;
	node(int val): val(val), cnt(1), siz(1){
		son[1]=null, son[0]=null;
		key=rand();
	}
	void pushup_siz(){
		siz=cnt;
		if(son[0]!=null)	siz+=son[0]->siz;
		if(son[1]!=null)	siz+=son[1]->siz;
	}
};

void Rotate(node *&root, bool type){
	node *tmp = root->son[type];
	root->son[type]=tmp->son[!type], tmp->son[!type]=root;
	root->pushup_siz(), tmp->pushup_siz();
	root=tmp;
}//右旋0， 左旋1
void Insert(node *&root, int val){
	if(root==null)	return (void)(root = new node(val));
	if(val==root->val)	return (void)(++root->cnt, ++root->siz);
	if(val<root->val){
		Insert(root->son[0], val);
		if(root->son[0]->key<root->key)	Rotate(root, 0);
	}else if(val>root->val){
		Insert(root->son[1], val);
		if(root->son[1]->key<root->key)	Rotate(root, 1);
	}
	root->pushup_siz();
}
void Delete(node *&root, int val){
	if(val>root->val)	Delete(root->son[1], val);
	else if(val<root->val)	Delete(root->son[0], val);
	else{
		if(root->cnt>1)	return (void)(root->cnt--, root->siz--);
		bool fl=root->son[0]!=null;
		bool fr=root->son[1]!=null;
		node *tmp = root;
		if(!fl&&!fr)	return (void)(delete root, root=null);
		else if(fl&&!fr)	root=tmp->son[0], delete tmp;
		else if(!fl&&fr)	root=tmp->son[1], delete tmp;
		else{
			bool type = root->son[0]->key < root->son[1]->key ? 0 : 1;
			Rotate(root, type), Delete(root->son[!type], val);
		}
	}
	root->pushup_siz();
}
#define lsiz (root->son[0]==null?0:root->son[0]->siz)
int GetValueByRank(node *root, int rk){
	// cerr<<rk<<" "<<(root->son[0]==null)<<" "<<root->val<<" "<<root->key<<endl;
	if(rk<=lsiz)	return GetValueByRank(root->son[0], rk);
	else if(rk<=lsiz+root->cnt)	return root->val;
	else	return GetValueByRank(root->son[1], rk-lsiz-root->cnt);
}
int GetRankByValue(node *root, int val){
	if(root->val==val)	return lsiz+1;
	else if(root->val>val)	return root->son[0]==null?1:GetRankByValue(root->son[0], val);
	else	return root->son[1]==null?(root->siz+1):(GetRankByValue(root->son[1], val) + lsiz + root->cnt);
}
#undef lsiz
int pretmp, suftmp;
int FindPre(node *root, int val){
	// cout<<root->val<<" "<<val<<endl;
	if(val<=root->val){
		if(root->son[0]!=null)	return FindPre(root->son[0], val);
	}else{
		// cout<<"QAQ"<<endl;
		pretmp = root->val;
		if(root->son[1]!=null)	FindPre(root->son[1], val);
		return pretmp;
	}
	return -1;
}
int FindSuf(node *root, int val){
	if(val>=root->val){
		if(root->son[1]!=null)	return FindSuf(root->son[1], val);
	}else{
		suftmp = root->val;
		if(root->son[0])	FindSuf(root->son[0], val);
		return suftmp;
	}
	return -1;
}

int n,op,x;
node *root;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	while(n--){
		cin>>op>>x;
		if(op==1)	Insert(root, x);
		else if(op==2)	Delete(root, x);
		else if(op==3)	cout<<GetRankByValue(root, x)<<endl;
		else if(op==4)	cout<<GetValueByRank(root, x)<<endl;
		else if(op==5)	cout<<FindPre(root, x)<<endl;
		else	cout<<FindSuf(root, x)<<endl;
		// cout<<root->val<<endl;
	}
	return 0;
}