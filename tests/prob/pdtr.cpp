#include <cephes/prob.h>
#include <xtest.hpp>
#include <cmath>

TEST(pdtr, Branches) {
    // k=0, m=1.0. P(X=0) = e^-1
    EXPECT_NEAR(cephes::pdtr(0, 1.0), std::exp(-1.0), 1e-15);
}
