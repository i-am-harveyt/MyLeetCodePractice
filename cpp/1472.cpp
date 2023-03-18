#include <iostream>
#include <vector>

using namespace std;

class BrowserHistory
{
public:
    BrowserHistory(string homepage)
    {
        hist.push_back(homepage);
    }

    void visit(string url)
    {
        ++cur;
        if (hist.size() > cur)
            hist[cur] = url;
        else
            hist.push_back(url);
        last = cur;
    }

    string back(int steps)
    {
        cur - steps < 0 ? cur = 0 : cur -= steps;
        return hist[cur];
    }

    string forward(int steps)
    {
        cur + steps > last ? cur = last : cur += steps;
        return hist[cur];
    }

private:
    int cur = 0;
    int last = 0;
    vector<string> hist;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 **/