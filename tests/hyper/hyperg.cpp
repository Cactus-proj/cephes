#include <xtest.hpp>
#include <cephes/hyper.h>


TEST(Hyp2f1, Branches) {
    EXPECT_GT(cephes::hyperg(1.0, 2.0, 3.0), 0.0);
}
