#include <iostream>
#include <vector>

using namespace std;

int knapsack(int capacity, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;  // Number of items
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weights of the items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int maxVal = knapsack(capacity, weights, values);

    cout << "The maximum value that can be obtained is: " << maxVal << endl;

    return 0;
}


















/*Enter the number of items: 6
Enter the weights of the items:
1 
2
3
6
7
4
Enter the values of the items:
10
20
30
40
60
70
Enter the knapsack capacity: 7
The maximum value that can be obtained is: 100*/