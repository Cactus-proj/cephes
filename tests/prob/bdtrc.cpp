#include <cephes/prob.h>
#include <xtest.hpp>

TEST(bdtrc, Branches) {
    // k=1, n=2, p=0.5. P(X>1) = P(X=2) = 0.25
    EXPECT_NEAR(cephes::bdtrc(1, 2, 0.5), 0.25, 1e-15);
}
