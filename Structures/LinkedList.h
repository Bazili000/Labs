#include "../Pointers/unique.h"
#include "../Pointers/shared.h"

template <typename T>
struct Node {
    T data;
    UnqPtr<Node<T>> next;

    explicit Node(const T& data) : data(data), next(nullptr) {}

    ~Node() {}
};

template <typename T>
class LinkedList {
private:
    UnqPtr<Node<T>> head;
    size_t length;

public:
    LinkedList() : head(nullptr), length(0) {}
    
    ~LinkedList() {
        destroy();
    }

    void destroy() {
        while (head.get()) {
            popFront();
        }
    }

    size_t size() const {
        return length;
    }

    void pushFront(const T& value) {
        UnqPtr<Node<T>> newNode(new Node<T>(value));
        newNode->next.reset(head.release());
        head.reset(newNode.release());
        ++length;
    }


    void popFront() {
        if (head.get()) {
            UnqPtr<Node<T>> oldHead(head.release()); // Освобождаем текущий head
            head.reset(oldHead->next.release());    // Передаём владение следующим узлом в head
            --length;
        }
    }

    const T& getFront() const {
        if (!head.get()) {
            throw std::runtime_error("List is empty");
        }
        return head->data;
    }

};
