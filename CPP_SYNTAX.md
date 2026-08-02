# C++ Syntax Cheat Sheet — never Google basic syntax again

Copy-paste reference for everything you'll use in Bronze→Silver. `Ctrl+F` to the topic.
*(For the deeper "why" and the bug-gotchas we've hit, see `CHEATSHEET.md`. Last updated 2026-07-24.)*

---

## Starter template
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;                 // or: using ll = long long;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);   // fast IO

    return 0;
}
```

## Types & constants
```cpp
int  a = 5;             // ~ ±2.1e9
ll   b = 5;             // ~ ±9.2e18  — use for sums/products/anything past 2e9
double d = 3.14;        // approximate — never compare with ==
char c = 'a';
bool flag = true;
string s = "hi";

const int INF   = 1e9;      // safe "infinity" for int  (you can add to it)
const ll  INF64 = 4e18;     // safe "infinity" for long long
const int MOD   = 1e9 + 7;
```

## Input / Output
```cpp
int n; cin >> n;                     // one value
cin >> a >> b >> c;                  // several (spaces/newlines don't matter)
for (int i = 0; i < n; i++) cin >> v[i];      // read n values
while (cin >> x) { /* ... */ }       // read until end of input (no count given)

cout << ans << "\n";                 // use '\n', NOT endl (endl flushes = slow)
cout << fixed << setprecision(6) << d << "\n";   // 6 decimals

string line;
getline(cin, line);                  // whole line, including spaces
// after `cin >> x`, call cin.ignore() before getline to skip the leftover newline

// split a line with an unknown number of tokens:
getline(cin, line);
istringstream ss(line);
int x; while (ss >> x) { /* ... */ }
```

## Loops & conditionals
```cpp
for (int i = 0; i < n; i++) { }
for (int x : v)   { }                // range-based, read-only
for (auto &x : v) { x *= 2; }        // by reference — can modify
while (cond) { }
if (a == b) { } else if (c) { } else { }
int y = cond ? A : B;                // ternary
```

## Strings
```cpp
string s = "hello";
s.size();                            // length
s[0];  s.back();
s += "!";                            // append
s == "hello";                        // compare
s.substr(1, 3);                      // from index 1, length 3
s.find("ll");                        // index, or string::npos if absent
int digit = c - '0';                 // char '7' -> int 7
char up = toupper(c);                // RETURNS new char (doesn't change c)
int v = stoi(s);                     // string -> int   (stoll for long long)
string t = to_string(42);            // number -> string
sort(s.begin(), s.end());            // sort the characters
```

## Vectors (resizable arrays)
```cpp
vector<int> v;                       // empty
vector<int> v(n);                    // n zeros
vector<int> v(n, 7);                 // n sevens
vector<int> v = {1, 2, 3};
v.push_back(9);   v.pop_back();
v.size();  v.empty();
v[i];  v.front();  v.back();
v.clear();
sort(v.begin(), v.end());

vector<vector<int>> g(R, vector<int>(C, 0));   // R x C grid of zeros
int arr[100005];                     // fixed array — put BIG ones at global scope
```

## Sorting & comparators
```cpp
sort(v.begin(), v.end());                    // ascending
sort(v.begin(), v.end(), greater<int>());    // descending
sort(v.rbegin(), v.rend());                  // descending (reverse iterators)

// custom: return true if a should come BEFORE b
sort(v.begin(), v.end(), [](const T& a, const T& b){
    return a.x < b.x;                // '<' ascending, '>' descending
});

// multi-key tie-break: check keys in order, last line is an UNCONDITIONAL return
sort(v.begin(), v.end(), [](const T& a, const T& b){
    if (a.x != b.x) return a.x > b.x;    // primary
    if (a.y != b.y) return a.y < b.y;    // tie -> secondary
    return a.z < b.z;                    // tie -> tertiary
});
```

## Pairs & structs
```cpp
pair<int,int> p = {3, 4};
p.first;  p.second;
vector<pair<int,int>> vp;
vp.push_back({a, b});                // pairs sort by first, then second, for free
auto [x, y] = p;                     // structured binding

