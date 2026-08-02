# Sorting & Structs — Lock-In Exercises (2026-07-22)

Do these **solo**, in order. For each one: write it, run the sample **and** one nasty case you
invent yourself, then say **"check"**. Skills: structs · comparators · tie-breaks · scan-vs-sort · the checklist.

Suggested files: `ex1.cpp` … `ex5.cpp` in this folder.

---

## Ex 1 — Sort Descending  *(single-key comparator — warm-up)*
Read `N`, then `N` lines: `name score`. Print players sorted by score, **highest first**.

**Input**
```
3
Ann 50
Bob 80
Cat 65
```
**Output**
```
Bob 80
Cat 65
Ann 50
```

---

## Ex 2 — Contest Standings  *(2-key tie-break)*
Read `N`, then `N` lines: `name solved penalty`. Rank by **most solved first**; if tied,
**lower penalty first**. Print `name solved penalty`.

**Input**
```
4
Alpha 5 200
Beta 5 150
Gamma 4 100
Delta 5 180
```
**Output**
```
Beta 5 150
Delta 5 180
Alpha 5 200
Gamma 4 100
```

---

## Ex 3 — Class Ranking  *(3-key tie-break)*
Read `N`, then `N` lines: `name grade age`. Rank by **grade desc**; tie → **age asc**; tie →
**name alphabetical**. Print `name grade age`.
*(Remember: 3 keys = 2 `if`-returns + 1 plain return.)*

**Input**
```
5
Zoe 90 15
Amy 90 15
Ben 90 16
Cid 85 14
Dan 90 15
```
**Output**
```
Amy 90 15
Dan 90 15
Zoe 90 15
Ben 90 16
Cid 85 14
```

---

## Ex 4 — Tallest Building  *(SCAN — don't sort!)*
Read `N`, then `N` lines: `name height`. Print the `name height` of the **tallest**. If there's
a tie, print the one that appears **first** in the input. Solve with a single O(N) scan.

**Input**
```
4
A 30
B 45
C 45
D 20
```
**Output**
```
B 45
```

---

## Ex 5 — Leaderboard + Total  *(combine everything + overflow ⚠️)*
Read `N` (up to 10^5), then `N` lines: `name score` (score up to 10^9).
1. Print players sorted by **score desc**, tie → **name asc**.
2. Then print one final line: the **sum of all scores**.

*(Checklist: what's the biggest that sum can get? Pick your type accordingly.)*

**Input**
```
3
Ann 1000000000
Bob 1000000000
Cat 500000000
```
**Output**
```
Ann 1000000000
Bob 1000000000
Cat 500000000
2500000000
```
