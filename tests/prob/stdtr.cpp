#include <cephes/prob.h>
#include <xtest.hpp>

TEST(stdtr, Branches) {
    // k=1, t=0.0 -> 0.5
    EXPECT_NEAR(cephes::stdtr(1, 0.0), 0.5, 1e-15);
}
