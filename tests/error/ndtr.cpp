#include <xtest.hpp>
#include <cephes/error.h>


TEST(ndtr, Branches) {
    EXPECT_GT(cephes::ndtr(0.1), 0.0);
}
