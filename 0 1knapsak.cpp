#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int W, n;
    cout << "Enter knapsack capacity: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> weights(n);
    vector<int> values(n);
    cout << "Enter the values and weights of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }
    int result = knapsack(W, weights, values);
    cout << "Maximum value: " << result << endl;
    return 0;
}

/**
Enter knapsack capacity: 12
Enter the number of items: 4
Enter the values and weights of each item:
30 5
28 7
20 4
24 2
Maximum value: 74
**/

