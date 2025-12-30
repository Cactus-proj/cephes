#include <cephes/prob.h>
#include <xtest.hpp>
#include <cmath>

TEST(pdtrc, Branches) {
    // k=0, m=1.0. 1 - e^-1
    EXPECT_NEAR(cephes::pdtrc(0, 1.0), 1.0 - std::exp(-1.0), 1e-15);
}
