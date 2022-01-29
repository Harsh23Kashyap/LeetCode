class Solution {
public:
    void backtrack(string tiles, int start, int &count)
    {
        count++;
        //cout<<tiles<<endl;
        for(int i=start;i<tiles.length();i++)
        {
            if(i != start && tiles[i] == tiles[start]){
                continue;
            }
            swap(tiles[i], tiles[start]);
            backtrack(tiles, start+1, count);
        }
    }
   
    int numTilePossibilities(string tiles) 
    {
        sort(tiles.begin(),tiles.end());
        int count=-1;
        //string t="";
       backtrack(tiles,0,count);
        return count;
    }
};