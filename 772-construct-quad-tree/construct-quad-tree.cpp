/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* build(vector<vector<int>>& grid, int i, int j, int sz){
        bool same=true;
        int val=grid[i][j];
        for(int r=i;r<i+sz;r++){
             for(int c=j;c<j+sz;c++){
                if(grid[r][c]!=val){
                    same=false;
                    break;
                }
            
        }
        if(!same)
        break;
        }

        if(same)
          return new Node(val, true);
        int half=sz/2;
        Node* tl=build(grid,i,j,half);
        Node* tr=build(grid,i,j+half,half);
        Node* bl=build(grid,i+half,j,half);
        Node* br=build(grid,i+half,j+half,half);
        return new Node(1, false, tl,tr,bl,br);
    }
    Node* construct(vector<vector<int>>& grid) {
        return build(grid,0,0,grid.size());
    }
};