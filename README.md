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

  ### Update Operation 
   Adds a value to an index.

   ```
   void update(int idx, int val, int n) {
       for (; idx <= n; idx += (idx & -idx))
           BIT[idx] += val;
   }
   ```

  ### Query Operation
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

# 🧭 Coordinate Compression

**Coordinate Compression** is a technique to map large or arbitrary values into a smaller range like `[1, N]`, preserving their order.

## 🤔 Why Use It?

- BITs and Segment Trees require index-based access (`1..N`)
- If input values are large (e.g., `10^9`), directly indexing is impractical
- Compression reduces range while maintaining relative order


## 🛠️ How to Do It?

1. Store all unique values in a vector
2. Sort and remove duplicates
3. Map original values to their new compressed form

```
vector<int> arr = {100, 300, 1000};
vector<int> temp = arr;

sort(temp.begin(), temp.end());
temp.erase(unique(temp.begin(), temp.end()), temp.end());

unordered_map<int, int> compressed;
for (int i = 0; i < temp.size(); ++i) {
    compressed[temp[i]] = i + 1; // +1 for 1-based indexing
}

```

---

# 🔍 Online vs Offline Queries

When dealing with multiple queries on an array or dataset, the strategy for answering them efficiently can be broadly categorized into two types **Online Queries** and **Offline Queries**.



## 🟢 Online Queries

- Queries are answered **in the order they are given**.
- Cannot reorder or preprocess them globally.
- Used with **data structures** like Segment Tree, Binary Indexed Tree (Fenwick Tree), etc.
- Ideal when the **query order matters** or **real-time processing** is required.


## 🔴 Offline Queries

- All queries are **collected first**, then **sorted or grouped** to optimize processing.
- Allows **global preprocessing** or clever sorting 
- Better performance when query reordering is allowed.

## 📊 Comparison Table

| Feature                  | Online Queries                          | Offline Queries                          |
|--------------------------|------------------------------------------|-------------------------------------------|
| Processing Order         | As input is received                    | Can be reordered                          |
| Query Reordering         | ❌ Not Allowed                           | ✅ Allowed                                 |
| Preprocessing            | Limited                                 | Extensive, often required                 |
| Use of Advanced DS       | Common (BIT, Segment Tree, etc.)        | Common (Mo’s, Merge Sort Tree, etc.)      |
| Time Efficiency          | May be slower for large batch queries   | Often faster using global optimizations   |
| Real-time Friendly       | ✅ Yes                                   | ❌ No                                      |

---

# 🔮 Binary Lifting

Binary Lifting is a method to jump in powers of 2 (1, 2, 4, 8...) to efficiently find the first position that satisfies a condition.

Instead of checking every index, try jumping 2^k steps forward if it's still valid (i.e., doesn't break the condition).

> 🧠 This reduces the search from O(n) to O(log n).

## 🎲 Finding Lower Bound of array

```
int binary_lift_lower_bound(int n) {
    int pos = 0;
    for (int jump = 1 << 20; jump > 0; jump >>= 1) {
        if (pos + jump < n && f(pos + jump) == false) {
            pos += jump;
        }
    }
    return pos + 1; // first index where f(i) == true
}
```

## 🎨 Finding LCA of 2 nodes in a Tree

```
int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    // Bring u up to v's level
    for (int j = LOG - 1; j >= 0; --j) {
        if (depth[u] - (1 << j) >= depth[v])
            u = up[u][j];
    }

    if (u == v)
        return u;

    // Jump both up together
    for (int j = LOG - 1; j >= 0; --j) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0]; 
}
```
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
- [INCSEQ - Increasing Subsequences](https://www.spoj.com/problems/INCSEQ/)
- [Shil and Wave Seqeunce](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-wave-seqeuncemonk)
- [QTREE2 - Query on a tree II](https://www.spoj.com/problems/QTREE2/cstart=20)



