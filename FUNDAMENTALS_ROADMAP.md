# Adam's 0→1 Competitive Programming Fundamentals Roadmap

*A single, gap-free, dependency-ordered checklist from "I can barely compile" to a rock-solid USACO Silver / Codeforces 1200+ foundation. Nothing at the start is skipped. Every tool arrives welded to the trigger that fires it, so you never learn a technique's name without knowing when to reach for it.*

---

## How to use this roadmap

- **~4 hours/week.** Realistic cadence: **one skill-group per session, ~2 problems + 2 drills per session.** Suggested pace below (adjust freely):
  - Stages 0–4 (mechanics): ~1 stage / week — batch the small drills.
  - Stages 5–9 (storage, sorting, correctness, math): ~1 stage / 1–2 weeks.
  - Stages 10–13 (containers, search, Bronze patterns): ~2 weeks each — these move your rating.
  - Stages 14–16 (prefix sums, Silver on-ramp, the bridge): slow, one technique at a time.
- **Concrete first, always.** For every new idea, read its **analogy** (💡), then **hand-trace a tiny example on real numbers (n = 2, 3)** *before* coding. If you can't trace it by hand, you don't understand it yet.
- **Run EVERY problem through this fixed pre-code ritual** (build the habit until it's automatic):
  1. **Read the statement into a contract:** input format, output format, constraint list, and *exactly what quantity is asked.*
  2. **Speed line:** write literally `N ≤ ____ so I can afford O(____) ≈ ____ ops`. No code before this line exists.
  3. **Trace** the idea by hand on n = 2, 3.
  4. Code it.
  5. **Pre-submit checklist** out loud: overflow · init · boundaries · tested.
  6. **Edge-case menu + stress test** before you trust it (Stage 9).
- **Two reflexes run through every single stage from day one** (they fix your two biggest weaknesses):
  - > 🧮 **OVERFLOW REFLEX** — multiply the constraint bounds in your head, compare to 2·10⁹, and size the type *before* coding.
  - > ⏱️ **SPEED REFLEX** — the instant you read N, say "N ≤ ___, so I can afford O(___)". Brute force is not an answer until you've checked it fits.
- **Two HARD GATES.** You may not begin the technique stages until the gates are *automatic*, not merely "understood":
  - **Gate A (complexity)** unlocks after Stage 8.
  - **Gate B (correctness/testing)** unlocks after Stage 9.
  - A stage's EXIT test is passed only when you can do it on **edge-case inputs without looking anything up** — not when it "makes sense."
- **`[x] (done)`** = you already own it; it's listed for a complete map — skim, don't re-grind. **`[ ]`** = to do.
- **Spaced review:** every 2 weeks, re-solve one earlier problem cold. Add one row to your `CHEATSHEET.md` **trigger table** (Appendix A) after *every* solved problem — that table is the direct cure for "knowing names without triggers."

---

## Stage 0 — The compile-run loop
**Goal:** turn text into a running, debuggable program on your Windows/MSYS2 g++ setup, and never be blocked by the toolchain again.
*Guide anchor: General → Expected Knowledge.*

- [ ] **Program skeleton, compile & run** — `#include <bits/stdc++.h>`, `using namespace std;`, `int main(){ return 0; }`; build `g++ -std=c++20 -O2 -Wall -Wextra f.cpp -o f.exe` then `./f.exe`. *Mistake: editing `f.cpp` but re-running an old `f.exe` (forgot to recompile) — "my change did nothing."*
- [ ] **Preprocessor & namespace basics** — `#include <bits/stdc++.h>` pulls in the whole STL; `using namespace std;` drops the `std::` prefix. *Mistake: naming a variable `count`, `y1`, or `next` — clashes with library names → cryptic errors.*
- [ ] **Read a compiler error** — deliberately break code (drop a `;`, misspell `cout`) and read g++'s message so errors stop being scary. *Mistake: panicking at the first line of red instead of reading the file:line it points to.*
- [ ] **Warnings as a debugging tool** — `-Wall -Wextra -Wshadow`; treat every warning as a probable bug, bake the flags into your build command. *Mistake: ignoring "may be used uninitialized" / "comparison of integer of different signedness" — those point straight at your WAs.*
- [ ] **Sanitizers early** — a debug build `g++ -std=c++20 -g -fsanitize=address,undefined f.cpp -o f.exe` names the file+line of out-of-bounds and signed overflow at runtime (MSYS2 g++ supports these). *Mistake: staring at code for an hour instead of letting the sanitizer locate the bug.*
- [ ] **Windows/MSYS2 specifics** — for deep recursion / huge local arrays, raise the stack at link time: `-Wl,--stack,268435456` (256 MB). Use `freopen("in.txt","r",stdin);` (or `< in.txt`) to feed a saved test locally. *Mistake: an unexplained crash that's really a stack overflow the default ~1–8 MB stack couldn't hold.*

**💡 Analogy:** the compiler is a strict copy-editor. Warnings are its margin notes; sanitizers are a proofreader that watches the program *run* and shouts the exact line where it misbehaves.

> **EXIT 0:** you can create, compile (warnings on), run, break-then-read-the-error, and feed a file as input — and you never confuse a stale `.exe` with a live one.

---

## Stage 1 — First AC: values in, answer out
**Goal:** get a real judge to say **Accepted** this week. Solve CSES *Weird Algorithm* and a CF "A+B".
*Guide anchor: General → Data Types. This stage is where most of your WAs are born — go slow.*

- [ ] **Statement → I/O contract** — before anything, translate the prose into: what tokens come in, in what order; what to print; and the single quantity asked. *Mistake: coding from a vague memory of the statement and solving the wrong problem.*
- [ ] **Variables & declaration** — `int x = 5;`: pick a type, name a box, put a value in. *Mistake: `int sum;` then using it — reads garbage (your init-to-0 weakness, named).*
- [ ] **`cin` / `cout` basics** — `cin >> x;` reads one whitespace-delimited token; `cout << x << '\n';` chains output. *Mistake: the judge sees only stdout — a trailing space, missing newline, or leftover debug line is a WA even with correct logic.*
- [ ] **Arithmetic operators & precedence** — `+ - * / %`; `* / %` bind before `+ -`; parens override. *Mistake: expecting `1/2` to be `0.5`.*
- [ ] **Integer division** — `int/int` truncates toward zero (`7/2==3`), dropping the remainder. Ceil for positives = `(a+b-1)/b`. *Mistake: `(a+b)/2` "average" that silently floors.*
- [ ] **Modulo, incl. negatives** — remainder's sign follows the dividend: `-7 % 5 == -2`, **not 3**. True math-mod = `((a%b)+b)%b`. *Mistake: `arr[(i-1)%n]` going negative → out-of-bounds.*
- [ ] **`int` and its ~2.1·10⁹ range** — 32-bit signed. Print `INT_MAX`; compute `INT_MAX+1` and watch it wrap negative. *Mistake: treating `int` as "big enough for anything."*
- [ ] **`long long` & overflow reasoning** — 64-bit (~9.2·10¹⁸); use when a value **or an intermediate product** can pass ~2·10⁹. *Trigger: any sum/product where `max_value × count` or `a·b` could exceed 2·10⁹ — multiply the bounds in your head first.* *Mistake: `long long ans = a * b;` with `a,b` int — the multiply overflows **in int** before being stored.*
- [ ] **Type conversion & casting** — implicit promotion + explicit `(long long)x`; taught here because the overflow fix depends on it. *Mistake: casting the **result** `(long long)(a*b)` instead of an **operand** `(long long)a*b` — the overflow already happened.*
- [ ] **Type aliases & CP macros (read + write)** — `using ll = long long;`, `typedef pair<int,int> pii;`, `const int MOD = 1e9+7;`, `#define pb push_back`. *Mistake: can't read editorials because `ll`/`pb`/`all(v)` are opaque — and you learn from editorials.*
- [ ] **Pre-submit checklist** `[x] (done)` — overflow / init / boundaries / tested, said aloud before every submit. *Mistake: skipping it on the "confident" submissions — those are the ones that WA.*

**Canonical practice:** CSES *Weird Algorithm* (needs `long long`), CSES *Missing Number*, a CF Div-2 A "A+B" style. **Drill:** for `n ≤ 10⁵, aᵢ ≤ 10⁹`, state the type of the sum aloud (`long long`) before coding.
**💡 Analogy:** an `int` is a car odometer with a fixed number of digits — roll past its max and it silently wraps to a wrong number. `long long` is a bigger odometer.

> **EXIT 1:** you have one green **Accepted** on CSES and one on Codeforces, and given any constraint line you can name the correct type and predict overflow *before* running.

---

## Stage 2 — Decisions & loops: make the program *do* something
**Goal:** solve simulation and casework, and be born the "is it fast enough?" reflex at the first real nested loop.
*Guide anchor: General → Expected Knowledge; Bronze → Simulation, Casework.*

- [ ] **`bool` & truth values** — `true/false`; any nonzero int is truthy. *Mistake: `if(x = 5)` (assignment, always true) instead of `if(x == 5)`.*
- [ ] **Comparison operators** — `== != < <= > >=` → bool; boundary `<` vs `<=` **is** off-by-one. *Mistake: chaining `a < b < c`, which parses as `(a<b)<c`.*
- [ ] **Logical operators `&& || !` + short-circuit** — right side of `&&` skipped if left is false; use it to guard: `i<n && a[i]==x`. *Mistake: using bitwise `&`/`|`, or putting the bounds check *after* the array access.*
- [ ] **`if / else if / else`** — branch on a bool. *Mistake: forgetting `{}` on a multi-line branch, so only the first line is conditional.*
- [ ] **Ternary conditional `?:`** — the expression form of a branch: `cout << (ok ? "YES" : "NO");`. *Mistake: precedence when mixing with `<<` — wrap it: `(ok?1:0)`.*
- [ ] **`switch`** — multi-way branch on an int/char with `break`. *Mistake: forgetting `break` → fall-through into the next case.*
- [ ] **Compound assignment & `++`/`--`** — `+= -= *= /= %=`. *Mistake: `a[i++]=i`, relying on evaluation order.*
- [ ] **Running-accumulator loop** — the primitive: `long long sum=0; for(...) sum += a[i];` — one running value updated each step. *This is the seed of the O(n) scan AND prefix sums later.* *Mistake: an `int` accumulator that overflows, or one you forgot to initialize.*
- [ ] **`for` loop** — `for(int i=0;i<n;i++)`; its bound is where off-by-one lives. *Mistake: `i<=n` reads one past the end.*
- [ ] **`while` & `do-while`** — repeat while a condition holds; `do-while` runs the body at least once. *Mistake: forgetting to update the loop variable → infinite loop.*
- [ ] **`break` & `continue`** — `break` exits the nearest loop; `continue` skips to its next iteration. *Mistake: expecting `break` to exit BOTH loops when nested (it exits only the inner).*
- [ ] **Nested loops** — a loop inside a loop (grids, all pairs) — **and the first moment to ask "n² — is that fast enough?"** *Mistake: not realizing `n=10⁵` makes `n²=10¹⁰` (too slow).*
- [ ] **⭐ Constraint → complexity → "is it fast enough?"** — CPU does **~10⁸ simple ops/sec** (~2 s ≈ 2·10⁸). Back out the target from N: `N≤10→n!` · `N≤20→2ⁿ` · `N≤500→n³` · `N≤5000→n²` · `N≤2·10⁵→n log n` · `N≤10⁷→n`. *Trigger: the moment you finish reading any statement.* *Mistake: "it ran fast on the sample" — samples are tiny; hidden tests use max N.*
- [ ] **Simulation** — model the described process step by step, exactly as stated. *Trigger: the statement is a sequence of concrete rules asking for the final state.* *Mistake: off-by-one on step counts / grid edges; misreading one rule.*
- [ ] **Casework / exhaustive case analysis** — split into a few mutually-exclusive, fully-covering scenarios and handle each. *Trigger: the answer depends on discrete situations (signs, orderings, overlaps, parity).* *Mistake: cases that overlap or miss the boundary/equal case; testing only one branch.*

**Canonical practice:** USACO Bronze *Simulation* module, USACO Bronze *Casework* module; **Drill:** for 8 constraint lines (N≤18, N≤10³, N≤2·10⁵…) name the loosest complexity that passes — no coding.
**💡 Analogy:** the 10⁸/sec budget is a grocery budget. Big-O is the price tag per item, N is how many you're buying — multiply *before* you reach the register, not after.

> **EXIT 2:** you solve a Bronze simulation/casework problem *and* you wrote the `N ≤ ___ → O(___)` line before coding. If you skipped that line, this stage isn't done.

---

## Stage 3 — Storing many things: arrays, vectors, strings
**Goal:** read N items and process a collection. Solve CSES *Distinct Numbers*, *Repetitions*.
*Guide anchor: Bronze → Intro to Data Structures.*

- [ ] **Fixed-size arrays (1D)** — `int a[100005];`, indexed `0..n-1`. *Mistake: indexing `a[n]`; sizing `a[n]` with a runtime `n`.*
- [ ] **Big arrays must be global/static** — a big array declared **inside `main`** overflows the stack → RE that is *not* out-of-bounds/÷0/recursion. Put big buffers at global scope (or raise the stack, Stage 0). *Mistake: `int a[10000000];` inside `main` → mysterious crash before it does anything.*
- [ ] **Global vs local & init-to-zero** — globals/statics auto-zero; **locals do not** (garbage). *Mistake: assuming a local `int cnt[100]` starts at 0 — your init-to-0 weakness, again.*
- [ ] **Uninitialized-variable UB** — a local used before assignment is garbage → undefined behavior. Drill: `int sum;` accumulate, watch the wrong total, fix with `=0`. *Mistake: this whole family belongs permanently on your checklist.*
- [ ] **`std::vector` basics** — resizable array: `push_back`, `size()`, `v[i]`, `back()`. *Trigger: storing a runtime-sized sequence (almost always).* *Mistake: `v[i]` before it's that big; `v[0]=5` on an empty vector.*
- [ ] **vector sizing & mutators** — `vector<int> v(n,0)` sizes-and-fills; `assign`, `resize`, `clear`, `pop_back`, `front/back`, `empty`. `reserve` changes **capacity only** (size stays 0). *Mistake: forgetting to reset between test cases → stale data; confusing `reserve` with `resize`.*
- [ ] **`size()` is unsigned — the `size_t` trap** — mixing it with signed ints, or `v.size()-1` on an empty vector, wraps to ~1.8·10¹⁹. Drill: run `for(int i=0;i<=(int)v.size()-1;i++)` with/without the `(int)` on an empty vector. *Mistake: the underflow → ~4-billion-iteration loop.*
- [ ] **`vector<bool>` is a bit-packed proxy** — not a real container of bools; you can't take `auto&`/`bool*` to an element. Use **`vector<char>`** for a reference-mutable boolean/`visited` array. *Mistake: `for(auto& b : vis)` on a `vector<bool>`.*
- [ ] **Out-of-bounds = UB** — `a[i]` with `i<0` or `i>=size` may crash *or silently corrupt*. Drill: write `a[n]=5`, rerun with `-fsanitize=address`. *Mistake: off-by-one at the last index — a top cause of "passes sample, WA/RE on judge."*
- [ ] **`char` & ASCII arithmetic** — a char is a small int code; `c-'a'` → `0..25`, `c-'0'` → digit value. *Mistake: using the char `'7'` (value 55) as the number 7.*
- [ ] **`string` basics** — `s[i]`, `s.size()`, `+`, `==`; `cin >> s` reads **one word**. *Mistake: thinking `cin>>s` reads a whole line (stops at the first space); indexing `s[s.size()]`.*
- [ ] **`double`/`float` & precision** — approximations, NOT exact; `0.1+0.2 != 0.3`. *Trigger: only when the problem genuinely needs fractions — prefer integers.* *Mistake: `==` on doubles; use `abs(a-b) < 1e-9`.*

**Canonical practice:** CSES *Distinct Numbers*, CSES *Repetitions*, CSES *Missing Number*. **Drill:** read `n` then `n` ints into a vector and print them reversed.
**💡 Analogy:** an array is a row of numbered lockers. A `vector` is a row of lockers that grows a new wing when it fills up.

> **EXIT 3:** you read `n` then `n` values into a vector, transform them, print correctly-formatted output, and you know exactly which arrays auto-zero and which are garbage.

---

## Stage 4 — Input/output mastery: the judge only sees your bytes
**Goal:** parse any input shape and produce byte-exact output. A misparse = you solved the wrong problem.
*Guide anchor: General → Input/Output, Fast I/O.*

- [ ] **Reading N items in a loop** — `cin >> n;` then a loop reading `n` values. *Mistake: looping to `<= n`, or reading `n` itself as a value.*
- [ ] **Reading mixed types & multiple values per line** — `cin >> a >> c >> s` crosses whitespace regardless of line breaks. *Mistake: reading in the wrong declared order.*
- [ ] **Reading until EOF** — `while(cin >> x){...}` stops cleanly at end of input. *Trigger: no leading count given.* *Mistake: `while(!cin.eof())` then reading — processes the last value twice; test the extraction itself.*
- [ ] **`getline` & the `>>`-then-`getline` trap** — `getline(cin,s)` reads a whole line incl. spaces; clear the leftover newline after `>>` with `cin.ignore()`. *Trigger: whole-line input, or a count then full lines.* *Mistake: the first `getline` returns empty because of the dangling `\n`.*
- [ ] **`stringstream` / `istringstream`** — `getline(cin,line); istringstream ss(line); while(ss >> x)` splits a line into an **unknown** number of tokens. *Trigger: a line with a variable count of numbers, or "read the rest of the line."* *Mistake: trying this with plain `cin>>`, which can't tell where a line ends.*
- [ ] **String↔number conversion** — `stoi/stoll/stod`, `to_string`. *Mistake: `stoi` on a value exceeding int range (needs `stoll`).*
- [ ] **Character classification (`<cctype>`)** — `isdigit`, `isalpha`, `islower`, `toupper`, `tolower`. *Mistake: `toupper` **returns** the new char (doesn't modify in place).*
- [ ] **Output formatting: `'\n'` vs `endl`, `setprecision`** — `'\n'` just newlines; `endl` also **flushes** (slow); `fixed<<setprecision(k)` sets decimals. *Trigger: any big output loop; any float answer.* *Mistake: `endl` in a tight loop (TLE); a double without `fixed` prints `1e+09`.*
- [ ] **Fast I/O setup** — `ios::sync_with_stdio(false); cin.tie(NULL);` at the top of `main`. *Trigger: N ≥ ~10⁵ with cin/cout.* *Mistake: mixing `scanf/printf` with `cin/cout` after disabling sync.*
- [ ] **Exact output formatting** — match bytes: no trailing space, correct newlines, exact `YES`/`Yes` case, right line count. *Mistake: trailing space / wrong capitalization / missing final newline → WA or PE on correct logic.*
- [ ] **USACO file I/O convention** — old USACO problems use `ifstream fin("prob.in"); ofstream fout("prob.out");`. *Trigger: any pre-Dec-2020 USACO problem, or a statement naming files.* *Mistake: using `cin/cout` on a file-IO problem → score 0.*

**Canonical practice:** USACO Bronze *Word Processor* (getline), CSES *Introductory* input-variety problems; **Drill:** read `n` lines each with an unknown count of ints (getline + istringstream), sum each line.

> **EXIT 4:** you can parse any input shape (counted, EOF, mixed, whole-line, variable-token-per-line), print byte-exact output, and switch to USACO file I/O without thinking.

---

## Stage 5 — Functions, references, scope, lambdas
**Goal:** package logic (so your stress harness has a `solve()` to call), pass big data cheaply, write a comparator.
*Needed before recursion, before comparators.*

- [ ] **Functions & return values** — `int f(int a){ return ...; }`. *Trigger: repeated logic; a self-contained sub-computation; a multi-test `solve()`.* *Mistake: a non-void function with a path that returns nothing (UB).*
- [ ] **`void` functions & side effects** — do work (print, mutate) without returning. *Mistake: trying to use the (nonexistent) return value.*
- [ ] **Pass by value vs reference (`&`)** — value copies; `int&`/`vector<int>&` lets you modify the caller's variable and avoids copying. *Trigger: a function must change its argument, or the argument is a big container.* *Mistake: `swap` by value doesn't swap; passing big vectors by value in a hot loop → TLE.*
- [ ] **`const` reference** — `const vector<int>&`: read a big argument with no copy, no writes. *Trigger: passing a large container you only read.* *Mistake: copying large inputs by leaving off `const&`.*
- [ ] **Lambda expressions** — `[capture](params){ body }`; `[&]` captures by reference, `[=]` by value. Taught **here, before any comparator/predicate uses one.** *Trigger: an inline comparator/predicate for `sort`/`count_if`/`priority_queue`.* *Mistake: capturing by value `[=]` when you needed the live value → uses a stale copy.*
- [ ] **Scope & lifetime** — a variable lives only inside its `{}`; globals live the whole program. *Mistake: shadowing — re-declaring in an inner block so the outer never updates.*
- [ ] **Recursion basics** — a function calling itself, reducing to a base case. **Placed before every recursive-generation/backtracking skill.** *Trigger: a problem defined in terms of smaller instances of itself, or branching choices.* *Mistake: missing/wrong base case → infinite recursion / stack overflow; relying on a global you don't restore.*
- [ ] **Deep-recursion / stack depth** — a DFS on a 10⁵-long chain can blow the stack; either raise the stack (`-Wl,--stack,...`, Stage 0), convert to an explicit stack/queue (iterative), or use BFS. *Mistake: assuming any recursion depth is fine on the judge.*

**Canonical practice:** write `int gcd(int,int)` and a `solve()` called in a `for(t)` loop; **Drill:** `sort(v.begin(), v.end(), [](int a,int b){ return a>b; });` then a `count_if` capturing a threshold with `[&]`.
**💡 Analogy:** pass-by-value hands someone a *photocopy* (edits don't come back); pass-by-reference hands them the *original*. A lambda is a sticky-note function you write inline and hand to `sort`.

> **EXIT 5:** you decompose into functions, pick value/reference/const-ref correctly per parameter, write a lambda comparator from memory, and can trace a small recursion (factorial, sum) by hand.

---

## Stage 6 — Iterators, sorting & comparators
**Goal:** order data by any rule. Solve CSES *Ferris Wheel* (sort + greedy).
*Guide anchor: Bronze → Intro to Sorting. Iterators are taught FIRST because sort/next_permutation use begin()/end().*

- [ ] **Iterators & the begin/end idiom** — a pointer-like bookmark; `begin()` = first, `end()` = **one past** the last; algorithms take a `[begin, end)` range. *Mistake: dereferencing `end()`; comparing iterators with `<` instead of `!=`.*
- [ ] **Iterator / reference invalidation** — erasing while iterating, or holding a reference/iterator into a vector then `push_back` (realloc), is UB that often "works on the sample." Erase-idiom: `it = v.erase(it)`. *Mistake: mutating a container mid-iteration; holding `auto& x = v[0]` across a `push_back`.*
- [ ] **`pair`** — two glued values via `.first`/`.second`; sorts by first then second **for free**. *Trigger: carry two related values as one sortable unit (value+index, coords).* *Mistake: putting the wrong field first when the sort key must be `.first`.*
- [ ] **`tuple`** — like pair for 3+ values; `get<0>(t)` or structured binding `auto [a,b,c]=t`; free lexicographic sort. *Trigger: sort/bundle 3+ fields, default order fine.* *Mistake: reaching for tuple when a named struct is clearer.*
- [ ] **structs** `[x] (done)` — `struct Player{ string name; int score; };` bundles fields. *Mistake: leaving members uninitialized; forgetting the `;` after `}`.*
- [ ] **`sort()` + complexity awareness** — `sort(v.begin(),v.end())` ascending, O(N log N); `sort(v.rbegin(),v.rend())` descending. *Trigger: need ordered data, or "sort then greedy/two-pointer."* *Mistake: sorting inside a loop → O(N² log N); sorting when you needed the original indices (store them first).*
- [ ] **Sort stability & `stable_sort`** — `sort` may reorder equal elements; `stable_sort` preserves their input order. *Trigger: ties must keep their original relative order.* *Mistake: assuming `sort` is stable.*
- [ ] **Custom sort comparators (multi-key tie-breaks)** `[x] (done)` — a `bool cmp(a,b)`/lambda meaning "a comes before b," ties chained. Single canonical entry. *Trigger: order by a rule other than natural ascending.* *Mistake: **using `<=` → violates strict-weak-ordering → runtime crash/WA on big tied inputs. Always `<`.** (Your named weak spot.)*
- [ ] **Comparator correctness (strict weak ordering)** — a comparator must return **false** for equal elements. Drill: sort many equal keys under `-D_GLIBCXX_DEBUG` with a `<=` comparator, watch it get flagged, fix to `<`. *Mistake: `return a.x <= b.x;` — occasional crash on large tied inputs only.*
- [ ] **Built-in helpers: `min/max/swap/abs/__gcd` + `min({a,b,c})`** `[x] (done — O(n) scan)` — the ubiquitous helpers; initializer-list form for 3+. *Trigger: running max/min, gcd, swap, absolute value.* *Mistake: initializing a running max to 0 when values can be negative (use `LLONG_MIN`/`a[0]`).*
- [ ] **O(n) linear scan (max/min/count/running best)** `[x] (done)` — one pass keeping a running answer. *Trigger: a single aggregate over the array.* *Mistake: init max to 0 on all-negative input; an overflowing `int` sum.*

**Canonical practice:** CSES *Ferris Wheel* (sort + greedy), USACO Bronze *Intro to Sorting*. **Drill:** sort players by score desc, then name asc — verify your comparator uses strict `<`.

> **EXIT 6:** you sort a vector of structs by any multi-key rule with a strict lambda comparator, you say the sort's complexity out loud, and you never invalidate an iterator mid-loop.

---

## Stage 7 — Elementary math foundations
**Goal:** integer-first thinking as a correctness habit. Solve CSES *Sum of Two Values*, number-theory intro tasks.
*Guide anchor: Bronze math + CSES Introductory.*

- [ ] **Fixed-width ranges recap** — `int` ≈ ±2.1·10⁹, `long long` ≈ ±9.2·10¹⁸. *Mistake: not knowing the 2.1·10⁹ line.*
- [ ] **Detecting & preventing overflow** — a product/sum can overflow int even when the final answer is small; fix with `long long` / mid-expression cast. It's item one on your checklist. *Trigger: any multiply, running sum, or `n(n-1)/2` with operands ≳ 10⁵.* *Mistake: widening *after* the multiply already overflowed.*
- [ ] **Big constants as double literals** — `const int INF = 1e9;` and `const ll INF = 4e18;` assign a *double* literal to an integer — usually fine at these values, but `1e18` as an int, or arithmetic on the literal, can lose precision. Prefer `1'000'000'000` / `4'000'000'000'000'000'000LL` when exactness matters. *Mistake: assuming `1e9` is an exact integer everywhere.*
- [ ] **`pow()`/`sqrt()` are floating-point — never for exact integer math** — `pow(10,9)` can return `999999999.999…` and truncate wrong; `(int)sqrt(n)` can be off by one near large perfect squares. Integer sqrt: `long long k=sqrtl(n); while(k*k>n)k--; while((k+1)*(k+1)<=n)k++;`. *Trigger: any exact integer power or square root.* *Mistake: using `<cmath>` `pow/sqrt/round` for exact answers — a silent WA squarely in your precision cluster.*
- [ ] **Integer vs floating-point (stay in integers)** — compare `a*d` vs `b*c` instead of `a/b` vs `c/d`. Drill: decide `1/3 < 2/7` by cross-multiplication (`1*7` vs `2*3`). *Mistake: equality-comparing doubles; indexing with a rounded double.*
- [ ] **Negative floor/ceil division** — C++ truncates toward zero, so `floor(-7/2)` should be −4 but C++ gives −3; both floor and ceil need care with negatives. *Trigger: coordinates that go negative.* *Mistake: reusing the positive-only `(a+b-1)/b` ceil on negatives.*
- [ ] **Parity & divisibility** — `x%2` for even/odd, `x%k==0` for "k divides x." *Trigger: pairing, alternating, splitting evenly, "is it reachable."* *Mistake: `x%2==1` for odd on possibly-negative x (can be −1).*
- [ ] **Elementary counting & combinatorics** — `n choose 2 = n(n-1)/2` pairs, `1..n = n(n+1)/2`, product rule. *Trigger: counting pairs/handshakes/ways, summing a range.* *Mistake: computing `n(n-1)/2` in int for `n=10⁵` (overflow); looping O(n²) for an O(1) formula.*
- [ ] **Manhattan & Euclidean distance** — `|x1−x2|+|y1−y2|`; for Euclidean compare **squared** distances `a²+b²` to dodge `sqrt` precision. *Trigger: closeness/nearest on a grid or plane.* *Mistake: taking `sqrt` and comparing doubles when squared-integer comparison is exact.*
- [ ] **GCD via Euclid (`__gcd`)** — `gcd(a,b)=gcd(b,a%b)` until `b==0`; first clean O(log) algorithm. *Trigger: gcd, fraction reduction, common periods.* *Mistake: a slow subtraction-based gcd; forgetting `gcd(0,x)=x`.*
- [ ] **LCM & its overflow trap** — `lcm(a,b) = a / __gcd(a,b) * b` — **divide before multiply.** *Trigger: "when do two cycles align," synchronization.* *Mistake: `a*b/gcd` overflows before the divide.*
- [ ] **Primality by trial division to √n** — n is prime iff no `i` in `2..√n` divides it; loop `i*i<=n`. *Trigger: test one/few numbers, n up to ~10¹².* *Mistake: looping to n (slow); `i<=sqrt(n)` float rounding; mishandling `n<2`.*
- [ ] **Pigeonhole / parity / invariant reasoning** — the *reasoning move*: "n+1 items in n boxes → two collide"; "this quantity's parity never changes, so the target is unreachable." *Trigger: "is it possible" / constructive impossibility on CF 900–1200 ad-hoc.* *Mistake: trying to brute-force a "possible?" problem instead of finding the invariant.*

**Canonical practice:** CSES *Sum of Two Values*, CSES *Weird Algorithm* (parity), CSES *Counting Divisors* (later). **Drill:** count pairs among 100000 people via `n(n-1)/2` and confirm it overflows `int`.

> **EXIT 7:** you reach for integer math by default, never use `pow`/`sqrt` for exact answers, and can compute gcd/lcm/pair-counts without overflow.

---

## Stage 8 — Complexity reading (⛔ GATE A)
**Goal:** turn any Big-O into a yes/no verdict against the limit. Pure paper drills — no coding.
*Guide anchor: Bronze → Time Complexity. This is the reflex you're missing.*

- [ ] **Big-O growth-rate intuition** — read O(f(n)) as "how steps grow with n," dropping constants and lower terms. Drill: classify 8 snippets by hand. *Mistake: writing `O(2n+5)` or `O(n²+n)`.*
- [ ] **The complexity ladder + code shapes** — O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!), each tied to a code shape (index / binary search / scan / sort / all-pairs / all-subsets / all-permutations). *Mistake: believing every nested loop is O(n²) even when the inner loop is fixed/shrinking.*
- [ ] **The ~10⁸ ops/sec budget** — after computing an op count, compare to ~10⁸/sec and the ~1–2 s limit. Drill: `N=10⁵` with O(n²) = 10¹⁰ ops → ~100 s → fails. Do 6. *Mistake: "2 seconds is a lot" without multiplying loops out.*
- [ ] **Constraint→complexity table** — back out the intended complexity from N. *Trigger: first thing after reading constraints.* *Mistake: designing O(n²) for N=10⁵; over-engineering O(n log n) when N=1000 makes O(n²) trivially fine.*
- [ ] **CF "sum of N over all test cases ≤ X"** — on Codeforces, the *real* budget is often stated as "the sum of n over all test cases does not exceed 2·10⁵." That means per-test you may look O(n²) but across all tests it's bounded — read it and budget against the **sum**, not the per-test n. *Mistake: multiplying max-n by max-T and wrongly concluding TLE, or ignoring the bound and actually TLE-ing.*
- [ ] **Estimating op-count from nested loops** — multiply loop bounds, sum sequential blocks; a triangular loop `for j>i` is `n(n-1)/2`, not `n²`. *Mistake: treating a triangular loop as full n²; forgetting O(n) work *inside* the loop multiplies the total.*
- [ ] **Worst vs best vs average case** — Big-O in CP means worst case; early-exit best cases lie about safety. *Trigger: an algorithm with a data-dependent runtime.* *Mistake: trusting "it usually returns early."*
- [ ] **Why log growth is nearly free** — `log₂(10⁹)≈30`, so an O(n log n) sort of 10⁶ is ~2·10⁷. *Mistake: treating a `set`/`map` op as O(1) — it's O(log n).*
- [ ] **Space complexity & the 256 MB budget** — an int is 4 bytes, so `int[10⁸]` ≈ 400 MB won't fit; `N×N` for `N=10⁵` is impossible. *Mistake: declaring an N×N array without checking bytes.*
- [ ] **Amortized cost (why `push_back` is O(1))** — a rare resize spread over many cheap appends averages to O(1); n push_backs total O(n). *Mistake: counting one realloc as if it happened every iteration.*
- [ ] **Constant factors (same-O, different wall time)** — cache, `cin` vs `scanf`, `endl` flushing, `map`'s log — same Big-O, 10× time. *Trigger: correct complexity but still TLE near the limit.* *Mistake: assuming correct Big-O guarantees AC.*
- [ ] **Measure before you trust** — for a borderline solution, generate a max-size input and *time it locally* before submitting. Drill: echo 10⁶ ints with and without fast I/O, time both. *Mistake: guessing "probably fast enough" on a tight solution.*

**Canonical practice:** USACO Bronze *Time Complexity* module; **Drill:** for 8 given N, name the loosest complexity that passes, then reverse it on a real CSES statement.

> **⛔ EXIT 8 (GATE A):** you never write code before saying "N ≤ ___, so O(___), ≈ ___ ops, which fits/doesn't in ___ s" — and on CF you read the "sum of n" bound correctly. This sentence is automatic. **No technique stage proceeds until it is.**

---

## Stage 9 — Correctness, debugging & testing (⛔ GATE B)
**Goal:** convert your high WA rate into a ritual that catches bugs before the judge. Habits, not new algorithms — your highest-leverage stage.
*Guide anchor: General → Debugging Checklist, Basic Debugging, Practicing.*

- [ ] **Intermediate-product overflow (cast an operand)** — `(long long)a*b`, not `long long x = a*b`. Drill: `n(n-1)/2` for `n=100000` with/without the cast. *Mistake: the widening is too late.*
- [ ] **Initialize every variable** — locals aren't auto-zeroed; init at declaration. Drill: max-scan with `int best;` (garbage) vs `int best=a[0];` on all-negative input. *Mistake: `int mx; ... mx=max(mx,a[i]);` — garbage start.*
- [ ] **Safe "infinity" constant (fused overflow+init bug)** — never `INF = INT_MAX`/`LLONG_MAX` (then `dist+w` overflows to negative). Use a **padded** sentinel: `const int INF = 1e9;` / `const ll INF = 4e18;` you can safely add to. *Trigger: BFS `dist[]` init, any min-DP.* *Mistake: `min(cur, INF+1)` wrapping negative — your top two failure modes at once.*
- [ ] **Off-by-one / loop-boundary discipline** — deliberately choose `<n` vs `<=n`, 0- vs 1-indexed, inclusive vs exclusive. Drill: for `a[0..n-1]` write loops touching (a) all, (b) all-but-last, (c) adjacent pairs, none overrunning. *Mistake: `for(i=0;i<=n;i++)` reads `a[n]`.*
- [ ] **Systematic edge-case menu** — run a fixed card before submit: `n=1`, empty/zero, all-equal, all-negative, max values, ties, sorted, reverse-sorted. *Trigger: the "tested" item of your checklist.* *Mistake: testing only the (deliberately gentle) provided sample.*
- [ ] **The `n=1` / single-element / empty case** — the most common single hidden killer. *Trigger: code touching pairs, differences, "previous element," second-max.* *Mistake: accessing `a[i-1]` when `i` can be 0.*
- [ ] **"Passes sample but wrong" skepticism** — a matching sample is necessary, not sufficient. **Your named failure mode.** *Trigger: the urge to submit the instant the sample matches.* *Mistake: after a sample-pass, not naming one input the sample doesn't cover and testing it first.*
- [ ] **Multiple test cases: T-loop + clearing state** — read `T`, loop, **reset every global/array/counter** each case. *Trigger: the problem starts with a lone integer `T` (most CF problems).* *Mistake: stale global `visited`/`count` poisoning later cases — "first test passes, rest fail."*
- [ ] **Reading tricky input formats** — parse exactly what's described (tokens per line, leading T, N-then-M order). *Mistake: reading M before N when input gives N then M — shifts everything.*
- [ ] **Floating-point output & comparison** — `fixed<<setprecision(k)`; compare with epsilon, never `==`. *Mistake: `==` on doubles; scientific notation from missing `fixed`.*
- [ ] **Understanding judge verdicts** — WA=logic/format, TLE=too slow, RE=crash, MLE=memory, CE=compile, PE=format; each says *which* fundamental failed. *Mistake: treating TLE as a logic bug, or RE as a math bug.*
- [ ] **Diagnosing runtime errors (RE)** — causes: out-of-bounds, div/mod by zero, deep/infinite recursion (stack overflow), **big local array (stack overflow)**, invalid iterator. *Mistake: an off-by-one access that only crashes on some inputs.*
- [ ] **Memory-limit awareness (MLE)** — an array of K ints ≈ 4K bytes; check it fits (often 256 MB) at max N. Drill: `int dp[10000][10000]` ≈ 381 MB won't fit. *Mistake: an N×N int array for N=10⁵.*
- [ ] **Reproduce first** — get the exact failing input + wrong output, reproduce locally (`./sol < in.txt`), *then* fix. *Mistake: editing random lines before ever reproducing.*
- [ ] **Print-debug to `stderr`; assertions; NDEBUG** — trace with `cerr` (judge ignores it); `assert(idx>=0 && idx<n)` crashes loudly where an invariant breaks; note asserts are compiled out under `-DNDEBUG`, so don't put side-effects inside them. *Mistake: debugging to `cout` (breaks output); leaving debug in → WA/PE.*
- [ ] **Step-debugging with gdb** — `gdb ./f.exe`, `run < in.txt`, `bt` on a crash to see the exact call stack. A backstop when cerr/sanitizers aren't enough. *Mistake: never learning it, so some crashes stay mysterious.*
- [ ] **Compile with warning flags** `[x] (implied)` — `-Wall -Wextra -Wshadow`; fix every warning before running. *Mistake: ignoring the one warning pointing at the bug.*
- [ ] **Sanitizers for runtime UB** — `-fsanitize=address,undefined` names the file+line of out-of-bounds/overflow. *Trigger: unexplained RE or a WA you can't locate by reading.* *Mistake: staring at code instead of letting the sanitizer name the line.*
- [ ] **Trace-by-hand a tiny example before coding** — run the idea on paper with `n=2,3` real numbers to confirm it's even correct. **Matches how you learn best.** *Mistake: coding an approach you only "feel" is right.*
- [ ] **Re-read the statement for misreads** — on a stubborn WA, assume you misread; list every constraint and check your code honors each. *Mistake: confusing N/M, minimize vs maximize, 0- vs 1-indexed.*
- [ ] **Stress testing against a brute force** `[x] (done)` — random small inputs, diff fast vs trivially-correct slow until they disagree. *Trigger: samples pass but you're unsure (greedy/constructive).* *Mistake: generating only large inputs — bugs hide in n=1, all-equal, ties.*
- [ ] **Writing a good random generator** — respect constraints AND over-sample small sizes, dups, extremes, ties (seeded `mt19937`). *Mistake: only large uniform-random cases → the failing input never appears.*
- [ ] **Minimizing a failing test case** — shrink a found mismatch to the smallest input that still fails. *Mistake: debugging the giant original instead of shrinking first.*
- [ ] **Remove debug output & dead code before submit** — strip `cerr`/`cout` debug. Add "debug removed?" to the checklist card. *Mistake: a leftover `cout<<"here"` in the final submission.*
- [ ] **How judges hide & strengthen tests (CF pretests/hacks)** — tests are hidden, include worst/corner cases; WA stops at the first failure; on CF weak pretests can pass but hacks/system tests later fail you. *Trigger: deciding how hard to test before submitting on CF.* *Mistake: trusting a CF "Accepted" pretest and getting hacked.*
- [ ] **Time-boxing + strategic editorials + upsolving** — Bronze: stuck ~15–20 min → reveal *one* editorial step, finish yourself, then **implement it**. After every contest, upsolve the first problem you missed the same day. *Mistake: grinding one problem for 2 h, or reading the whole solution+code at once and copying it.*
- [ ] **Recognizing technique TRIGGERS, not names** — maintain the **signal → technique** table (Appendix A) in `CHEATSHEET.md`; add a row after every solved problem. **Direct fix for your named weakness.** *Mistake: knowing "prefix sums" as a word but not recognizing the range-sum-query signal.*

**Canonical practice:** USACO *Debugging Checklist* walkthrough on any past WA; **Drill:** take a solved Bronze problem and run all 8 edge cases, then stress-test a doubtful greedy vs brute force on n≤8.

> **⛔ EXIT 9 (GATE B):** your pre-submit checklist is automatic; you enumerate edge cases and never trust a sample; you clear state between test cases; you reproduce-then-fix with sanitizer/stress-test/hand-trace; and your trigger table has started. **This is where "algorithms" is finally allowed to begin.**

---

## Stage 10 — The STL container toolkit
**Goal:** membership, counting, dedup, ordered/priority access. One canonical pass per structure. Solve USACO Bronze *Intro to Sets & Maps*.
*Guide anchor: Bronze → Intro to Data Structures, Sets & Maps.*

**Algorithm helpers**
- [ ] **`min_element`/`max_element`** — return an **iterator**; `*` for value, `- v.begin()` for index. *Mistake: printing the iterator instead of `*it`.*
- [ ] **`accumulate`** — `accumulate(v.begin(),v.end(),0LL)`; the seed's **type** decides overflow. *Mistake: seed `0` (int) when the sum exceeds 2·10⁹ — silent WA. Use `0LL`.*
- [ ] **`count`/`count_if`** — tally equal-to-x / satisfy-a-predicate, O(n). *Mistake: calling `count` inside a loop (O(n²)) when a frequency map is O(n).*
- [ ] **`reverse`** — flip a range in place, O(n); range is `[begin,end)`. *Mistake: off-by-one on the end iterator.*
- [ ] **`unique` + erase-remove idiom** — removes **consecutive** dups; `sort` first, then `v.erase(unique(v.begin(),v.end()), v.end())`. *Trigger: distinct values / collapse adjacent runs.* *Mistake: forgetting to sort first; forgetting the erase (garbage tail).*
- [ ] **`fill` / `iota`** — `fill(b,e,v)` sets a range; `iota` fills 0,1,2,…; reliable reset between test cases. *Mistake: `memset(a,1,...)` does NOT set ints to 1; forgetting to reset globals between cases.*
- [ ] **Safe INF constant** `[x] (Stage 9)` — recalled here: `const ll INF = 4e18;` for `dist[]` init before BFS.

**Linear containers**
- [ ] **`stack` (LIFO)** — `push/top/pop/empty`. *Trigger: last-in-first-out (matching, nesting, undo).* *Mistake: `top()/pop()` on empty (UB); `pop()` returns void — read `top()` first.*
- [ ] **`queue` (FIFO)** — `push`(back)/`front`/`pop`(front). *Trigger: first-in-first-out (BFS, a line).* *Mistake: confusing `front()` (read) with `pop()` (remove, void).*
- [ ] **`deque`** — push/pop at both ends O(1), plus `[]`. *Trigger: fast insert/remove at both ends.* *Mistake: assuming middle insertion is O(1) (it's O(n)). (Monotonic-deque sliding-window max deferred — Gold.)*

**Associative & priority**
- [ ] **`set`** — sorted UNIQUE keys; `insert/erase/find/count` O(log n); `*s.begin()` = min. *Trigger: distinct elements kept sorted with fast membership.* *Mistake: calling `sort()`/`[]` on a set; `count` returns only 0/1.*
- [ ] **`map`** — sorted key→value, unique keys, `m[k]` O(log n), key-order iteration. *Trigger: associate values with large/sparse/string keys.* *Mistake: `m[k]` **inserts a default 0 just by reading it** — use `.count()`/`.find()` to check existence.*
- [ ] **Frequency counting** — `freq[x]++` (array if values are small/bounded, map otherwise). *Trigger: "how many times," "most common," "duplicates," "anagram."* *Mistake: a fixed array when values exceed bounds — use a map.*
- [ ] **Set/map for dedup & membership ("seen")** — the canonical visited/seen idiom. *Trigger: "distinct," "unique," "already seen," "does it contain."* *Mistake: an O(n) linear membership scan inside a loop (O(n²)) instead of an O(log n) set lookup.*
- [ ] **`multiset`** — sorted with DUPLICATES; `count(x)` can exceed 1. *Trigger: sorted collection that keeps repeats + erase-one.* *Mistake: `ms.erase(x)` deletes **all** copies — use `ms.erase(ms.find(x))` for one.*
- [ ] **`priority_queue` (heap)** — max on top by default, `top` O(1), push/pop O(log n); min-heap via `priority_queue<int,vector<int>,greater<int>>`. *Trigger: repeatedly need the current best among changing elements.* *Mistake: forgetting it's a MAX-heap by default; `pop()` doesn't return the value.*
- [ ] **set/map member `lower_bound` & neighbor navigation** — `s.lower_bound(x)` O(log n) "nearest ≥ x" inside the tree; `prev(it)`/`next(it)` walk neighbors. *Trigger: closest present value above/below x in a live changing set.* *Mistake: `prev(s.begin())` / deref `s.end()` at boundaries; using free `std::lower_bound` on a set (O(n), not O(log n)).*
- [ ] **`unordered_map`/`unordered_set` + the tradeoff** — hash-based expected O(1), no order, no `lower_bound`; ordered is O(log n) but sorted & range-capable. *Trigger: pure membership/counting, big N, no ordering → unordered; need order/min-max/lower_bound → ordered.* *Mistake: **on Codeforces, plain `unordered_map<int,int>` gets anti-hash-hacked into O(n) → TLE. When unsure, use `map`.** (Custom-hash deferred to Silver/Gold.)*

**💡 Analogies:** stack = pile of plates (take the top). queue = line at a shop (first come, first served). map = a dictionary you look words up in. heap = a to-do list that always floats the biggest task to the top.
**Canonical practice:** USACO Bronze *Intro to Sets & Maps*; CSES *Distinct Numbers* (sort+unique); **Drill:** `m[word]++` word frequencies, print the most common (ties → smallest).

> **EXIT 10:** given a task you name the right container ("distinct + sorted → set," "count by key → map," "k-th best repeatedly → heap") and you know each one's gotcha (`m[k]` auto-insert, `multiset::erase`, max-heap default, unordered on CF).

---

## Stage 11 — Complete search: recursion, subsets, permutations, backtracking
**Goal:** brute-force correctly and know when N makes it legal. Solve USACO Bronze *Complete Search* modules.
*Guide anchor: Bronze → Basic Complete Search, Complete Search with Recursion. Every entry forces the speed check first.*

- [ ] **Complete search / brute force (nested loops)** — try every candidate with 1–3 nested loops. *Trigger: small N (~≤2000 for O(N²), ~≤500 for O(N³)) and a small answer space.* *Mistake: not checking N against the limit first; double-counting `(i,j)` and `(j,i)`.*
- [ ] **Bitwise operators as language operators** — `& | ^ ~ << >>`, taught **here, before bitmasking needs them**. `~` is two's-complement; use `1LL<<i` for `i≥31`; precedence trap `x & 1 == 0` parses as `x & (1==0)`. Drill: test/set/clear bit i with `(x>>i)&1`, `x|(1<<i)`, `x&~(1<<i)`. *Mistake: `1<<31` on int is UB; the `& ==` precedence bug.*
- [ ] **Subsets via bitmask enumeration (2ⁿ)** — loop `mask` from 0 to `2ⁿ−1`; bit i set = element i chosen. The concrete meaning of "N≤20 → exponential is fine." *Trigger: N ≤ ~20–24, consider every subset.* *Mistake: `1<<N` with N≥31 without `1LL`; wrong test — use `(mask & (1<<i))`.*
- [ ] **64-bit bit correctness** — `1LL<<i` for i≥31; `__builtin_popcountll`/`__builtin_ctzll` (plain versions only see the low 32 bits). *Mistake: silent wrong answers when N reaches the 30s.*
- [ ] **Subsets recursively (include/exclude)** — branch "take"/"skip" at each index; generalizes to pruning. *Trigger: all subsets with early cut-offs.* *Mistake: mutating a shared vector without undoing the push.*
- [ ] **Permutations with `next_permutation`** — `sort()` then `do{...}while(next_permutation(...))`. *Trigger: tiny N (≤~10, N! explodes) and the answer depends on ORDER.* *Mistake: not sorting first (misses permutations before the start); using it for N≥15.*
- [ ] **Backtracking (recursion + prune + undo)** — build incrementally; on a violated partial, abandon and **undo the last step**; permutations-with-`used[]` is the worked example. *Trigger: search all configurations under constraints where many partials are rejectable early.* *Mistake: forgetting `used[i]=false` on return (state leaks); pruning valid branches.*

**Canonical practice:** USACO Bronze *Basic Complete Search*; N-Queens count (N≤10); brute-force smallest tour over ≤8 points. **Drill:** enumerate all subsets of N items, print each subset's sum.
**💡 Analogy:** backtracking = exploring a maze with a ball of string — walk forward, and whenever you hit a dead end, roll the string back up (undo) and try another turn.

> **EXIT 11:** before any brute force you write the `N → complexity` line and confirm N permits it; you enumerate subsets (bitmask *and* recursive) and permutations, and you always undo state on backtrack.

---

## Stage 12 — Bronze problem-solving patterns
**Goal:** cover every remaining named Bronze module. Trigger-first: learn the SIGNAL that fires each.
*Guide anchor: Bronze → Simulation, Grids, Casework, Rectangle Geometry, Greedy, Ad Hoc.*

- [ ] **Grid / 2D traversal + neighbor offsets** — `int dr[4]={1,-1,0,0}, dc[4]={0,0,1,-1};` loop the 4 (or 8) neighbors with an **in-bounds check before each access**. Build a 2D grid with `int g[R][C]` or `vector<vector<int>> g(R, vector<int>(C,0))`. *Trigger: a 2D map where you move between adjacent cells.* *Mistake: checking `grid[nr][nc]` **before** the bounds check; swapping row/col; `vector<vector<int>> g;` then `g[i][j]=x` without sizing.*
- [ ] **Axis-aligned rectangle & interval geometry** — area from two corners; two rects overlap iff `max(x1a,x1b) < min(x2a,x2b)` AND same for y; intersection area; 1D interval overlap; union = A + B − intersection (inclusion-exclusion). *Trigger: rectangles/intervals on a plane — "overlap?", "covered area."* *Mistake: wrong overlap inequality (`<=` vs `<`); double-subtracting the overlap; brute-forcing coordinates when O(1) geometry works (your speed weak spot).*
- [ ] **Sorting-based solutions** — sort first so structure (order, adjacency of equals, extremes) becomes obvious. *Trigger: answer doesn't depend on original order, or pairing smallest-with-largest / grouping equals helps.* *Mistake: needing original indices but not storing them before sorting.*
- [ ] **Sort-then-greedy (first greedy insight)** `[x] (done)` — sort by a key, sweep left-to-right taking the locally-best choice. *Trigger: best immediate choice after sorting seems to give the global optimum.* *Mistake: sorting by the wrong key (start time instead of end) and assuming optimality without proof.*
- [ ] **Ad hoc / constructive** — find one insight or build one valid construction; no standard algorithm. *Trigger: "construct any valid X" / "is it possible," no obvious technique — play n=1,2,3 by hand.* *Mistake: guessing a construction from n=2 alone and never verifying edge cases.*
- [ ] **Sets & maps as Bronze tools** `[x] (Stage 10)` — recalled here for membership/dedup/frequency inside Bronze problems.

**Canonical practice:** USACO Bronze *Rectangle Geometry* (Blocked Billboard / Square Pasture), *Ad Hoc* module, *Greedy* module, a grid simulation; CF Div-2 A/B constructive tasks.

> **EXIT 12:** you name a Bronze problem's category (simulation / casework / geometry / grid / sorting / greedy / ad hoc) from its shape, size the algorithm against the constraint, and pass your checklist. **You clear USACO Bronze consistently — the "Bronze foundation solid" milestone.**

---

## Stage 13 — Greedy with proof, and the greedy-proof habit
**Goal:** stop trusting greedies that only pass samples — the place "passes sample but wrong" bites you hardest.
*Guide anchor: Bronze → Intro to Greedy; Silver.*

- [ ] **Greedy with an exchange-argument (or stress-test) habit** — before trusting a greedy, argue that swapping any optimal choice toward the greedy one never makes things worse; if you can't, stress-test it against brute force. *Trigger: you have a greedy rule and must decide if it's *actually* correct.* *Mistake: assuming a greedy is correct because samples pass.*

**Canonical practice:** prove "sort by end time" optimal for interval scheduling via exchange argument; then stress-test a doubtful greedy on n≤8.

> **EXIT 13:** for any greedy you either sketch a one-line exchange argument or stress-test it — you never ship a greedy on vibes.

---

## Stage 14 — Prefix sums & difference arrays
**Goal:** the first "precompute so queries are O(1)" tools. You just started this — consolidate here.
*Guide anchor: Silver → Prefix Sums. One clean track: 1D build → 1D query → difference array → 2D. Overflow and off-by-one are the whole game.*

- [ ] **1D prefix-sum construction** `[x] (in progress)` — `pre[i] = a[0]+…+a[i-1]`, built once in O(n). *Trigger: you'll be asked many subrange sums of a fixed array.* *Mistake: off-by-one in `pre` size (n vs n+1); **overflow — `pre[]` must be `long long`.***
- [ ] **Range-sum query via prefix sums** `[x] (in progress)` — `sum(l..r) = pre[r+1] − pre[l]`, O(1); turns O(n·q) into O(n+q). *Trigger: many `(l,r)` sum queries on a static array. (First row of your trigger table.)* *Mistake: the 0- vs 1-indexed boundary (`pre[r]-pre[l]` vs `pre[r+1]-pre[l]`).*
- [ ] **Prefix generalizations** — the same idea gives prefix-max / prefix-min (careful: no easy "range max" from these — see below) and prefix-XOR (`xr(l..r) = px[r+1] ^ px[l]`). *Trigger: range XOR queries; running max/min from the left.* *Mistake: expecting `preMax[r]-preMax[l]` to give a range max — subtraction only works for invertible operations (sum, XOR), not max/min.*
- [ ] **Difference array (range update, then finalize)** — `d[l] += v; d[r+1] -= v;` then one prefix sum applies all range-adds in O(n). *Trigger: many "add X to `[l,r]`" updates, **all before any query**, then read the final array.* *Mistake: forgetting the `-v` at `r+1`; `r+1` out of bounds (size n+1); interleaving updates with queries.*
- [ ] **2D prefix sums** — `pre[i][j]` = sum of rectangle `(0,0)..(i-1,j-1)`; subrectangle via 4-corner inclusion-exclusion. *Trigger: repeated subrectangle-sum queries on a fixed grid.* *Mistake: wrong `+A −B −C +D` signs; the +1 index offsets.*

**Canonical practice:** CSES *Static Range Sum Queries*, CSES *Forest Queries* (2D), USACO Silver *Intro to Prefix Sums* / *More on Prefix Sums*.
**💡 Analogy:** a prefix-sum array is a running odometer — to get the distance between two mile markers you just subtract the two readings. A difference array is a thermostat schedule: you write "+2° at 8am, −2° at 10am," then sweep once to get the temperature at every minute.

> **EXIT 14:** you recognize "many static range-sum queries → prefix sums" and "many range-adds then read → difference array" instantly, and you get the boundary indices and `long long` right the first time.

---

## Stage 15 — Early-Silver on-ramp (the roadmap's ceiling)
**Goal:** the stretch rungs that open Silver / CF 1200+. **Do NOT front-load these** — enter only once Stages 12–13 (Bronze patterns + greedy habit) are automatic.
*Guide anchor: Silver modules.*

**Searching & two-pointer family**
- [ ] **`lower_bound` / `upper_bound` on a sorted vector** — on a SORTED range: `lower_bound` = first ≥ x, `upper_bound` = first > x, both O(log n); count in `[a,b]` = `upper_bound(b) − lower_bound(a)`. *Trigger: sorted data + "is X present" / "how many ≤ X" / "smallest ≥ X."* *Mistake: calling it on an UNSORTED range; deref-ing `end()` when nothing qualifies.*
- [ ] **`binary_search`** — yes/no existence in sorted data, O(log n). *Trigger: you only need membership.* *Mistake: wanting the position but it only returns a bool (use `lower_bound`).*
- [ ] **Binary search by hand** — half-open `[lo,hi)` reasoning; `mid = lo + (hi-lo)/2`. *Mistake: a loop that never terminates (bad lo/hi/mid update); `(lo+hi)/2` overflow.*
- [ ] **Binary search on the answer (BOTA)** — binary-search over candidate answer *values* with a monotone `check(x)`. *Trigger: "maximize the minimum" / "minimize the maximum" / "smallest X that works," AND feasibility is monotone.* *Mistake: applying it when feasibility isn't monotone; boundary returns the last infeasible value.*
- [ ] **Two pointers** — two indices over a (usually sorted) array advancing by a rule instead of a nested loop; collapses O(n²) to O(n). *Trigger: sorted array + pairs/subarrays meeting a condition (two-sum, count pairs ≤ K).* *Mistake: moving the wrong pointer / both at once → skips valid pairs; forgetting it must be sorted.*
- [ ] **Sliding window (fixed & variable)** — window `[l,r]`: add r, shrink l while a condition breaks, maintain an aggregate. *Trigger: "contiguous subarray/substring" with a constraint.* *Mistake: recomputing the window sum from scratch each step (back to O(n²)).*
- [ ] **Coordinate compression** — map large/sparse values (up to 10⁹) to ranks `0..k−1` via sort+unique+`lower_bound`. The payoff of sort+unique. *Trigger: values too big/sparse for a frequency/difference array, but you want to index by them.* *Mistake: forgetting to sort+unique before `lower_bound`; using the value instead of its rank.*

**Bit manipulation**
- [ ] **Elementary bit manipulation** — `(x>>i)&1`, `x&(x-1)`, `__builtin_popcountll`, XOR tricks (find the unique element via XOR). *Trigger: ≤~20 on/off flags, toggle a bit, count set bits, XOR properties.* *Mistake: `__builtin_popcount` on a long long sees only the low 32 bits — use the `...ll` variant.*

**Graphs & connectivity (the big Silver arc)**
- [ ] **String search/substring (`find`, `rfind`, `substr`, `npos`)** — `find` returns `string::npos` when absent. *Trigger: "does s contain t," "index of first x," "substring i..j."* *Mistake: forgetting the `npos` sentinel; O(n²) from `s = s + c` in a loop.*
- [ ] **Adjacency list** — `vector<int> adj[N];`, O(V+E) memory — the scalable default. (Adjacency **matrix** `adj[u][v]=1` only for small/dense N — O(N²) memory, O(1) edge lookup.) *Trigger: large sparse graph (almost all contest graphs).* *Mistake: adding an undirected edge only one way; 1- vs 0-indexed labels; an N×N matrix for N=10⁵ (MLE).*
- [ ] **Grid as an implicit graph** — each cell is a node with up/down/left/right neighbors via dr/dc; no explicit edge list. *Trigger: moving between adjacent open cells (mazes, regions).* *Mistake: building a huge explicit adjacency list for a grid; treating walls as passable.*
- [ ] **Visited array / marking** — a `bool visited[]` (or `vector<char>`) set on first arrival so each node is processed once. **The single most important correctness piece of traversal.** *Trigger: any DFS/BFS/flood fill.* *Mistake: marking visited too late (a node enqueued multiple times); not resetting between test cases.*
- [ ] **DFS on a grid (flood fill)** — recursively visit, mark, dive into each unvisited in-bounds same-region neighbor. *Trigger: "how many regions," "size of the blob at (r,c)," reachability on a grid.* *Mistake: missing the bounds/visited/wall base case; stack overflow on huge grids (use BFS / raise stack).*
- [ ] **BFS on a grid (shortest unweighted path)** — a queue expands level by level; neighbor dist = dist+1. *Trigger: "fewest moves" / "shortest path" on an unweighted grid.* *Mistake: marking visited at pop-time not push-time (a cell enqueued many times); using BFS distance when edge costs differ.*
- [ ] **DFS on an adjacency list** — visit, mark, recurse into unvisited neighbors. *Trigger: explore everything reachable in a non-grid graph.* *Mistake: no visited check → loops on cycles; recursion depth overflow on a 10⁵-node chain (iterative/BFS/raise stack).*
- [ ] **BFS on an adjacency list** — queue-based level order; shortest edge-count distance from the source; init `dist[]` to the safe INF. *Trigger: shortest hops / level distances in an unweighted non-grid graph.* *Mistake: push-time vs pop-time visited bug; uninitialized `dist[]`.*
- [ ] **Counting connected components** — loop all nodes; each unvisited one triggers a full DFS/BFS + a counter (share ONE visited array). *Trigger: "how many separate regions/groups/islands," "are all connected."* *Mistake: re-running from visited nodes (overcount); not sharing the visited array across the outer loop.*
- [ ] **Disjoint Set Union (Union-Find)** — a forest of parent pointers with **path compression + union by size**; near-O(1) "are u,v in the same group?" and "merge." The other standard connectivity tool, needed when edges arrive online. *Trigger: dynamic "connected after these unions?", merging groups without a static graph; later Kruskal.* *Mistake: forgetting path compression / union by size (slow); not initializing `parent[i]=i`.*

**Number theory & bit techniques ceiling**
- [ ] **Sieve of Eratosthenes** — all primes up to N in O(N log log N) by marking multiples. *Trigger: primality for MANY numbers / all primes ≤ N (~10⁷).* *Mistake: sizing the array wrong / off-by-one at N.*
- [ ] **Prime factorization & divisor enumeration** — divide out primes to √n; list divisors by pairing `d` with `n/d` for `d*d<=n`. *Trigger: number/sum of divisors, prime factors.* *Mistake: double-counting when `d*d==n`; forgetting the leftover prime factor > √n.*
- [ ] **Modular arithmetic + non-negative subtraction** — reduce after every add/multiply; cast to `long long` before multiplying; `((a-b)%m + m)%m`. *Trigger: "output the answer modulo 1e9+7," or a big count that would overflow.* *Mistake: multiplying two ints near 1e9 before the mod (overflow); a raw negative remainder.*
- [ ] **Fast (binary) exponentiation — intuition** — `aⁿ = (a^(n/2))²`, halving the exponent → O(log n); the same log-lever as binary search. **The top edge of this roadmap.** (Modular exponentiation / modular inverse edge into Gold — learn the halving idea now, defer those.) *Trigger: `aⁿ` for large n.* *Mistake: looping n multiplications (too slow); overflowing the square without `long long`/mod.*
- [ ] **`bitset` (container awareness)** — fixed-size bits packed 64/word; fast `&|^`, `count()`, `test()`; ~64× on bulk boolean ops. (Subset-sum DP framing is Gold — deferred.) *Trigger: a big boolean array / flag set wanting fast bulk bit ops.* *Mistake: size must be a compile-time constant; don't confuse with `vector<bool>`.*

**💡 Analogies:** BFS = ripples spreading from a stone dropped in a pond (nearest cells first). DSU = merging friend-circles: to check if two people are in the same circle, follow each up to its "leader." Binary-search-on-answer = guessing a number in 1..N by always asking "higher or lower?"
**Canonical practice:** USACO Silver *Binary Search*, *Two Pointers*, *Flood Fill*, *Graph Traversal*; CSES *Counting Rooms* (grid flood fill), *Building Roads* (components/DSU), *Maximum Median* (BOTA); "aggressive cows."

> **EXIT 15 (roadmap ceiling):** you pick binary-search / two-pointer / sliding-window / prefix / BFS-DFS / DSU from a problem's *trigger*, implement each cleanly with correct `visited`/INF/mod handling, and prove-or-stress-test greedies. **This is a solid USACO Silver / CF 1200+ foundation — the goal.**

---

## Stage 16 — The bridge to Silver/Gold: what comes next
**Goal:** name the next boundary so the foundation clearly *points* somewhere. Not part of the 0→1 checklist — a signpost.

- [ ] **Dynamic Programming mindset (the next big topic)** — DP = clean recursion + memoization: define a state, a transition, and a base case, then either memoize the recursion or fill a table bottom-up. It's the single biggest Silver/Gold topic. *Trigger: "count the number of ways," "min/max over choices with overlapping subproblems," "can I reach X" where greedy fails and brute force is exponential.* *Mistake: a DP with an ill-defined state, or recomputing overlapping subproblems (that's what memoization exists to kill).*
- [ ] **First DP problems when you get here** — CSES *Dice Combinations*, *Coin Combinations I*, *Longest Increasing Subsequence*, USACO Silver *Intro to DP*. *Prerequisite you already have: recursion (Stage 5/11), arrays/vectors, complexity reading.*

> Everything in Stages 0–15 is the load-bearing slab under DP and graphs-with-weights (Dijkstra, which reuses your priority_queue + BFS). When Stage 15 is automatic, start here.

---

## Appendix A — Trigger table (build this in `CHEATSHEET.md`, one row per solved problem)
*Your single highest-leverage artifact for the "names without triggers" weakness. The **signal** is what you read in the statement; the **tool** is what it should fire.*

| Signal in the statement / constraints | Fire this tool |
|---|---|
| `N ≤ 10` | permutations / `next_permutation`, O(n!) |
| `N ≤ 20–24` | subset bitmask, O(2ⁿ) |
| `N ≤ 500` | O(n³) triple loop is fine |
| `N ≤ 5000` | O(n²) brute force is fine |
| `N ≤ 2·10⁵` | need O(n log n) — sort / set / binary search |
| `N ≤ 10⁷` | need O(n) — single pass, fast IO |
| "sum of n over all test cases ≤ X" (CF) | budget against the **sum**, not per-test n |
| any sum/product of big values | `long long`, cast an operand before `*` |
| "many range-sum queries on a static array" | prefix sums |
| "add X to range `[l,r]`, many times, read at end" | difference array |
| "subrectangle sums on a grid" | 2D prefix sums |
| range XOR queries | prefix-XOR |
| sorted data + "first ≥ x / count ≤ x" | `lower_bound`/`upper_bound` |
| "maximize the minimum / minimize the maximum" | binary search on the answer |
| "count pairs / two-sum" on sorted data | two pointers |
| "longest/shortest contiguous subarray with a constraint" | sliding window |
| "distinct / seen / frequency" | set / map |
| values huge/sparse but you want to index by them | coordinate compression |
| "how many separate groups / islands / regions" | flood fill + component count, or DSU |
| "fewest moves / shortest path" on unweighted graph/grid | BFS |
| "connected after these merges?" | DSU |
| "construct any valid X" / "is it possible," no classic algo | ad-hoc: try n=1,2,3; look for a parity/pigeonhole invariant |
| "answer modulo 1e9+7" | modular arithmetic, reduce each step, `long long` before `*` |
| two axis-aligned rectangles / intervals | overlap test + inclusion-exclusion |
| "closest points" | compare **squared** distances (no `sqrt`) |
| "count ways / min-max over overlapping choices" | dynamic programming (next stage) |

## Appendix B — Self-audit: how this roadmap was made complete

**Gaps folded in that the raw inventory was missing:** lambdas · ternary `?:` · `stringstream` · type aliases/macros · raw bitwise operators (placed before bitmasking) · `pow`/`sqrt` float trap · `1e9`/`4e18`-double-literal subtlety · Manhattan/Euclidean distance · rectangle/interval geometry · DSU · coordinate compression · string `find`/`substr`/`npos` · pigeonhole/parity/invariant reasoning · safe INF constant (fused overflow+init) · iterator invalidation · big-local-array stack overflow · `vector<bool>` trap · negative floor/ceil division · 64-bit builtins/`1LL` shifts · CF "sum of n" idiom · running-accumulator primitive · statement→I/O-contract skill · deep-recursion/stack-size handling (MSYS2 `-Wl,--stack`) · gdb · `stable_sort`/stability · prefix-max/prefix-XOR · `assert`/NDEBUG · `freopen` · measure-before-you-trust timing · an explicit intro-DP bridge.

**Reordered** so nothing is taught before its prerequisite: recursion precedes all recursive-generation/backtracking · lambdas precede every comparator/predicate · casting sits with overflow · the `size_t` trap is anchored to array size (before vectors) · iterators/begin-end precede sort and next_permutation · bitwise operators precede bitmask enumeration · the safe INF constant precedes BFS · complexity gate (Stage 8) and correctness gate (Stage 9) precede all technique stages.

**Deferred as too advanced for 0→1200** (named at their spot, not placed in core rungs): `emplace_back`/`reserve` · `std::array` · monotonic-deque sliding-window max · bitset subset-sum DP · modular exponentiation/inverse · `unordered_map` custom anti-hash · full DP · weighted shortest paths (Dijkstra).

## One-glance stage map

| Stage | Theme | Gate / status |
|---|---|---|
| 0 | Compile-run loop, sanitizers, MSYS2 | pre |
| 1 | First AC: types & overflow | pre |
| 2 | Decisions, loops, speed reflex, simulation/casework | pre → Bronze |
| 3 | Arrays, vectors, strings | pre → Bronze |
| 4 | Input/output mastery | pre → Bronze |
| 5 | Functions, references, lambdas, recursion | pre → Bronze |
| 6 | Iterators, sort, comparators | mostly **done** |
| 7 | Elementary math | pre → Bronze |
| 8 | Complexity reading | **⛔ GATE A** |
| 9 | Correctness, debugging, testing | **⛔ GATE B**; anchors **done** |
| 10 | STL container toolkit | Bronze → Silver |
| 11 | Complete search & recursion | Bronze |
| 12 | Bronze patterns (+ rectangle geometry) | Bronze — **milestone** |
| 13 | Greedy + proof habit | Bronze → Silver |
| 14 | Prefix sums & difference arrays | **started** |
| 15 | Early-Silver on-ramp (search, graphs, DSU, bits, modular) | Silver — ceiling |
| 16 | Bridge: DP mindset | signpost |

---

## Sources

- USACO Guide — General / Expected Knowledge: https://usaco.guide/general/expected-knowledge
- USACO Guide — Input/Output: https://usaco.guide/general/input-output
- USACO Guide — Fast I/O: https://usaco.guide/general/fast-io
- USACO Guide — Data Types: https://usaco.guide/general/data-types
- USACO Guide — Time Complexity: https://usaco.guide/bronze/time-comp
- USACO Guide — Debugging Checklist: https://usaco.guide/general/debugging-checklist
- USACO Guide — Basic Debugging: https://usaco.guide/general/basic-debugging
- USACO Guide — Practicing: https://usaco.guide/general/practicing
- USACO Guide — Bronze track: https://usaco.guide/bronze
- USACO Guide — Intro to Data Structures: https://usaco.guide/bronze/intro-ds
- USACO Guide — Intro to Sorting: https://usaco.guide/bronze/intro-sorting
- USACO Guide — Rectangle Geometry: https://usaco.guide/bronze/rect-geo
- USACO Guide — Intro to Sets & Maps: https://usaco.guide/bronze/intro-sets
- USACO Guide — Silver track: https://usaco.guide/silver
- USACO Guide — Prefix Sums: https://usaco.guide/silver/prefix-sums
- USACO Guide — Binary Search: https://usaco.guide/silver/binary-search
- USACO Guide — Two Pointers: https://usaco.guide/silver/two-pointers
- USACO Guide — Flood Fill: https://usaco.guide/silver/flood-fill
- USACO Guide — Graph Traversal: https://usaco.guide/silver/graph-traversal
- USACO Guide — Intro to DP: https://usaco.guide/silver/intro-dp
- Darren Yao, "An Introduction to USACO" (C++): https://darrenyao.com/usacobook/cpp.pdf
- CP-Algorithms: https://cp-algorithms.com/
- CP-Algorithms — Sieve of Eratosthenes: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
- CP-Algorithms — Binary Exponentiation: https://cp-algorithms.com/algebra/binary-exp.html
- CP-Algorithms — DSU: https://cp-algorithms.com/data_structures/disjoint_set_union.html
- CP-Algorithms — BFS: https://cp-algorithms.com/graph/breadth-first-search.html
- CP-Algorithms — DFS: https://cp-algorithms.com/graph/depth-first-search.html
- Codeforces — "Blowing up unordered_map" (anti-hash / custom hash): https://codeforces.com/blog/entry/62393
- Codeforces — "Why you should never use pow": https://codeforces.com/blog/entry/21844
- CSES Problem Set: https://cses.fi/problemset/
- cppreference — Containers: https://en.cppreference.com/w/cpp/container
- cppreference — `next_permutation`: https://en.cppreference.com/w/cpp/algorithm/next_permutation
- cppreference — `setprecision`: https://en.cppreference.com/w/cpp/io/manip/setprecision
- SEI CERT INT10-C (modulo sign): https://wiki.sei.cmu.edu/confluence/spaces/c/pages/87152120/INT10-C