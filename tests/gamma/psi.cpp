#include <cephes/gamma.h>
#include <xtest.hpp>

/*
    Table[NumberForm[PolyGamma[0, x], 16],
        {x, {0.0, -10., 1.0, 8.0, 9.0, 10.0, 100.}}]
*/
TEST(DiGammaPsi, Branches)
{
    EXPECT_GT(cephes::psi(0.0), 1.0e308); // +Inf
}
