// Problem Description 
/*
 * 
 * Given an m x n matrix of positive integers representing the height of each unit cell in a 2D 
 * elevation map, compute the volume of water it is able to trap after raining.
 * Note:
 * Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.
 * 
 */

// This idea is to check starting from the lowest height and then progress until all height have been checked. 
// To select the current lowest height, we naturally think of using priority queue. 
// Boundary heights are initially pushed into the priority queue. 
// The visited array indicates whether each cell is accessible to a previous checked lower height ( visited ) 
// lowest_height indicates the currently lowest height (poped from the priority queue) only below which 
// a cell may contain water. To abide by the fact that only a lower than current lowest height cell holds water,
// we need to update the current  lowest height if the visited cell is higher. 
// a priority queue entry stores the pair of height and encoded coordinates. 

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if ( heightMap.size() == 0 )
            return 0;
        int row = heightMap.size(), col = heightMap[0].size(), totalwater = 0, lowest_height = INT_MIN;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        vector<vector<int>> neighbor{{0,-1},{-1,0},{0,1},{1,0}};
        for ( int row_idx = 0; row_idx < row; row_idx++ ) {
            for ( int col_idx = 0; col_idx < col; col_idx++ ) {
                if  ( row_idx == 0 || row_idx == row - 1 || col_idx == 0 || col_idx == col - 1 ) {
                    pq.push({heightMap[row_idx][col_idx],row_idx * col  + col_idx});
                    visited[row_idx][col_idx] = true;
                }
            }
        }
        
        while ( !pq.empty() ) { 
            auto cell = pq.top(); 
            pq.pop();
            int cell_height = cell.first, cell_row = cell.second / col, cell_col = cell.second % col; 
            // we need to increase the currently checked height ( similar to sea level) if the new element 
            // has a higher height.
            lowest_height = max( lowest_height, cell_height );
            for ( int cell_neighbor = 0; cell_neighbor < neighbor.size(); cell_neighbor++ ) {
                int neighbor_row = cell_row + neighbor[cell_neighbor][0];
                int neighbor_col = cell_col + neighbor[cell_neighbor][1];
                if  ( neighbor_row < 0 || neighbor_row >= row || neighbor_col < 0 || neighbor_col >= col || visited[neighbor_row][neighbor_col] )
                    continue;
                visited[neighbor_row][neighbor_col] = true;
                if ( lowest_height > heightMap[neighbor_row][neighbor_col] )
                    totalwater += (lowest_height - heightMap[neighbor_row][neighbor_col]);
                pq.push({heightMap[neighbor_row][neighbor_col],neighbor_row * col + neighbor_col});
            }
        }
        
        return totalwater;
    }
};