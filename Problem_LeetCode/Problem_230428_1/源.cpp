#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class DinnerPlates {
    int capacity;
    vector<stack<int>> stacks;
    priority_queue<int, vector<int>, greater<>> idx;
public:
    DinnerPlates(int capacity) : capacity(capacity) {}

    void push(int val)
    {
        if (!idx.empty() && idx.top() >= stacks.size())
            while (!idx.empty()) idx.pop();
        if (idx.empty())
        {
            stack<int> st;
            st.push(val);
            stacks.emplace_back(st);
            if (capacity > 1)
                idx.push(stacks.size() - 1);
        }
        else
        {
            auto& st = stacks[idx.top()];
            st.push(val);
            if (st.size() == capacity)
                idx.pop();
        }
    }

    int pop()
    {
        return popAtStack(stacks.size() - 1);
    }

    int popAtStack(int index)
    {
        if (index < 0 || index >= stacks.size() || stacks[index].empty())
            return -1;
        auto& st = stacks[index];
        if (st.size() == capacity)
            idx.push(index);
        int val = st.top();
        st.pop();
        while (!stacks.empty() && stacks.back().empty())
            stacks.pop_back();
        return val;
    }
};