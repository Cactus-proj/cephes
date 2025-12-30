#include <cephes/prob.h>
#include <xtest.hpp>

TEST(bdtr, Branches) {
    // k=1, n=2, p=0.5. P(X<=1) = 0.75
    EXPECT_NEAR(cephes::bdtr(1, 2, 0.5), 0.75, 1e-15);
}
