#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    double value;
    double weight;
};

class Knapsack
{
public:
    // Comparator to sort items by descending value-to-weight ratio
    static bool Comp(Item a, Item b)
    {
        double a1 = a.value / a.weight;
        double b1 = b.value / b.weight;
        return a1 > b1;
    }

    double FractionalKnapsack(int wt, Item arr[], int n)
    {
        double totalValue = 0.0; // Total value in knapsack
        double totalWeight = 0.0;

        // Sort items by value-to-weight ratio
        sort(arr, arr + n, Comp);

        for (int i = 0; i < n; i++)
        {
            if (totalWeight + arr[i].weight <= wt)
            {
                // If adding the whole item doesn’t exceed capacity, add it completely
                totalWeight += arr[i].weight;
                totalValue += arr[i].value;
            }
            else
            {
                // If adding the whole item exceeds capacity, add fractionally
                double remainingWeight = wt - totalWeight;
                totalValue += (arr[i].value / arr[i].weight) * remainingWeight;
                break;
            }
        }
        return totalValue;
    }
};

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    Item arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> arr[i].value >> arr[i].weight;
    }

    int maxWeight;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> maxWeight;

    Knapsack k;
    cout << "Maximum value in knapsack = " << k.FractionalKnapsack(maxWeight, arr, n) << endl;

    return 0;
}

// 5 40 2 50 3.14 100 1.98 95 5 30 3