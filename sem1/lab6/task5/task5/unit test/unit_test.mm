
#import <XCTest/XCTest.h>
#include "/Users/anterg0/Documents/bsuir/lab6/task5/task5/task5/main.cpp"

@interface unit_test : XCTestCase

@end

@implementation unit_test

- (void)test1 {
    std::string s1,s2;
    s1 = "edge";
    s2 = "geed";
    XCTAssert(answer(1000000000, s1, s2) % 10000 == 8352);
}

- (void)test2 {
    std::string s1,s2;
    s1 = "eye";
    s2 = "eye";
    XCTAssert((answer(3,s1,s2) % 10) == 1);
}

- (void)test3 {
    std::string s1,s2;
    s1 = "edge";
    s2 = "geed";
    XCTAssert((answer(6,s1,s2) % 10) == 2);
}
@end
