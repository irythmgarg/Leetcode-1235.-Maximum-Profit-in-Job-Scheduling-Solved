# Leetcode-1235.-Maximum-Profit-in-Job-Scheduling-Solved
# 📅 Weighted Job Scheduling - Max Profit

Welcome to the **Weighted Job Scheduling** problem! This project focuses on finding the **maximum profit** one can earn by scheduling non-overlapping jobs. Each job comes with a **start time**, **end time**, and **profit**. 🌟

---

## 🌐 Problem Statement

You're given three arrays:

* `startTime[]`
* `endTime[]`
* `profit[]`

Each index `i` represents a job:

* It starts at `startTime[i]`
* Ends at `endTime[i]`
* Gives a profit of `profit[i]`

**Goal:** Select a subset of non-overlapping jobs to maximize the total profit.

---

## ✨ Approach Overview

We solve this problem using **Dynamic Programming (DP)** with **Memoization** and **Greedy Sorting**:

### 🔄 Step-by-step Breakdown:

1. **Job Packaging**:

   * Combine the job info into a vector of pairs: `{startTime, {endTime, profit}}`

2. **Sorting**:

   * Sort jobs by their `startTime` to allow ordered traversal and binary search-like navigation.

3. **Recursive DP + Memoization**:

   * At each job index, we make a choice:

     * **Take** the job and find the next non-overlapping job
     * **Skip** the job and move to the next
   * Cache the result using a `dp[]` array to avoid recomputation ✅

4. **Finding Next Job**:

   * Implemented via a linear search, looking for the first job that starts after the current job ends.

---

## 🔢 Complexity Analysis

| Type             | Value                                        |
| ---------------- | -------------------------------------------- |
| Time Complexity  | O(n^2) (due to linear search for next index) |
| Space Complexity | O(n) (for memoization)                       |

> ⚠️ Optimization Tip: Use **binary search** instead of linear search for `getNextIndex()` to reduce time complexity to `O(n log n)`.

---

## 📊 Example

### Input:

```
startTime = [1, 2, 3, 4, 6]
endTime = [3, 5, 10, 6, 9]
profit = [20, 20, 100, 70, 60]
```

### Output:

```
150
```

### Explanation:

* Take job 1 (1 to 3, profit 20)
* Take job 4 (4 to 6, profit 70)
* Take job 5 (6 to 9, profit 60)
* Total profit = 20 + 70 + 60 = **150**

---

## 💡 Why This Approach?

* ✅ It explores both choices at every step.
* ✅ It uses memoization to avoid recalculating subproblems.
* ✅ Sorting helps maintain order and enables efficient lookup for the next job.

---

## 👤 Author

**Ridham Garg**
B.Tech Computer Engineering @ Thapar University, Patiala
Roll No: 102203014

---

## 📖 Reference

This problem is inspired by classic **weighted interval scheduling** and commonly appears in coding interviews and dynamic programming practice sets.

---

Thank you for visiting this project! 🙏
Feel free to leave feedback or suggest optimizations! 🛠️
