#include <bits/stdc++.h>
using namespace std;

//i convert the strings into pairs where each pair has 2 elements (a[i],b[i]) for each index i
// now the operations permit us to exchange the order in the pairs or change the order of pairs (exchange positions of 2 pairs)
// so basically (0,1) and (1,0) are counted as equal since they can be interchanged freely. 
// so i take the counts of (1,1), (0,0) and (0,1)+(1,0) 
// either all 3 should be even or 2 even 1 odd for palindrome strings to exist
// because each element should match with its mirrored position and max to max only 1 can be odd so it can be put in the middle



int main() {
    int t,n;
	std::cin >> t;
	for(int i = 0; i < t; i++){
	    std::cin >> n;
	    std::string a,b;
	    std::cin >> a >> b;
	    std::vector<int> pairs;
	    int x = 0;
	    int y = 0;
	    int z = 0;
	    for (int j = 0; j < n; j++){
	       std::pair<int,int> pair_num = {a[j] - '0', b[j] - '0'};
	       if (pair_num == std::pair{0,0}){
	           x++;
	       }
	       else if (pair_num == std::pair{1,1}){
	           y++;
	       }
	       else{
	           z++;
	       }
	       //pairs.push_back(pair_num);
	    }
	    
	    int count = 0;
	    if (x%2 == 0){
	        count++;
	    }
	    if (y%2 == 0){
	        count++;
	    }
	    if (z%2 == 0){
	        count++;
	    }
	    if (count >= 2){
	        std::cout << "YES" << '\n';
	    }
	    else{
	        std::cout << "NO" << '\n';
	    }
	}
	

}
