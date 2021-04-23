#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int, greater<>> que;
    
    for (int i = 0; i < operations.size(); i++) {
        char command = operations[i][0];
        int num = stoi(operations[i].substr(2));
        
        if (command == 'I') que.insert(num);
        else if (!que.empty()) {
            if (num > 0) que.erase(que.begin());
            else que.erase(--que.end()); 
        }
    }
    
    if (que.empty()) answer.push_back(0), answer.push_back(0);
    else answer.push_back(*que.begin()), answer.push_back(*--que.end());
    
    return answer;
}