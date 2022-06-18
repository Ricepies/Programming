#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class LinkedList
{
private:
    int listLength = 0;
    Node<T> *head = NULL;

public:
    // LinkedList()
    // {
    // }
    void append(T data)
    {
        listLength += 1;
        Node<T> *addingNode = (Node<T> *)malloc(sizeof(Node<T>));
        addingNode->data = data;
        addingNode->next = head;
        head = addingNode;
    }
    int pop()
    {
        int returnData = head->data;
        Node<T> *nextHead = head->next;
        free(head);
        head = nextHead;
        return returnData;
    }
    void printList()
    {
        Node<T> *start = head;
        for (int i = 0; i < listLength; i++)
        {
            // printf("%d->", start->data);
            std::cout << start->data << "->";
            start = start->next;
        }
        printf("NULL");
        printf("\n");
    }
};

int main(int argc, char const *argv[])
{
    LinkedList<std::string> test;
    test.append("Hello");
    test.append("World");
    test.append("!");
    test.append("!");
    test.printList();
    return 0;
}
