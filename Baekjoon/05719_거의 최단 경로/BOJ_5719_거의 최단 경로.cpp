#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define SIZE 501
#define INF 987654321
using namespace std;

struct compare {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        if (p1.second == p2.second) return p1.first > p2.first;
        return p1.second > p2.second;
    }
};
 
int N, M, S, D;
int shortPath, answer;
int Edge[SIZE][SIZE];
vector<vector<int>> path;
vector<int> dist;

void init() {
    shortPath = answer = -1;
    memset(Edge, 0, sizeof(Edge));
}

void inputEdge() {
    int U, V, P;
    for (int i = 0; i < M; i++) {
        cin >> U >> V >> P;
        Edge[U][V] = P;
    }
}

void deletePath(int v) {
    for (int p : path[v]) {
        if (Edge[p][v] == 0) continue;
        Edge[p][v] = 0;
        deletePath(p);
    }
}

int getPath() {
    int res = -1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    path.assign(N, vector<int>());
    dist.assign(N, INF);

    pq.push({ S, 0 });
    dist[S] = 0;

    while (!pq.empty()) {
        int v = pq.top().first;
        int w = pq.top().second;
        pq.pop();

        if (v == D) {
            res = w;
            if (shortPath == -1) shortPath = res;
            else if (shortPath < res) break;
        }

        for (int i = 0; i < N; i++) {
            if (Edge[v][i] == 0 || dist[i] < Edge[v][i] + w) continue;
            if (dist[i] > Edge[v][i] + w) {
                path[i].clear();
                dist[i] = Edge[v][i] + w;
                pq.push({ i, dist[i] });
            }
            path[i].push_back(v);
        }
    }

    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        
        cin >> S >> D;
        init();
        inputEdge();
        getPath();
        deletePath(D);
        answer = getPath();
        cout << answer << "\n";
    }

    return 0;
}