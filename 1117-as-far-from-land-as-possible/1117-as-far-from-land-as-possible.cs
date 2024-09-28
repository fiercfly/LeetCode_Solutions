public class Solution {

public int MaxDistance(int[][] grid) {

int[,] distance = new int[grid.Length, grid[0].Length];

Queue<(int x, int y)> q = new Queue<(int x, int y)>();

int ans = 0;

for(int i = 0; i < grid.Length; i++) {

for(int j = 0; j < grid[0].Length; j++) {

if (grid[i][j] == 0) distance[i,j] = int.MaxValue;

else {

distance[i,j] = 0;

q.Enqueue((i,j));

}

}

}

if (q.Count == 0 || q.Count == grid.Length * grid[0].Length) return -1;

int[] rows = {-1, 0, 1, 0};

int[] cols = {0, 1, 0, -1};

ans = 0;

while (q.Count > 0) {

var curr = q.Dequeue();

int currI = curr.x;

int currJ = curr.y;

for (int i = 0; i < 4; i++) {

int neighborI = currI + rows[i];

int neighborJ = currJ + cols[i];

if (neighborI >= 0 && neighborI < grid.Length && neighborJ >= 0 && neighborJ < grid[0].Length ) {

if (distance[neighborI, neighborJ] > distance[currI, currJ] + 1) {
                        distance[neighborI, neighborJ]= distance[currI, currJ]+ 1;
                        ans= Math.Max(ans,distance[neighborI,neighborJ]);
                        q.Enqueue((neighborI,neighborJ));
                    }

}

}

}

return ans;

}

}