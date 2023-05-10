
#import <XCTest/XCTest.h>
#include "/Users/anterg0/Documents/bsuir/lab5/task4/task4/main.cpp"
@interface tests : XCTestCase

@end

@implementation tests

- (void)test1 {
    double** array = new double*[2];
    array[0] = new double[2]{3.333,0.903};
    array[1] = new double[2]{0,3};
    XCTAssert(ZeroCount(array,2,2) == 1);
}

- (void)test2 {
    double** array = new double*[3];
    array[0] = new double[2]{0.0000000000001,0};
    array[1] = new double[2]{0.123,0};
    array[2] = new double[2]{0,0};
    XCTAssert(ZeroCount(array,3,2) == 4);
}

- (void)test3 {
    double** array = new double*[2];
    array[0] = new double[3]{90.503,0,123};
    array[1] = new double[3]{0,3,0};
    XCTAssert(ZeroCount(array,2,3) == 3);
}

@end
