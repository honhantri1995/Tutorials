# Problem
Given a undirected graph represented by an adjacency list `adj`, where each `adj[i]` represents the list of vertices connected to vertex `i`.
Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to right according to the adjacency list, and return a list containing the BFS traversal of the graph.

Input: adj[][] = [[1,2], [0,2,3], [0,1,4], [1,4], [2,3]]    (image graph1.png)
Output: [0, 1, 2, 3, 4]
Explanation:
	Starting from 0, the BFS traversal will follow these steps: 
	Visit 0 							→ Output: [0] 
	Visit 1 (first neighbor of 0) 		→ Output: [0, 1]
	Visit 2 (next neighbor of 0) 		→ Output: [0, 1, 2]
	Visit 3 (next neighbor of 1) 		→ Output: [0, 1, 2, 3]
	Visit 4 (neighbor of 2) 			→ Output: [0, 1, 2, 3, 4]

Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]   (image graph2.png)
Output: [0, 1, 2, 3, 4]
Explanation:
	Starting from 0, the BFS traversal proceeds as follows: 
	Visit 0 														→ Output: [0]
	Visit 1 (the first neighbor of 0) 								→ Output: [0, 1]
	Visit 2 (the next neighbor of 0) 								→ Output: [0, 1, 2]
	Visit 3 (the first neighbor of 2 that hasn't been visited yet) 	→ Output: [0, 1, 2, 3]
	Visit 4 (the next neighbor of 2) 								→ Output: [0, 1, 2, 3, 4]

# Solution
The algorithm works as follows:
1. Put the source vertex (starting vertex) at the back of a queue. It can be any vertex based on your choice.
2. Iterate the queue:
	2.1. Take the front item of the queue. If it has not visited yet, add it to the Visited List.
	2.2. Then save this front item to the traversal result list.
	2.3. Then find all of that vertex's adjacent nodes. And add those aren't in the visited list to the back of the queue.
    Repeat until the queue is empty.
Note: The graph might have two different disconnected parts, so to make sure that we cover every vertex, we can also run BFS on every node.

## Analysis
adj[][] = [[1,2], [0,2,3], [0,1,4], [1,4], [2,3]]

i = 0:
	adj[i] == 0:
		push i to queue: q=[0]
		add i to visited list: v=[0]
		adj[i] = [1,2]
			push adj[i] to queue: q[]=[1,2]

		qItem = q.front = 1
			add qItem to visited list: v=[0,1]
			pop qItem from queue: q[]=[2]
			adj[qItem] = [0, 2]
			push adj[qItem] to queue (ignore item already visited): q[]=[2]
		qItem = q.front = 2
			add qItem to visited list: v=[0,1,2]
			pop qItem from queue: q[]=[]
			adj[qItem] = [0, 1, 3, 4]
			push adj[qItem] to queue (ignore item already visited): q[]=[3,4]
		qItem = q.front = 3
			add qItem to visited list: v=[0,1,2,3]
			pop qItem from queue: q[]=[4]
			adj[qItem] = [1,4]
			push adj[qItem] to queue (ignore item already visited): q[]=[4]
		qItem = q.front = 4
			add qItem to visited list: v=[0,1,2,3,4]
			pop qItem from queue: q[]=[]
			end

## Snippet
queue<int> q=[]
vector<bool> visited v=[]
vector<int> result r=[]

Choose 0 as the first node
q=[0]
v=[0]
r=[]

loop q is not empty:
	add queue item to v
	mark note as visited
	pop queue item from queue
	loop all adjacent nodes of queue item:
		if node has not been visisted yet:
			push to queue q
