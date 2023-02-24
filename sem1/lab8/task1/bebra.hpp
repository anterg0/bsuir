#ifndef bebra_hpp
#define bebra_hpp

#include <stdio.h>

struct Zavod {
    struct {
        int cehID;
        int workersNum;
    } ceh;
    struct {
        char name[300]{};
        int quantity;
        int failedQuantity;
    } product;
    bool deleted = false;
};

void func1();
void func2();
void func3();
void func4();
void func5();
void func6();
void func7();
void func8();

#endif
