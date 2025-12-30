#include <cephes/prob.h>
#include <xtest.hpp>

TEST(nbdtrc, Branches) {
    // k=0, n=1, p=0.5. 1-0.5=0.5
    EXPECT_NEAR(cephes::nbdtrc(0, 1, 0.5), 0.5, 1e-15);
}
