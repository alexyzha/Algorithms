# Algorithms
more advanced cp algorithms

**Jump To**
- [List](#list)
- [String/matching](#string-processing-and-matching-algorithms)
- [Advanced strings](#string-algorithms-beyond-basics)
- [Graphs](#graph-algorithms)
- [Advanced graphs](#advanced-graph-algorithms)
- [Number theory](#number-theory-and-algebra)
- [Advanced math](#mathematical-and-combinatorial-algorithms)
- [Game theory](#game-theory-and-non-deterministic-algorithms)
- [Data structures](#data-structures)
- [Advanced DS](#advanced-data-structures)
- [Geometry](#geometry)
- [Computational geometry](#geometry-and-computational-geometry)
- [DP optimizations](#dynamic-programming-optimizations)
- [Advanced DP](#advanced-dynamic-programming-techniques)
- [Misc](#miscellaneous)
- [Quantum algorithms](#quantum-algorithms-and-complexity-theory-more-theoretical-and-less-practical-in-standard-competitions-but-still-interesting)
- [Random](#randomized-algorithms)

## String Processing and Matching Algorithms:
- Knuth-Morris-Pratt (KMP) Algorithm: For string matching without backtracking.
- Z-Algorithm: Finds all occurrences of a pattern in a text in linear time using a Z-array.
- Rabin-Karp Algorithm: For string matching using hashing.
- Suffix Array and LCP (Longest Common Prefix): For various string processing problems, like finding the longest repeated substring.
- Aho-Corasick Algorithm: For matching multiple patterns simultaneously.

## String Algorithms Beyond Basics:
- Manacher’s Algorithm: For finding the longest palindromic substring in linear time.
- Suffix Automaton: For a variety of string processing tasks, including searching for different substrings.
- Suffix Tree: For quick pattern matching, substring, and subsequence operations.
- Burrows-Wheeler Transform: For text transformation useful in data compression.

## Graph Algorithms:
- Dijkstra’s Algorithm: For finding the shortest paths in a graph with non-negative edge weights.
- Bellman-Ford Algorithm: For shortest paths in a graph with negative edge weights.
- Floyd-Warshall Algorithm: For all pairs shortest paths.
- A\* Search Algorithm: For finding the shortest path in a graph with heuristics.
- Ford-Fulkerson and Edmonds-Karp Algorithm: For maximum flow in a flow network.
- Dinic's Algorithm: An efficient maximum flow algorithm.
- Tarjan’s Algorithm: For strongly connected components.
- Kruskal’s and Prim’s Algorithms: For minimum spanning tree.
- Topological Sorting: For sorting vertices of a graph.
- Bridges and Articulation Points: For finding critical connections and nodes in a graph.

## Advanced Graph Algorithms:
- Maximum Bipartite Matching: Algorithms like the Hopcroft–Karp algorithm for finding maximum matchings in bipartite graphs.
- Min-Cost Max-Flow: For finding the maximum flow with the minimum cost in a flow network.
- Hungarian Algorithm: For solving the assignment problem.
- 2-SAT: A specific application of Tarjan's algorithm for satisfiability in logic expressions with two variables per clause.

## Number Theory and Algebra:
- Euclidean Algorithm for GCD: For finding the greatest common divisor.
- Extended Euclidean Algorithm: Also finds coefficients of Bézout's identity.
- Sieve of Eratosthenes: For finding all prime numbers up to a certain limit.
- Segmented Sieve: For finding primes in a certain range.
- Miller-Rabin Primality Test: A probabilistic test for primality.
- Fermat’s Little Theorem: For calculating powers modulo p.
- Chinese Remainder Theorem: For solving systems of congruences.
- Modular Inverse: For finding the inverse modulo m.

## Mathematical and Combinatorial Algorithms:
- Berlekamp-Massey Algorithm: For finding the linear feedback shift register (LFSR) or the shortest linear recurrence for a given sequence.
- Pollard’s Rho Algorithm: For integer factorization.
- Lucas Theorem and Generalizations: For dealing with binomial coefficients modulo a prime.
- Fast Multiplication (Karatsuba, Toom-Cook): For faster multiplication techniques, especially useful for large integers.

## Game Theory and Non-Deterministic Algorithms:
- Minimax Algorithm and Alpha-Beta Pruning: For decision-making in game theory.
- Nim and Sprague-Grundy Theorem: For solving impartial combinatorial games.

## Data Structures:
- Segment Trees: For range queries and updates.
- Fenwick Tree (Binary Indexed Tree): For prefix sums and range updates.
- Sparse Table: For range minimum queries (RMQ) and others.
- Disjoint Set Union (Union-Find): For tracking a set of elements partitioned into disjoint subsets.
- Trie (Prefix Tree): For efficient retrieval of strings from a set.
- Heavy-Light Decomposition: For queries on tree paths and subtrees.
- Centroid Decomposition: For decomposing a tree into a set of centroid trees.

## Advanced Data Structures:
- Persistent Data Structures: For maintaining history of versions of data (e.g., persistent segment tree).
- Treap and Splay Trees: For combining heap and binary search tree properties, and for creating a self-adjusting tree, respectively.
- Link-Cut Trees: For dynamic tree problems where trees are manipulated and queried.
- Wavelet Trees: For queries on sequences in logarithmic time.

## Geometry:
- Convex Hull Algorithms (Graham’s Scan, Jarvis’s March): For finding the smallest convex polygon enclosing a set of points.
- Line Intersection and Polygon Operations: For geometric computations and intersections.

# Geometry and Computational Geometry:
- Sweep Line Algorithms: For solving geometric problems by sweeping a line across the plane.
- Rotating Calipers: For problems like finding the farthest pair of points.
- Voronoi Diagrams and Delaunay Triangulation: For partitioning space for nearest neighbor queries and mesh generation.

## Dynamic Programming Optimizations:
- Divide and Conquer Optimization: For optimizing certain types of DP problems.
- Knuth Optimization: For speeding up specific DP problems.
- Convex Hull Trick: For optimizing DP with lines and queries.

## Advanced Dynamic Programming Techniques:
- State Compression Dynamic Programming: For solving problems with exponential state spaces efficiently.
- Dynamic Programming on Trees: For problems defined on trees using rerooting techniques or subtree merging.
- Bitmask Dynamic Programming: For handling subsets of small sets efficiently.

## Miscellaneous:
- Fast Fourier Transform (FFT) and Polynomial Multiplication: For multiplying large numbers and polynomials efficiently.
- Mo's Algorithm: For answering queries in offline mode.
- Burnside’s Lemma / Polya Enumeration Theorem: For counting distinct configurations considering symmetries.

## Quantum Algorithms and Complexity Theory (more theoretical and less practical in standard competitions but still interesting):
- Quantum Computing Basics: Understanding the principles behind quantum algorithms.
- P vs. NP Problem: Exploring algorithmic complexity and classifying problems.

## Randomized Algorithms:
- Monte Carlo and Las Vegas Algorithms: For problems where deterministic algorithms are inefficient or unknown.
- Parallel Algorithms and Concurrent Programming: With the rise of multicore processors, understanding how to parallelize algorithms can be crucial for performance.

## List:
1. Euclidean Algorithm for GCD
2. Sieve of Eratosthenes
3. Binary Search
4. Depth-First Search (DFS) and Breadth-First Search (BFS)
5. Dynamic Programming
6. Knuth-Morris-Pratt (KMP) Algorithm
7. Z-Algorithm
8. Dijkstra’s Algorithm
9. Floyd-Warshall Algorithm
10. Bellman-Ford Algorithm
11. Segment Trees
12. Fenwick Tree (Binary Indexed Tree)
13. Trie (Prefix Tree)
14. Disjoint Set Union (Union-Find)
15. Prim’s and Kruskal’s Algorithms for Minimum Spanning Tree
16. Rabin-Karp Algorithm
17. A Search Algorithm*
18. Ford-Fulkerson and Edmonds-Karp Algorithm for Maximum Flow
19. Dinic's Algorithm
20. Tarjan’s Algorithm for Strongly Connected Components
21. Convex Hull Algorithms (Graham’s Scan, Jarvis’s March)
22. Divide and Conquer Optimization
23. Knuth Optimization
24. Convex Hull Trick
25. Segmented Sieve
26. Miller-Rabin Primality Test
27. Extended Euclidean Algorithm
28. Modular Inverse
29. Fast Fourier Transform (FFT) and Polynomial Multiplication
30. Chinese Remainder Theorem
31. Manacher’s Algorithm
32. Sparse Table
33. Suffix Array and LCP
34. Heavy-Light Decomposition
35. Centroid Decomposition
36. Persistent Data Structures
37. Treap and Splay Trees
38. Link-Cut Trees
39. Wavelet Trees
40. State Compression Dynamic Programming
41. Dynamic Programming on Trees
42. Bitmask Dynamic Programming
43. Aho-Corasick Algorithm
44. Suffix Automaton
45. Suffix Tree
46. Berlekamp-Massey Algorithm
47. Pollard’s Rho Algorithm
48. Lucas Theorem and Generalizations
49. Fast Multiplication (Karatsuba, Toom-Cook)
50. Mo's Algorithm
51. Sweep Line Algorithms
52. Rotating Calipers
53. Voronoi Diagrams and Delaunay Triangulation
54. Maximum Bipartite Matching and Hopcroft–Karp Algorithm
55. Min-Cost Max-Flow
56. Hungarian Algorithm
57. 2-SAT
58. Game Theory (Minimax Algorithm and Alpha-Beta Pruning)
59. Nim and Sprague-Grundy Theorem
60. Monte Carlo and Las Vegas Algorithms
61. Parallel Algorithms and Concurrent Programming
62. Quantum Algorithms and Complexity Theory (More theoretical)
