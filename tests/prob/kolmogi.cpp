#include <cephes/prob.h>
#include <xtest.hpp>

TEST(kolmogi, Branches) {
    EXPECT_GT(cephes::kolmogi(0.5), 0.0);
}
