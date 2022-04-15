#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#define gap                        ' '
#define EPS                        1e-9
#define P_INF                      2e9+17
#define N_INF                     -2e9-17
#define MOD                        1000000007
#define PI                         2*acos(0.0)
#define All(x)                     x.begin(),x.end()
#define Mem(Name, type)            memset(Name, type, sizeof(Name))

template<typename T>
T GCD(T a, T b) { return a ? GCD(b % a, a) : b; }

template<typename T>
T LCM(T a, T b) { return (a * b) / GCD(a, b); }

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    for (auto ob: v) os << ob << " ";
    return os;
}

using namespace std;

class MinimizingCoins {

    vector<int> coins, dp;

    int miniCoins(int amount) {
        if (amount < 0) return P_INF;
        else if (amount == 0) return 0;
        else if (dp[amount] != -1) return dp[amount];

        int cur = 0, mini = P_INF;
        for (int i = 0; i < coins.size(); ++i) {
            cur = 1 + miniCoins(amount - coins[i]);
            mini = min(mini, cur);
        }
        return dp[amount] = mini;
    }

public:
    void solve(std::istream &in, std::ostream &out) {
        int n, x;
        in >> n >> x;
        coins.resize(n);
        dp.resize(x + 1, -1);
        for (int &x: coins) in >> x;

        int mini = miniCoins(x);
        if (mini == P_INF) out << -1 << endl;
        else out << mini << endl;
    }
};
