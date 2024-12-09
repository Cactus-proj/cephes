#include <xtest.hpp>
#include <cephes/error.h>


TEST(Dawson, Branches) {
    EXPECT_GT(cephes::dawsn(1.0), 0.0);
}
