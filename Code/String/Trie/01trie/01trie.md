# 01-Trie

## 介绍

$01-Trie$ 是一类解决有关异或问题的工具。它支持插入、删除、全局 $+1$、求异或和、求最大异或值的问题。

## 异或和 $01-Trie$

### 插入，删除操作

首先我们明确 $01-Trie$ 的基本形态。它类似于一个动态开点线段树。每个节点有两个儿子 $t_{p,0}$ 和 $t_{p,1}$ 分别表示下一位是 $0/1$ 的编号是多少。这里我们的 $Trie$ 树维护的二进制串是从最低位开始的。而我们需要维护三个信息：

- $t_{p,0/1}$，表示下一位是 $0/1$ 时的儿子编号是多少。这与普通的 $Trie$ 相同。
- $w_p$，表示最后落在 $p$ 子树内的数有多少个。也可以理解为经过 $(p,fa_p)$ 这条边的数的数量。
- $sum_p$，表示 $p$ 子树内的异或和。注意这里以 $p$ 为根节点就不需要考虑 $p$ 以上的部分，也就是原来 $11010$ 的东西现在可能是 $01011,1011,011,11$ 或者 $1$。

对于最终的异或和的答案，我们只关心在某一条 $1$ 边，它的 $w$ 是多少。因为只有权值是 $1$ 且经过次数为奇数的边才会对答案产生贡献。那么不难想到：

$$sum_{p}=sum_{t_{p,0}}\times2+sum_{t_{p,1}}*2+(w_{t_{p,1}}\&1)$$

这表示左儿子和右儿子的异或和分别乘以二，然后看 $1$ 边的奇偶情况选择加不加。

于是代码也很简单了。

```cpp
#define ls(p) t[p][0]
#define rs(p) t[p][1]
void push_up(int p){
	w[p]=sum[p]=0;
	if(ls(p))	w[p]+=w[ls(p)], sum[p]^=sum[ls(p)]<<1;
	if(rs(p))	w[p]+=w[rs(p)], sum[p]^=(sum[rs(p)]<<1)|(w[rs(p)]&1);
	w[p]&=1;
}
void update(int &p,int x,int dep){
	if(!p)	p=++idx;
	if(dep>MAXN)	return (void)(++w[p]);
	update(t[p][x&1],x>>1,dep+1);
	push_up(p);
}
```

注意，删除操作其实和增加没有区别。因为再增加一次就相当于在异或和当中把它删除掉了。

### 全局 $+1$

首先我们观察二进制下加一的规律。

```cpp
00000 + 1 = 00001
00111 + 1 = 01000
10101 + 1 = 10110
```

相信大家已经观察出来了，对于某一位 $i$，它 $+1$ 就代表它由 $0\to 1$ 或者 $1\to 0$，而如果它的下一位仍然是 $1$，就继续到下一位进行操作。

这样就不难得出我们的代码：

```cpp
void alladd(int p){
	swap(ls(p), rs(p));
	if(ls(p))	alladd(ls(p));
	push_up(p);
}
```

### 合并

其实和线段树的合并都差不多，分为以下几个步骤：

1. 如果 $p$ 或者 $q$ 为空，就直接返回 $p+q$。( $coduck$祖传)
2. `w[p]+=w[q], sum[p]^=sum[q];`
3. 对左、右儿子继续进行合并操作。

复杂度应该仍然是均摊 $n\log n$。注意这里不需要再 `push_up` 来更新了。

```cpp
int merge(int p,int q){
	if(!p||!q)	return p+q;
	w[p]+=w[q], sum[p]^=sum[q];
	ls(p)=merge(ls(p),ls(q)), rs(p)=merge(rs(p),rs(q));
	return p;
}
```

## 最大异或路径 $01-Trie$

问题是给定序列，求

$$\max\limits_{i=1,j=1}^n a_i \oplus a_j$$

我们考虑枚举 $i$，然后执行下列操作：

- 在字典树中查询可以与 $i$ 组成的最大异或和的数，算入答案。
- 将 $i$ 插入字典树。

关键在于如何查询。

### 最大异或

这个 $01-Trie$ 是从最高位开始插入的。我们一般设 `MAXN=31`。

插入与普通 $Trie$ 基本一样，但是，在查询的时候，我们需要自己选择路径走。我们设当前查询的数的二进制是 $\{b_n\}$，于是：

- 如果 $t_{p,!b_i}$ 存在，那么进入 $t_{p,!b_i}$ 并且将 `1<<dep-1` 计入答案。
- 否则，如果 $t_{p,b_i}$ 存在，那么进入 $t_{p,b_i}$。
- 否则，返回 `ans`。

因为我们知道 $\sum\limits_{i=1}^n 2^i< 2^{n+1}$，因此我们随时要保证最高位最大才能够保证最后结果最大。因此就有这上述的贪心做法。

```cpp
int query(_2 x){
	int p=0, dep=31, ans=0;
	for(int i=0;i<31;++i, --dep)
		if(t[p][!x.b[i]])	ans+=(1<<dep-1), p=t[p][!x.b[i]];
		else if(t[p][x.b[i]])	p=t[p][x.b[i]];
		else	return ans;
	return ans;	
}
```

## $01-Trie$ 做平衡树

让我们回顾一下 **【模板】普通平衡树**，不难发现，插入、删除和查询区间查排名、拿排名查值的操作，我们的 $01-trie$ 因为有线段树的特性显然这两个可以用线段树的东西也是可以用 $01-trie$ 的。而对于查询前驱和后继，我们直接查询排名为当前值 +1/-1 的值即可。

```cpp
const int MAXH = 30;

int n, op, x, m;
const int ADD = 1e7;

int t[N<<5][2], w[N<<5], idx = 1;

void insert(int x,int k){
	int p = 1;
	for(int i=MAXH;i>=0;--i){
		if(!t[p][(x>>i)&1])	t[p][(x>>i)&1] = ++idx;
		w[p]+=k;
		p = t[p][(x>>i)&1];
	}
	w[p]+=k;
}
int GRBV(int x){
	int p = 1, ans = 0;
	for(int i=MAXH;i>=0;--i){
		if(((x>>i)&1))	ans += w[t[p][0]];
		p = t[p][(x>>i)&1];
		if(!p)	return ans+1;
	}
	return ans+1;
}
int GVBR(int x){
	int p = 1, ans = 0;
	for(int i=MAXH;i>=0;--i){
		if(w[t[p][0]] >= x)	p = t[p][0];
		else	x -= w[t[p][0]], p = t[p][1], ans += (1<<i);
	}
	return ans;
}
int pre(int x){
	return GVBR(GRBV(x)-1);
}
int nxt(int x){
	return GVBR(GRBV(x+1));
}
```

其中，有一些需要注意的点：

1. 因为值域为 $[-10^7, 10^7]$，而 $01-trie$ 处理不了负数，这就需要我们给值域整个加上 $10^7$。
2. $idx$ 一定要从 $1$ 开始，否则可能会出现无 左/右 儿子但是却仍然会访问到 $0$ 节点导致错误。