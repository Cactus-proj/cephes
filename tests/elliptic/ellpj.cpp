#include <cephes/elliptic.h>
#include <xtest.hpp>

TEST(EllipticJaco, SpecialValues) {
    double sn, cn, dn, ph;
    // u = 0 -> sn=0, cn=1, dn=1
    cephes::ellpj(0.0, 0.5, &sn, &cn, &dn, &ph);
    EXPECT_REL_NEAR_F64(sn, 0.0);
    EXPECT_REL_NEAR_F64(cn, 1.0);
    EXPECT_REL_NEAR_F64(dn, 1.0);
    
    // m = 0 -> sn=sin(u), cn=cos(u), dn=1
    double u = 1.0;
    cephes::ellpj(u, 0.0, &sn, &cn, &dn, &ph);
    EXPECT_REL_NEAR_F64(sn, std::sin(u));
    EXPECT_REL_NEAR_F64(cn, std::cos(u));
    EXPECT_REL_NEAR_F64(dn, 1.0);
}

TEST(EllipticJaco, ImplementationBranches) {
    double sn, cn, dn, ph;
    double u = 0.5, m;

    // m < 0.0 || m > 1.0
    u = 1.0;
    EXPECT_REL_NEAR_F64(cephes::ellpj(u, -1.0, &sn, &cn, &dn, &ph), -1);
    EXPECT_REL_NEAR_F64(cephes::ellpj(u, 2.0, &sn, &cn, &dn, &ph), -1);

    // Code: if (m < 1.0e-9) ...
    // m < 1.0e-9 -> Small m approximation
    double m_small = 1e-10;
    cephes::ellpj(u, m_small, &sn, &cn, &dn, &ph);
    // sn approx sin(u)
    EXPECT_NEAR(sn, std::sin(u), 1e-9);

    // Code: if (m >= 0.9999999999) ...
    // m >= 0.9999999999 -> m near 1 approximation
    double m_near_1 = 0.99999999995;
    cephes::ellpj(u, m_near_1, &sn, &cn, &dn, &ph);
    // sn approx tanh(u)
    EXPECT_NEAR(sn, std::tanh(u), 1e-8);

    // Generic case to trigger AGM loop
    // Wolfram result: sn(0.5, 0.5) = 0.4707504736556571, cn(0.5, 0.5) = 0.88226639489044
    // dn(0.5, 0.5) = 0.942972425777386, phi(0.5, 0.5) = 0.490141205414255
    cephes::ellpj(0.5, 0.5, &sn, &cn, &dn, &ph);
    EXPECT_REL_NEAR_F64(sn, 0.4707504736556571);
    EXPECT_REL_NEAR_F64(cn, 0.88226639489044);
    EXPECT_REL_NEAR_F64(dn, 0.942972425777386);
    EXPECT_REL_NEAR_F64(ph, 0.490141205414255);
}
