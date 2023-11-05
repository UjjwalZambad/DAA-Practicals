#include <bits/stdc++.h>
using namespace std;

int knapsack(int capacity, vector<int> &weights, vector<int> &values, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int w = 0; w <= capacity; ++w)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

int main()
{
    int capacity;
    cout << "Enter the capacity of the Knapsack" << endl;
    cin >> capacity;
    int n;
    cout << "Enter the number of items" << endl;
    cin >> n;
    vector<int> weights(n), values(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight and value for item" << i + 1 << ":";
        cin >> weights[i] >> values[i];
    }
    double result = knapsack(capacity, weights, values, n);
    cout << "Maximum value obtained is " << result << endl;
    return 0;
}