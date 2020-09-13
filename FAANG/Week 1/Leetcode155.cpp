class MinStack
{
public:
    stack<int> s;
    stack<int> mini;
    void push(int x)
    {
        s.push(x);
        if(mini.empty() || x < mini.top())mini.push(x); // if current element is smaller than mini, push in mini stack to change current min element
        else mini.push(mini.top()); // If current element is not smaller, push the last smallest in min stack again so that you can keep multiple instances while you pop
    }
    void pop()
    {
        mini.pop();
        s.pop();
        //This is done so that when a pop operation is called the current minimum if equal
        //to the top of our main stack is popped as well otherwise the if there is any other minimum rather than stack top,
        //it will not hinder the functioning of our min stack 
    }
    int top()return s.top();
    int getMin()return mini.top();
};
