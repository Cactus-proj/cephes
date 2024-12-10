#include <cephes/exp_int.h>
#include <xtest.hpp>

TEST(ShiChi, Errors)
{
    int ret;
    double x, si, ci;

    // x == 0.0
    ret = cephes::shichi(0.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(si, 0.0);
    EXPECT_LT(ci, -1e308);
}
TEST(ShiChi, CodecovTodo)
{
    const double nan64 = std::numeric_limits<double>::quiet_NaN();
    int ret;
    double x, si, ci;

    // x < 0.0
    ret = cephes::shichi(-1.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_NE(si, nan64);
    EXPECT_NE(ci, nan64);

    // x >= 8.0
    // chb:
    ret = cephes::shichi(8.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_NE(si, nan64);
    EXPECT_NE(ci, nan64);
    // x < 18.0
    ret = cephes::shichi(15.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_NE(si, nan64);
    EXPECT_NE(ci, nan64);
    // 18.0 <= x <= 88.0
    ret = cephes::shichi(18.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_NE(si, nan64);
    EXPECT_NE(ci, nan64);
    ret = cephes::shichi(88.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_NE(si, nan64);
    EXPECT_NE(ci, nan64);
    // x > 88.0
    ret = cephes::shichi(100.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_NE(si, nan64);
    EXPECT_NE(ci, nan64);

    // x < 8.0
    // power series expansion
    ret = cephes::shichi(3.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_NE(si, nan64);
    EXPECT_NE(ci, nan64);
}
