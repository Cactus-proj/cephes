#include <xtest.hpp>
#include <cephes/gamma.h>


TEST(Beta, BasicAssertions) {
}
TEST(Beta, Branches) {
    EXPECT_GT(cephes::beta(0.0, 0.0), 1.0e308);  // +Inf
}
