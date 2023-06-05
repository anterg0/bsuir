#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <list>

using namespace std;

template <class T1, class T2>
class NodeMap {
public:
    NodeMap(pair<T1, T2> p) :left(nullptr), right(nullptr), parent(nullptr), height(0)
    {
        this->p.first = p.first;
        this->p.second = p.second;
    }
    pair<T1, T2> p;
    NodeMap* left;
    NodeMap* right;
    NodeMap* parent;
    int height;
};

template <class T1, class T2>
class MyMap {
private:
    NodeMap<T1, T2>* root;
    list<NodeMap<T1, T2>*> tree_list;
    void in_list(NodeMap<T1, T2>* node)
    {
        if (node) {

            in_list(node->left);
            tree_list.push_back(node);
            in_list(node->right);
        }
    }

public:


    class Iterator_map
    {
    private:
        NodeMap<T1, T2>* curr_node;
        NodeMap<T1, T2>* root;

    public:

        Iterator_map(NodeMap<T1, T2>* root, NodeMap<T1, T2>* node): curr_node(root), root(node) {}

        Iterator_map& operator=(const Iterator_map& other)
        {
            this->root = other.root;
            this->curr_node = other.curr_node;

            return *this;
        }
        bool operator==(const Iterator_map& other) { return curr_node == other.curr_node; }
        bool operator!=(const Iterator_map& other) { return !(curr_node == other.curr_node); }
        pair<T1, T2>& operator*() { return curr_node->p; }

        Iterator_map& operator++()
        {
            if (curr_node == nullptr)
            {
                curr_node = root;

                if (curr_node == nullptr)
                    return *this;

                while (curr_node->left != nullptr)
                {
                    curr_node = curr_node->left;
                }
            }
            else if (curr_node->right != nullptr)
            {
                curr_node = curr_node->right;

                while (curr_node->left != nullptr)
                {
                    curr_node = curr_node->left;
                }
            }
            else {

                NodeMap<T1, T2>* p = curr_node->parent;
                while (p != nullptr && curr_node == p->right)
                {
                    curr_node = p;
                    p = p->parent;
                }
                curr_node = p;
            }
            return *this;
        }

        Iterator_map& operator--()
        {
            if (curr_node == nullptr) {
                curr_node = root;

                if (curr_node == nullptr)
                    return *this;

                while (curr_node->right != nullptr) {
                    curr_node = curr_node->right;
                }
            }
            else if (curr_node->left != nullptr) {
                curr_node = curr_node->left;

                while (curr_node->right != nullptr) {
                    curr_node = curr_node->right;
                }
            }
            else {
                NodeMap<T1, T2>* p = curr_node->parent;
                while (p != nullptr && curr_node == p->left) {
                    curr_node = p;
                    p = p->parent;
                }

                curr_node = p;
            }
            return *this;
        }
    };

    Iterator_map insertIt(pair<T1, T2> item)
    {
        MyMap<T1, T2>::insert_map(item);
        return Iterator_map(MyMap<T1, T2>::root);
    }
    Iterator_map erase(const T1& key)
    {
        MyMap<T1, T2>::remove_map(key);
        return Iterator_map(MyMap<T1, T2>::root);
    }
    Iterator_map begin()
    {
        NodeMap<T1, T2>* node = MyMap<T1, T2>::root;
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return Iterator_map(node, MyMap<T1, T2>::root);
    }
    Iterator_map end() { return Iterator_map(nullptr, MyMap<T1, T2>::root); }

    class IteratorList_map {

    private:
        list<NodeMap<T1, T2>> tree_list;
        typename list<NodeMap<T1, T2>*>::iterator it;
    public:
        IteratorList_map(const list<NodeMap<T1, T2>>& other, bool begin)
        {
            tree_list = other;
            if (begin) it = tree_list.begin();
            else it = tree_list.end();
        }
        list<NodeMap<T1,T2>> getList() { return tree_list; }
        pair<T1, T2> operator*() { return (*it)->p; }
        IteratorList_map& operator++()
        {
            ++it;
            return *this;
        }
        IteratorList_map& operator--()
        {
            --it;
            return *this;
        }
    };

