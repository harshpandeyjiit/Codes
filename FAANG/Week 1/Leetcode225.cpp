class MyStack {
    queue<int> que1,que2;
    int sz;
public:
    MyStack()
    {
        sz=0;
    }
    void push(int x)
    {
        ++sz;
        que2.push(x);
        while(!que1.empty())
        {
            que2.push(que1.front());
            que1.pop();
        }
        swap(que1,que2);
    }
    int pop()
    {
        int popvalue=que1.front();
        que1.pop();
        sz--;
        return popvalue;
    }
    int top()
    {
        return que1.front();
    }
    bool empty()
    {
        return que1.empty();
    }
};
