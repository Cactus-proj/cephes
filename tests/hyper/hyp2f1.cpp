#include <xtest.hpp>
#include <cephes/hyper.h>


TEST(Hyp2f1, Errors) {
    double a, b, c, x, y, y_ref;

    // c is a negative integer
    // hypdiv:
    EXPECT_GT(cephes::hyp2f1(2.0, 3.0, -4.0, 5.0), 1e308);
    // ax > 1.0
    EXPECT_GT(cephes::hyp2f1(2.0, 3.0, 4.0, 2.0), 1e308);
}

TEST(Hyp2f1, Branches) {
    double a, b, c, x, y, y_ref;
}
