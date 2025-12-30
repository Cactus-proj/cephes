#include <cephes/prob.h>
#include <xtest.hpp>

TEST(smirnovi, Branches) {
    EXPECT_GT(cephes::smirnovi(10, 0.5), 0.0);
}
