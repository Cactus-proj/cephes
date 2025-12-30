#include <cephes/prob.h>
#include <xtest.hpp>
#include <cmath>

TEST(chdtri, Branches) {
    EXPECT_NEAR(cephes::chdtri(2.0, 0.5), 2.0 * std::log(2.0), 1e-15);
}
