#include <xtest.hpp>
#include <cephes/exp_int.h>


TEST(SiCi, Errors) {
    int ret;
    double x, si, ci;

    // x == 0.0
    ret = cephes::sici(0.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(si, 0.0);
    EXPECT_LT(ci, -1e308);
}
TEST(SiCi, CodecovTodo) {
    const double nan64 = std::numeric_limits<double>::quiet_NaN();
    int ret;
    double x, si, ci;

    // x < 0.0
    ret = cephes::sici(-1.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_NE(si, nan64);
    EXPECT_NE(ci, nan64);

    // x > 1.0e9
    ret = cephes::sici(1e10, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_NE(si, nan64);
    EXPECT_NE(ci, nan64);

    // x > 4.0
    // asympt
    ret = cephes::sici(5.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_NE(si, nan64);
    EXPECT_NE(ci, nan64);
    // x >= 8.0
    ret = cephes::sici(8.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_NE(si, nan64);
    EXPECT_NE(ci, nan64);

    // x <= 4.0
    // asympt
    ret = cephes::sici(3.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_NE(si, nan64);
    EXPECT_NE(ci, nan64);
}
