#include <iostream>
#include <list>

using namespace std;

template <class T>
class Node {
public:

    Node(T key): left(nullptr), right(nullptr), parent(nullptr), height(0) {this->key=key;}
    T key;
    Node* left;
    Node* right;
    Node* parent;
    int height;
};

template <class T>
class MySet {
private:
    Node<T>* root;
    list<Node<T>*> tree;

    void clearTree(Node<T>* node)
    {
        if (node == nullptr)
            return;

        clearTree(node->left);
        clearTree(node->right);

        delete node;
    }

public:
    class Iterator
    {
    private:
        Node<T>* currentNode;
        Node<T>* root;

    public:
        Iterator(Node<T>* root, Node<T>* node): currentNode(root), root(node) {}

        Iterator& operator=(const Iterator& other)
        {
            this->root = other.root;
            this->currentNode = other.currentNode;

            return *this;
        }
        bool operator==(const Iterator& other) { return currentNode == other.currentNode; }
        bool operator!=(const Iterator& other) { return !(currentNode == other.currentNode); }
        T& operator*() { return currentNode->key; }

        Iterator& operator++()
        {
            if (currentNode == nullptr)
            {
                currentNode = root;

                if (currentNode == nullptr)
                    return *this;

                while (currentNode->left != nullptr)
                {
                    currentNode = currentNode->left;
                }
            }
            else if (currentNode->right != nullptr)
            {
                currentNode = currentNode->right;

                while (currentNode->left != nullptr)
                {
                    currentNode = currentNode->left;
                }
            }
            else {

                Node<T>* p = currentNode->parent;
                while (p != nullptr && currentNode == p->right)
                {
                    currentNode = p;
                    p = p->parent;
                }
                currentNode = p;
            }
            return *this;
        }

        Iterator& operator--()
        {
            if (currentNode == nullptr) {
                currentNode = root;

                if (currentNode == nullptr)
                    return *this;

                while (currentNode->right != nullptr) {
                    currentNode = currentNode->right;
                }
            }
            else if (currentNode->left != nullptr) {
                currentNode = currentNode->left;

                while (currentNode->right != nullptr) {
                    currentNode = currentNode->right;
                }
            }
            else {
                Node<T>* p = currentNode->parent;
                while (p != nullptr && currentNode == p->left) {
                    currentNode = p;
                    p = p->parent;
                }

                currentNode = p;
            }
            return *this;
        }
    };
    Iterator insert(T key)
    {
        MySet<T>::InsertNode(key);
        return Iterator(MySet<T>::root);
    }
    Iterator erase(const T& key)
    {
        MySet<T>::remove(key);
        return Iterator(MySet<T>::root);
    }
    Iterator begin()
    {
        Node<T>* node = MySet<T>::root;
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return Iterator(node, MySet<T>::root);
    }
    Iterator end() { return Iterator(nullptr, MySet<T>::root); }

    class IteratorList {

    private:
        list<Node<T>> treeList;
        typename list<Node<T>*>::iterator it;
    public:
        IteratorList(const list<Node<T>>& other, bool begin)
        {
            treeList = other;
            if (begin) it = treeList.begin();
            else it = treeList.end();
        }
        list<Node<T> > getList() { return treeList; }
        T operator*() { return (*it)->p; }
        IteratorList& operator++()
        {
            ++it;
            return *this;
        }
        IteratorList& operator--()
        {
            --it;
            return *this;
        }
    };

    IteratorList begin_listIt()
    {
        tree.clear();
        in_list(MySet<T>::root);
        return IteratorList(tree, true);
    }
    IteratorList end_listIt()
    {
        tree.clear();
        in_list(MySet<T>::root);
        return IteratorList(tree, false);

    }


    MySet() : root(nullptr) {}

    Node<T>* getRoot() { return root; }
    int GetBalance(Node<T>* tmp) { return (GetHeight(tmp->right) - GetHeight(tmp->left)); }
    int GetHeight(Node<T>* tmp) { return ((tmp == nullptr) ? -1 : tmp->height); }

    bool isEmpty() {
        return root == nullptr;
    }

    void InsertNode(T key)
    {
        if (root == nullptr)
        {
            root = new Node<T>(key);
            root->height = 0;
            root->parent = nullptr;
        }
        else {
            Node<T>* new_root = getRoot();
            Node<T>* new_node = new Node<T>(key);
            while (new_root != nullptr)
            {
                if (new_root->key > key)
                {
                    if (new_root->left == nullptr)
                    {
                        new_root->left = new_node;
                        new_node->height = 0;
                        new_node->parent = new_root;
                        break;
                    }
                    else
                    {
                        new_root = new_root->left;
                    }
                }
                else if (new_root->key < key)
                {
                    if (new_root->right == nullptr)
                    {
                        new_root->right = new_node;
                        new_node->height = 0;
                        new_node->parent = new_root;
                        break;
                    }
                    else
                    {
                        new_root = new_root->right;
                    }
                }
                else {
                    delete new_node;
                    return;
                }
            }
            rebalance(new_node);
        }
    }



    void clear()
    {
        clearTree(root);
        root = nullptr;
    }

