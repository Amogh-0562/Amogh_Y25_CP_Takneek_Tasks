#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,y,z,a,b,c,t;
	std::cin >> t;
	for (int i = 0; i < t; i++){
	    int count = 0;
	    std::cin >> x >> y >> z >> a >> b >> c;
	    // basically converting all excess larger shirts into the one just smaller and repeating this 2 times. 
	    if (z>c){
	        y += z-c;
	        z = c;
	        
	        count += c;
	    }
	    else{
	        count += z;
	    }
	    if (y>b){
	        x += y-b;
	        y = b;
	        
	        count += b;
	    }
	    else{
	        count += y;
	    }
	    if (x>a){
	        count += a;
	    }
	    else{
	        count += x;
	    }
	    
	    std:cout << count << '\n';
	}
	

}
