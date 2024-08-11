---
title: Tree 题解
date: 2024-7-1 21:30:21
tags: 题解笔记
mathjax: true
---

# Tree (CF1111E)

## Des

给定一棵树和若干次询问。每次询问有若干个数，前三个为 $k,m,r$ 分别表示节点数量，分组数量和根节点。即选中树上的 $k$ 个节点，在 $r$ 为根的情况下至多分成 $m$ 组有多少种分法，要求每个组内不能出现祖先关系。

其中 $\sum k\le 10^5, m\le 300$。

## Sol

是不是一眼虚树，但其实完全没必要。考虑动态规划。我们发现一个点能分到哪几个组里只与它有多少个关键节点祖先有关。因此，我们可以假设我们已经知道了它有多少个祖先，并且都做完了这些祖先的动态规划，然后试着转移当前节点。

因为 $m$ 很小，所以我们完全可以设成二维的状态 $f_{i,j}$ 表示前 $i$ 个点分成 $j$ 组的方案数。那么一个点可以分到原来的组里面，也可以自己一个组。而它不能分到祖先在的组里面。因此，我们设 $s(u)$ 表示 $u$ 有多少个关键节点祖先，那么很容易得到转移方程：

$$f_{i,j} = \max\{ j - s(i), 0\}\times f_{i-1, j} + f_{i-1, j-1}$$

然后就可以考虑如何先计算祖先。我们发现可以提前把点按照 $dfn$ 排序，这样就一定能够保证祖先在 $u$ 之前就被处理到。但是每一次的根节点不一样，因此我们可以考虑先计算出 $s(u)$，这样 $s(u)$ 小的一定是大的的祖先。那么 $s(u)$ 使用树剖求 $(r, u)$ 路径上的关键节点数量即可。复杂度 $O(n\log^2n +nm)$。

## Code

```cpp
#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 3e2 + 10;
const int MOD = 1e9 + 7;

int n,q,m,k,r;
int a[N], s[N], f[N][M];
vector<int> g[N];

namespace BIT{
	int b[N];
	#define lowbit(x) (x&-x)
	void update(int x,int k){ for(int i=x;i<=n;i+=lowbit(i))	b[i]+=k;}
	int query(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))	ans+=b[i]; return ans;}
	#undef lowbit
}

namespace cut{
	int dfn[N], rk[N], top[N], siz[N], son[N], dep[N], fa[N], idx;
	void dfs1(int x,int fat){
		fa[x] = fat, siz[x] = 1, dep[x] = dep[fat]+1;
		for(int y:g[x]){
			if(y==fat)	continue;
			dfs1(y,x);
			siz[x]+=siz[y];
			if(siz[y]>siz[son[x]])	son[x]=y;
		}
	}
	void dfs2(int x,int tp){
		top[x] = tp, dfn[x] = ++idx, rk[idx] = x;
		if(son[x])	dfs2(son[x], tp);
		for(int y:g[x])
			if(y!=son[x] && y!=fa[x])	dfs2(y, y);
	}
	int query(int x,int y){
		int ans = 0;
		while(top[x] != top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			// cout<<x<<" "<<y<<" "<<top[x]<<endl;
			ans += BIT::query(dfn[x]) - BIT::query(dfn[top[x]]-1);
			x = fa[top[x]];
		}
		if(dep[x]<dep[y])	swap(x,y);
		// cout<<x<<" "<<y<<endl;
		return ans + BIT::query(dfn[x]) - BIT::query(dfn[y]-1);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i=2, x, y; i<=n; ++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	cut::dfs1(1, 0), cut::dfs2(1, 1);
	while(q--){
		cin>>k>>m>>r;
		for(int i=1;i<=k;++i)	cin>>a[i], BIT::update(cut::dfn[a[i]], 1);
		for(int i=1;i<=k;++i)	s[i] = cut::query(a[i], r) - 1;
		// for(int i=1;i<=k;++i)	cout<<s[i]<<" ";
		// cout<<endl;
		sort(s+1, s+1+k);
		f[1][1] = 1;
		for(int i = 2; i<=k; ++i)
			for(int j = 1, _end = min(i, m); j<=_end; ++j)
				f[i][j] = (max(j-s[i], 0ll) * f[i-1][j] % MOD + f[i-1][j-1]) % MOD;
		int ans = 0;
		for(int i=1;i<=m;++i)	ans = (ans + f[k][i]) % MOD;
		cout<<ans<<endl;
		for(int i=1;i<=k;++i)	BIT::update(cut::dfn[a[i]], -1);
	}
	return 0;
}
```