    void heightBalance(Node<T>* tmp)
    {
        int l = -1, r = -1;
        if (tmp->left)
            l = tmp->left->height;
        if (tmp->right)
            r = tmp->right->height;
        tmp->height = max(l, r) + 1;
    }
    void treeFix(Node<T>* tmp)
    {
        if (GetBalance(tmp) == 2)
        {
            if (GetBalance(tmp->right) <0)
                RightRotate(tmp->right);
            LeftRotate(tmp);
            heightBalance(tmp);
        }
        else if (GetBalance(tmp) == -2)
        {
            if (GetBalance(tmp->left) > 0)
                LeftRotate(tmp->left);
            RightRotate(tmp);
            heightBalance(tmp);
        }
    }
    void rebalance(Node<T>* tmp)
    {
        if (tmp == root)  treeFix(root);
        else
        {
            while (tmp != nullptr)
            {
                heightBalance(tmp);
                tmp = tmp->parent;
                if (tmp) treeFix(tmp);
            }
        }
    }

    void LeftRotate(Node<T>* x)
    {
        T tmp=0;
        Node<T>* new_node = new Node<T>(tmp);

        if (x->right->left) new_node->right = x->right->left;

        new_node->left = x->left;
        new_node->key = x->key;
        x->key = x->right->key;
        x->left = new_node;

        if (new_node->left) new_node->left->parent = new_node;
        if (new_node->right) new_node->right->parent = new_node;

        new_node->parent = x;

        if (x->right->right) x->right = x->right->right;
        else x->right = nullptr;

        if (x->right)  x->right->parent = x;

        heightBalance(x->left);

        if (x->right) { heightBalance(x->right); }
        heightBalance(x);
    }

    void RightRotate(Node<T>* x)
    {
        T tmp= 0;
        Node<T>* new_node = new Node<T>(tmp);
        if (x->left->right) new_node->left = x->left->right;

        new_node->right = x->right;
        new_node->key = x->key;
        x->key = x->left->key;

        x->right = new_node;

        if (new_node->left) new_node->left->parent = new_node;

        if (new_node->right)  new_node->right->parent = new_node;

        new_node->parent = x;

        if (x->left->left)  x->left = x->left->left;
        else  x->left = nullptr;

        if (x->left) x->left->parent = x;

        heightBalance(x->right);
        if (x->left) { heightBalance(x->left); }
        heightBalance(x);
    }


    void PreorderTraversal(Node<T>* tmp)
    {
        if (tmp == nullptr) return;
        cout <<"->" <<tmp->key;
        PreorderTraversal(tmp->left);
        PreorderTraversal(tmp->right);
    }

    void PostorderTraversal(Node<T>* tmp)
    {
        if (tmp == nullptr) return;
        PostorderTraversal(tmp->left);
        PostorderTraversal(tmp->right);
        cout <<"->" <<tmp->key.first;
    }

    void RemoveNode(Node<T>* par, Node<T>* curr)
    {
        if (curr == nullptr) return;
        if (curr->key == curr->key)
        {
            if (curr->left == nullptr && curr->right == nullptr)
            {
                if (par->key == curr->key)
                    root = nullptr;
                else if (par->right == curr)
                    par->right = nullptr;
                else
                    par->left = nullptr;
                rebalance(par);
            }

            else if (curr->left != nullptr && curr->right == nullptr)
            {
                T sp = curr->key;
                curr->key = curr->left->key;
                curr->left->key = sp;
                RemoveNode(curr, curr->left);
            }

            else if (curr->left == nullptr && curr->right != nullptr)
            {
                T sp = curr->key;
                curr->key = curr->right->key;
                curr->right->key = sp;
                RemoveNode(curr, curr->right);
            }

            else {
                Node<T>* temp = curr->right;
                int flag = 0;
                while (temp->left)
                {
                    flag = 1;
                    par = temp;
                    temp = temp->left;
                }
                if (!flag) par = curr;

                T sp = curr->key;
                curr->key = temp->key;
                temp->key = sp;
                RemoveNode(par, temp);
            }
        }
    }

    void remove(T key)
    {
        auto tmp = root;
        auto parent = tmp;
        bool flag = false;

        if (tmp == nullptr) RemoveNode(nullptr, nullptr);

        while (tmp)
        {
            if (key == tmp->key)
            {
                flag = true;
                RemoveNode(parent, tmp);
                break;
            }
            else if (key <tmp->key)
            {
                parent = tmp;
                tmp = tmp->left;
            }
            else
            {
                parent = tmp;
                tmp = tmp->right;
            }
        }

        if (!flag)
            cout <<"Element doesn't exist in the table\n";
    }

    Node<T>* search(T key)
    {
        Node<T>* tmp = getRoot();
        if (tmp == nullptr)
            return nullptr;

        while (tmp)
        {
            if (key == tmp->key)  return tmp;
            else if (key <tmp->key) tmp = tmp->left;
            else  tmp = tmp->right;
        }
        return nullptr;
    }

    int& operator[](int key) {
        if (search(key))
            return search(key)->key;
        else
            throw "no matches!";
    }

};
