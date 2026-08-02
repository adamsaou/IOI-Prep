# The Accuracy-Then-Toolkit Plan
### Adam.Saoudani — CF 836 → 1200, USACO Bronze → Silver, at ~4 hours a week

---

## 1. Diagnosis: what your numbers actually say

Three facts, all from your own account:

| Number | You | What it means |
|---|---|---|
| **96 WA vs 78 OK**, 3 TLE | 55% of submissions are wrong answers; TLE is 1.6% | Correctness is the bottleneck. Speed is not costing you anything right now. |
| **188 submissions / 56 solves = 3.36 per AC** | should be under 2.0 | You cannot tell a correct solution from a wrong one *before* you submit. Every problem costs you three attempts instead of one — at 4h/week that divides your real throughput by roughly three. |
| **46 of 56 solves rated 800**; zero solves tagged binary search, two pointers, prefix sums, dp, graphs, dfs/bfs, dsu | 82% of your practice is below your own rating | Below-rating problems are *retrieval*, not learning. That is why max rating = current rating = 836 after 8 months. |

Now the part people usually get wrong about this profile. Your bug species — integer overflow, `max` initialised to `0` instead of a real element, off-by-one loop bounds, comparator key ordering — all happened on **800-rated problems where no missing technique was involved**. Prefix sums would not have saved you. So the empty toolkit and the WA rate are **two separate problems**, and correctness is the one that is bleeding you *today*.

But an empty toolkit is what caps your ceiling. Your zero-solve tag list is, almost line for line, the USACO Silver syllabus (Prefix Sums → Sorting & Searching → Graphs). And the USACO Guide FAQ puts Silver competitors at roughly **CF 1200-1500**. So **"CF 1200" and "past Bronze" are one milestone reached by one curriculum**, not two goals.

One thing you should hear plainly: **46 solves at 800 was not wasted time.** xinyster's own recommendation is 40-50 problems per tier. You *completed* that tier. What you never installed was a process, so you're carrying a 55% error rate up with you. This is a graduation, not a correction.

---

## 2. The tension, resolved — accuracy vs toolkit vs volume

Three defensible plans exist for you and they genuinely conflict. Here is how I'm weighting them and why, so you can hold me to it:

- **Accuracy-first** says: fix the leak before adding water. Correct — but three weeks of zero new topics at a band you've already cleared has no evidence behind it and can stall on a noisy metric.
- **Toolkit-first** says: your ceiling is the empty inventory. Correct — but it treats correctness as a one-time 2-hour setup and then never trains it again for five months.
- **Volume-first** says: rating measures converting judged problems into AC, so do more of that. Correct — but it needs your throughput to jump from 1.6 to 4 problems/week inside the *same* 4 hours while *also* adding a ritual. That lever doesn't exist at this budget.

**The resolution — sequenced and weighted:**

| Weeks | Accuracy | Toolkit | Volume |
|---|---|---|---|
| **0** (setup) | 100% | — | — |
| **1-3** (sprint, hard-capped at 3 weeks) | **80%** | 0% | 20% |
| **4-20** (the main body) | **30%** — permanently, via a recurring debug lab and the ritual | **50%** | 20% |
| **21+** | 20% | 30% | **50%** |

Accuracy is never a "phase you finish". It becomes a **standing 60-minute slot every other week** (§5, Session C) that eats your own WAs as training material. Toolkit leads the middle. Volume takes over once the inventory is full, because by then a judged verdict is the only thing left that teaches you anything.

**The 3-week sprint has a hard time cap.** If your submissions-per-AC is still above 2.5 at week 4, you start the toolkit anyway and run the debug lab **every** week instead of alternating. An ungated gate is how plans die.

---

## 3. Study order — and why it is not the order you'd pick

From `usaco.guide/silver`, the module frequency labels:

| Silver module | Frequency |
|---|---|
| **Graph Traversal** | **Very Frequent — the only one** |
| Intro to Prefix Sums, Binary Search on a Sorted Array, Binary Search, Custom Comparators & Coordinate Compression, Greedy with Sorting, Flood Fill, Intro to Bitwise | Somewhat Frequent |
| **Two Pointers**, More on Prefix Sums, Priority Queues, Intro to Tree Algorithms, Functional Graphs | **Not Frequent** |

Read that against your history. You reached for *"two pointers from both ends"* on a problem where it didn't apply — **two pointers is the least frequent Silver topic**. DFS/BFS, which you have never written a single line of, is **the only Very Frequent one**.

So the order is:

> **prefix sums → binary search (incl. on the answer) → graph traversal + flood fill (spend the most time here) → comparators + coordinate compression + greedy proofs → two pointers → [GATED] DSU → [GATED] intro DP**

DSU and intro DP are **Gold** modules in the Guide. They stay in the plan because they're your north star, but they're locked (§4, Phase 6). Nearly every Silver-level DSU problem is also solvable with the DFS/BFS you'll already own — *Wormhole Sort* and *Moocast* appear under **both** Graph Traversal and DSU. Learning DSU before BFS buys you nothing.

---

## 4. Phased roadmap with measurable milestones

Every block has the same three-part shape, and part (a) is non-negotiable:

> **(a)** Write the **trigger sentence** in your own words into `CHEATSHEET.md`, **plus one traced counterexample where the technique FAILS**. → **(b)** Canonical problems. → **(c)** Unlabelled mixed review.

A technique name without a trigger and a failure case is exactly what produced the two-pointers misfire.

### Phase 0 — Machinery (week 0, ~2h, one-time)
Build the debug build line, the stress harness, the 7-item checklist card, and fix `CLAUDE.md`'s file-IO instruction.

**Exit test:** you plant a deliberate off-by-one *and* a deliberate overflow into an already-solved problem, and the rig finds both in under 60 seconds and prints the failing test.

### Phase 0.5 — Accuracy sprint (weeks 1-3, ~12h, **hard cap 3 weeks**, ZERO new topics)
Problems you are *already capable of solving* — CF 900-1000, plus the back half of kilobyte136's sheet and any CSES Introductory leftovers. Every single one runs the full ritual (§7).

