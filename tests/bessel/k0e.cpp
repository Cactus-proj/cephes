#include <cephes/bessel.h>
#include <xtest.hpp>

/*
In[]:= Table[NumberForm[Exp[Abs[x]]*BesselK[0,x],16],
            {x,{-2.7,-1.,0.,1.,2.,3.14}}]
Out[]= {
    0.7329071516284216-179.582031201311 I,
    1.144463079806895-10.81186610439807 I,
    \[Infinity],
    1.144463079806895,0.841568215070771,0.683013776280224}
*/
TEST(BesselK0Exp, Branches) {
    // x <= 0.0
    EXPECT_GT(cephes::k0e(-2.7), 1.0e308); // DOMAIN error
    EXPECT_GT(cephes::k0e(-1.0), 1.0e308); // DOMAIN error
    EXPECT_GT(cephes::k0e(0.0), 1.0e308);  // DOMAIN error

    // x <= 2.0
    EXPECT_REL_NEAR_F64(cephes::k0e(1.0), 1.144463079806895);
    EXPECT_REL_NEAR_F64(cephes::k0e(2.0), 0.841568215070771);

    // x > 2.0
    EXPECT_REL_NEAR_F64(cephes::k0e(3.14), 0.683013776280224);
}
