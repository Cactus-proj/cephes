#include <cephes/prob.h>
#include <xtest.hpp>

TEST(smirnov, Branches) {
    EXPECT_GT(cephes::smirnov(10, 0.1), 0.0);
    EXPECT_LT(cephes::smirnov(10, 0.1), 1.0);
}