| Milestone | Measurement |
|---|---|
| **M1** | Submissions per AC under **2.0**, rolling over the last 15 solves (currently 3.36) |
| **M2** | **8 of 10** consecutive problems ACed on the first submission — count it in a text file |
| **M3** | The rig catches **≥2 bugs before you submit**. If it never catches anything, your generator is producing the wrong shapes (§8.2) |

*If week 4 arrives and M1 isn't met: proceed anyway, and run Session C's debug lab weekly instead of biweekly.*

### Phase 1 — Prefix sums (~2 weeks)
**Trigger:** *"many range-sum queries, or 'count subarrays where a running total has property P'."*
**Traced counterexample:** range **max** queries — prefix arrays don't invert, subtraction is meaningless, the trick dies. Trace it on `[3, 9, 1]`.
**Exit:** AC *Subarray Sums II* in ≤2 submissions, and say out loud why it's `pre[r+1]-pre[l]` and not `pre[r]-pre[l]`.

### Phase 2 — Binary search, both kinds (~4 weeks)
Two separate skills: (i) `lower_bound`/`upper_bound` on a sorted array, (ii) **binary search on the answer**.
**Trigger, verbatim from the Guide:** *"binary search on the answer only works if the answer function is monotonic, meaning that it is always non-decreasing or always non-increasing."* Phrase-level tells: **"minimize the maximum"**, **"maximize the minimum"**, **"smallest X such that…"**.
**Traced counterexample:** a `check()` that returns true, false, true across 5 values, drawn on paper.
**Primary resource: CF EDU / ITMO Academy course 2, Binary Search section.** Free, graded, stepwise, and it has a dedicated binary-search-on-the-answer step. This is the best-fit resource in the entire plan for you because it states the trigger *before* the exercises.
**Exit:** given 10 statements you've never seen, correctly flag which are binary-search-on-answer, with reasons, in 5 minutes — **≥6 of 10**. Plus 5 module problems ACed.

### Phase 3 — Graph traversal + flood fill (~6-8 weeks) ← **the big one**
**Trigger:** *"things are connected / reachable / grouped / how many regions."*
Do **grids first**, then adjacency lists. A grid is drawable and traceable on paper, which is how you learn; an adjacency list is abstract and you have literally zero exposure. Note: this **inverts** the Guide's own page order, which lists traversal before flood fill. I'm recommending it on pedagogical grounds, not authority.
**Exit (behavioural, not a problem count):** you type a BFS **and** a DFS on `vector<vector<int>> adj` from a blank file in **under 5 minutes, twice in a row, no reference.** That is the Gold-facing investment that pays now — Dijkstra, toposort, tree DP and DSU are all variations on that one skeleton.

### Phase 4 — Comparators, coordinate compression, greedy proofs (~3 weeks)
You did multi-key comparators solo this week — but the Guide module is *"Custom Comparators **and Coordinate Compression**"*, and compression is a separate idea you have not touched. **Don't skip the module.**
Then the **exchange argument**, verbatim from the Guide: *"If we have two events E1 and E2, with E2 ending later than E1, then it is always optimal to select E1. This is because selecting E1 gives us more choices for future events. If we can select an event to go after E2, then that event can also go after E1, because E1 ends first."*
**Exit:** for every greedy you submit, you can write one sentence naming the sort key and why swapping two adjacent out-of-order elements cannot improve the answer.

### Phase 5 — Two pointers (~2 weeks) — last, on purpose
**Trigger, verbatim:** *"Since the array is sorted, moving the left pointer to the right will never decrease the sum, and moving the right pointer to the left will never increase the sum."*
**Traced counterexample:** an unsorted array, or a window predicate that isn't monotone. Build it at 5 elements and write it in the cheat sheet.

### Phase 6 — 🔒 GATED: DSU, then intro DP
**Locked until BOTH are true:** (1) you score **≥700** on a timed past Bronze contest, **and** (2) submissions-per-AC is **under 2.0**. Both are Gold modules (CF 1500-2200 territory). Opening them early is the single most tempting way to burn two months.

