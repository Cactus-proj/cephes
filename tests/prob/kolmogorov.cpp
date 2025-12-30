#include <cephes/prob.h>
#include <xtest.hpp>

TEST(kolmogorov, Branches) {
    EXPECT_GT(cephes::kolmogorov(1.0), 0.0);
    EXPECT_LT(cephes::kolmogorov(1.0), 1.0);
}
