#include <bits/stdc++.h>
using namespace std;

class Item {
public:
    int value, weight;
    Item(int v_, int w_) : value(v_), weight(w_) {}
};

class FractionalKnapsack {
public:
    double solve(int capacity, vector<Item> items) {
        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return (double)a.value / a.weight > (double)b.value / b.weight;
        });
        double total = 0;
        for (auto& item : items) {
            if (capacity >= item.weight) {
                total += item.value;
                capacity -= item.weight;
            } else {
                total += (double)item.value * capacity / item.weight;
                break;
            }
        }
        return total;
    }
};

int main() {
    int capacity = 50;
    vector<Item> items = {Item(60, 10), Item(100, 20), Item(120, 30)};
    FractionalKnapsack fk;
    cout << "Max value = " << fk.solve(capacity, items) << "\n";
    return 0;
}
