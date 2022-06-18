from typing import Any


class Node:
    def __init__(self, data: Any):
        self.next = None
        self.data = data


class linkedList:
    def __init__(self):
        self.headNode = Node(None)
        self.__len__ = 0

    def append(self, data: Any):
        newNode = Node(data)
        newNode.next = self.headNode
        self.headNode = newNode
        self.__len__ += 1

    def printList(self):
        currentNode = self.headNode
        for i in range(self.__len__):
            print(currentNode.data)
            currentNode = currentNode.next

    def pop(self):
        returnData = self.headNode.data
        self.headNode = self.headNode.next
        self.__len__ -= 1
        return returnData

    def size(self):
        return self.__len__


testlist = linkedList()
testlist.append(1)
testlist.append(2)
testlist.append(3)
testlist.append(4)
testlist.pop()
testlist.printList()
