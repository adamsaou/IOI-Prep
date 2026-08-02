# Practice Progress

Maintained by Claude (coach mode — see `CLAUDE.md`). Update after each session.

## ⚠️ Pre-submit checklist — run EVERY time before calling a solution "done"
1. **Overflow?** Can any sum / product / difference exceed ~2.1×10⁹? → use `long long`
   (and check library init types, e.g. `accumulate(…, 0LL)`). *Compute the bound, don't guess.*
2. **Init?** Seed max/min from a **real element**, never `0`. What if all values are negative / all equal?
3. **Boundaries?** N=1, N=2, empty, first/last index, ties, duplicates.
4. **Tested?** Ran the sample **and** one nasty case I invented myself.

> This checklist is the #1 fix for the WA problem. It has already caught real bugs (diag1).

## Profile — updated 2026-07-22
- **Level:** USACO Bronze / CSES Introductory. **Codeforces: Adam.Saoudani — 836 (newbie)**, 56 solved (mostly 800-rated).
- **Time:** 3–6 hours/week
- **Goal (restated 2026-07-23):** **CF 1200+** and **well past USACO Bronze** (Silver → Gold). North star: IOI-level understanding. **Next checkpoint: CF 1000+ / USACO Silver.**
- **Weak spots (data-backed):** #1 = **correctness / WRONG_ANSWER** (96 WA vs 78 OK on CF) → edge cases, overflow, no pre-submit testing. Toolkit gap: no binary search / two pointers / prefix sums / DP / graphs yet. TLE is *not* a real issue (only 3 ever). Idea-finding reaches brute force but doesn't auto-ask "is it fast enough?", and grafts technique *names* without their triggers.

## Roadmap — Bronze → Silver
**Two fronts, run in parallel:**

**A · Correctness habit** — the checklist above, on *every* problem. Metric: WA-before-AC trending down.

**B · Toolkit modules** — for each: learn the **trigger** (when to reach for it) → one worked idea → 2–3 real problems → STL drill → review. Order:
1. 🟡 **Sorting + comparators ✅ & sort-then-greedy** ← *in progress (comparators owned; greedy reps ongoing)*
2. ⬜ **Prefix sums** (1D → 2D)
3. ⬜ **Two pointers / sliding window** (correct triggers: sorted array, or contiguous subarray)
4. ⬜ **Binary search** (on an array → on the answer)
5. ⬜ **Graphs: BFS / DFS / flood fill + DSU**
6. ⬜ **Intro DP** (later)

**Weekly (3–6h):** 2–3 module problems from real judges + 1 short STL drill. Promote a 🟡→✅ after 2–3 clean solves.

**Active spine (from 2026-07-24): the USACO Guide BRONZE track** — official modules in order, as a
**gap-focused sweep** (Bronze promotion is the near checkpoint, ~Dec 2026). Breeze the topics his CF
grind already covers (simulation, complete search, math, greedy — confirm with 1–2 problems); spend
real time on the genuine gaps: **Sets & Maps, Casework, Complete Search with Recursion, Intro to
Graphs**, plus **Gate A (complexity)** and **Gate B (correctness ritual, his #1)** which apply to every
problem. Coach contract per rep: skill-first → he solves → Claude compiles/runs/stress-tests → review
for the lesson → mark done only when owned. Prefix sums (a Silver topic) is on hold after one
consolidation rep; resume it at the Silver on-ramp. Secondary: CF problemset, tags `implementation`/
`greedy`/`sortings`, rating 1000–1100.

## Concept checklist
Legend: ✅ solid · 🟡 shaky / needs reps · ⬜ not started

### Bronze — current focus
- ✅ **C++ structs** (learned 2026-07-22: declare, `vector<struct>`, `.` access, O(n) max-scan, comparator lambdas)
- 🟡 Complete search / brute force (9 solved on CF)
- 🟡 Simulation — *MixMilk*
- 🟡 Ad-hoc & math (math=19 on CF) — *CoinPiles, NumberSpiral, TwoKnights*
- 🟡 Basic greedy (14 on CF) — **sort-then-greedy started 2026-07-23** (perfect_pairs: found the insight solo ✓)
- 🟢 Sorting comparators — single + multi-key tie-breaks ✅ confirmed **solo** (4-key rep, 2026-07-23). **Next: sort-then-greedy (the greedy *insight* = idea-finding).**
- ⬜ Recursion: generate subsets / permutations (`next_permutation`, backtracking)

> Note: the 🟡 tags have *solves* but a high WA rate — the gap is **correctness**, not exposure. We'll pressure-test each.

### Silver — next
- ⬜ Binary search (incl. binary search on the answer)
- ⬜ Two pointers / sliding window
- ⬜ Prefix sums (1D & 2D)
- ⬜ DSU (union-find)
- ⬜ Graphs: BFS / DFS / flood fill
- ⬜ Elementary number theory

## Practice log
| Date | Problem (source) | Result | Notes / concept |
|------|------------------|--------|-----------------|
| 2026-07-22 | *(coaching setup)* | — | Profile + plan established |
| 2026-07-22 | diag1 — array basics (impl probe) | AC after 1 review | Bugs: overflow (`int` + `accumulate(…,0)`) & max init = 0. Fixed both, nailed `0LL`. First pre-submit rep. |
| 2026-07-22 | diag2 — minimum difference (idea probe) | **AC, first check** | Found sort + adjacent scan (dropped wrong "2P from ends"). Init-from-real-pair lesson **transferred** from diag1. |
| 2026-07-22 | player_ranking — tie-break sort (Module 1) | AC (heavy scaffolding) | Learned multi-key comparator (primary `if`-return + unconditional tie-break) after a rough patch, then recovered. Confirm with a solo rep. |
| 2026-07-23 | Lock-in set ex1–ex5 (sorting/structs) | 3/5 clean; ex3 & ex4 passed sample but WRONG | ex1 ✓, ex2 ✓, ex5 ✓ (handled overflow + tie-break unprompted). ex3: comparator key-order (checked age before grade). ex4: scan compared neighbor, not running best. Both = "passes sample ≠ correct" → the WA pattern, caught in drills. |
| 2026-07-23 | ex3 & ex4 fixes + multi-key comparators | Both fixed → set fully clean ✅ | ex4: scan → running best ✓. ex3: multi-key comparator clicked after the "alphabetical order / first difference decides" analogy + `!=` chaining. |
| 2026-07-23 | tournament — 4-key comparator (solo) | **AC, first check** | Solo 4-key tie-break (wins↓ losses↑ rating↓ name↑), Zed trap handled. Multi-key comparators confirmed OWNED. |
| 2026-07-23 | perfect_pairs — sort-then-greedy (1st rep) | **AC, solo** | Found the greedy (sort + pair neighbours) **independently** — first solo greedy insight. `int` safe here (pair gaps are disjoint → sum ≤ span ≤ 2·10⁹), but likely chosen by default, not analysis. |

## STL drills done
| Date | Focus | How it went |
|------|-------|-------------|
| 2026-07-22 | structs + linear max-scan + single-key comparator lambdas | Learned structs from zero. Fixed an off-by-one (`i < n-1` skipped last element) via the boundary check. Clean after review. |
