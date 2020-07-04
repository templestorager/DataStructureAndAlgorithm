// Problem Description
/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/
#include <iostream>
#include <vector>
using namespace std;
#if 0
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int> > q;
        q.push({sr,sc});
        int oldcol = image[sr][sc];
        image[sr][sc] = newColor;
        int nr = image.size();
        int nc = image[0].size();
        bool visited[nr][nc];
        memset( visited, 0, sizeof(visited) );
        visited[sr][sc] = 1;
        while ( !q.empty() )
        {
            auto pos = q.front();
            q.pop();
            int r = pos.first;
            int c = pos.second;
            if ( r - 1 >= 0 && image[r-1][c] == oldcol && !visited[r-1][c] )
            {
                image[r-1][c] = newColor;
                visited[r-1][c] = 1;
                q.push({r-1,c});
            }
            if ( r + 1 < nr && image[r+1][c] == oldcol && !visited[r+1][c] )
            {
                image[r+1][c] = newColor;
                visited[r+1][c] = 1;
                q.push({r+1,c});
            }
            if ( c - 1 >= 0 && image[r][c-1] == oldcol && !visited[r][c-1] )
            {
                image[r][c-1] = newColor;
                visited[r][c-1] = 1;
                q.push({r,c-1});
            }
            if ( c + 1 < nc && image[r][c+1] == oldcol && !visited[r][c+1] )
            {
                image[r][c+1] = newColor;
                visited[r][c+1] = 1;
                q.push({r,c+1});
            }
        }
        
        return image;
    }
};
#endif 

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int nr = image.size();
        int nc = image[0].size();
        vector<vector<bool> > visited(nr,vector<bool>(nc,false));
        dfs(image,sr,sc,newColor,visited);
        return image;
    }
    
    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, vector<vector<bool>> &visited )
    {
        int oldcol = image[sr][sc];
        int nr = image.size();
        int nc = image[0].size();
        
        image[sr][sc] = newColor;
        visited[sr][sc] = true;
        if ( sr + 1 < nr && image[sr+1][sc] == oldcol && !visited[sr+1][sc] )
            dfs(image,sr+1,sc,newColor,visited);
        if ( sr -1 >= 0 && image[sr-1][sc] == oldcol && !visited[sr-1][sc] )
            dfs(image,sr-1,sc,newColor,visited);
        if ( sc + 1 < nc && image[sr][sc+1] == oldcol && !visited[sr][sc+1] )
            dfs(image,sr,sc+1,newColor,visited);
        if ( sc - 1 >= 0 && image[sr][sc-1] == oldcol && !visited[sr][sc-1] )
            dfs(image,sr,sc-1,newColor,visited);
    }
};

int main()
{
    Solution s;
    vector<vector<int> > image = {{1,1,1},{1,1,0},{1,0,1}};
    s.floodFill(image,1,1,2);
    return 0;
}