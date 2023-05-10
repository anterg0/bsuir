#import <XCTest/XCTest.h>
#include "/Users/anterg0/Documents/bsuir/lab7/lab7/task5/main.cpp"

@interface Tests5 : XCTestCase

@end

@implementation Tests5

- (void) test1 {
    XCTAssert(bebrochka(999999999) == 100000000);
}

- (void) test2 {
    XCTAssert(bebrochka(123456789) == 12345679);
}

- (void) test3 {
    XCTAssert(bebrochka(987654321) == 98765432);
}

@end
