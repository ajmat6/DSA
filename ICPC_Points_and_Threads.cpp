#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(int n, vector<long long>& x, vector<long long>& a) {
    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; ++i) {
        points[i] = {x[i], a[i]};
    }

    sort(points.begin(), points.end());

    long long total_cost = 0;
    for (int i = 1; i < n; ++i) {
        long long dist = points[i].first - points[i - 1].first;
        long long cost = min(points[i].second, points[i - 1].second) * dist;
        total_cost += cost;
    }

    return total_cost;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<long long> x(n), a(n);

        for (int i = 0; i < n; ++i) cin >> x[i];
        for (int i = 0; i < n; ++i) cin >> a[i];

        cout << solve(n, x, a) << endl;
    }

    return 0;
}