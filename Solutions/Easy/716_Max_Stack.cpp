/*
 Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
 */

/*
 Complexity Analysis

Time Complexity: O(N) for the popMax operation, and O(1) for the other operations, where NN is the number of operations performed.

Space Complexity: O(N), the maximum size of the stack.
 */
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {

    }

    void push(int x) {
        stk.push(x);
        if (max_stk.empty() || max_stk.top() <= x)
            max_stk.push(x);
    }

    int pop() {
        int t = stk.top();
        if (t == max_stk.top())
            max_stk.pop();
        stk.pop();
        return t;
    }

    int top() {
        return stk.top();
    }

    int peekMax() {
        return max_stk.top();
    }

    int popMax() {
        int t = max_stk.top();
        max_stk.pop();
        stack<int> temp;
        while(stk.top() != t) {
            int x = stk.top();
            temp.push(x);
            stk.pop();
        }
        stk.pop();
        while(!temp.empty()) {
            int x = temp.top();
            stk.push(x);
            if (max_stk.empty() || max_stk.top() <= x)
                max_stk.push(x);
            temp.pop();
        }
        return t;
    }
private:
    stack<int> stk;
    stack<int> max_stk;
};


/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */



// Solution 2 : Doubly Linked List and Map
// Complexity Analysis

// Time Complexity: O(logN) for all operations except peek which is O(1), where N is the number of operations performed. Most operations involving TreeMap O(logN).

// Space Complexity: O(N), the size of the data structures used.

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        stack_list.push_front(x);
        it_map[x].push_back(stack_list.begin());
    }
    
    int pop() {
        int x = stack_list.front();
        it_map[x].pop_back();
        if (it_map[x].empty())
            it_map.erase(x);
        stack_list.pop_front();
        return x;
    }
    
    int top() {
        return stack_list.front();
    }
    
    int peekMax() {
        return it_map.rbegin()->first;
    }
    
    int popMax() {
        int x = it_map.rbegin()->first;
        auto it = (it_map.rbegin()->second).back();
        stack_list.erase(it);
        it_map[x].pop_back();
        if (it_map[x].empty())
            it_map.erase(x);
        return x;
    }
private:
    list<int> stack_list;
    map<int, vector<list<int>::iterator>> it_map;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
