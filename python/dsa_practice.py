#!/bin/python3

class Node:
    def __init__(self, val):
        self.value = val;
        self.next=None
    def __str__(self):
        values = []
        current = self
        while current:
            values.append(str(current.value))
            current = current.next
        return " -> ".join(values)

n = Node(1)
b = n
for i in range(2,11):
    b.next = Node(i)
    b=b.next
print(n)
