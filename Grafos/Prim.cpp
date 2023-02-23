#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100;
const int INF = 1e9;

vector<pair<int, int>> adj[MAXN];
bool visited[MAXN];
int dist[MAXN];

int prim(int start, int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        dist[i] = INF;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    int mst = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        mst += dist[u];

        for (auto v : adj[u]) {
            int cost = v.second;
            int newDist = cost;

            if (!visited[v.first] && newDist < dist[v.first]) {
                dist[v.first] = newDist;
                pq.push(make_pair(newDist, v.first));
            }
        }
    }

    return mst;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;

        adj[u].push_back(make_pair(v, cost));
        adj[v].push_back(make_pair(u, cost));
    }

    int mstCost = prim(0, n);

    cout << "Minimum Spanning Tree Cost: " << mstCost << endl;

    return 0;
}
