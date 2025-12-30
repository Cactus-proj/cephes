#include <cephes/prob.h>
#include <xtest.hpp>

TEST(ndtri, Branches) {
    EXPECT_NEAR(cephes::ndtri(0.5), 0.0, 1e-15);
}
