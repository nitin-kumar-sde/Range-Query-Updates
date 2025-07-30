
# 🌲 Introduction to Segment Trees

A **Segment Tree** is a powerful data structure that allows efficient processing of:

**Range queries** (e.g., sum, min, max) over a subarray

**Point or range updates** in the array

Instead of recalculating values from scratch during each query, segment trees break the array into segments and store **precomputed results** in a **binary tree** format.


## ⚙️ Why Use Segment Trees?

For an array of size `n` 

| Operation               | Brute Force | Segment Tree |
|------------------------|-------------|---------------|
| Range Query (Sum/Min)  | O(n)        | O(log n)      |
| Point Update            | O(1)        | O(log n)      |
| Range Update (with Lazy)| O(n)        | O(log n)      |

When you have to **frequently update elements** and **query subarrays**, segment trees shine by reducing time complexity significantly.


## 🧠 How It Works?

Think of it as a **binary tree**
  - Each node represents a segment `[l, r]` of the array.
  - The root node represents the whole array.
  - Leaf nodes represent individual elements.
  - Internal nodes store the result (like sum or min) of their child segments.

>  **Build Time**: O(n)
>  **Query/Update Time**: O(log n)


---

# ⛵ Practise Problems
- [Range Minimum Query](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/range-minimum-query)
- [Help Ashu](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1)
- [KGSS - Maximum Sum](https://www.spoj.com/problems/KGSS)
- [GSS1 - Can you answer these queries I](https://www.spoj.com/problems/GSS1/)
- [2 vs 3](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/2-vs-3)
- [HORRIBLE - Horrible Queries](https://www.spoj.com/problems/HORRIBLE)
- [SEGSQRSS - Sum of Squares with Segment Tree](https://www.spoj.com/problems/SEGSQRSS/)
