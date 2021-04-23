#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return p1.second > p2.second;
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<vector<pair<int, int>>> adjList(n, vector<pair<int, int>>());
    for (int i = 0; i < costs.size(); i++) {
        adjList[costs[i][0]].push_back({costs[i][1], costs[i][2]});
        adjList[costs[i][1]].push_back({costs[i][0], costs[i][2]});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<bool> visited(n, false);
    pq.push({0, 0});
    
    while (!pq.empty()) {
        int v = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        
        if (visited[v]) continue;
        visited[v] = true;
        answer = answer + cost;
        
        for (int i = 0; i < adjList[v].size(); i++) {
            if (visited[adjList[v][i].first]) continue;
            pq.push(adjList[v][i]);
        }
    }
    
    return answer;
}