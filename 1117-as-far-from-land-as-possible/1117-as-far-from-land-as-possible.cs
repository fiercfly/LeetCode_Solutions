public class Solution {
    public int MaxDistance(int[][] grid) {
        int n = grid.Length;
        int[,] distance = new int[n, n]; // To store distances
        Queue<(int, int)> q = new Queue<(int, int)>();
        
        // Initialize BFS queue and distance array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.Enqueue((i, j)); // All land cells
                    distance[i, j] = 0; // Distance is 0 for land cells
                } else {
                    distance[i, j] = int.MaxValue; // Initially set water cells to max distance
                }
            }
        }
        
        // If no water or no land exists
        if (q.Count == 0 || q.Count == n * n) return -1;
        
        // 4 possible directions for neighbors (up, down, left, right)
        int[] rows = {-1, 0, 1, 0};
        int[] cols = {0, 1, 0, -1};
        int maxDistance = 0;
        
        // BFS traversal
        while (q.Count > 0) {
            var (currI, currJ) = q.Dequeue();
            
            // Traverse all 4 directions
            for (int d = 0; d < 4; d++) {
                int neighborI = currI + rows[d];
                int neighborJ = currJ + cols[d];
                
                // Ensure the neighbor is within grid bounds
                if (neighborI >= 0 && neighborI < n && neighborJ >= 0 && neighborJ < n) {
                    // Only update if we find a shorter distance
                    if (distance[neighborI, neighborJ] > distance[currI, currJ] + 1) {
                        distance[neighborI, neighborJ] = distance[currI, currJ] + 1;
                        maxDistance = Math.Max(maxDistance, distance[neighborI, neighborJ]);
                        q.Enqueue((neighborI, neighborJ)); // Enqueue this water cell to process its neighbors
                    }
                }
            }
        }
        
        return maxDistance;
    }
}
