#include <cephes/elliptic.h>
#include <xtest.hpp>

TEST(EllipticJaco, Branches) {
    double u, m, sn, cn, dn, ph;
    // m < 0.0 || m > 1.0
    u = 1.0;
    EXPECT_REL_NEAR_F64(cephes::ellpj(u, -1.0, &sn, &cn, &dn, &ph), -1);
    EXPECT_REL_NEAR_F64(cephes::ellpj(u, 2.0, &sn, &cn, &dn, &ph), -1);
}

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
