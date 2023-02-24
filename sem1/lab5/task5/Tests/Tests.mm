
#import <XCTest/XCTest.h>
#include "/Users/anterg0/Documents/bsuir/lab5/task5/task5/main.cpp"
@interface tests : XCTestCase

@end

@implementation tests

- (void)test1 {
    double** array = new double*[2];
    array[0] = new double[2]{3.25,10};
    array[1] = new double[2]{0,5};
    XCTAssert(AverageArth(array, 2, 2) == 4.5625);
}

- (void)test2 {
    double** array = new double*[3];
    array[0] = new double[2]{0.75,6};
    array[1] = new double[2]{0.5,3};
    array[2] = new double[2]{9,13};
    XCTAssert(AverageArth(array,3,2) == 5.375);
}

- (void)test3 {
    double** array = new double*[2];
    array[0] = new double[3]{90,0,123};
    array[1] = new double[3]{0,3,6};
    XCTAssert(AverageArth(array, 2, 3) == 37);
}

@end
