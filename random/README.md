## Key Concepts in Randomized Algorithms

**Monte Carlo Algorithms:**
- Algorithms that rely on repeated random sampling to obtain numerical results. They are often used when deterministic strategies are infeasible due to high complexity.

**Las Vegas Algorithms:**
- Unlike Monte Carlo algorithms, Las Vegas algorithms always produce the correct result or report failure. Randomness is used to reduce the expected runtime, but not at the cost of correctness.

**Randomized Quick Sort:**
- A variant of quick sort where the pivot is chosen randomly. This simple modification ensures that the expected runtime of quick sort is O(n log n), even on worst-case inputs.

**Randomized Data Structures:**
- Data structures like skip lists and treaps that use randomness to maintain balance with high probability, offering simpler alternatives to deterministic balancing methods.

## Problems and Resources

**Min-Cut Problem:**
- The Karger’s algorithm for finding the minimum cut of a graph uses randomization to simplify the problem, repeatedly contracting random edges until only two vertices remain.
- Resource for learning: Introduction to Algorithms by Cormen, Leiserson, Rivest, and Stein offers a comprehensive explanation of Karger's algorithm.

**Reservoir Sampling:**
- A family of algorithms for randomly choosing a sample of k items from a list or stream of n items, where n is either a very large or unknown number.
- LeetCode Problem: [Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/) demonstrates the application of reservoir sampling in a data structure.

**Estimating the Value of Pi:**
- A classic problem that can be approached with Monte Carlo methods by randomly placing points within a square and calculating the ratio of points that fall inside a quarter circle.
- Resource for practice: Many programming challenge websites and educational platforms feature this problem as an exercise in understanding Monte Carlo algorithms.

**Randomized Algorithms for Matrices:**
- Techniques for matrix multiplication, determining the rank of a matrix, or finding determinant with randomized strategies can significantly reduce complexity on average.
- Study Material: The book Randomized Algorithms by Rajeev Motwani and Prabhakar Raghavan covers several of these techniques in detail.
