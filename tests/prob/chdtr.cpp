#include <cephes/prob.h>
#include <xtest.hpp>
#include <cmath>

TEST(chdtr, Branches) {
    // df=2 is Exponential(0.5). CDF(x) = 1 - exp(-0.5*x)
    // x = 2*ln(2) -> 0.5*x = ln(2) -> exp = 0.5 -> CDF = 0.5
    EXPECT_NEAR(cephes::chdtr(2.0, 2.0 * std::log(2.0)), 0.5, 1e-15);
}
