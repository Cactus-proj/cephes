#include <cephes/bessel.h>
#include <xtest.hpp>

TEST(Airy, BasicAssertions) {
    const double nan64 = std::numeric_limits<double>::quiet_NaN();
    int ret;
    double x, ai, aip, bi, bip;

    x = 26.0;
    ret = cephes::airy(x, &ai, &aip, &bi, &bip);
    EXPECT_EQ(ret, -1);
    EXPECT_EQ(ai, 0.0);
    EXPECT_EQ(aip, 0.0);
    EXPECT_TRUE(bi > 1e308);
    EXPECT_TRUE(bip > 1e308);
}

TEST(Airy, SpecialValues) {
    const double inf64 = std::numeric_limits<double>::infinity();
    int ret;
    double x, ai, aip, bi, bip;

    // +Inf
    x = inf64;
    ret = cephes::airy(x, &ai, &aip, &bi, &bip);
    EXPECT_EQ(ret, -1);
    EXPECT_EQ(ai, 0.0);
    EXPECT_EQ(aip, 0.0);
    EXPECT_TRUE(bi > 1e308);
    EXPECT_TRUE(bip > 1e308);
}

TEST(Airy, ImplementationBranches) {
    int ret;
    double x, ai, aip, bi, bip;
    double ai_ref, aip_ref, bi_ref, bip_ref;

    // x < -2.09
    x = -5.0;
    ret = cephes::airy(x, &ai, &aip, &bi, &bip);
    EXPECT_EQ(ret, 0);
    /*
        x = -5.0;
        {NumberForm[AiryAi[x], 16], NumberForm[AiryAiPrime[x], 16],
        NumberForm[AiryBi[x], 16], NumberForm[AiryBiPrime[x], 16]}
     */
    ai_ref = 0.3507610090241144;
    aip_ref = 0.327192818554443;
    bi_ref = -0.1383691349016005;
    bip_ref = 0.7784117730018992;
    XTEST_ISAPPROX_F64(ai);
    XTEST_ISAPPROX_F64(aip);
    XTEST_ISAPPROX_F64(bi);
    XTEST_ISAPPROX_F64(bip);

    // -2.09 <= x < 2.09 (Power series)
    x = 0.0;
    ret = cephes::airy(x, &ai, &aip, &bi, &bip);
    EXPECT_EQ(ret, 0);
    /*
        x = 0.0;
        {NumberForm[AiryAi[x], 16], NumberForm[AiryAiPrime[x], 16],
        NumberForm[AiryBi[x], 16], NumberForm[AiryBiPrime[x], 16]}
     */
    ai_ref = 0.3550280538878173;
    aip_ref = -0.2588194037928068;
    bi_ref = 0.6149266274460007;
    bip_ref = 0.44828835735382633;
    XTEST_ISAPPROX_F64(ai);
    XTEST_ISAPPROX_F64(aip);
    XTEST_ISAPPROX_F64(bi);
    XTEST_ISAPPROX_F64(bip);

    x = 2.0;
    ret = cephes::airy(x, &ai, &aip, &bi, &bip);
    EXPECT_EQ(ret, 0);
    /*
        x = 2.0;
        {NumberForm[AiryAi[x], 16], NumberForm[AiryAiPrime[x], 16],
        NumberForm[AiryBi[x], 16], NumberForm[AiryBiPrime[x], 16]}
     */
    ai_ref = 0.03492413042327438;
    aip_ref = -0.05309038443365364;
    bi_ref = 3.298094999978214;
    bip_ref = 4.1006820499328835;
    XTEST_ISAPPROX_F64(ai);
    XTEST_ISAPPROX_F64(aip);
    XTEST_ISAPPROX_F64(bi);
    XTEST_ISAPPROX_F64(bip);

    // x >= 2.09 (cbrt(9))
    x = 5.0;
    ret = cephes::airy(x, &ai, &aip, &bi, &bip);
    EXPECT_EQ(ret, 0);
    /*
        x = 5.0;
        {NumberForm[AiryAi[x], 16], NumberForm[AiryAiPrime[x], 16],
        NumberForm[AiryBi[x], 16], NumberForm[AiryBiPrime[x], 16]}
     */
    ai_ref = 0.00010834442813607442;
    aip_ref = -0.0002474138908684624;
    bi_ref = 657.7920441711713;
    bip_ref = 1435.8190802179702;
    XTEST_ISAPPROX_F64(ai);
    XTEST_ISAPPROX_F64(aip);
    XTEST_ISAPPROX_F64(bi);
    XTEST_ISAPPROX_F64(bip);

    // x > 8.3203353
    x = 10.0;
    ret = cephes::airy(x, &ai, &aip, &bi, &bip);
    EXPECT_EQ(ret, 0);
    /*
        x = 10.0;
        {NumberForm[AiryAi[x], 16], NumberForm[AiryAiPrime[x], 16],
        NumberForm[AiryBi[x], 16], NumberForm[AiryBiPrime[x], 16]}
     */
    ai_ref = 1.1047532552898691e-10;
    aip_ref = -3.520633676738926e-10;
    bi_ref = 4.556411535482249e8;
    bip_ref = 1.4292361344828472e9;
    XTEST_ISAPPROX_F64(ai);
    XTEST_ISAPPROX_F64(aip);
    XTEST_ISAPPROX_F64(bi);
    XTEST_ISAPPROX_F64(bip);

    // Overflow
    x = 104.0;
    ret = cephes::airy(x, &ai, &aip, &bi, &bip);
    EXPECT_EQ(ret, -1);
    EXPECT_EQ(ai, 0.0);
    EXPECT_EQ(aip, 0.0);
    EXPECT_TRUE(bi > 1e308);
    EXPECT_TRUE(bip > 1e308);
}
