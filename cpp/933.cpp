#include <queue>

using namespace std;

class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
    }
    
    int ping(int t) {
        q.push(t);
        int span = 3000;
        int bound = t - 3000;
        while (q.front() < bound) {
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */