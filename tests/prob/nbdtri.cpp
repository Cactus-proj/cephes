#include <cephes/prob.h>
#include <xtest.hpp>

TEST(nbdtri, Branches) {
    // k=0, n=1, y=0.5. p=0.5
    EXPECT_NEAR(cephes::nbdtri(0, 1, 0.5), 0.5, 1e-15);
}
