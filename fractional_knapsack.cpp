#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item i1, Item i2) {
    double ratio1 = double(i1.value) / i1.weight;
    double ratio2 = double(i2.value) / i2.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int capacity, Item items[], int n) {
    sort(items, items + n, compare);
    double totalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += double(items[i].value) * capacity / items[i].weight;
            break;
        }
    }
    return totalValue;
}

int main() {
    int capacity;
    cout << "Enter the capacity of the Knapsack: " << endl;
    cin >> capacity;
    
    int n;
    cout << "Enter the number of items: " << endl;
    cin >> n;
    
    Item items[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }
    
    double result = fractionalKnapsack(capacity, items, n);
    cout << "Maximum value obtained is " << result << endl;
    
    return 0;
}