    IteratorList_map begin_listIt()
    {
        tree_list.clear();
        in_list(MyMap<T1, T2>::root);
        return IteratorList_map(tree_list, true);
    }
    IteratorList_map end_listIt()
    {
        tree_list.clear();
        in_list(MyMap<T1, T2>::root);
        return IteratorList_map(tree_list, false);

    }



    MyMap() : root(nullptr) {}

    NodeMap<T1, T2>* getRoot_map() { return root; }
    int getHeight_map(NodeMap<T1, T2>* tmp) { return ((tmp == nullptr) ? -1 : tmp->height); }
    int getBalance_map(NodeMap<T1, T2>* temp) { return (getHeight_map(temp->right) - getHeight_map(temp->left)); }
    bool isEmpty() {
        return root == nullptr;
    }
    void insert_map(pair<T1, T2> elem_node)
    {
        if (root == nullptr)
        {
            root = new NodeMap<T1, T2>(elem_node);
            root->height = 0;
            root->parent = nullptr;
        }
        else {

            NodeMap<T1, T2>* curr_root = getRoot_map();
            NodeMap<T1, T2>* new_node = new NodeMap<T1, T2>(elem_node);

            while (curr_root != nullptr)
            {
                if (curr_root->p.first > elem_node.first)
                {
                    if (curr_root->left == nullptr)
                    {
                        curr_root->left = new_node;
                        new_node->height = 0;
                        new_node->parent = curr_root;
                        break;
                    }
                    else
                        curr_root = curr_root->left;
                }

                else if (curr_root->p.first < elem_node.first)
                {
                    if (curr_root->right == nullptr)
                    {
                        curr_root->right = new_node;
                        new_node->height = 0;
                        new_node->parent = curr_root;
                        break;
                    }
                    else
                        curr_root = curr_root->right;
                }
                else {
                    return;
                }
            }
            rebalancer_map(new_node);
        }
    }




    void heightBalance_map(NodeMap<T1, T2>* tmp)
    {
        int l = -1, r = -1;
        if (tmp->left)
            l = tmp->left->height;
        if (tmp->right)
            r = tmp->right->height;

        tmp->height = max(l, r) + 1;
    }


    void treeFix_map(NodeMap<T1, T2>* tmp)
    {
        if (getBalance_map(tmp) == 2)
        {
            if (getBalance_map(tmp->right) < 0)


                rightRotate_map(tmp->right);

            leftRotate_map(tmp);
            heightBalance_map(tmp);
        }
        else if (getBalance_map(tmp) == -2)
        {
            if (getBalance_map(tmp->left) > 0)


                leftRotate_map(tmp->left);

            rightRotate_map(tmp);
            heightBalance_map(tmp);
        }
    }


    void rebalancer_map(NodeMap<T1, T2>* tmp)
    {
        if (tmp == root)
            treeFix_map(root);
        else {
            while (tmp != nullptr) {
                heightBalance_map(tmp);
                tmp = tmp->parent;
                if (tmp)
                    treeFix_map(tmp);
            }
        }
    }

    void leftRotate_map(NodeMap<T1, T2>* x) {
        pair<T1, T2> temp{0, 0};
        NodeMap<T1, T2>* new_node = new NodeMap<T1, T2>(temp);
        if (x->right->left)
            new_node->right = x->right->left;

        new_node->left = x->left;
        new_node->p.first = x->p.first;
        new_node->p.second = x->p.second;
        x->p.second = x->right->p.second;
        x->p.first = x->right->p.first;

        x->left = new_node;

        if (new_node->left)
            new_node->left->parent = new_node;
        if (new_node->right)
            new_node->right->parent = new_node;

        new_node->parent = x;

        if (x->right->right)
            x->right = x->right->right;
        else
            x->right = nullptr;

        if (x->right)
            x->right->parent = x;

        heightBalance_map(x->left);
        if (x->right) { heightBalance_map(x->right); }
        heightBalance_map(x);
    }

