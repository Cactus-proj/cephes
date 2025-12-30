#include <cephes/bessel.h>
#include <xtest.hpp>

/*
In[]:= Table[NumberForm[BesselK[0,x],16],
            {x,{-2.7,-1.,0.,1.,2.,3.14}}]
Out[]= {0.04925540091581759-12.06890248572984 I,
    0.4210244382407083-3.977463260506422 I,
    \[Infinity],
    0.4210244382407083,
    0.1138938727495334,
    0.02956274724299548}
*/
TEST(BesselK0, Branches) {
    // x <= 0.0
    EXPECT_GT(cephes::k0(-2.7), 1.0e308); // DOMAIN error
    EXPECT_GT(cephes::k0(-1.0), 1.0e308); // DOMAIN error
    EXPECT_GT(cephes::k0(0.0), 1.0e308);  // DOMAIN error

    // x <= 2.0
    EXPECT_REL_NEAR_F64(cephes::k0(1.0), 0.4210244382407083);
    EXPECT_REL_NEAR_F64(cephes::k0(2.0), 0.1138938727495334);

    // x > 2.0
    EXPECT_REL_NEAR_F64(cephes::k0(3.14),  0.02956274724299548);
}
