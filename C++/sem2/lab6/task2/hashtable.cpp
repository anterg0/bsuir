#include <iostream>

class HashTable {
private:
    std::vector<int> table;
    std::vector<std::string> collisions;
    int modulo;

    int hash(int key) {
        return key % modulo;
    }

    void rehash() {
        std::vector<int> oldTable = table;
        table.assign(modulo, -1);
        collisions.clear();
        for (int i = 0; i < oldTable.size(); ++i) {
            if (oldTable[i] != -1) {
                this->insert(oldTable[i]);
            }
        }
    }

public:
    HashTable(int size) : table(size, -1), collisions(size), modulo(size) {}

    void setModulo(int value) {
        modulo = value;
        rehash();
    }

    void insert(int key) {
        int index = hash(key);

        if (table[index] == -1) {
            table[index] = key;
        } else {
            int collisionIndex = (index + 1) % modulo;

            while (collisionIndex != index && table[collisionIndex] != -1) {
                collisionIndex = (collisionIndex + 1) % modulo;
            }

            if (collisionIndex == index) {
                std::cout << "Table is full. Unable to insert key: " << key << std::endl;
            } else {
                table[collisionIndex] = key;
                collisions.push_back("Collision at index " + std::to_string(index) + ": " + std::to_string(key));
            }
        }
    }

    void printTable() {
        for (int i = 0; i < table.size(); ++i) {
            std::cout << "Index " << i << ": ";

            if (table[i] != -1) {
                std::cout << table[i];
            } else {
                std::cout << "-";
            }

            std::cout << std::endl;
        }
        for (auto collision : collisions) {
            if (!(collision.empty())) {
                std::cout << collision << std::endl;
            }
        }
    }
    int search(int key) {
        int index = hash(key);
        int collisionIndex = index;

        while (table[collisionIndex] != -1) {
            if (table[collisionIndex] == key) {
                return table[collisionIndex];
            }
            collisionIndex = (collisionIndex + 1) % modulo;

            if (collisionIndex == index) {
                break;
            }
        }

        return -1;
    }
    int operator[](int index) {
        return table[index];
    }
    int getSize() {
        return table.size();
    }
};
