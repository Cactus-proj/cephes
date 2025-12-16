#include <xtest.hpp>
#include <cephes/elliptic.h>


TEST(EllipticJaco, Branches) {
    double u, m, sn, cn, dn, ph;
    // m < 0.0 || m > 1.0
    u = 1.0;
    EXPECT_REL_NEAR_F64(cephes::ellpj(u, -1.0, &sn, &cn, &dn, &ph), -1);
    EXPECT_REL_NEAR_F64(cephes::ellpj(u, 2.0, &sn, &cn, &dn, &ph), -1);
}
