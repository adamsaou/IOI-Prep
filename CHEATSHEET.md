# C++ / CP Cheat Sheet

My personal quick-reference. Claude adds to it after each exercise. If I forget how to do
something, it's probably here.

*Last updated: 2026-07-23*

---

## 🧰 Starter template
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    // read input → solve → print
    return 0;
}
```

## ✅ Before every submit — the checklist
1. **Overflow?** sum / product / difference > ~2.1×10⁹ → use `long long`. *Compute the bound, don't guess.*
2. **Init?** seed max/min from a **real element**, never `0`.
3. **Boundaries?** N=1, first/last element, ties, duplicates. (Loop bound `i < n`, not `i < n-1`!)
4. **Tested?** ran the sample **and** one nasty case I invented.

## 🧪 How to invent a "nasty case" that actually bites
The sample is the *easy* case — passing it proves nothing. Build one that fights back:
- **Sorting / tie-break:** make the tie-break **conflict** with the primary key (the item that should win on the primary key *loses* on the secondary). Ties on the primary that force the tie-break to matter.
- **Max / min:** put the answer **not last** and out of order, e.g. `10 40 20 30`.
- **Numbers:** biggest allowed values (overflow), all-negative, `N=1`, duplicates.

## ⏱️ Constraints → complexity  (budget ≈ 10⁸ operations / sec)
Read N and pick your target complexity **before** coding:

| N up to | Allowed complexity | Typical tool |
|---|---|---|
| ~10–12 | O(N!) , O(2ᴺ) | brute force / permutations |
| ~20–25 | O(2ᴺ) | subsets / bitmask |
| ~500 | O(N³) | triple loop |
| ~5,000 | O(N²) | double loop |
| ~10⁵–10⁶ | O(N log N) , O(N) | sort, two pointers, prefix sums |
| ~10⁷–10⁸ | O(N) | single pass |

If your idea is slower than the budget → **it's the wrong idea, find a better tool.**

## 🔢 Numbers & overflow
- `int` maxes out near **2.1×10⁹**. Adding many big numbers overflows → use `long long`.
- `accumulate(v.begin(), v.end(), 0LL)` — the `0LL` matters, or it adds up **in `int`** and overflows!
- Negative modulo: `-4 % 2 == 0` ✓ but `-3 % 2 == -1` (not 1). → test even with `% 2 == 0`; never test odd with `% 2 == 1`.
- **`long long` is NOT slower** for a single variable/accumulator on a 64-bit judge — identical speed to `int`. It only costs on: huge **arrays** (2× memory → cache), heavy `/` and `%` in hot loops, or 32-bit compilers. → **`int` for big arrays, `long long` for sums/accumulators.**
- ⚠️ **Constraints are a promise, not a suggestion.** If it says `N ≤ 2·10⁵`, a test with `N = 2·10⁵` **exists**. Never assume the input will be smaller or nicer than stated — that assumption is a WA factory.

## 🏗️ Structs — bundle related data
```cpp
struct Point { int x, y; };        // <-- don't forget the semicolon

Point a;  a.x = 3;  a.y = 5;       // access fields with .
Point b = {3, 5};                  // or set all at once (declaration order)

vector<Point> v(n);
for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;   // read straight into fields
```
Common uses: points `{x,y}`, edges `{u,v,w}`, intervals `{l,r}`.

## 🔎 Find max / min → SCAN (don't sort!)
Just need the biggest/smallest? An O(N) loop beats an O(N log N) sort:
```cpp
Point best = v[0];                     // seed from a REAL element
for (int i = 1; i < n; i++)            // i < n  → check EVERY element
    if (v[i].y > best.y) best = v[i];
```
Rule: **need max/min → scan. Need everything in order → sort.**
⚠️ Compare each element to your **running best** (`best`), NOT to its neighbor (`v[i+1]`). Neighbor-comparison does **not** find the max.

## 🔀 Sorting
```cpp
sort(v.begin(), v.end());                  // ascending (default)
sort(v.begin(), v.end(), greater<int>());  // descending (for ints)
```

**Custom comparator** = a function returning `true` if `a` should come **before** `b`:
```cpp
sort(v.begin(), v.end(), [](const T& a, const T& b){
    return a.key < b.key;    // '<' = ascending,  '>' = descending
});
```
- Take **both** args as `const T&`.
- Must be **strict**: use `<` / `>`, never `<=` / `>=`.

**Tie-break (multiple keys)** — check keys in order; the last line is an **unconditional** return:
```cpp
sort(v.begin(), v.end(), [](const Car& a, const Car& b){
    if (a.speed != b.speed) return a.speed > b.speed;  // key 1: speed, highest first
    return a.price < b.price;                          // tie → key 2: price, cheapest first
});
```
Rule: **N keys = (N−1) `if`-returns + 1 plain `return`.**
(If the last line is still an `if`, the function can end without answering → `sort` crashes.)
⚠️ **Order = priority: check the PRIMARY key FIRST**, then tie-break, then its tie-break. Checking a tie-break key too early sorts wrong when items are equal on it.
🧠 **Mental model = alphabetical order.** Compare key 1; the first key where they **differ** decides the winner. Tied on a key → move to the next. That's why `if (a.k != b.k) return …;` chains cleanly for any number of keys.
