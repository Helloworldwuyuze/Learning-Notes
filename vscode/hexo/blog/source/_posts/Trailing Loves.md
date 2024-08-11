---
title: Trailing Loves 题解
date: 2024-7-1 21:29:21
tags: 题解笔记
mathjax: true
---

# Trailing Loves

## 题意

给定一个数 $n$ 求 $n!$ 在 $b$ 进制下末尾 0 的个数。

## Solution

很容易想到的是 $n!$ 中有多少个因子 $b$ 就能在末尾产生多少个 0。那么假设

$$b=\prod_{i=1}^{k} p_i^{\alpha_i}，n!=\prod_{j=1}^{m} p_j^{\beta_j}$$

那么我们就只需要一一对应 $b$ 含有的质因子，取

$$\min_{i=1}^k\{\frac{\beta_i}{\alpha_i}\}$$

为答案即可。

其中 $n!$ 的因子 $p_j$ 的指数可以表示为

$$\beta_j=\sum_{i=1}^{p_i\le n}\frac{n}{p^i}$$

## CODE

```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,b,p[N],minn=INF,cnt;

int fun(int x){
	int ans=0;
	int m=n;
	while(m)    ans+=m/x, m/=x;
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>b;
	for(int i=2;i*i<=b;++i){
		int sum=0;
		while(b%i==0)	++sum, b/=i;
		if(sum==0)	continue;
		minn=min(minn,fun(i)/sum);
	}
	if(b!=1)	minn=min(minn,fun(b));
	cout<<minn<<endl;
	return 0;
}
```