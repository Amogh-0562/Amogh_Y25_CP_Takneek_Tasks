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
	    for (int j = 0; j < n; j++){
	        if (dict.contains(std::string(1,s[j]))){
	            dict[std::string(1,s[j])] += 1; 
	        }
	        else{
	            dict[std::string(1,s[j])] = 1;
	        }
	    }
	    std::vector<int> nums;
        for (const auto& pair : dict) {
            nums.push_back(pair.second);
        }

    
        std::sort(nums.begin(), nums.end());
        
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