    void rightRotate_map(NodeMap<T1, T2>* x) {
        pair<T1, T2> tmp{0, 0};
        NodeMap<T1, T2>* new_node = new NodeMap<T1, T2>(tmp);
        if (x->left->right)
            new_node->left = x->left->right;

        new_node->right = x->right;
        new_node->p.first = x->p.first;
        new_node->p.second = x->p.second;
        x->p.second = x->left->p.second;
        x->p.first = x->left->p.first;

        x->right = new_node;

        if (new_node->left)
            new_node->left->parent = new_node;

        if (new_node->right)
            new_node->right->parent = new_node;

        new_node->parent = x;

        if (x->left->left)
            x->left = x->left->left;
        else
            x->left = nullptr;

        if (x->left)
            x->left->parent = x;

        heightBalance_map(x->right);
        if (x->left) { heightBalance_map(x->left); }
        heightBalance_map(x);
    }

    void preorderTraversal_map(NodeMap<T1, T2>* temp)
    {
        if (temp == nullptr) return;
        cout << "->" << temp->p.first;
        preorderTraversal_map(temp->left);
        preorderTraversal_map(temp->right);
    }
    void postorderTraversal_map(NodeMap<T1, T2>* temp)
    {
        if (temp == nullptr) return;
        postorderTraversal_map(temp->left);
        postorderTraversal_map(temp->right);
        cout << "->" << temp->p.first;
    }
    void removeNode_map(NodeMap<T1, T2>* Parent, NodeMap<T1, T2>* curr, T1 key) {
        if (curr == nullptr)
            return;

        if (curr->p.first == key) {

            if (curr->left == nullptr && curr->right == nullptr) {
                if (Parent->p.first == curr->p.first)
                    root = nullptr;
                else if (Parent->right == curr)
                    Parent->right = nullptr;
                else
                    Parent->left = nullptr;
                rebalancer_map(Parent);
            }

            else if (curr->left != nullptr && curr->right == nullptr) {
                T1 sp = curr->p.first;
                curr->p.first = curr->left->p.first;
                curr->left->p.first = sp;
                removeNode_map(curr, curr->left, key);
            }
            else if (curr->left == nullptr && curr->right != nullptr) {
                T1 sp = curr->p.first;
                curr->p.first = curr->right->p.first;
                curr->right->p.first = sp;
                removeNode_map(curr, curr->right, key);
            }

            else {
                NodeMap<T1, T2>* temp = curr->right;
                int flag = 0;
                while (temp->left) {
                    flag = 1;
                    Parent = temp;
                    temp = temp->left;
                }
                if (!flag)
                    Parent = curr;

                T1 sp = curr->p.first;
                curr->p.first = temp->p.first;
                temp->p.first = sp;
                removeNode_map(Parent, temp, temp->p.first);
            }
        }
    }

    void remove_map(T1 key) {
        auto tmp = root;
        auto Parent = tmp;
        bool flag = false;

        if (tmp == nullptr)
            removeNode_map(nullptr, nullptr, key);

        while (tmp) {
            if (key == tmp->p.first) {
                flag = true;
                removeNode_map(Parent, tmp, key);
                break;
            }
            else if (key < tmp->p.first) {
                Parent = tmp;
                tmp = tmp->left;
            }
            else {
                Parent = tmp;
                tmp = tmp->right;
            }
        }

        if (!flag) cout << "Element doesn't exist in the table\n";
    }

    NodeMap<T1, T2>* search_map(T1 key)
    {
        NodeMap<T1, T2>* tmp = getRoot_map();
        if (tmp == nullptr) return nullptr;
        while (tmp) {
            if (key == tmp->p.first) return tmp;
            else if (key < tmp->p.first) tmp = tmp->left;
            else tmp = tmp->right;
        }
        return nullptr;
    }
    int& operator[](int key)
    {
        if (search_map(key)) return search_map(key)->p.second;
        else throw "no matches!";
    }

};

#endif