struct Point { int x, y; };          // don't forget the ;
Point q = {3, 5};
q.x;  q.y;
vector<Point> pts(n);
cin >> pts[i].x >> pts[i].y;
```

## set / multiset  — sorted, unique, O(log n) add/find/erase
```cpp
set<int> s;
s.insert(5);
s.count(5);                          // 1 if present, else 0
s.erase(5);
s.size();
*s.begin();                          // smallest    *s.rbegin(); // largest
s.find(5);                           // iterator, or s.end() if absent
s.lower_bound(5);                    // first >= 5   (member call = O(log n))
s.upper_bound(5);                    // first > 5
for (int x : s) { }                  // iterates in sorted order

multiset<int> ms;                    // allows duplicates
ms.erase(ms.find(5));                // erase ONE 5   (ms.erase(5) erases ALL of them)
```

## map  — key -> value, sorted by key, O(log n)
```cpp
map<string,int> m;
m["apple"] = 3;
m["apple"]++;                        // count occurrences of a key
m.count("apple");                    // 1 if key exists, else 0
m.size();
for (auto &[key, val] : m) { }       // iterate in sorted KEY order
// WARNING: reading m[k] for a missing key INSERTS it (value 0). Use m.count(k) to just check.

unordered_map<int,int> um;           // hash, ~O(1), no order.
                                     // on Codeforces can be hacked -> TLE; prefer map when unsure.
```

## stack / queue / deque / priority_queue
```cpp
stack<int> st;  st.push(x);  st.top();   st.pop();  st.empty();   // LIFO
queue<int> q;   q.push(x);   q.front();  q.pop();   q.empty();    // FIFO (BFS)
deque<int> dq;  dq.push_back(x); dq.push_front(x); dq.front(); dq.back();

priority_queue<int> pq;                              // MAX-heap (biggest on top)
pq.push(x);  pq.top();  pq.pop();
priority_queue<int, vector<int>, greater<int>> mn;   // MIN-heap
```

## Handy STL algorithms
```cpp
max(a,b);  min(a,b);  max({a,b,c});  swap(a,b);  abs(x);  __gcd(a,b);

*max_element(v.begin(), v.end());                 // max value
max_element(v.begin(), v.end()) - v.begin();      // ...its index
accumulate(v.begin(), v.end(), 0LL);              // sum — 0LL avoids int overflow!
count(v.begin(), v.end(), x);                     // how many equal x
reverse(v.begin(), v.end());
fill(v.begin(), v.end(), 0);

// distinct values: sort, then erase-unique
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

// binary search on a SORTED vector:
lower_bound(v.begin(), v.end(), x) - v.begin();   // index of first >= x
upper_bound(v.begin(), v.end(), x) - v.begin();   // index of first  > x
binary_search(v.begin(), v.end(), x);             // true / false

// all permutations (must sort first):
sort(v.begin(), v.end());
do { /* ... */ } while (next_permutation(v.begin(), v.end()));
```

## Math & numbers (the traps)
```cpp
7 / 2;                 // 3   (integer division truncates toward zero)
7 % 2;                 // 1
-7 % 5;                // -2  (sign follows the dividend!)  true mod: ((a%b)+b)%b
(long long)a * b;      // cast an OPERAND before the multiply, not the result
n * (n+1) / 2;         // sum 1..n / pair count — long long if n is big
__gcd(a, b);           // gcd
a / __gcd(a,b) * b;    // lcm — divide FIRST to avoid overflow
// avoid pow() / sqrt() for exact integer answers — they're floating point
```

## Bit tricks
```cpp
(x >> i) & 1;          // is bit i set?
x | (1 << i);          // set bit i
x & ~(1 << i);         // clear bit i
1LL << i;              // use LL when i >= 31
__builtin_popcountll(x);   // count set bits (the ...ll version for long long)
```

## Reusable idioms
```cpp
// frequency count
map<int,int> freq;
for (int x : v) freq[x]++;

// prefix sums (1-indexed): pre[i] = sum of the FIRST i elements
vector<ll> pre(n + 1, 0);
for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + a[i-1];
// sum of positions l..r (1-indexed) = pre[r] - pre[l-1]

// linear max — seed from a REAL element, never 0
ll best = a[0];
for (int i = 1; i < n; i++) best = max(best, a[i]);

// grid: visit the 4 neighbors (bounds-check BEFORE access)
int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
for (int d = 0; d < 4; d++) {
    int nr = r + dr[d], nc = c + dc[d];
    if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
    // ... use grid[nr][nc]
}
```
