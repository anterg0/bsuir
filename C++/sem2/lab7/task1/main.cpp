#include <iostream>
#include "liba.cpp"

class BinaryHeapArray {
private:
    std::vector<int> heap;

public:
    void insert(int value) {
        heap.push_back(value);
        int currentIndex = heap.size() - 1;
        int parentIndex = (currentIndex - 1) / 2;

        while (currentIndex > 0 && heap[currentIndex] < heap[parentIndex]) {
            std::swap(heap[currentIndex], heap[parentIndex]);
            currentIndex = parentIndex;
            parentIndex = (currentIndex - 1) / 2;
        }
    }

    int removeMin() {
        if (heap.empty()) {
            std::cout << "Heap is empty." << std::endl;
            return -1;
        }

        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);

        return minValue;
    }

private:
    void heapify(int index) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int smallestIndex = index;

        if (leftChildIndex < heap.size() && heap[leftChildIndex] < heap[smallestIndex])
            smallestIndex = leftChildIndex;

        if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[smallestIndex])
            smallestIndex = rightChildIndex;

        if (smallestIndex != index) {
            std::swap(heap[index], heap[smallestIndex]);
            heapify(smallestIndex);
        }
    }
};

class Node {
public:
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    std::weak_ptr<Node> parent;
    int data;

    Node(int val) : data(val), left(nullptr), right(nullptr), parent() {}
};

class Heap {
private:
    std::shared_ptr<Node> root;

public:
    Heap() : root(nullptr) {}

    std::shared_ptr<Node> lastparent() {
        std::list<std::shared_ptr<Node>> q;
        q.push_back(root);
        std::shared_ptr<Node> tmp;
        while (!q.empty()) {
            tmp = q.front();
            q.pop_front();
            if (tmp->left && tmp->right) {
                q.push_back(tmp->left);
                q.push_back(tmp->right);
            } else {
                break;
            }
        }
        return tmp;
    }

    void upHeapify(std::shared_ptr<Node> tmp) {
        if (tmp->parent.expired()) {
            return;
        }
        if (tmp->parent.lock()->data < tmp->data) {
            std::swap(tmp->parent.lock()->data, tmp->data);
            upHeapify(tmp->parent.lock());
        }
    }

    void add(int data) {
        std::shared_ptr<Node> newnode = std::make_shared<Node>(data);
        if (root == nullptr) {
            root = newnode;
            return;
        }

        std::shared_ptr<Node> left_par = lastparent();

        if (left_par->left == nullptr) {
            left_par->left = newnode;
            newnode->parent = left_par;
        } else {
            left_par->right = newnode;
            newnode->parent = left_par;
        }
        upHeapify(newnode);
    }

    void out(std::shared_ptr<Node> bin_heap) {
        if (bin_heap == nullptr) return;
        out(bin_heap->left);
        std::cout << bin_heap->data << " ";
        out(bin_heap->right);
    }

    bool isEmpty() {
        return root == nullptr;
    }

    std::shared_ptr<Node> lastnode() {
        std::list<std::shared_ptr<Node>> q;
        q.push_back(root);
        std::shared_ptr<Node> last;
        while (!q.empty()) {
            last = q.front();
            q.pop_front();
            if (last->left) q.push_back(last->left);
            if (last->right) q.push_back(last->right);
        }
        return last;
    }

    void downHeapify(std::shared_ptr<Node> bin_heap) {
        std::shared_ptr<Node> largest = bin_heap;

        if (bin_heap->left && bin_heap->left->data > largest->data)
            largest = bin_heap->left;
        if (bin_heap->right && bin_heap->right->data > largest->data)
            largest = bin_heap->right;

        if (largest != bin_heap) {
            std::swap(largest->data, bin_heap->data);
            downHeapify(largest);
        }
    }

    void remove() {
        if (isEmpty())  return;
        std::shared_ptr<Node> last = lastnode();

        if (last == root) {
            root = nullptr;
            return;
        }

        std::shared_ptr<Node> pr = last->parent.lock();

        if (pr->left == last) {
            pr->left = nullptr;
        } else {
            pr->right = nullptr;
        }

        std::swap(root->data, last->data);
        downHeapify(root);
    }

    std::shared_ptr<Node> getRoot() const {
        return root;
    }
};





int main() {
    BinaryHeapArray heap;
    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    heap.insert(15);
    std::cout << "Binary heap based on array: " << std::endl;
    std::cout << "Removed min value: " << heap.removeMin() << std::endl;
    std::cout << "Removed min value: " << heap.removeMin() << std::endl;
    std::cout << "Removed min value: " << heap.removeMin() << std::endl;
    std::cout << "Removed min value: " << heap.removeMin() << std::endl;

    Heap heapList;

    heapList.add(5);
    heapList.add(2);
    heapList.add(10);
    heapList.add(3);
    heapList.add(8);

    heapList.remove();

    std::shared_ptr<Node> root = heapList.getRoot();
    while (root != nullptr) {
        std::cout << root->data << " ";
        heapList.remove();
        root = heapList.getRoot();
    }

    std::cout << std::endl;

    return 0;
}
