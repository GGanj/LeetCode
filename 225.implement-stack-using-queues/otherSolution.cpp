#include <queue> 

class MyStack1 {
public:
    std::queue<int> q1;
    MyStack1() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        std::queue<int> q2;
        for(int i = q1.size(); i > 1; --i) {
            q2.push(q1.front());
            q1.pop();
        }
        int qTail = q1.front();
        q1 = q2;
        return qTail;
    }
    
    int top() {
        std::queue<int> q2;
        for(int i = q1.size(); i > 1; --i) {
            q2.push(q1.front());
            q1.pop();
        }
        int qTail = q1.front();
        q2.push(qTail);
        q1 = q2;
        return qTail;
    }
    
    bool empty() {
        if(q1.size()) {
            return false;
        }
        return true;
    }
};

class MyStack2 {
public:
    std::queue<int> q;
    MyStack2() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        for(int i = q.size(); i > 1; --i) {
            q.push(q.front());
            q.pop();
        }
        int qTail = q.front();
        q.pop();
        return qTail;
    }
    
    int top() {
        std::queue<int> q2;
        for(int i = q.size(); i > 1; --i) {
            q.push(q.front());
            q.pop();
        }
        int qTail = q.front();
        q.push(qTail);
        q.pop();
        return qTail;
    }
    
    bool empty() {
        if(q.size()) {
            return false;
        }
        return true;
    }
};