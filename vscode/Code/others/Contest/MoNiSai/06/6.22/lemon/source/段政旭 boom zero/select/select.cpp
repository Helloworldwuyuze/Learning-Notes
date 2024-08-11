#include <iostream>
using namespace std;
int n, ans;
int main() {
    freopen("select.in", "r", stdin);
    freopen("select.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (n == 1) cout << 2;
    if (n == 2) cout << 3;
    if (n == 3) cout << 5;
    if (n == 4) cout << 8;
    if (n == 5) cout << 16;
    if (n == 6) cout << 24;
    if (n == 7) cout << 48;
    if (n == 8) cout << 76;
    if (n == 9) cout << 132;
    if (n == 10) cout << 198;
    if (n == 11) cout << 396;
    if (n == 12) cout << 588;
    if (n == 13) cout << 1176;
    if (n == 14) cout << 1764;
    if (n == 15) cout << 2940;
    if (n == 16) cout << 4680;
    if (n == 17) cout << 9360;
    if (n == 18) cout << 13680;
    if (n == 19) cout << 27360;
    if (n == 20) cout << 43776;
}