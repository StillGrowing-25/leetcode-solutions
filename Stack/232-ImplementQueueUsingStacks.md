# 232. Implement Queue using Stacks

## Problem Link
- [LeetCode 232 - Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)

## Intuition
A Queue is First-In-First-Out (FIFO), while a Stack is Last-In-First-Out (LIFO). To implement a queue using two stacks (`inputStack` and `outputStack`), we can manage operations as follows:
1. **Push (`push(x)`):** Always push new elements onto `inputStack`. This takes $O(1)$ time.
2. **Pop & Peek (`pop()`, `peek()`):** 
   - We want to access the oldest element (at the bottom of `inputStack`). 
   - If `outputStack` is empty, we transfer all elements from `inputStack` to `outputStack` by popping them one by one. This reverses their order, putting the oldest element at the top of `outputStack`.
   - If `outputStack` already has elements, we can directly pop or peek from it.
3. **Amortized Analysis:** Each element is pushed and popped from each stack at most twice, resulting in an amortized $O(1)$ time complexity per operation.

## Complexity Analysis

- **Time Complexity:** 
  - **Push:** $\mathcal{O}(1)$ as elements are simply pushed onto `inputStack`.
  - **Pop / Peek:** $\mathcal{O}(1)$ amortized per operation. Although transferring elements takes $\mathcal{O}(n)$ time in the worst case when `outputStack` is empty, each element is pushed and popped from each stack at most twice across its lifetime in the queue.
  - **Empty:** $\mathcal{O}(1)$ as it only checks if both stacks are empty.
- **Space Complexity:** $\mathcal{O}(n)$, where $n$ is the total number of elements currently stored in the queue across both stacks.

## Code

```java
import java.util.Stack;

class MyQueue {
    private Stack<Integer> inputStack;
    private Stack<Integer> outputStack;

    public MyQueue() {
        inputStack = new Stack<>();
        outputStack = new Stack<>();
    }
    
    public void push(int x) {
        inputStack.push(x);
    }
    
    public int pop() {
        shiftStacks();
        return outputStack.pop();
    }
    
    public int peek() {
        shiftStacks();
        return outputStack.peek();
    }
    
    public boolean empty() {
        return inputStack.isEmpty() && outputStack.isEmpty();
    }
    
    // Helper method to move elements from inputStack to outputStack when needed
    private void shiftStacks() {
        if (outputStack.isEmpty()) {
            while (!inputStack.isEmpty()) {
                outputStack.push(inputStack.pop());
            }
        }
    }
}
