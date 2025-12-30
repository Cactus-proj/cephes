#include <cephes/prob.h>
#include <xtest.hpp>

TEST(fdtrc, Branches) {
    // F(10, 10) median is 1.0.
    EXPECT_NEAR(cephes::fdtrc(10, 10, 1.0), 0.5, 1e-15);
}
