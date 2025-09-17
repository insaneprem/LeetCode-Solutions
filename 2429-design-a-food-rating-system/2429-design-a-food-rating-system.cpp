class FoodRatings {
public:
    struct CMP {
        bool operator()(auto &a, auto &b) const {
            if (a.first != b.first)
                return a.first > b.first; 
            return a.second < b.second;   
        }
    };

    map<string, string> foodtoCuisine;
    map<string, int> foodRating;
    map<string, set<pair<int,string>, CMP>> CuisineToFood; 

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodtoCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
            CuisineToFood[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodtoCuisine[food];

        CuisineToFood[cuisine].erase({foodRating[food], food});
        foodRating[food] = newRating;
        CuisineToFood[cuisine].insert({foodRating[food], food});
    }

    string highestRated(string cuisine) {
        return CuisineToFood[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */