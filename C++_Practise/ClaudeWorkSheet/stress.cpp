#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// =====================================================================
//  STRESS TEST  —  wired to "Perfect Pairs"
//
//  Idea: two solvers must ALWAYS agree. The moment they don't, we've
//  found a bug AND the tiny input that triggers it. To reuse this for
//  another problem, you only swap the 3 numbered parts below.
// =====================================================================


// ---------- 1. YOUR REAL SOLUTION (the "fast" one you'd submit) ----------
namespace Fast {
    ll solve(int n, vector<ll> a) {
        sort(a.begin(), a.end());
        ll total = 0;
        for (int i = 0; i < n; i += 2)
            total += llabs(a[i] - a[i + 1]);      // pair neighbours
        return total;
    }
}

// ---------- 2. THE BRUTE FORCE (the "oracle" you trust 100%) ----------
//  It does NOT know the greedy. It tries EVERY ordering, pairs the
//  neighbours in each ordering, and keeps the best total. Dead slow,
//  but the inputs are tiny, so who cares. Slow-but-obviously-correct.
namespace Brute {
    ll solve(int n, vector<ll> a) {
        sort(a.begin(), a.end());                 // next_permutation needs a sorted start
        ll best = LLONG_MAX;
        do {
            ll total = 0;
            for (int i = 0; i < n; i += 2)
                total += llabs(a[i] - a[i + 1]);
            best = min(best, total);
        } while (next_permutation(a.begin(), a.end()));
        return best;
    }
}

// ---------- 3. THE GENERATOR (makes tiny random inputs) ----------
mt19937 rng(12345);                                // fixed seed => same tests every run => reproducible
ll R(ll lo, ll hi) { return uniform_int_distribution<ll>(lo, hi)(rng); }

void gen(int &n, vector<ll> &a) {
    n = (int) R(1, 3) * 2;                         // even n: 2, 4, or 6
    a.assign(n, 0);
    for (auto &x : a) x = R(-5, 5);                // tiny values; negatives + duplicates ON PURPOSE
}


// ---------- THE LOOP: generate -> run both -> compare ----------
int main() {
    for (int iter = 1; iter <= 50000; iter++) {
        int n; vector<ll> a;
        gen(n, a);

        ll f = Fast::solve(n, a);
        ll b = Brute::solve(n, a);

        if (f != b) {                              // they disagreed -> bug found
            printf("MISMATCH on test %d\n", iter);
            printf("n = %d\na =", n);
            for (ll x : a) printf(" %lld", x);
            printf("\nfast  = %lld\nbrute = %lld\n", f, b);
            return 0;
        }
    }
    puts("OK - 50000 random tests passed, no mismatch found");
    return 0;
}
