
#import <XCTest/XCTest.h>
#include "/Users/anterg0/Documents/bsuir/lab5/task3/task3/main.cpp"
@interface tests : XCTestCase

@end

@implementation tests

- (void)test1 {
    int **arr = new int*[2];
    arr[0] = new int[2]{2,2};
    arr[1] = new int[2]{2,2};
    XCTAssert(Multiplication(arr, 2, 2) == 16);
}

- (void)test2 {
    int **arr = new int*[2];
    arr[0] = new int[3]{2,3,10};
    arr[1] = new int[3]{1,6,12};
    XCTAssert(Multiplication(arr, 2, 3) == 4320);
}

- (void)test3 {
    int **arr = new int*[2];
    arr[0] = new int[4]{30,103,1,3};
    arr[1] = new int[4]{30,9,3,10};
    XCTAssert(Multiplication(arr, 2, 4) == 75087000);
}

@end
