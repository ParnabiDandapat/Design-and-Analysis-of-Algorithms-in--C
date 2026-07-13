# Travelling Salesman Problem (TSP) using Dynamic Programming (Bitmasking)

## 📌 Overview

This project implements the **Travelling Salesman Problem (TSP)** using **Dynamic Programming with Bitmasking (Memoization)** in C.

The program finds the **minimum cost tour** that:

* Starts from city **0**
* Visits every city exactly once
* Returns to the starting city

This approach is much faster than the brute-force solution because it stores previously computed results and avoids repeated calculations.

---

## 🎯 Problem Statement

Given `n` cities and the distance between every pair of cities, find the minimum travelling cost such that:

1. Start from city **0**.
2. Visit every city exactly once.
3. Return to the starting city.
4. Minimize the total travelling cost.

---

## 💡 Algorithm

1. Read the number of cities and the distance matrix.
2. Initialize the DP table with `-1`.
3. Start from city `0` with only city `0` marked as visited.
4. If all cities are visited, return the cost to reach the starting city.
5. Otherwise, try visiting every unvisited city.
6. Recursively calculate the travelling cost.
7. Store the minimum cost in the DP table (memoization).
8. Return the minimum travelling cost.

---

## 🧠 DP State

```text
dp[mask][pos]
```

* **mask** → Represents the set of visited cities.
* **pos** → Current city.
* **dp[mask][pos]** → Minimum cost to complete the tour from the current state.

---

## 🔄 Bitmask Operations

### Check if a city is visited

```c
(mask & (1 << city))
```

### Mark a city as visited

```c
mask | (1 << city)
```

### Check if all cities are visited

```c
mask == (1 << n) - 1
```

---

## ▶️ Example Input

```text
Enter number of cities: 4

Distance Matrix

0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
```

## ✅ Output

```text
Minimum cost of TSP tour: 80
```

---

## ⏱️ Time Complexity

```text
O(n² × 2ⁿ)
```

---

## 💾 Space Complexity

```text
O(n × 2ⁿ)
```

---

## 📚 Concepts Used

* Dynamic Programming
* Bitmasking
* Recursion
* Memoization
* Graph Algorithms

---

## ⭐ Features

* Efficient DP solution using memoization.
* Easy-to-understand implementation.
* Works for symmetric distance matrices.
* Includes comments for better learning.
* Suitable for academic projects, practicals, and interview preparation.

---

## 🚀 Future Improvements

* Print the complete optimal tour path.
* Handle asymmetric distance matrices.
* Optimize memory usage.
* Improve scalability for larger numbers of cities.

---

## 👩‍💻 Language

* C

---

## 📄 License

This project is intended for educational and learning purposes.
