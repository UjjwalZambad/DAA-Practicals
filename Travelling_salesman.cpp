#include <iostream>
#include <climits>
#include <algorithm> // Added for 'copy' function
using namespace std;

const int MAX_N = 10;
const int INF = INT_MAX;
int n;
int graph[MAX_N][MAX_N];
bool visited[MAX_N];
int lowerBound = INT_MAX; // Initialize to a high value

void inputGraph() {
    cout << "Enter the number of cities: ";
    cin >> n;
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }
}

void LCBB(int currPos, int cost, int level, int path[MAX_N]) {
    if (level == n) {
        if (graph[currPos][0] != INF) {
            int currentCost = cost + graph[currPos][0];
            if (currentCost < lowerBound) {
                lowerBound = currentCost;
                copy(path, path + n, path + 1); // Fix path copy
                path[0] = 0; // Start and end at city 0
            }
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i] != INF) {
            visited[i] = true;
            path[level] = i;
            LCBB(i, cost + graph[currPos][i], level + 1, path);
            visited[i] = false;
        }
    }
}

int main() {
    inputGraph();
    int path[MAX_N];
    visited[0] = true;
    path[0] = 0;
    LCBB(0, 0, 1, path);

    cout << "Optimal Path: ";
    for (int i = 0; i < n; i++) {
        cout << path[i] << " ";
    }
    cout << "0\n"; // Return to starting city
    cout << "Cost: " << lowerBound << "\n";
    return 0;
}
