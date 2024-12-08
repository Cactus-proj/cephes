#include <limits>
#include <complex>
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

TEST(Airy, Branches) {
    int ret;
    double x, ai, aip, bi, bip, ref;
    double ai_ref, aip_ref, bi_ref, bip_ref;

    // x < -2.09
    x = -3.0;
    ret = cephes::airy(x, &ai, &aip, &bi, &bip);
    EXPECT_EQ(ret, 0);
    /*
        x = -3.0;
        {NumberForm[AiryAi[x], 16], NumberForm[AiryAiPrime[x], 16],
        NumberForm[AiryBi[x], 16], NumberForm[AiryBiPrime[x], 16]}
     */
    ai_ref  = -0.378814293677658;
    aip_ref =  0.3145837692165989; 
    bi_ref  = -0.1982896263749266; 
    bip_ref = -0.6756112226852585;
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
    ai_ref  =  0.0001083444281360744;
    aip_ref = -0.0002474138908684624; 
    bi_ref  =  657.7920441711713; 
    bip_ref =  1435.81908021797;
    XTEST_ISAPPROX_F64(ai);
    XTEST_ISAPPROX_F64(aip);
    XTEST_ISAPPROX_F64(bi);
    XTEST_ISAPPROX_F64(bip);

    // x > 8.3203353
    x = 8.5;
    ret = cephes::airy(x, &ai, &aip, &bi, &bip);
    EXPECT_EQ(ret, 0);
    /*
        x = 8.5;
        {NumberForm[AiryAi[x], 16], NumberForm[AiryAiPrime[x], 16],
         NumberForm[AiryBi[x], 16], NumberForm[AiryBiPrime[x], 16]}
     */
    ai_ref  =  1.099700975519552e-8;
    aip_ref = -3.237725440447604e-8; 
    bi_ref  =  4.965319541471301e6; 
    bip_ref =  1.432630103066198e7;
    XTEST_ISAPPROX_F64(ai);
    XTEST_ISAPPROX_F64(aip);
    XTEST_ISAPPROX_F64(bi);
    XTEST_ISAPPROX_F64(bip);
}

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
