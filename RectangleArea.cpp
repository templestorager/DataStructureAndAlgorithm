// Problem Description
/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
*/

// We calulate the two areas and then check whether they overlap or not.
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C-A) * (D-B);
        int area2 = (H-F) * (G-E);
        
        if ( C <= E || B >= H || A >= G || D <= F )
            return area1 + area2;
        int overlapped = (min(C,G) - max(A,E)) * (min(D,H) - max(B,F));
        return area1-overlapped + area2;
    }
};