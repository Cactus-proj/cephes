#include <cephes/prob.h>
#include <xtest.hpp>

TEST(stdtri, Branches) {
    // k=1, p=0.5 -> t=0.0
    EXPECT_NEAR(cephes::stdtri(1, 0.5), 0.0, 1e-15);
}
