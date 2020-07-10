class MinStack
{
public:
	/** initialize your data structure here. */
	stack<int> min_stack;
	stack<int> normal_stack;

	MinStack()
	{
		min_stack.push(numeric_limits<int>::max());
	}

	void push(int x)
	{
		normal_stack.push(x);
		min_stack.push(min(min_stack.top(), x));
	}

	void pop()
	{
		normal_stack.pop();
		min_stack.pop();
	}

	int top()
	{
		return normal_stack.top();
	}

	int getMin()
	{
		return min_stack.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */