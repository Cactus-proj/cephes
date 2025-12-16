#include <cephes/error.h>
#include <xtest.hpp>

TEST(Dawson, Branches) { EXPECT_GT(cephes::dawsn(1.0), 0.0); }
