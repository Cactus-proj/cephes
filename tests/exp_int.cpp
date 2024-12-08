#include <xtest.hpp>
#include <cephes/exp_int.h>


TEST(ExpN, Errors) {
    // n < 0
    EXPECT_TRUE(cephes::expn(-1, 10.0) > 1e308);
    // x < 0
    EXPECT_TRUE(cephes::expn(1, -1.0) > 1e308);
    // x > MAXLOG ≈ 709.78
    EXPECT_EQ(cephes::expn(1, 800), 0.0);
    // x==0 && n < 2
    EXPECT_TRUE(cephes::expn(1, 0.0) > 1e308);
    EXPECT_TRUE(cephes::expn(0, 0.0) > 1e308);
}
TEST(ExpN, CodecovTodo) {
    const double nan64 = std::numeric_limits<double>::quiet_NaN();

    // x==0.0 && n >= 2
    EXPECT_NE(cephes::expn(2, 0.0), nan64);
    EXPECT_NE(cephes::expn(10, 0.0), nan64);
    // n==0
    EXPECT_NE(cephes::expn(0, 10.0), nan64);
    // n > 5000
    EXPECT_NE(cephes::expn(5500, 10.0), nan64);
    // n <= 5000 && x > 1.0
    // cfrac: continued fraction
    EXPECT_NE(cephes::expn(10, 10.0), nan64);
    // Power series expansion
    EXPECT_NE(cephes::expn(1, 0.5), nan64);
    EXPECT_NE(cephes::expn(10, 0.5), nan64);
}


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


TEST(ShiChi, Errors) {
    int ret;
    double x, si, ci;

    // x == 0.0
    ret = cephes::shichi(0.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(si, 0.0);
    EXPECT_LT(ci, -1e308);
}
TEST(ShiChi, CodecovTodo) {
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
