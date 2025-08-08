#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> heights(n);
    for (int i = 0; i < n; i++){
        std::cin >> heights[i];
    }
    std::vector<int> cost(n);
    cost[0] = 0;
    cost[1] = std::abs(heights[1] - heights[0]);
    for (int i = 2; i < n; i++){
        cost[i] = std::min(std::abs(heights[i-1] - heights[i]) + cost[i-1], std::abs(heights[i-2] - heights[i]) + cost[i-2]);
    }
    std::cout << cost[n-1];
    

    return 0;
}
