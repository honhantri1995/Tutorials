# Problem
Given a graph with `V` vertices numbered from `0` to `V-1` and a list of edges, determine whether the graph is bipartite or not.
A bipartite graph is a graph whose vertices can be split into two distinct sets such that:
- Every edge connects a vertex in one set to a vertex in the other.
- No edge connects vertices within the same set.

## Examples
``` python
Input: V = 4, edges[][]= [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: false
Explanation: 'The graph is not bipartite because no matter how we try to color the nodes using two colors, there exists a cycle of odd length (like 1–2–0–1), which leads to a situation where two adjacent nodes end up with the same color. This violates the bipartite condition, which requires that no two connected nodes share the same color.'
Check input1.png
```

``` python
Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 3]] 
Output: true
Explanation: 'The given graph can be colored in two colors so, it is a bipartite graph. Check input2.png'
```

# Solution
Graph representation used: **adjacency list**.
So we have to convert the inputed **edge set** to **adjacency list**:
```cpp
vector<vector<int>> adj(V);
for (auto& edge : edges) {
	adj[edge[0]].push_back(edge[1]);
	adj[edge[1]].push_back(edge[0]);
}
```

You color the graph using two colors so that no connected nodes share a color.
Steps:
1. Start at any node and assign it a color (say, color 0).
2. For each neighbor, assign the opposite color (color 1).
3. Keep repeating this for all nodes using BFS or DFS.
4. If you ever reach a neighbor that already has the same color as the current node, the graph is not bipartite.
