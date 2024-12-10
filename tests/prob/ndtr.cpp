#include <cephes/prob.h>
#include <xtest.hpp>

TEST(ndtr, Branches)
{
    EXPECT_GT(cephes::ndtr(0.1), 0.0);
}
