class FoodRatings {
public:
    unordered_map<string, string> u;
    unordered_map<string,int> fratig;
    unordered_map<string, set<pair<int, string>>> foodrate;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
           u[foods[i]]=cuisines[i];
           foodrate[cuisines[i]].insert({-1*ratings[i],foods[i]});
           fratig[foods[i]]=-1*ratings[i];
        }
        
    }
    
    void changeRating(string food, int newRating) {
       string cuisine = u[food];
       pair<int,string> res= {fratig[food],food};
       fratig[food]=-1*newRating;
       foodrate[cuisine].erase(res);
       foodrate[cuisine].insert({-1*newRating,food});
    }
    
    string highestRated(string cuisine) {
        return foodrate[cuisine].begin()->second;
        // return it.second.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */