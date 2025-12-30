#include <cephes/prob.h>
#include <xtest.hpp>

TEST(fdtri, Branches) {
    // F(10, 10) median is 1.0.
    // Assuming fdtri is inverse of fdtrc (complement)
    EXPECT_NEAR(cephes::fdtri(10, 10, 0.5), 1.0, 1e-15);
}
