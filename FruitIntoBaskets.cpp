// Problem Description
/*
    In a row of trees, the i-th tree produces fruit with type tree[i].

    You start at any tree of your choice, then repeatedly perform the following steps:

    Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
    Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
    Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

    You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

    What is the total amount of fruit you can collect with this procedure?

 * 
 */


// this is essentially the same problem as 
// 149. Longest Substring with At Most Two Distinct Characters
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0, left = 0, n = tree.size();
        unordered_map<int,int> fruitcnt;
        for ( int i = 0; i < n; i++ ) {
            fruitcnt[tree[i]]++;
            while ( fruitcnt.size() > 2 ) {
                if ( --fruitcnt[tree[left]] == 0 )
                    fruitcnt.erase(tree[left]);
                left++;
            }
            res = max(res,i-left+1);
        }
        
        return res;
    }
};

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int left = 0, right = -1, res = 0, n = tree.size();
        for ( int i = 1; i < n; i++ ) {
            if ( tree[i] == tree[i-1] )
                continue;
            if ( right >= 0 && tree[right] != tree[i] ) {
                res = max(res, i - left );
                left = right + 1;
            }
            right = i - 1;
        }
        
        return max(n-left,res);
    }
};

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0, cur = 0, fruitA = 0, fruitB = 0, cntB = 0;
        for ( int fruit : tree ) {
            cur = ( fruit == fruitA || fruit == fruitB ) ? cur + 1 : cntB + 1;
            cntB = ( fruit == fruitB ) ? cntB + 1 : 1; 
            if ( fruit != fruitB ) {
                fruitA = fruitB;
                fruitB = fruit;
            }
            res = max( res, cur );
        }
        
        return res;
    }
};