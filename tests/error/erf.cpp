#include <cephes/error.h>
#include <xtest.hpp>

TEST(Erf, Branches)
{
    // fabs(x) > 1.0
    EXPECT_REL_NEAR_F64(cephes::erf(20.0), 1.0);
}
