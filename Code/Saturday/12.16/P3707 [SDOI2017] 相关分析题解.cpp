#include <iostream>
#include <cstdio>
#include <cstring>
#define space putchar(' ')
#define endl putchar('\n')
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
typedef double db;
typedef long double LD;
namespace io { //fast read && write 可以直接不管
    bool FREAD = false; //do you need to use fread?
    void fastio()
    {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
    }
    char buf[1 << 21], *p1 = buf, *p2 = buf;
    inline char getc()
    {
        if (!FREAD) return getchar();
        if (p1 == p2) p2 = buf + fread(buf, 1, 1 << 21, stdin), p1 = buf;
        return *(p1++);
    }
    inline int read()
    {
        char op = getc(); int x = 0, f = 1;
        while (op < 48 || op > 57) {if (op == '-') f = -1; op = getc();}
        while (48 <= op && op <= 57) x = (x << 1) + (x << 3) + (op ^ 0x30), op = getc();
        return x * f;
    }
    inline void write(int x)
    {
        if (x < 0) putchar('-'), x = -x;
        if (x > 9) write(x / 10);
        putchar(x % 10 + 0x30);
    }
} using namespace io;
const int N = 1e5 + 5;
db kx[N], ky[N];
struct Node
{
	db x, y, xx, xy, s, t;
	bool cov;
    Node() {x = y = xx = xy = s = t = cov = 0;}
} tr[N << 2];
Node operator +(Node a, Node b)
{
	Node ans;
	ans.x = a.x + b.x;
	ans.y = a.y + b.y;
	ans.xx = a.xx + b.xx;
	ans.xy = a.xy + b.xy;
	return ans;
}
struct SegmentTree
{
    int ls(int x) {return x << 1;}
    int rs(int x) {return x << 1 | 1;}
    void pushup(int pos) {tr[pos] = tr[ls(pos)] + tr[rs(pos)];}
    void build(int l, int r, int pos)
    {
        if (l == r)
        {
            tr[pos].x = kx[l], tr[pos].y = ky[l];
            tr[pos].xx = kx[l] * kx[l];
            tr[pos].xy = kx[l] * ky[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, ls(pos));
        build(mid + 1, r, rs(pos));
        pushup(pos);
    }
    db sqsum(db x) {return x * (x + 1) * (2 * x + 1) / 6;} //1*1 + 2*2 + ... + x*x
    db sqsum(int l, int r) {return sqsum(r) - sqsum(l - 1);} //l*l + ... + r*r
    void rebuild(db l, db r, int pos) //重建 xi = yi = i
    {
        tr[pos].s = tr[pos].t = 0, tr[pos].cov = true;
        tr[pos].x = tr[pos].y = (l + r) * (r - l + 1) / 2; //等差数列求和
        tr[pos].xx = tr[pos].xy = sqsum(l, r);
    }
    void lazy(int l, int r, int pos, db S, db T)
    {
        tr[pos].s += S, tr[pos].t += T;
        tr[pos].xy += T * tr[pos].x + S * tr[pos].y + S * T * (r - l + 1); //对比原xy暴力展开即可 
        tr[pos].xx += 2 * S * tr[pos].x + S * S * (r - l + 1); //对比原xx暴力展开即可 
        tr[pos].x += S * (r - l + 1), tr[pos].y += T * (r - l + 1); 
    }
    void pushdown(int l, int r, int pos)
    {
        int mid = (l + r) >> 1;
        if (tr[pos].cov)
        {
            rebuild(l, mid, ls(pos));
            rebuild(mid + 1, r, rs(pos));
            tr[pos].cov = false;
        }
        lazy(l, mid, ls(pos), tr[pos].s, tr[pos].t);
        lazy(mid + 1, r, rs(pos), tr[pos].s, tr[pos].t);
        tr[pos].s = tr[pos].t = 0;
    }
    void update(int L, int R, int l, int r, int pos, db S, db T)
    {
        if (L <= l && r <= R) return lazy(l, r, pos, S, T);
        pushdown(l, r, pos);
        int mid = (l + r) >> 1;
        if (L <= mid) update(L, R, l, mid, ls(pos), S, T);
        if (mid < R) update(L, R, mid + 1, r, rs(pos), S, T);
        pushup(pos);
    }
    void modify(int L, int R, int l, int r, int pos, db S, db T)
    {
        if (L <= l && r <= R)
        {
            rebuild(l, r, pos), lazy(l, r, pos, S, T);
            return;
        }
        pushdown(l, r, pos);
        int mid = (l + r) >> 1;
        if (L <= mid) modify(L, R, l, mid, ls(pos), S, T);
        if (mid < R) modify(L, R, mid + 1, r, rs(pos), S, T);
        pushup(pos);
    }
    Node query(int L, int R, int l, int r, int pos)
    {
        if (L <= l && r <= R) return tr[pos];
        pushdown(l, r, pos);
        int mid = (l + r) >> 1;
		Node ans;
		if (L <= mid) ans = ans + query(L, R, l, mid, ls(pos));
        if (mid < R) ans = ans + query(L, R, mid + 1, r, rs(pos));
        return ans;
    }
} seg;
int main()
{
    //freopen("C:\\Users\\User\\Desktop\\对拍\\data.txt", "r", stdin);
    //freopen("C:\\Users\\User\\Desktop\\cuojie.txt", "w", stdout);
    int n = read(), T = read();
    for (int i = 1; i <= n; i++) kx[i] = read();
    for (int i = 1; i <= n; i++) ky[i] = read();
    seg.build(1, n, 1);
    while (T--)
    {
        int op = read(), l = read(), r = read(), s = (op == 1 ? -1 : read()), t = (op == 1 ? -1 : read()); //压行 
        if (op == 1)
        {
            Node ans = seg.query(l, r, 1, n, 1); //抄公式
            db x = ans.x, y = ans.y, xx = ans.xx, xy = ans.xy;
            db fenzi = xy - x * y / (r - l + 1), fenmu = xx - x * x / (r - l + 1);
            printf("%.10lf\n", fenzi / fenmu);
        }
        else if (op == 2) seg.update(l, r, 1, n, 1, s, t);
        else if (op == 3) seg.modify(l, r, 1, n, 1, s, t);
    }
    return 0;
}
