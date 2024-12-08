#include <limits>
#include <complex>
#include <gtest/gtest.h>
#include <cephes/bessel.h>

TEST(Airy, BasicAssertions) {
  const double nan64 = std::numeric_limits<double>::quiet_NaN();
  int ret;
  double x, ai, aip, bi, bip;

  x = 26.0;
  ret = airy(x, &ai, &aip, &bi, &bip);
  EXPECT_EQ(ret, -1);
  EXPECT_EQ(ai, 0.0);
  EXPECT_EQ(aip, 0.0);
  EXPECT_TRUE(bi > 1e308);
  EXPECT_TRUE(bip > 1e308);
}
