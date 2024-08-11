---
title: P1445 [Violet] 樱花 题解
date: 2024-7-1 21:30:21
tags: 题解笔记
mathjax: true
---

# P1445 [Violet] 樱花 题解

## 题面

给定正整数 $n$，求有多少组正整数有序数对 $(x,y)$ 满足 $\frac{1}{x}+\frac{1}{y}=\frac{1}{n!}$。

## Solution

### 拆式子

观察式子 $\frac{1}{x}+\frac{1}{y}=\frac{1}{n!}$，同分后移项得到 $x\times y-n!\times (x+y)=0$，注意到这个式子中既含有 $x$ 与 $y$ 的乘积又含有它们的和，想到韦达定理，因此两边添加二次项 $(n!)^2$，然后因式分解得到：

$$(n!-x)(n!-y)=(n!)^2$$

对于任意一个 $x,y$ 满足给定条件的，一定对应着一种 $(n!-x)(n!-y)$ 的乘积方式，也就一定对应着 $(n!)^2$ 的一种分解方式。即每一种 $a,b\in \N$ 使得 $a\times b=(n!)^2$，就对应着唯一一组 $x,y$ 满足 $x=n!-a, y=n!-b$，也就对应着一组解。而行相对应的，一个 $a$ 就能得到唯一一个 $b=\frac{(n!)^2}{a}$，因此对于每一个 $a|n$ 都能得到一个整数对 $x,y$ 作为一组解。

于是问题就转化成了 $(n!)^2$ 有多少个因子。

### 实现

设 $n!=\prod p_i^{\alpha_i}$，那么 $(n!)^2=\prod p_i^{2\times \alpha_i}$，最后的答案就是 $\prod(2\times \alpha_i+1)$。

于是很自然地想到线性筛出 $n$ 以内的指数作为唯一分解定理中的 $p_i$，在指数上，每隔 $p_i$ 就能够乘一次 $p_i$，而每隔 $p_i^2$ 个数 $p_i$ 又能被多乘一次，因此指数上就是

$$\sum_{j=1}^{p_i^j\le n}\frac{n}{p_i^j}$$

## CODE

``` cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n,p[N],cnt,ans=1,a[N];

void prime(){
	for(int i=2;i<=n;++i){
		if(!p[i])	p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<=n;++j){
			p[p[j]*i]=1;
			if(i%p[j]==0)	break;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n; prime();
	for(int i=1;i<=cnt;++i)
		for(int j=p[i];j<=n;j=j*p[i])	a[i]+=n/j;
	for(int i=1;i<=cnt;++i)
		ans=ans*(2*a[i]+1)%MOD;
	cout<<ans;
	return 0;
}
```