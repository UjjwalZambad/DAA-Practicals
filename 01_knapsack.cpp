#include <iostream>
using namespace std;

const int MAX_N = 100; // Maximum number of items
const int MAX_CAPACITY = 1000; // Maximum knapsack capacity

int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[MAX_N + 1][MAX_CAPACITY + 1] = {0};

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int capacity;
    cout << "Enter the capacity of the Knapsack: " << endl;
    cin >> capacity;
    
    int n;
    cout << "Enter the number of items: " << endl;
    cin >> n;

    int weights[MAX_N];
    int values[MAX_N];

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> weights[i] >> values[i];
    }

    int result = knapsack(capacity, weights, values, n);
    cout << "Maximum value obtained is " << result << endl;

    return 0;
}
