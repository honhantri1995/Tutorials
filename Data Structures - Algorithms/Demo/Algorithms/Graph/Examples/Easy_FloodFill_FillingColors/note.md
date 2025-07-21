# Problem
You are given a 2D grid `image[][]`, where each `image[i][j]` represents the color of a pixel in the image.
Also provided is a `coordinate(sr, sc)` representing the starting pixel (row and column) and a new color value `newColor`.

Your task is to perform a flood fill starting from the pixel `(sr, sc)`, changing its color and the color of all connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.

Example: 
``` python
Input: image = [		# check input1.png
	[1, 1, 1, 0],
	[0, 1, 1, 1],
	[1, 0, 1, 1]
],
sr = 1, sc = 2, newColor = 2

Output: [				# check output1.png
	[2, 2, 2, 0],
	[0, 2, 2, 2],
	[1, 0, 2, 2]
]
```

``` python
Input: image = [
	[0, 1, 0],
	[0, 1, 0]
],
sr = 0, sc = 1, newColor = 0

Output: [
	[0, 0, 0],
	[0, 0, 0]
]
```

# Solution
The idea is to use Breadth-First Search (BFS) to change all connected pixels with the original color to a new color.
For each pixel, it checks its adjacent pixels (horizontally and vertically), and if they match the original color, it changes their color and adds them to the queue for further exploration.
This process ensures that all connected pixels are filled with the new color.

Step-by-step implementation :
- Use a queue to keep track of pixels that need to be processed. Start by adding the starting pixel `(sr, sc)` to the queue.
- Start BFS traversl, while the queue is not empty, remove the front pixel, update its color to `newColor`, and check all four adjacent - pixels, if they're within bounds and match the original color, add them to the queue for further processing.
- Repeat until the queue is empty, continue the above process until all connected pixels with the original color have been visited and - updated.
- After the BFS traversal, return the updated image with the filled region.