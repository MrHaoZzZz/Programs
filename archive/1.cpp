/*
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define int long long
int a[MAXN], n, ans;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ans = a[1] + a[n];
    cout << ans << endl;
    return 0;
}
*/

#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;

void input(std::vector<ll>& arr) {
    ll length{};
    std::cin >> length;
    for (ll i = 0; i < length; ++i) {
        ll temp{};
        std::cin >> temp;
        arr.push_back(temp);
    }
}

ll solve(const std::vector<ll>& a) {
    return a.front() + a.back();
}

int main() {
    std::vector<ll> arr;
    input(arr);
    std::sort(arr.begin(), arr.end());
    std::cout << solve(arr) << '\n';
    return 0;
}