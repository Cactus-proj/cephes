#include <cephes/prob.h>
#include <xtest.hpp>

TEST(nbdtr, Branches) {
    // k=0, n=1, p=0.5. P(0 failures before 1 success) = 0.5
    EXPECT_NEAR(cephes::nbdtr(0, 1, 0.5), 0.5, 1e-15);
}