### The dashboard — three numbers, nothing else
1. **Submissions per AC** — 3.36 → target **<2.0**. CF computes it; zero tracking cost.
2. **Tag coverage** — six tags at zero → each block ends with **≥8 solves** on its tag. Unfakeable, and it moves while rating doesn't.
3. **UNAIDED %** — fraction solved with no hint and no editorial. Target zone **30-40%** (SuperJ6's rule). **Above ~50% → move the band up. Below ~20% → move it down.** This is what makes "pick the right difficulty" a rule instead of a guess.

Plus one checkpoint metric: **timed past-Bronze mock score out of 1000** (§9).

---

## 5. Weekly schedule — ~3h45m scheduled inside a 4h week

Minimum block is 75 minutes. Six 40-minute sessions is a worse week than three 80-minute ones, because you lose the first 15 minutes reloading the problem into your head.

### Session A — Deep practice (90 min, Saturday)
| Time | Activity |
|---|---|
| 0:00-0:05 | **Re-read `CHEATSHEET.md`.** At the *start*, not just appending at the end. Zero-cost retention. |
| 0:05-0:45 | Problem 1 from the queue — full ritual (§7). Paper out, timer on. |
| 0:45-1:25 | Problem 2 — full ritual. |
| 1:25-1:30 | Append this week's reusable idiom + any new bug species to `CHEATSHEET.md`. |

### Session B — Module (75 min, Tuesday)
| Time | Activity |
|---|---|
| 0:00-0:10 | Read the module page. Write the **trigger sentence in your own words** into `CHEATSHEET.md`. |
| 0:10-0:20 | **Construct and hand-trace one counterexample where the technique FAILS**, on real numbers, on paper. |
| 0:20-1:15 | The block's next queue problem — full ritual, stress-tested, ACed. |

*During the Phase 0.5 sprint, this session is a third practice problem instead — no modules yet.*

### Session C — Alternating (60 min, Thursday)
- **Odd weeks — DEBUG LAB.** Take every problem this week that needed **more than one submission**. For each, **name the bug species** from the fixed taxonomy: *overflow / max-init-to-0 / off-by-one / comparator ordering / misread statement / uncleared state*. Log it with a date. Then run the stress rig until it reproduces. This is the slot that eats your own 96 WAs as training material.
- **Even weeks — CONTEST.** One **Div. 4** virtual (Div. 3 if no Div. 4 is available), then upsolve **exactly the easiest problem you missed**, properly, stress-tested. Count the upsolve as that week's archive work, not as extra.
  - *Why Div. 4 over Div. 3:* Div. 4 is rated for <1400, so **A-D all sit in 800-1200 — four in-band problems.** In Div. 3 only A-C are in band and D is a stretch.

### Session D — Ledger (15 min, Sunday, or tacked onto A)
Update the three dashboard numbers. That's it. Measurement gets a time box or it doesn't happen.

### Slack: ~15 min. **Do not fill it.** It absorbs overruns so one bad week doesn't break the streak.

**Weekly output target: 3 finished problems** (4 on a good week). **"Finished"** = you typed it, it got AC, and **if you read a hint or editorial you re-implemented it from scratch in the same session.** A problem you read the solution to and did not type does **not** count and does not go on the tag counter.

**3h week:** drop Session B's problem half, keep the 20-minute trigger+counterexample work. **Never drop the virtual in a contest week — it is your only unfiltered correctness signal.**
**6h week:** add a **second 90-minute Session A**, *not* a second contest. Archives teach you to solve; contests teach you to solve *fast* — and with 3 TLEs, speed is demonstrably not your constraint.

---

## 6. The problem queue — pull from the top

**This is a queue, not a schedule.** ~45 named problems at ~3 properly-done problems/week is 4-6 months. Do not put dates on it; a missed date is worth less than nothing.

### Sprint (weeks 1-3, no new technique)
Pull from **[kilobyte136's 70-problem sheet, CF blog 152911](https://codeforces.com/blog/entry/152911)** — ordered by *learning* difficulty rather than crowd-sourced rating. **Start from the back half (the ~950-1000 region), not the front**, or the sprint quietly becomes another month of low-insight 800s. That sheet is the right one for you specifically: your 38 implementation-tagged solves say you've been sampling the tedious, no-insight end of 800.

### Block 1 — Prefix sums · `usaco.guide/silver/prefix-sums`
| # | Problem | Judge | Note |
|---|---|---|---|
| 1 | **Breed Counting** | USACO Silver | *Very Easy* — your first one |
| 2 | **Hoof, Paper, Scissors** | USACO Silver | *Very Easy* |
| 3 | **GCD on Blackboard** | AtCoder | prefix/suffix from both ends |
| 4 | **Good Subarrays** | Codeforces | *Easy* |
| 5 | **Subarray Divisibility** | CSES | prefix mod + counting map |
| 6 | **Subarray Sums II** | CSES | ⚠️ n ≤ 2·10⁵, aᵢ ≤ 10⁹ — **this one overflows `int` by design. Do it deliberately as your overflow lesson.** |
| 7 | **Subsequences Summing to Sevens** | USACO Silver | |
| 8 | **Maximum Subarray Sum** | CSES | note exactly where "init max to 0" would have bitten you |
| 9 | **Forest Queries** | CSES | 2D prefix sums |

### Block 2 — Binary search · **CF EDU course 2** + `usaco.guide/silver/binary-search`
| # | Problem | Judge | Note |
|---|---|---|---|
| 10 | **CF EDU, Binary Search steps 1-3** | CF EDU | graded — do all the practice, not just the videos |
| 11 | **Factory Machines** | CSES | the canonical binary-search-on-the-answer |
| 12 | **Array Division** | CSES | "minimize the maximum" |
| 13 | **Cow Dance Show** | USACO Silver | *Easy* |
| 14 | **Convention** | USACO Silver | *Easy* |
| 15 | **Guess the K-th Zero** | Codeforces | interactive — forces you to state the invariant |
| 16 | **1201C Maximum Median** | Codeforces | the Guide's focus problem |
| 17 | **Angry Cows** | USACO Silver | *Easy* |
| 18 | **Social Distancing** | USACO Silver | *Normal* — reach problem |

> **Practical note:** declare `lo` and `hi` as `long long` and the classic `(l+r)/2` midpoint overflow *cannot happen*. Learn the **type**, not the `l + (r-l)/2` ritual. A ritual you don't understand is one more thing to misapply.

### Block 3 — Graphs (longest block) · `silver/flood-fill` then `silver/graph-traversal`
| # | Problem | Judge | Note |
|---|---|---|---|
| 19 | **Counting Rooms** | CSES | grid flood fill — start here |
| 20 | **Labyrinth** | CSES | grid BFS + path reconstruction |
| 21 | **Icy Perimeter** | USACO Silver | flood fill with two accumulators |
| 22 | **Solve The Maze** | Codeforces | flood fill + construction |
| 23 | **Mooyo Mooyo** | USACO Silver | flood fill + simulation |
| 24 | **Building Roads** | CSES | ← **first adjacency-list problem**, components |
| 25 | **Building Teams** | CSES | bipartite check via BFS colouring |
| 26 | **Message Route** | CSES | BFS shortest path + reconstruction |
| 27 | **Closing the Farm** | USACO Silver | *Easy* — repeated connectivity |
| 28 | **Moocast** | USACO Silver | *Easy* — build the graph yourself |
| 29 | **Fence Planning** | USACO Silver | *Easy* |
| 30 | **Round Trip** | CSES | cycle detection |
| 31 | **Flight Routes Check** | CSES | *Normal* |
| 32 | **Wormhole Sort** | USACO Silver | *Normal* — binary search **+** connectivity. Do this last. |

### Block 4 — Comparators, coordinate compression, greedy proofs · `silver/greedy-sorting`
| # | Problem | Judge | Note |
|---|---|---|---|
| 33 | **Ferris Wheel** | CSES | classic two-sided greedy |
| 34 | **Stick Lengths** | CSES | median argument — prove it |
| 35 | **Concert Tickets** | CSES | multiset + `upper_bound` |
| 36 | **Movie Festival** | CSES | ← **the exchange-argument focus problem** |
| 37 | **Tasks and Deadlines** | CSES | sort key is non-obvious; write the swap proof |
| 38 | **Reading Books** | CSES | casework on the largest element |
| 39 | **Lemonade Line** | USACO Silver | *Easy* |
| 40 | **Rest Stops** | USACO Silver | greedy on suffix maxima |
| 41 | **High Card Wins** | USACO Silver | |
| 42 | **Closest Cow Wins** | USACO Silver | coordinate reasoning |

### Block 5 — Two pointers (last) · `silver/two-pointers`
| # | Problem | Judge | Note |
|---|---|---|---|
| 43 | **Sum of Two Values** | CSES | module focus problem |
| 44 | **279B Books** | Codeforces | the other focus problem — sliding window |
| 45 | **Subarray Sums I** | CSES | positive values only — *this is why it's here and not in Block 1* |
| 46 | **Sum of Three Values** | CSES | |
| 47 | **They Are Everywhere** | Codeforces | minimal window containing all distinct |
| 48 | **Diamond Collector** | USACO Silver | |

### Bronze-specific gap modules (before your first mock, Phase 3 of §9)
Your CF tag profile (implementation 38, math 19, greedy 14, brute force 9, sortings 8) **already covers all three "Very Frequent" Bronze modules** — Simulation, Basic Complete Search, Ad Hoc. The genuine gaps are only these four:
> **Intro to Sets & Maps** · **Casework** · **Complete Search with Recursion** · **Intro to Graphs**

Then **`usaco.guide/bronze/bronze-conclusion`** — uncategorised problems, i.e. *unlabelled* practice, which is the recognition skill you're weakest at.

### 🛑 CSES Sorting & Searching is NOT linear — explicit stop-list
The section is **33 problems** (older lists say 22 — stale). Skip these until much later; they need a BIT, a multiset, or a monotonic stack and are Silver-to-Gold:
> **Nested Ranges Check** · **Nested Ranges Count** · **Room Allocation** · **Nearest Smaller Values** · **Movie Festival II** · **Towers** · **Traffic Lights** · **Distinct Values Subarrays II** · **Maximum Subarray Sum II**

CSES ships **no editorials** — [CF blog 83295](https://codeforces.com/blog/entry/83295) is the community editorial set for that section. Bookmark it now; it's load-bearing for a solo learner.

### Running in parallel (Session A's second problem, once per week)
CF problemset filtered **rating 1000-1100, tags HIDDEN**. Unlabelled is the point — recognising the trigger *is* the skill, and labelled lists delete that step. When you need more structure, use **[CP-31](https://www.tle-eliminators.com/cp-sheet)** — but **start at the 1000 and 1100 buckets and skip the 800 bucket entirely**, or it undoes your band graduation.

### Optional substitute, never an addition
**AtCoder ABC problems C and D** — *not* B and C. ABC went from 6 to 8 problems in **July 2021 (ABC 212)**, so today's A and B are trivial warmups. Use an ABC as a **replacement** for a CF round occasionally, never on top of one.

---

## 7. The per-problem ritual — run this every single time

### Before you write any code (5 min, on paper)

```
1. Read the CONSTRAINT LINE FIRST, before the story.
     N = ______        →  ops budget = 1e8
     my idea is O(______) = ______ ops

2. Read the table BACKWARDS, as a HINT GENERATOR, not a post-hoc check:
     n ≤ 10    → O(n!)          n ≤ 20   → O(2^n · n)
     n ≤ 80    → O(n^4)         n ≤ 400  → O(n^3)
     n ≤ 7500  → O(n^2)         n ≤ 7e4  → O(n √n)
     n ≤ 5e5   → O(n log n)  ← MEANS: sort / binary search /
                                two pointers / prefix sums
     n ≤ 5e6   → O(n)           n ≤ 1e18 → O(log n)
   The constraint IS the trigger. This is the direct fix for
   "reaches brute force, never asks if it's fast enough."

3. Every accumulator: write down its MAX value. Bigger than 2e9? long long.

4. If it's greedy: name the sort key, then write ONE SENTENCE on why
   swapping two adjacent elements out of that order cannot help.
   If you can't write the sentence, you don't have a solution — you have a vibe.
```

### The attempt
- **Time box: 15-20 min** on Bronze / CF ≤1000. **30-40 min** on Silver / CF 1100-1300. *(Darren Yao, `usaco.guide/general/practicing`.)*
- **The qualifier is "of no meaningful progress", not wall clock.** If genuinely new ideas are still arriving at minute 35, keep going. If you've produced zero new ideas in the last 5 minutes, the clock expired.
- **Paper is mandatory.** Write every observation down as it occurs, even the ones that look irrelevant. *"Don't think the same things over and over."*

### When the timer expires — hint ladder, one rung at a time
`L1 nudge` → `L2 key observation` → `L3 name the technique + plan` → `L4 full walkthrough`.
Solo? Try **tags first**, then someone's accepted code, then the editorial — and read only far enough to unstick.

> **Non-negotiable, and every source agrees on this one: you type it and get it AC yourself, from scratch, in the same session.** Reading a solution and nodding is not a solved problem.

### Stuck a second time on the same problem?
**Log it with a date and move on.** Re-attempt anything on that list once the entry is **4+ weeks old**, cold, *before* re-reading your old code.

### Pre-submit routine — your 4 items + exactly 3, + 1 conditional
You built the 4-item habit days ago. **Do not replace it with a 12-item list — long checklists get skipped.** Write these seven on an index card and put it next to the keyboard.

```
1. Overflow?          every product/sum — is it long long? is the CAST there?
2. Initialization?    max/min seeded from a REAL ELEMENT, never 0. INF big enough?
3. Boundaries?        loop bounds, < vs <=, n=1, n=max
4. Actually tested?   on cases *I* invented, not the sample
--- the three additions ---
5. Cleared all state between test cases?
6. RE-READ THE STATEMENT — did I answer the question actually asked?
7. Output format exact? no leftover debug prints?
--- greedy / constructive only ---
⏱ 60 seconds actively trying to BREAK my own solution by hand at n = 1, 2, 3.
   Not reviewing it. Attacking it.
```

**"Actually tested" now means cases you invented, every time:**
`N=1` · `N=2` · all equal · all negative · already sorted · reverse sorted · ties everywhere · **every value at the stated maximum**.

### Upsolve rule
After a contest, upsolve **exactly the easiest problem you didn't get** — implemented from scratch, stress-tested. Then back to the queue. **Do not upsolve a whole contest**; that is mathematically your entire week.

---

## 8. Anti-WA machinery

### 8.1 The free steps you are currently skipping

At **3.36 submissions per AC**, you are resubmitting where rng_58's first four steps are **free and unused**:

1. **Re-read your own code**, line by line, as if someone else wrote it.
2. **Hand-test on a case you invented** (not the sample).
3. **Verify the ALGORITHM is correct** — separately from whether the code implements it.
4. **Re-read the statement.**

Zero tooling, zero setup, and they come **before** the rig, not after it. A misread statement is invisible to every tool in this section.

### 8.2 Your build lines — fix these today

**Do NOT use `-fsanitize=address` or `-fsanitize=undefined`.** Verified on *your* machine (MSYS2 mingw64, g++ 15.2.0): `ld.exe: cannot find -lasan` / `cannot find -lubsan`. libsanitizer is not ported to mingw-w64, and the USACO Guide says so too. If you paste an internet tutorial's flags and get a linker error — **that is the toolchain, not you.** It also means a large fraction of generic online debugging advice simply does not apply to your setup.

```bash
# NORMAL build — use by default, and before submitting
g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -Wconversion f.cpp -o f.exe

# DEBUG build — use while developing anything you're unsure about
g++ -std=c++17 -O0 -Wall -Wextra -Wshadow \
    -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -ftrapv f.cpp -o f_dbg.exe
```

What each flag actually bought, **verified on your box**:

- **`-D_GLIBCXX_DEBUG`** turns a raw `0xC0000374` heap-corruption crash (which teaches you nothing) into:
  `attempt to subscript container with out-of-bounds index 5, but container only holds 3 elements` — your off-by-one species, **named**.
  It also catches an invalid sort comparator: `comparison doesn't meet irreflexive requirements, assert(!(a < a))` — i.e. **exactly the multi-key comparator work you did this week**, for free.
  ⚠️ **Never submit with this on** — real constant-factor cost. And it does **not** catch integer overflow (verified: printed garbage, exit 0).
- **`-ftrapv`** *may* abort on signed overflow. Evidence across runs conflicts — at `-O2` the overflow can get constant-folded and silently wrap. **So keep it on the `-O0` debug line only**, and **test it once yourself**: a 5-line program that reads `n` from `cin` and prints `n*n`, run with `n = 1000000000`. Treat *"it aborted"* as a strong signal and *"it didn't"* as weak evidence — it only instruments signed `+ - *`, and it aborts with a bare exit code and no message.
- **Remote fallback** for UB the local flags miss: **Codeforces → Custom Invocation → whatever `Clang++NN Diagnostics` entry currently exists** in the dropdown (the version number tracks their current Clang; the old "Clang++17 Diagnostics" name is dead). That's a real ASan/UBSan build. Second-line only — the round trip costs minutes you don't have.

### 8.3 The stress harness — one file, no shell

With no working sanitizers, **the stress loop is your only mechanical bug-catcher.** And it's nearly free for you, because **you already write the brute force**. Stop deleting it. **The brute force is the oracle.** One artifact trains both of your diagnosed weaknesses at once.

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ---------- 1. YOUR REAL SOLUTION ----------
namespace Fast {
    ll solve(int n, vector<ll> a) {
        // paste your submission's logic here (take args, don't read cin)
        return 0;
    }
}

// ---------- 2. THE BRUTE FORCE (the oracle) ----------
namespace Brute {
    ll solve(int n, vector<ll> a) {
        // the obviously-correct O(n^2) or O(2^n) version. Slow is fine.
        return 0;
    }
}

// ---------- 3. THE GENERATOR — TWO MODES, BOTH REQUIRED ----------
mt19937 rng(12345);                       // fixed seed => reproducible failures
ll R(ll lo, ll hi) { return uniform_int_distribution<ll>(lo, hi)(rng); }

void gen(int mode, int &n, vector<ll> &a) {
    n = (int)R(1, 6);                     // tiny: n=1 and n=2 come up constantly
    a.assign(n, 0);
    if (mode == 0) {                      // MODE 0 — logic, off-by-one, TIES
        for (auto &x : a) x = R(-3, 3);   // duplicates and negatives ON PURPOSE
    } else {                              // MODE 1 — OVERFLOW ONLY
        for (auto &x : a) x = R(900000000LL, 1000000000LL);
    }
}

int main() {
    for (int iter = 1; iter <= 200000; iter++) {
        int mode = iter % 2;              // alternate the two modes
        int n; vector<ll> a;
        gen(mode, n, a);
        ll f = Fast::solve(n, a), b = Brute::solve(n, a);
        if (f != b) {
            printf("MISMATCH  iter=%d  mode=%d\nn = %d\na =", iter, mode, n);
            for (ll x : a) printf(" %lld", x);
            printf("\nfast = %lld   brute = %lld\n", f, b);
            return 0;
        }
    }
    puts("OK - 200000 random tests passed");
}
```

**The four rules that decide whether this actually works:**

1. **Two modes is mandatory.** Tiny values (`-3..3`) find logic errors, off-by-ones, and force the **ties** your comparator bug needs. They can **never** reproduce integer overflow — your #1 species. Overflow needs values near **10⁹** with `n` still tiny so the brute force stays fast.
2. **Duplicates allowed on purpose.** Errichto's published `gen.cpp` forces values to be **distinct** via a `set<int>`. Copy it verbatim and it will generate the one shape your comparator bug can never appear in. **Delete the set.**
3. **`n` stays ≤ 6-8** so you can hand-trace the failing case. A 200-element counterexample teaches nothing.
4. **Seed from a constant, never `time()`.** A time seed gives you the same test repeatedly within a second, and you can't reproduce a failure.

**Poor-man's UBSan:** compile the *same* file twice, once with the accumulator as `int` and once as `long long`, and diff. Overflow shows up as a mismatch on a 3-element test.

**The trigger that makes this a habit instead of a project you build once and abandon:**
> *Any greedy, any constructive, or **any solution I cannot say out loud why it's correct**, gets stress-tested before the first submit.*

**Two honest limits — know these now so the first failure doesn't sour you on the technique:**
- **It cannot catch a misread statement.** If your brute force encodes the same misunderstanding, both programs agree and both are wrong. That's why "re-read the statement" is a checklist item and sits *before* stress testing in rng_58's protocol.
- **It needs a unique correct answer.** Many CF 1000-1300 constructive problems accept *any* valid answer, and plain comparison reports false failures. **Do your first several stress sessions on single-answer problems** so the tool earns your trust. When you eventually need a checker, it's ~10 lines: recompute the objective from your own output and compare *that number* to brute's.

### 8.4 `assert()` as a weapon

When you get a WA you can't explain, assert the invariant you *think* holds and resubmit. **An RE tells you which assumption broke; a WA tells you nothing.** For your specific bug log:

```cpp
assert(!a.empty());                   // before ANY max/min scan  -> your init bug
assert(0 <= i && i < n);              // your off-by-one species
assert(total <= 2000000000LL);        // your overflow species
```

Costs one submission. Worth it. (Not on interactive problems.)

### 8.5 The C++ traps that survive "I learned about overflow"

These were all verified by actually running them — the outputs below are real:

```cpp
int a = 1000000000, b = 1000000000;
long long bad  = a * b;                 // WRONG: int*int overflows BEFORE the assign
long long good = (long long)a * b;      // RIGHT: 1000000000000000000

accumulate(v.begin(), v.end(), 0);      // WRONG: returns int -> printed -1294967296
accumulate(v.begin(), v.end(), 0LL);    // RIGHT: printed 3000000000

v.size() - 1                            // WRONG on empty v -> 18446744073709551615
(int)v.size() - 1                       // RIGHT -> -1

ms.erase(5);                            // erases ALL copies of 5
ms.erase(ms.find(5));                   // erases ONE
```

**Trace `1000000000 * 1000000000` on paper once.** Once is enough.

**Do NOT adopt blanket `#define int long long`.** It *hides* the cast bug rather than teaching it, and you'll carry the misunderstanding into a problem where it matters.

### 8.6 The two beliefs to delete

**"long long is slow."** Not false — but irrelevant to you, and here's the *correct* mechanism so you're not blindsided later: **64-bit arithmetic is the same speed as 32-bit on x86-64.** The real cost is memory bandwidth and cache pressure (a 10⁷-element `long long` array is 80MB vs 40MB, so it misses cache twice as often) plus narrower SIMD width. That only bites in tight vectorizable loops at 10⁷-10⁸ scale. **You have 3 TLEs and 96 WAs.** You are paying nothing for speed and everything for overflow. The Guide's own line for lower divisions: *"it might be a good idea to use 64-bit integers in place of 32-bit integers everywhere."* USACO gives C++ **2 seconds**.
> **Rule:** `long long` for anything summed, multiplied, accumulated, or used as binary-search bounds. `int` for indices and loop counters.

**"The statement won't actually give max constraints."** It's a mechanism, not an opinion. From CSES's own rules page: *"After solving a problem, you can view the solutions by other users and try to hack them by giving a test case where the solution fails. Then, the new test case can be added to the test data and all submissions will be regraded."* Codeforces has the same. USACO uses **10-30 hidden tests per problem, equally weighted, samples excluded**, and max-constraint cases are always among them. **The tests get more adversarial over time, not less.**

### 8.7 ⚠️ Fix `CLAUDE.md` today

Your repo's `CLAUDE.md` says: *"USACO problems use file IO: `ifstream fin("problem.in")`."*
**That has been wrong since December 2020.** Official USACO instructions: *"as of the December 2020 contest, input and output switched from file-based to terminal-based, using standard input and standard output."*

Writing `fin`/`fout` in a 2026 contest scores **0**. Only **pre-December-2020 archive problems** need file I/O — so what you need is the **date rule**, not either blanket statement. Edit that line before your next USACO session.

---

## 9. Honest timeline and the plateaus

**The arithmetic, so you can check it yourself:** 4 hours/week ÷ ~35 minutes per *properly done* problem ≈ 6/week if nothing goes wrong, **realistically 3** once the ritual, stress testing and re-implementation are included. That's ~150 problems/year. A Silver module is 5-8 problems, so **one module every 2-3 weeks**, and the full Silver toolkit is **4-6 months of module work alone.**

| Milestone | Realistic | How you'll know |
|---|---|---|
| Machinery live | week 1 | rig catches a planted off-by-one *and* a planted overflow |
| Sprint done, S/AC under 2.0 | ~week 4 | rolling over last 15 solves |
| Prefix sums + binary search installed | ~week 10 | ≥6 of 10 unseen statements correctly triaged |
| DFS/BFS from a blank file in <5 min | ~week 18 | do it twice, timed |
| Full toolkit (blocks 1-5) | **~5-6 months** | ~48 queue problems, six tag counters ≥8 |
| **≥700/1000 on a timed past Bronze contest** | **~month 5-7** | self-graded on official test data |
| **CF 1200 / Silver-level** | **a year-plus at 4h/week.** | Anyone doing it in 4-5 months is practising 15-25h/week. |

For calibration: a Carnegie Mellon analysis of Codeforces data estimated on the order of **800 hours per 200 rating points** for experienced competitors. That number is too pessimistic for *your* band — you're repaying obvious technique debt, which is far cheaper than grinding marginal skill at 1600 — and its own authors call individual estimates *"very noisy."* Use it for order of magnitude, not as a plan.

### The Bronze arithmetic you must internalise

Each Bronze problem is worth **333.33 points**. **Two full solves = 667.** All three 2026 Bronze contests used a **700** cutoff (the cutoff is announced **per contest**, historically 600-850, typically 750 — it is not a standing rule). So:

> **Two clean solves does not promote you.** You need two solves **plus partial credit on the third** — which means a WA on an easy problem isn't a small loss, it is the entire promotion margin.

The corollary works in your favour: because scoring is **per hidden test**, **writing the slow brute force banks real points.** Your brute-force instinct is an *asset* here, not a habit to suppress.

**Readiness test (Benq's, two-part):** familiar with every USACO Guide Bronze module, **and** able to score past the cutoff on recent Bronze contests. Run a **timed 4-hour mock — monthly at most**, because it consumes your entire weekly budget. Recent sets: *Chip Exchange / COW Splits / Photoshoot* · *It's Mooin' Time IV / Moo Hunt / Purchasing Milk* · *Make All Distinct / Strange Function / Swap to Win*.

**Contest tactic:** in **USACO**, read all three problems before coding — **they are not ordered by difficulty.** This does **NOT** transfer to Codeforces, where problems *are* sorted by difficulty and in a Div. 3/4 virtual A really is the easiest.

**Season timing:** the 2025-26 season concluded (Jan 9-12, Jan 30-Feb 2, Feb 20-23, US Open Mar 28). The 2026-27 schedule isn't posted; plan for roughly **Dec 2026 - Jan 2027**. That's ~5 months of runway — almost exactly the length of the toolkit build. **Bronze promotion is the target. Silver in the same season is not** — the Bronze→Silver gap is the steepest between any two divisions.

### Plateaus to expect, in order — none of these mean the plan is failing

| When | What happens | What it means |
|---|---|---|
| **Weeks 1-3** | Submissions-per-AC drops but **rating does not move**, and problems feel *slower* because of the ritual | Correct and intended. You are trading speed for accuracy on purpose. Judge by M1, not rating. |
| **Weeks 4-7** | Moving to CF 1000-1200, your **WA rate rises again** | Predicted. New techniques bring new bug surfaces. If S/AC goes above 2.5, pause topics for one week of pure sprint discipline. |
| **Weeks 8-16** | **The graph wall.** Your first adjacency list will feel genuinely alien after 56 problems of arrays and strings. ~3-4 problems of real confusion. | Then it clicks and stays clicked forever. This is the highest-value week in the plan. Do not shortcut to the next block. |
| **Months 3-6** | Rating flat while **tag counters climb** | The correct signal. Six tags going 0 → 8-10 each is unfakeable progress that rating lags by months. |
| **~Month 6** | A false ceiling around 1050-1150 | Usual cause: the practice band drifted back down. Check UNAIDED — above 50%, move up immediately. |
| **Any time** | One contest goes badly | One contest is not a measurement. Track S/AC, tag coverage, UNAIDED. Nothing else. |

---

## 10. Do NOT do these — traps specific to you

**Practice**
1. **Do not grind 800s as your main diet.** 46 solves at 800 is a *completed tier* (xinyster's own target is 40-50 per tier, and he explicitly says don't exceed 50). Keep 800s only as **timed stopwatch drills** with a target time — never on the learning counter.
2. **Do not set the band with a formula.** The two popular rules (`X+200` and `X-200..X+200`) **contradict each other** — for you they'd give 1036 and 636 respectively. Use the self-correcting test instead: **the right band is where you solve 30-40% unaided** (SuperJ6). Start at 1000-1100.
3. **Do not read a CF rating as ground truth for difficulty.** Ratings are crowd-sourced from standings — a 900 can need one clean insight while an 800 is tedious implementation with no idea in it. Your 38 implementation-tagged solves say you've been sampling the low-insight end.
4. **Do not practise only from topic-labelled lists.** They delete the hardest step — deciding *which* technique applies — which is precisely your weakest skill. Labelled module → then **unlabelled** rating-filtered problems, in that order, every block.

**Topics**
5. **Do not learn two pointers first** just because it's the name you reached for. It is *Not Frequent* in Silver; **graph traversal is the only Very Frequent module** and you have zero solves. Graphs are the blocker.
6. **Do not touch DP, DSU, Dijkstra, MST, segment trees or LCA yet.** All Gold, all CF 1500-2200. DSU especially: nearly every Silver-level DSU problem (*Wormhole Sort*, *Moocast*) is solvable with the DFS/BFS you're about to learn.
7. **Do not skip the "Custom Comparators **and Coordinate Compression**" module** because you did comparators. Compression is a separate idea you have not touched.
8. **Do not ever accept a technique NAME without its trigger sentence and one traced counterexample where it fails.** That is literally your documented failure mode.

**Process**
9. **Do not adopt "never read editorials, come back in a month."** That protocol is written for people doing 15+ problems/week chasing red. At 3/week, one month-long stall is a meaningful slice of your season. Use **15-20 min / 30-40 min *of no meaningful progress*** — and that qualifier is not a wall-clock permission slip to stop thinking.
10. **Do not bolt a 12-item WA checklist onto the 4-item habit you built days ago.** Long checklists get skipped. Seven items and the 60-second break-attempt. That's the ceiling.
11. **Do not treat "the sample passed" as testing.** Ever again. That sentence is the source of most of your 96.
12. **Do not upsolve a whole contest,** and do not run a 4-hour USACO mock weekly. **Monthly at most.**
13. **Do not schedule a rated contest every week** — one round plus a proper upsolve is your whole budget. But **do not cut contests to zero either**: hidden tests you can't see, on problems you didn't pre-select, are the cheapest available signal for your exact failure mode.
14. **Do not let "I solved 2 of 3" feel like promotion.** 2 × 333.33 = **667 < 700**.

**Tooling & mechanics**
15. **Do not paste `-fsanitize=address,undefined`.** Verified to fail at link on your exact install. Use §8.2.
16. **Do not write `ifstream fin("problem.in")` for any USACO problem from Dec 2020 onward.** Fix `CLAUDE.md` first.
17. **Do not use `c2-ladders.com`** — the domain is DNS-dead. Skip ladder sites entirely; the CF tag+rating filter targets your actual holes.
18. **Do not over-engineer the harness.** No Python drivers, no CMake, no generator libraries, no shell scripts. One file, two namespaces. And never `diff -w` — `10 11` and `101 1` both reduce to `1011` and compare equal.
19. **Do not build an Anki deck, a four-category retrospective journal, or a debugging-framework repo, and do not learn a GUI debugger right now.** All budget leaks competing with the only thing that moves rating: finished problems. The zero-cost version of review is **re-reading `CHEATSHEET.md` at the start of each session**.
20. **Do not collect resources.** You have room for **one primary + one supplement.** Primary: **CF EDU course 2, binary search**. Supplement: **kilobyte136's 70-problem sheet**, then CP-31 from the 1000 bucket. Everything else is a distraction wearing a productive costume.
21. **Do not read this queue as a schedule.** ~48 problems plus a 33-problem CSES section is a multi-month pull-queue. A missed date is worth less than nothing.

---

## 11. Do these three things this week

1. **(45 min)** Write `stress.cpp` from §8.3, save it as a template. Verify it by planting a deliberate off-by-one in `Fast::solve` and a deliberate `int` overflow, and confirm both modes catch their own bug. Put both build lines in a `build.ps1`.
2. **(15 min)** Write the 7-item checklist on an index card and put it next to the keyboard. Add the three new items to `PROGRESS.md`. Fix the file-IO line in `CLAUDE.md`. Add `pre[r+1]-pre[l]` to `CHEATSHEET.md` with its trigger sentence.
3. **(90 min)** First Session A of the **sprint**: two problems from the back half of kilobyte136's sheet, full ritual on both, both run through the debug build before submitting even though you'll be sure they're right. Record submissions-per-AC as your baseline.

---

> **The one-line version:** Fix the leak for three weeks, then fill the inventory in frequency order — prefix sums, binary search, and above all **graphs** — at CF 1000-1100, keeping the brute force as your oracle instead of deleting it. Measure submissions-per-AC, tag coverage, and unaided-solve-rate. Never rating.

---

## Sources

**USACO Guide**
- Silver syllabus & module frequency labels — https://usaco.guide/silver
- Bronze syllabus & module frequency labels — https://usaco.guide/bronze
- Prefix sums — https://usaco.guide/silver/prefix-sums
- Binary search (monotonicity precondition) — https://usaco.guide/silver/binary-search
- Two pointers (sorted-array precondition) — https://usaco.guide/silver/two-pointers
- Greedy with sorting (the exchange argument, quoted in §4) — https://usaco.guide/silver/greedy-sorting
- Graph traversal — https://usaco.guide/silver/graph-traversal
- Flood fill — https://usaco.guide/silver/flood-fill
- Additional Bronze practice (unlabelled) — https://usaco.guide/bronze/bronze-conclusion
- N → complexity table, 10⁸ ops/sec — https://usaco.guide/bronze/time-comp
- 64-bit integers in lower divisions — https://usaco.guide/general/data-types
- Stress testing (single-file two-namespace setup) — https://usaco.guide/general/basic-debugging
- Wrong-answer checklist — https://usaco.guide/general/debugging-checklist
- Compiler flags + "sanitizers don't work with MinGW" — https://usaco.guide/general/debugging-cpp
- Editorial timing (Darren Yao 15-20 / 30-40 min; "always implement it afterward") — https://usaco.guide/general/practicing
- CF-rating ↔ division mapping — https://usaco.guide/general/usaco-faq
- Standard I/O since Dec 2020 — https://usaco.guide/general/io
- Gold modules, for later — https://usaco.guide/gold/dsu · https://usaco.guide/gold/intro-dp

**Official USACO**
- Rules, per-test scoring, 2s C++ limit, stdin/stdout since Dec 2020 — https://usaco.org/index.php?page=instructions
- Contest schedule — https://usaco.org/index.php?page=contests
- 2026 results pages (700 cutoffs, problem names) — https://usaco.org/index.php?page=season26contest1results · `...contest2results` · `...contest3results`
- Benq's two-part readiness criterion — https://forum.usaco.guide/t/bronze-to-silver-what-problems-to-practice/6086

**Codeforces / practice methodology**
- CF EDU, ITMO Academy (binary search, graded) — https://codeforces.com/edu/course/2
- SuperJ6 — 30-40% unaided band, 15-min rule, 90-min sessions, upsolve-easiest-only — https://codeforces.com/blog/entry/116371
- xinyster — the "too many 800s" trap, 40-50 problems per tier — https://codeforces.com/blog/entry/107174
- kilobyte136 — 70 problems 800-1000 ordered by *learning* difficulty — https://codeforces.com/blog/entry/152911
- CP-31 sheet (start at the 1000 bucket) — https://www.tle-eliminators.com/cp-sheet
- YouKn0wWho — Common Mistakes in CP (the `(long long)` cast, INF too small, `v.size()`) — https://codeforces.com/blog/entry/111217
- rng_58 — the 8-step wrong-answer protocol — https://codeforces.com/blog/entry/21066
- Errichto — stress testing (seed from argv, not the clock) — https://codeforces.com/blog/entry/71558 · https://github.com/Errichto/youtube/tree/master/testing
- Debugging with sanitizers (current) — https://codeforces.com/blog/entry/149527
- Um_nik — solve vs. solve-fast; the month-long abandon rule (adopt that half only) — https://codeforces.com/blog/entry/98806
- MikeMirzayanov — 8 idea-finding techniques ("Print Out and Look" bridges brute force → pattern) — https://codeforces.com/blog/entry/20548

**CSES**
- Problem set (Introductory, then Sorting & Searching — 33 problems, use the stop-list) — https://cses.fi/problemset/
- Hacking & regrading rule — https://cses.fi/problemset/text/2433
- Community editorials for Sorting & Searching — https://codeforces.com/blog/entry/83295

**Other**
- AtCoder contests (ABC **C and D**, occasional substitute) — https://atcoder.jp/contests/
- Educational DP Contest, for the eventual DP phase only — https://atcoder.jp/contests/dp
- Darren Yao, *An Introduction to the USA Computing Olympiad* — https://darrenyao.com/usacobook/cpp.pdf
- VPlanet — common USACO mistakes (vendor blog; corroboration, not authority) — https://www.vplanetcoding.com/blog/usaco-common-mistakes
- Carnegie Mellon, *Competitive Programming: Talent vs Tenacity* (order-of-magnitude only; authors call individual estimates "very noisy") — https://carnegiemellon.shorthandstories.com/competitive-programming-talent-vs-tenacity/index.html
