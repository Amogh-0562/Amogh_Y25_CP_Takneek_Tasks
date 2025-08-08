#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    std::cin >> n;
    int matrix[n][3];
    for (int i = 0; i < n; i++){
        std::cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
    }
    int hpy[n][3];
    hpy[0][0] = matrix[0][0];
    hpy[0][1] = matrix[0][1];
    hpy[0][2] = matrix[0][2];
    
    for (int i = 1; i<n; i++){
        hpy[i][0] = std::max(hpy[i-1][1], hpy[i-1][2]) + matrix[i][0];
        hpy[i][1] = std::max(hpy[i-1][0], hpy[i-1][2]) + matrix[i][1];
        hpy[i][2] = std::max(hpy[i-1][0], hpy[i-1][1]) + matrix[i][2];
    }
    
    std::cout << std::max({hpy[n-1][0], hpy[n-1][1], hpy[n-1][2]});
    
    return 0;
}
