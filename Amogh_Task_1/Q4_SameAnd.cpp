#include <bits/stdc++.h>
using namespace std;

//i first realised that for bitwise and operator between any 2 elements to always give n, in the binary represenation of n,
//all the 0s can be a 1 only once (in only one other number) because if that spot was 1 in 2 numbers, the bitwise and would
//give a 1 there which wont give n. so i basically replace a 0 with a 1 making a new number one at a time, going with smallest
//first, and checking at each step to make sure the number hasnt exceeded m. 
// to do this, i reverse the binary represenation of n, check for 0s, convert it to 1. inrease a counter so that next time,
//it parses through 2 zeroes and converts the second 0 to 1 making a diff number.and i just check every time 
//that it hasnt exceeded m.

int main() {
    int t;
    long long int n,m;
	std::cin >> t;
	for (int i = 0; i < t; i++){
	    std::vector<long long int> nums;
	    std::cin >> n >> m;
	    std::string binary_n = std::bitset<sizeof(long long int) * 8>(n).to_string();
	    //int decimal_value = std::stoi(binaryString,2);
	    
	    std::string reverse_n = binary_n;
	    std::reverse(reverse_n.begin(), reverse_n.end());
	    int flag = 1;
	    int count = 0;
	    int num = 0;
	    std::string bin;
	    while (flag == 1){
	        count = num;
	        bin = reverse_n;
	        for (char &c : bin){
	            if (c == '0'){
	                //std::cout << count;
	                if (count == 0){
	                    c = '1';
	                    num ++;
	                    break;
	                }
	                else{
	                    count-=1;
	                    //std::cout << 'minus';
	                }
	                
	            }
	        }
	        //std::cout << bin;
	        std::string new_num = bin;
	        std::reverse(new_num.begin(), new_num.end());
	        
	        long long int decimal_value = std::stoll(new_num,nullptr,2);
	        nums.push_back(decimal_value);
	        //std::cout << decimal_value;
	        if (decimal_value > m){
	            flag = 0;
	            if (num == 1){
	                std::cout << -1 << '\n';
	            } 
	            else{
	                std::cout << num << '\n';
	                std::cout << n << ' ';
	                for (long long int i = 0; i < nums.size()-1; i++){
	                    std::cout << nums[i] << ' ';
	                }
	                std::cout << '\n';
	            }
	            
	        }
	        
	    }
	        
	    }
	    
	}
    
    


