#include <cephes/elliptic.h>
#include <xtest.hpp>

TEST(EllipticKInc, SpecialValues) {
    // m = 0 -> F(phi, 0) = phi
    EXPECT_REL_NEAR_F64(cephes::ellik(1.0, 0.0), 1.0);
    // phi = 0 -> F(0, m) = 0
    EXPECT_REL_NEAR_F64(cephes::ellik(0.0, 0.5), 0.0);
}

TEST(EllipticKInc, ImplementationBranches) {
    // Code: if (m == 0.0) return (phi);
    EXPECT_REL_NEAR_F64(cephes::ellik(0.5, 0.0), 0.5);
    
    // Code: a = 1.0 - m; if (a == 0.0) ... return (log(tan((PIO2 + phi) / 2.0)));
    // m == 1.0 (a == 0.0) -> log(tan((PIO2 + phi) / 2.0)) = atanh(sin(phi))
    double phi = 0.5;
    double expected = std::log(std::tan((1.5707963267948966 + phi) / 2.0));
    EXPECT_REL_NEAR_F64(cephes::ellik(phi, 1.0), expected);

    // Negative phi
    // Wolfram result: EllipticF[-0.5, 0.5] = -0.5104671356280047
    EXPECT_REL_NEAR_F64(cephes::ellik(-0.5, 0.5), -0.5104671356280047);

    // Large tan(phi) (phi=1.5, tan(1.5)~14 > 10)
    // Wolfram result: EllipticF[1.5, 0.5] = 1.754036916866746
    EXPECT_REL_NEAR_F64(cephes::ellik(1.5, 0.5), 1.754036916866746);

    // Large phi (> PI/2), periodicity check
    // Wolfram result: EllipticF[3.5, 0.5] = 4.070404266410484
    EXPECT_REL_NEAR_F64(cephes::ellik(3.5, 0.5), 4.070404266410484);
}
