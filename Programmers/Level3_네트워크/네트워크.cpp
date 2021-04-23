#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visited[201];
    memset(visited, false, sizeof(visited));
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
               
        answer++;
        queue<int> que;
        que.push(i);
        visited[i] = true;
        
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            
            for (int j = 0; j < n; j++) {   
                if (cur == j || computers[cur][j] == 0 || visited[j]) continue;
                que.push(j);
                visited[j] = true;
            }
        }
    }
    
    return answer;
}