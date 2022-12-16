#import <XCTest/XCTest.h>
#include "/Users/anterg0/Documents/bsuir/lab6/task6/task6/task6/main.cpp"
@interface test : XCTestCase

@end

@implementation test

- (void) test1 {
    char s[15]{'S','O','L','O'};
    XCTAssert(answer(s) == 12);
}

- (void) test2 {
    char s2[15]{'S','O','l','o'};
    XCTAssert(answer(s2) == 12);
}

- (void) test3 {
    char s3[15]{'B','e','b','R','a'};
    XCTAssert(answer(s3) == 60);
}

@end
