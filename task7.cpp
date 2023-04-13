#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {
        // Constructor to initialize empty stacks
    }
    void push(int x) {
        // Add element to stack1
        stack1.push(x); 
    }
    int pop() {
        //first call peek function because it has to pop element from stack2
        int val=peek(); 
        // Remove the front element from stack2
        stack2.pop(); 
        // Return the front element
        return val; 
    }
    int peek() {
        // If stack2 is empty
        if(stack2.empty()){ 
            // Transfer elements from stack1 to stack2
            while(stack1.empty() == false){ 
                // Add top element of stack1 to stack2
                stack2.push(stack1.top()); 
                 // Remove top element from stack1
                stack1.pop();
            }
        }
         // Return the front element of stack2
        return stack2.top();
    }   
    bool empty() {
        // Check if both stacks are empty
        return stack1.empty() && stack2.empty(); 
    }

private:
// Two stacks to implement queue
    stack<int> stack1, stack2; 
};

int main() {
    MyQueue q; // Create a MyQueue object q
    q.push(1); // Push 1 into the queue
    q.push(2); // Push 2 into the queue
    q.push(3); // Push 3 into the queue
    cout << "Front of queue: " << q.peek() << endl; // Print the front element of the queue
   q.pop(); // Remove the front element of the queue
    cout << "Front of queue: " << q.peek() << endl; // Print the front element of the queue
    q.push(4); // Push 4 into the queue
    while (!q.empty()) {
        cout << q.pop() << " "; // Remove and print each element in the queue
    }
    cout << endl;
    
    return 0;
}
