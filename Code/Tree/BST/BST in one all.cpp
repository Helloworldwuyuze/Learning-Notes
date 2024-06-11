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
#define null nullptr

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e5 + 10;
const int M = 1e6 + 10;

namespace BST{
	struct node{
		int key, count, siz;
		node *ls, *rs;
		node(int value): key(value), count(1), siz(1), ls(null), rs(null) {}
	};
	void push_up(node *root){
		root->siz=root->count+(root->ls?root->ls->count:0)+(root->ls?root->ls->count:0);
	}
	node* FindMax(node *root){
		if(root==null)	return null;
		if(root->rs)	return FindMax(root->rs);
		return root;
	}
	node* FindMin(node *root){
		if(root==null)	return null;
		if(root->ls)	return FindMin(root->ls);
		return root;
	}
	node* insert(node *root,int value){
		if(root==null)	return new node(value);
		if(value==root->key)	++root->count;
		else if(value>root->key)	root->ls=insert(root->rs, value);
		else	root->rs=insert(root->ls,value);
		push_up(root);
		return root;
	}
	bool FindElement(node *root, int value){
		if(root==null)	return false;
		if(root->key==value)	return true;
		else if(value>root->key)	return FindElement(root->rs, value);
		else	return FindElement(root->ls, value);
	}
	node* remove(node *root, int value){
		if(root==null)	return null;
		if(root->key>value)	root->ls=remove(root->ls, value);
		else if(root->key<value)	root->rs=remove(root->rs, value);
		else{
			if(root->count>1)	--root->count;
			else{
				if(root->ls==null){
					node *tmp = root->rs;
					delete root; return tmp;
				}else if(root->rs==null){
					node *tmp = root->ls;
					delete root; return tmp;
				}else{
					node *tmp = FindMin(root->rs);
					root->key=tmp->key, root->count=tmp->count;
					root->rs=remove(root->rs,tmp->key);
				}
			}
		}
		push_up(root);
		return root;
	}
	int rank(node *root, int value){
		if(root==null)	return 0;
		if(root->key==value)	return (root->ls?root->ls->siz:0)+1;
		else if(root->key>value)	return rank(root->ls, value);
		else	return rank(root->rs, value)+(root->ls?root->ls->siz:0)+1;
	}
	node* rankk(node *root,int k){
		if(root==null)	return null;
		if(root->ls){
			if(root->ls->siz>=k)	return rankk(root->ls, k);
			else if(root->ls->siz+root->count>=k)	return root;
		}else if(k==1)	return root;
		return rankk(root->rs, k-(root->ls?root->ls->siz:0)-root->count);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}