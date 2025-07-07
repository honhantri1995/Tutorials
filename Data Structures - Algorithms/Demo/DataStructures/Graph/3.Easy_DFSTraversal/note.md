# Problem
Given a undirected graph represented by an adjacency list `adj`, where each `adj[i]` represents the list of vertices connected to vertex `i`.
Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right according to the adjacency list, and return a list containing the DFS traversal of the graph.

Input: adj[][] = [[1,2], [0,2,3], [0,1,4], [1,4], [2,3]]    (image graph1.png)
Output: [0, 1, 2, 4, 3]

Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]   (image graph2.png)
Output: [0, 1, 2, 3, 4]

Not that there can be more than one DFS Traversals of a Graph. For example, after 1, we may pick adjacent 2 instead of 0 and get a different DFS. Here we pick in the insertion order.

# Solution
The algorithm works as follows:
1. Put the source vertex (starting vertex) at the top of a stack. It can be any vertex based on your choice.
2. Iterate the stack:
	2.1. Take the top item of the stack. If it has not visited yet, add it to the Visited List.
	2.2. Then save this top item to the traversal result list.
	2.3. Then find all of that vertex's adjacent nodes. And add those aren't in the visited list to the top of the stack.
   Repeat until the stack is empty.
Note: The graph might have two different disconnected parts, so to make sure that we cover every vertex, we can also run DFS on every node.

## Analysis

## Snippet
Similar to BDF, except that you will use stack instead of queue