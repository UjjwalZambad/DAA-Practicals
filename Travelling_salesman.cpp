#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int tsp(int graph[][10], bool visited[], int currentPos, int n, int count, int cost, int& ans) {
    if (count == n && graph[currentPos][0]) {
        ans = min(ans, cost + graph[currentPos][0]);
        return ans;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && graph[currentPos][i]) {
            visited[i] = true;
            tsp(graph, visited, i, n, count + 1, cost + graph[currentPos][i], ans);
            visited[i] = false;
        }
    }
    return ans;
}

int branchAndBoundTSP(int graph[][10], int n) {
    bool visited[10] = { false };
    visited[0] = true; // Starting from the 0th vertex

    int ans = INF;
    ans = tsp(graph, visited, 0, n, 1, 0, ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;
    int graph[10][10];

    cout << "Enter the adjacency matrix for the graph: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int minCost = branchAndBoundTSP(graph, n);

    cout << "Minimum cost for TSP: " << minCost << endl;

    return 0;
}
