# Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

class MinStack:
    def __init__(self):
         self.items = []
        
    # @param x, an integer
    def push(self, x):
        curr = self.getMin()
        if curr == -1 or curr >x:
            curr=x
        self.items.append((x,curr))

    # @return nothing
    def pop(self):
        if(len(self.items) == 0):
            return 
        self.items.pop()

    # @return an integer
    def top(self):
        if(len(self.items) == 0):
            return -1
        return self.items[len(self.items)-1][0]

    # @return an integer
    def getMin(self):
        if(len(self.items) == 0):
            return -1
        return self.items[len(self.items)-1][1]
