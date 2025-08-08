#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int n,c;
    std::string s;
	std::cin >> t;
	for (int i = 0; i < t; i++){
	    int price = 0;
	    std::cin >> n >> c;
	    std::cin >> s;
	    //finding how many minimum people required speaking a language such that learning it is cheaper than repeated translations
	    int sum = 0;
	    int count = 0;
	    while (sum <= c){
	        count++;
	        sum += count;
	    }
	    std::unordered_map<std::string, int> dict;

		//here i am making a mapping where the key is the language and the value is the number of people speaking it
	    for (int j = 0; j < n; j++){
	        if (dict.contains(std::string(1,s[j]))){
	            dict[std::string(1,s[j])] += 1; 
	        }
	        else{
	            dict[std::string(1,s[j])] = 1;
	        }
	    }

		//this is a vector contaning only the number of people speaking a language
	    std::vector<int> nums;
        for (const auto& pair : dict) {
            nums.push_back(pair.second);
        }

    	//sorting it
        std::sort(nums.begin(), nums.end());

		// here comes the main part of the logic. we have to keep using the translator until learning the language is cheaper.
		// if we make more popular languages use the translator first, that would be non optimal as we would have to learn the smaller languages
		// so if we do reach a point where learning is cheaper, we ought to learn the bigger languages
		// hence i sorted the vector having the number of people speaking each language
		// now i start with smallest languages, using translator by default. i check after translating my way through each language if learning it would have been cheaper
		// if it would have been, then we dont use the translator and learn it. and since the vector is in ascending order, all languages after it also would be cheaper to learn.
		
		
        int counter = 0;
        int current_count = 0;
        int flag = 1;
        int it = 0;
        
        for (int k = 0; k < nums.size(); k++){
            current_count = 0;
            //std::cout << price;
            if (flag == 1){
                it = 0;
                while (it < nums[k]){
                    it++;
                    counter ++;
                    current_count += counter;
                
            }
                if (current_count > c){
                    flag = 0;
                    price += c;
            }
                else{
                    price += current_count;
            }
            }
            else{
                price += c;
            }
            
            
            
        }
	    std::cout << price << '\n';
	}
}

