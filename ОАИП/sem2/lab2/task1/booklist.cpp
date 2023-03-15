#include "booklist.h"

BookList::BookList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

void BookList::add(Node *book) {
    if (head == NULL && tail == NULL) {
        book->next = NULL;
        book->prev = NULL;
        head = book;
        tail = book;
        size++;
    } else {
        book->prev = tail;
        book->next = NULL;
        tail->next = book;
        tail = book;
        size++;
    }
}

bool BookList::del(int index) {
    if (index < 0 || index >= size) {
        return false;
    }
    if (size == 1) {
        delete head;
        head = NULL;
        tail = NULL;
    } else if (index == 0) {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
    } else if (index == size - 1) {
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
    } else {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        Node* previous = current->prev;
        previous->next = current->next;
        current->next->prev = previous;
        delete current;
    }
    size--;
    return true;
}
bool BookList::ins(Node* book, int index) {
    if (index < 0 || index > size) {
        return false;;
    }
    Node* newNode = new Node(*book);
    if (size == 0) {
        head = newNode;
        tail = newNode;
    } else if (index == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (index == size) {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    } else {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        Node* previous = current->prev;
        newNode->prev = previous;
        newNode->next = current;
        current->prev = newNode;
        previous->next = newNode;
    }
    size++;
    return true;
}


void BookList::debug() {
    Node* temp = head;
    while (temp != NULL) {
        qDebug() << temp->bookID << "\t" << temp->bookName << "\t" << temp->bookAuthor << "\t" << temp->bookPublisher << "\t" << temp->bookYear << "\t" << temp->bookPageAmount;
        temp = temp->next;
    }
    qDebug() << size;
}

void BookList::clear() {
    Node* current = head;
    while (current != NULL) {
        head = current->next;
        delete current;
        current = head;
    }
    tail = NULL;
    size = 0;
}

int BookList::getID(int index) {
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->bookID;
}

QString BookList::getName(int index) {
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->bookName;
}

QString BookList::getAuthor(int index) {
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->bookAuthor;
}

QString BookList::getPublisher(int index) {
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->bookPublisher;
}

int BookList::getYear(int index) {
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->bookYear;
}

int BookList::getPages(int index) {
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->bookPageAmount;
}

Node* merge(Node* left, Node* right, bool (*compare)(Node*, Node*)) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    if (compare(left, right)) {
        left->next = merge(left->next, right, compare);
        left->next->prev = left;
        left->prev = NULL;
        return left;
    } else {
        right->next = merge(left, right->next, compare);
        right->next->prev = right;
        right->prev = NULL;
        return right;
    }
}


void BookList::Sort(Node** head, bool (*compare)(Node*, Node*)) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    Node* left = *head;
    Node* right = (*head)->next;
    while (right != NULL) {
        right = right->next;
        if (right != NULL) {
            left = left->next;
            right = right->next;
        }
    }
    right = left->next;
    left->next = NULL;
    left = *head;
    Sort(&left, compare);
    Sort(&right, compare);
    *head = merge(left, right, compare);
}


int BookList::capacity() {
    return size;
}

Node* BookList::getHp() {
    return head;
}

Node* BookList::getNode(int index) {
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}
