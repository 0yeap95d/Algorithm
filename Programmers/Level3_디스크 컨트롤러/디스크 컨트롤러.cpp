#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
};

bool compare(vector<int> v1, vector<int> v2) {
    if (v1[0] == v2[0]) return v1[1] < v2[1];
    return v1[0] < v2[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int idx = 0;
    int weight = 0;
    int time = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
    
    sort(jobs.begin(), jobs.end(), compare);
    
    while (true) {
        if (idx == jobs.size()) break;
        
        if (que.empty()) {
            que.push({jobs[idx][0], jobs[idx][1]});
            time = jobs[idx][0];
            idx++;
        }
        
        while (!que.empty()) {
            int start = que.top().first;
            int cost = que.top().second;
            time = time + cost;
            weight = weight + time - start;
            que.pop();

            while(true) {
                if (idx == jobs.size() || jobs[idx][0] > time) break;
                que.push({jobs[idx][0], jobs[idx][1]});
                idx++;
            }
        }
    }
    
    answer = weight / jobs.size();
    
    return answer;
}