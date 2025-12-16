#include <cephes/error.h>
#include <xtest.hpp>

TEST(ErfC, Branches) {
    // z < -MAXLOG && a < 0
    EXPECT_REL_NEAR_F64(cephes::erfc(-20.0), 2.0);
}
