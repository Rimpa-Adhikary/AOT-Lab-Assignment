#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
};

// Function to compare two items by value/weight ratio (descending)
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int n;
    float capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[100];

    // Taking input
    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    // Sort items by value/weight ratio
    sort(items, items + n, compare);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take full item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take fractional part
            totalValue += (items[i].value * capacity) / items[i].weight;
            break; // Knapsack is full
        }
    }

    cout << "Maximum value in knapsack = " << totalValue << endl;

    return 0;
}

