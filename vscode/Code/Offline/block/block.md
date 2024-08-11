# 分块

## 基本思想

对于一个序列，我们希望区间修改区间查询，在普通情况下，这些操作都是 $O(n)$ 的，但如果我们维护的是前缀和或者是差分，询问 / 修改就可以变成 $O(1)$，但是在两种操作平均的情况下复杂度仍然渐进于 $O(nq)$。

于是，伟大的信息学家们发明了一系列数据结构来维护这个序列，例如线段树，树状数组，平衡树等等。

但我们今天的重点不在于此。我们希望一个兼容性高的算法，能够在较短的时间内做出大部分我们希望的事情。刚刚学完线性代数举行分块的你一拍脑子就想到了，如果一种操作是可以在较短时间内直接下发到一个区间内的，那么我们就可以将整个序列进行分组。假设我们分成 $B$ 组，共 $N$ 个数，每组包含 $\frac{N}{B}$ 个数。那么对于一次询问或修改操作，必然包含了一些整块和一些散块。其中处理整块的复杂度为整块数量 $O(B)$，而散块的复杂度为每个块内的元素数量即 $O(\frac{N}{B})$。于是我们把它们加起来，然后用均值不等式求最小值，就得到 $O(B+\frac{N}{B})\ge O(2\sqrt N)$ 在 $\frac{N}{B}=B$，即 $B=\sqrt N$ 时取等。

这样，**分块** 就诞生了。它是一种优雅的暴力，优雅的根号算法，虽然渐进意义上不如 $O(\log n)$ 优秀，但是仍然是比赛时的不错选择。

## 细节处理

虽然思想简单，但是实现的时候细节仍然需要注意。

- 在预处理块的时候，我们需要记录 `blk[N],l[BLOCK],r[BLOCK],cnt,nn` 这五个基本信息。它们分别表示 **每个位置属于哪个块**、**每个块的左 / 右端点在哪**、**块的数量** 以及 **每个块的大小**。
- 在修改 / 查询的时候，我们需要首先判断这个区间在不在一个整块，然后再处理 左/右 端点所在的散块、和中间的整块。在处理散块的时候，复杂度是允许我们对于整个散块进行下穿标记、重新建立等操作的。这是分块兼容性好的一大原因。

## 例题

### [P2801 教主的魔法]([P2801 教主的魔法 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P2801))

要求区间加区间 $\text{kth}$。

考虑对于原序列进行分块，然后对每一个块排序。这样我们得到了两份数组，一份是原序列，另一份是排好序的序列。

- 对于查询，我们在散块内暴力统计大于它的数的数量，在每个整块我们进行二分求取有多少个数大于它。复杂度 $O(\frac{n}{k}\log n)$






