#include <cephes/prob.h>
#include <xtest.hpp>

TEST(bdtri, Branches) {
    // k=1, n=2, y=0.75 -> p=0.5
    EXPECT_NEAR(cephes::bdtri(1, 2, 0.75), 0.5, 1e-15);
}
