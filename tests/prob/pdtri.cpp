#include <cephes/prob.h>
#include <xtest.hpp>
#include <cmath>

TEST(pdtri, Branches) {
    // k=0, y=P(X<=0)=e^-1 (approx 0.367). m should be 1.0
    // pdtr(0, m) = e^-m.
    // pdtri(0, y) -> y = e^-m -> ln(y) = -m -> m = -ln(y).
    EXPECT_NEAR(cephes::pdtri(0, std::exp(-1.0)), 1.0, 1e-15);
}
