class Solution {
public:
    void fill(vector<vector<int>>& image, int sr, int sc, int color,int col)
    {
        if(sr>=0 and sc>=0 and sr<image.size() and sc<image[0].size() and image[sr][sc]==col)
        {
            image[sr][sc]=color;
             fill(image,sr-1,sc,color,col);
             fill(image,sr,sc-1,color,col);
             fill(image,sr+1,sc,color,col);
             fill(image,sr,sc+1,color,col);
        }
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int col=image[sr][sc];
        if(col==color)
            return image;
        fill(image,sr,sc,color,col);
        return image;
    }
};