# 🌲 Segment Trees

A **Segment Tree** is a powerful data structure that enables efficient processing of

- ✅ **Range Queries** (e.g., sum, min, max) over a subarray.
- ✅ **Point Updates** (change a single element).
- ✅ **Range Updates** (update an entire range) using **Lazy Propagation**.

Instead of recalculating values from scratch during each query, segment trees break the array into segments and store **precomputed results** in a **binary tree** format.

---

## ⚙️ Why Use Segment Trees?

For an array of size `n`

| Operation                | Brute Force | Segment Tree |
|-------------------------|-------------|---------------|
| Range Query (Sum/Min)   | O(n)        | O(log n)      |
| Point Update            | O(1)        | O(log n)      |
| Range Update (with Lazy)| O(n)        | O(log n)      |

When you need to **frequently update** elements and **query subarrays**, segment trees significantly reduce time complexity.

---

## 🧠 How Does It Work?

A Segment Tree is a **binary tree** where

- Each node represents a segment `[l, r]` of the array.
- The **root node** represents the entire array.
- **Leaf nodes** represent individual elements.
- **Internal nodes** store results (sum/min/max) from their child segments.

## 🔨 Time Complexities
- **Build Time**: `O(n)`
- **Query Time**: `O(log n)`
- **Update Time**: `O(log n)`

---

# 💤 Lazy Propagation

Lazy Propagation is a **clever optimization** used when performing **range updates**.

## ⚡ Problem
Updating each element of a range takes `O(n)` time.

## ✅ Solution
- Instead of updating immediately, we **delay (or lazily propagate)** the updates until necessary.
- A **lazy array** is maintained alongside the segment tree.
- When a query/update affects a node, we first apply any **pending updates** (stored lazily), then proceed.

## 📈 Use Cases
- Range Increment/Decrement
- Range Assignments
- Range Flips (like in some XOR problems)

## 💡 Time Complexity (with Lazy)
- **Range Update**: `O(log n)`
- **Range Query**: `O(log n)`

---

# 🌿 Fenwick Tree (Binary Indexed Tree)

A **Fenwick Tree**, also known as a **Binary Indexed Tree (BIT)**, is a space-efficient data structure useful for

- ✅ Prefix sum queries in `O(log n)` time
- ✅ Point updates in `O(log n)` time

It is especially useful when

- You need to **update** elements frequently
- You need to **query prefix sums**
- You want a simpler and faster alternative to Segment Tree for cumulative queries


## 📦 Operations

  **Update Operation**  
   Adds a value to an index.

   ```
   void update(int idx, int val, int n) {
       for (; idx <= n; idx += (idx & -idx))
           BIT[idx] += val;
   }
   ```

  **Query Operation**
    Returns the prefix sum from index 1 to idx.
    
    ```
     int query(int idx) {
         int sum = 0;
         for (; idx > 0; idx -= (idx & -idx))
              sum += BIT[idx];
         return sum;
    }
    
     ```

  
## 🧠 BIT Indexing Insight
       
BIT uses the lowest set bit to jump efficiently
   
    ```
    idx += (idx & -idx) moves upward (used in updates)
    idx -= (idx & -idx) moves downward (used in queries)
    ```

> This enables both operations in O(log n) time.

---

# ⛵ Practice Problems

- [Range Minimum Query](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/range-minimum-query)
- [Help Ashu](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1)
- [KGSS - Maximum Sum](https://www.spoj.com/problems/KGSS)
- [GSS1 - Can You Answer These Queries I](https://www.spoj.com/problems/GSS1/) 
- [2 vs 3](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/2-vs-3) 
- [HORRIBLE - Horrible Queries](https://www.spoj.com/problems/HORRIBLE) 
- [SEGSQRSS - Sum of Squares with Segment Tree](https://www.spoj.com/problems/SEGSQRSS/)
- [RATING - Coder Ratings](https://www.spoj.com/problems/RATING)
- [DQUERY - D-query](https://www.spoj.com/problems/DQUERY)
- [ORDERSET - Order Statistic Set](https://www.spoj.com/problems/ORDERSET/en)



