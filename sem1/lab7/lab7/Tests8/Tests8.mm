#import <XCTest/XCTest.h>
#include "/Users/anterg0/Documents/bsuir/lab7/lab7/task8/main.cpp"

@interface Tests8 : XCTestCase

@end

@implementation Tests8

- (void) test1 {
    XCTAssert(convertTo3(999999) == "1212133131223");
}

- (void) test2 {
    XCTAssert(convertTo3(777777777) == "1222312111312111323");
}

- (void) test3 {
    XCTAssert(convertTo3(999999999999999999) == "13122212213313233323123313213211312223");
}

@end
