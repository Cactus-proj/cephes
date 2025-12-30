#include <cephes/prob.h>
#include <xtest.hpp>
#include <cmath>

TEST(chdtrc, Branches) {
    // df=2, x=2*ln(2) -> chdtr=0.5 -> chdtrc=0.5
    EXPECT_NEAR(cephes::chdtrc(2.0, 2.0 * std::log(2.0)), 0.5, 1e-15);
}
