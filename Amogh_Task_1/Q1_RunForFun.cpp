#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y;
    std::cin >> x>> y;
    if (x>=y){
        std::cout << 0; // trivial case
    }
    else{
        if (y%x == 0){
            std::cout << (floor(y/x) - 1); // since last rest will happen after he reaches the finish line so -1 from floor division
        }
        else{
            std::cout << (floor(y/x)); // trivial
        }
    }

    return 0;
}
