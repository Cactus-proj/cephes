#include <cephes/gamma.h>
#include <xtest.hpp>

TEST(Gamma, BasicAssertions)
{
    EXPECT_TRUE(std::isnan(cephes::gamma(xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::gamma(-xtest::NaN64)));
    EXPECT_TRUE(std::isinf(cephes::gamma(xtest::Inf64)));
    EXPECT_TRUE(std::isnan(cephes::gamma(-xtest::Inf64))); // gamma(-Inf) == NaN
    EXPECT_TRUE(std::isnan(cephes::gamma(0.0)));

    EXPECT_REL_NEAR_F64(cephes::gamma(1.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(2.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(3.0), 2.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(10.0), 362880.0);
}

TEST(Gamma, BranchCov)
{
    // fabs(x) > 33.0 && x < 0.0
    EXPECT_REL_NEAR_F64(cephes::gamma(-33.1), 8.23969199675675e-37);

    // while (x < 0.0)
    EXPECT_REL_NEAR_F64(cephes::gamma(-0.5), -3.544907701811032);
    // while (x < 0.0) && x > -1.E-9
    EXPECT_REL_NEAR_F64(cephes::gamma(-1.0e-100), -1.0e100);
    EXPECT_REL_NEAR_F64(cephes::gamma(-1.0e-300), -1.0e300);
    // small:  x < 1.e-9 && x != 0.0
    EXPECT_REL_NEAR_F64(cephes::gamma(1.0e-10), 9.999999999422785e9);
    EXPECT_REL_NEAR_F64(cephes::gamma(1.0e-100), 1.0e100);
    EXPECT_REL_NEAR_F64(cephes::gamma(1.0e-300), 1.0e300);
}

/* Julia + SpecialFunctions (MPFR 4.2.0)
```jl
using SpecialFunctions
for i in 1:50
    gam = gamma(BigInt(i)/10)
    f64 = Float64(gam)
    println("EXPECT_REL_NEAR_F64(cephes::gamma($i/10.0), $f64);")
end
```
*/
// TABLE 3.11 Gamma Function
TEST(Gamma, CoSF_Table_3p1) {
    EXPECT_REL_NEAR_F64(cephes::gamma(1/10.0), 9.513507698668732);
    EXPECT_REL_NEAR_F64(cephes::gamma(2/10.0), 4.5908437119988035);
    EXPECT_REL_NEAR_F64(cephes::gamma(3/10.0), 2.991568987687591);
    EXPECT_REL_NEAR_F64(cephes::gamma(4/10.0), 2.218159543757688);
    EXPECT_REL_NEAR_F64(cephes::gamma(5/10.0), 1.772453850905516);
    EXPECT_REL_NEAR_F64(cephes::gamma(6/10.0), 1.489192248812817);
    EXPECT_REL_NEAR_F64(cephes::gamma(7/10.0), 1.2980553326475577);
    EXPECT_REL_NEAR_F64(cephes::gamma(8/10.0), 1.1642297137253035);
    EXPECT_REL_NEAR_F64(cephes::gamma(9/10.0), 1.0686287021193193);
    EXPECT_REL_NEAR_F64(cephes::gamma(10/10.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(11/10.0), 0.9513507698668732);
    EXPECT_REL_NEAR_F64(cephes::gamma(12/10.0), 0.9181687423997607);
    EXPECT_REL_NEAR_F64(cephes::gamma(13/10.0), 0.8974706963062772);
    EXPECT_REL_NEAR_F64(cephes::gamma(14/10.0), 0.8872638175030753);
    EXPECT_REL_NEAR_F64(cephes::gamma(15/10.0), 0.886226925452758);
    EXPECT_REL_NEAR_F64(cephes::gamma(16/10.0), 0.8935153492876903);
    EXPECT_REL_NEAR_F64(cephes::gamma(17/10.0), 0.9086387328532904);
    EXPECT_REL_NEAR_F64(cephes::gamma(18/10.0), 0.9313837709802427);
    EXPECT_REL_NEAR_F64(cephes::gamma(19/10.0), 0.9617658319073874);
    EXPECT_REL_NEAR_F64(cephes::gamma(20/10.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(21/10.0), 1.0464858468535605);
    EXPECT_REL_NEAR_F64(cephes::gamma(22/10.0), 1.1018024908797128);
    EXPECT_REL_NEAR_F64(cephes::gamma(23/10.0), 1.1667119051981603);
    EXPECT_REL_NEAR_F64(cephes::gamma(24/10.0), 1.2421693445043054);
    EXPECT_REL_NEAR_F64(cephes::gamma(25/10.0), 1.329340388179137);
    EXPECT_REL_NEAR_F64(cephes::gamma(26/10.0), 1.4296245588603045);
    EXPECT_REL_NEAR_F64(cephes::gamma(27/10.0), 1.5446858458505939);
    EXPECT_REL_NEAR_F64(cephes::gamma(28/10.0), 1.6764907877644368);
    EXPECT_REL_NEAR_F64(cephes::gamma(29/10.0), 1.8273550806240362);
    EXPECT_REL_NEAR_F64(cephes::gamma(30/10.0), 2.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(31/10.0), 2.197620278392477);
    EXPECT_REL_NEAR_F64(cephes::gamma(32/10.0), 2.423965479935368);
    EXPECT_REL_NEAR_F64(cephes::gamma(33/10.0), 2.683437381955769);
    EXPECT_REL_NEAR_F64(cephes::gamma(34/10.0), 2.981206426810333);
    EXPECT_REL_NEAR_F64(cephes::gamma(35/10.0), 3.3233509704478426);
    EXPECT_REL_NEAR_F64(cephes::gamma(36/10.0), 3.7170238530367916);
    EXPECT_REL_NEAR_F64(cephes::gamma(37/10.0), 4.170651783796603);
    EXPECT_REL_NEAR_F64(cephes::gamma(38/10.0), 4.694174205740423);
    EXPECT_REL_NEAR_F64(cephes::gamma(39/10.0), 5.299329733809705);
    EXPECT_REL_NEAR_F64(cephes::gamma(40/10.0), 6.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(41/10.0), 6.812622863016679);
    EXPECT_REL_NEAR_F64(cephes::gamma(42/10.0), 7.7566895357931775);
    EXPECT_REL_NEAR_F64(cephes::gamma(43/10.0), 8.855343360454038);
    EXPECT_REL_NEAR_F64(cephes::gamma(44/10.0), 10.136101851155132);
    EXPECT_REL_NEAR_F64(cephes::gamma(45/10.0), 11.631728396567448);
    EXPECT_REL_NEAR_F64(cephes::gamma(46/10.0), 13.38128587093245);
    EXPECT_REL_NEAR_F64(cephes::gamma(47/10.0), 15.431411600047431);
    EXPECT_REL_NEAR_F64(cephes::gamma(48/10.0), 17.837861981813607);
    EXPECT_REL_NEAR_F64(cephes::gamma(49/10.0), 20.66738596185785);
    EXPECT_REL_NEAR_F64(cephes::gamma(50/10.0), 24.0);
}

/* Julia + SpecialFunctions (MPFR 4.2.0)
```jl
using SpecialFunctions
for i in 0:100
    gam = gamma(BigInt(i+1))
    f64 = Float64(gam)
    println("EXPECT_REL_NEAR_F64(cephes::gamma($i+1), $f64);")
end
```
*/
// TABLE 3.2 Gamma Function for Integers
TEST(Gamma, CoSF_Table_3p2) {
    EXPECT_REL_NEAR_F64(cephes::gamma(0+1), 1.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(1+1), 1.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(2+1), 2.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(3+1), 6.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(4+1), 24.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(5+1), 120.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(6+1), 720.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(7+1), 5040.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(8+1), 40320.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(9+1), 362880.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(10+1), 3.6288e6);
    EXPECT_REL_NEAR_F64(cephes::gamma(11+1), 3.99168e7);
    EXPECT_REL_NEAR_F64(cephes::gamma(12+1), 4.790016e8);
    EXPECT_REL_NEAR_F64(cephes::gamma(13+1), 6.2270208e9);
    EXPECT_REL_NEAR_F64(cephes::gamma(14+1), 8.71782912e10);
    EXPECT_REL_NEAR_F64(cephes::gamma(15+1), 1.307674368e12);
    EXPECT_REL_NEAR_F64(cephes::gamma(16+1), 2.0922789888e13);
    EXPECT_REL_NEAR_F64(cephes::gamma(17+1), 3.55687428096e14);
    EXPECT_REL_NEAR_F64(cephes::gamma(18+1), 6.402373705728e15);
    EXPECT_REL_NEAR_F64(cephes::gamma(19+1), 1.21645100408832e17);
    EXPECT_REL_NEAR_F64(cephes::gamma(20+1), 2.43290200817664e18);
    EXPECT_REL_NEAR_F64(cephes::gamma(21+1), 5.109094217170944e19);
    EXPECT_REL_NEAR_F64(cephes::gamma(22+1), 1.1240007277776077e21);
    EXPECT_REL_NEAR_F64(cephes::gamma(23+1), 2.585201673888498e22);
    EXPECT_REL_NEAR_F64(cephes::gamma(24+1), 6.204484017332394e23);
    EXPECT_REL_NEAR_F64(cephes::gamma(25+1), 1.5511210043330986e25);
    EXPECT_REL_NEAR_F64(cephes::gamma(26+1), 4.0329146112660565e26);
    EXPECT_REL_NEAR_F64(cephes::gamma(27+1), 1.0888869450418352e28);
    EXPECT_REL_NEAR_F64(cephes::gamma(28+1), 3.0488834461171387e29);
    EXPECT_REL_NEAR_F64(cephes::gamma(29+1), 8.841761993739702e30);
    EXPECT_REL_NEAR_F64(cephes::gamma(30+1), 2.6525285981219107e32);
    EXPECT_REL_NEAR_F64(cephes::gamma(31+1), 8.222838654177922e33);
    EXPECT_REL_NEAR_F64(cephes::gamma(32+1), 2.631308369336935e35);
    EXPECT_REL_NEAR_F64(cephes::gamma(33+1), 8.683317618811886e36);
    EXPECT_REL_NEAR_F64(cephes::gamma(34+1), 2.9523279903960416e38);
    EXPECT_REL_NEAR_F64(cephes::gamma(35+1), 1.0333147966386145e40);
    EXPECT_REL_NEAR_F64(cephes::gamma(36+1), 3.7199332678990125e41);
    EXPECT_REL_NEAR_F64(cephes::gamma(37+1), 1.3763753091226346e43);
    EXPECT_REL_NEAR_F64(cephes::gamma(38+1), 5.230226174666011e44);
    EXPECT_REL_NEAR_F64(cephes::gamma(39+1), 2.0397882081197444e46);
    EXPECT_REL_NEAR_F64(cephes::gamma(40+1), 8.159152832478977e47);
    EXPECT_REL_NEAR_F64(cephes::gamma(41+1), 3.345252661316381e49);
    EXPECT_REL_NEAR_F64(cephes::gamma(42+1), 1.40500611775288e51);
    EXPECT_REL_NEAR_F64(cephes::gamma(43+1), 6.041526306337383e52);
    EXPECT_REL_NEAR_F64(cephes::gamma(44+1), 2.658271574788449e54);
    EXPECT_REL_NEAR_F64(cephes::gamma(45+1), 1.1962222086548019e56);
    EXPECT_REL_NEAR_F64(cephes::gamma(46+1), 5.502622159812089e57);
    EXPECT_REL_NEAR_F64(cephes::gamma(47+1), 2.5862324151116818e59);
    EXPECT_REL_NEAR_F64(cephes::gamma(48+1), 1.2413915592536073e61);
    EXPECT_REL_NEAR_F64(cephes::gamma(49+1), 6.082818640342675e62);
    EXPECT_REL_NEAR_F64(cephes::gamma(50+1), 3.0414093201713376e64);
    EXPECT_REL_NEAR_F64(cephes::gamma(51+1), 1.5511187532873822e66);
    EXPECT_REL_NEAR_F64(cephes::gamma(52+1), 8.065817517094388e67);
    EXPECT_REL_NEAR_F64(cephes::gamma(53+1), 4.2748832840600255e69);
    EXPECT_REL_NEAR_F64(cephes::gamma(54+1), 2.308436973392414e71);
    EXPECT_REL_NEAR_F64(cephes::gamma(55+1), 1.2696403353658276e73);
    EXPECT_REL_NEAR_F64(cephes::gamma(56+1), 7.109985878048635e74);
    EXPECT_REL_NEAR_F64(cephes::gamma(57+1), 4.0526919504877214e76);
    EXPECT_REL_NEAR_F64(cephes::gamma(58+1), 2.3505613312828785e78);
    EXPECT_REL_NEAR_F64(cephes::gamma(59+1), 1.3868311854568984e80);
    EXPECT_REL_NEAR_F64(cephes::gamma(60+1), 8.32098711274139e81);
    EXPECT_REL_NEAR_F64(cephes::gamma(61+1), 5.075802138772248e83);
    EXPECT_REL_NEAR_F64(cephes::gamma(62+1), 3.146997326038794e85);
    EXPECT_REL_NEAR_F64(cephes::gamma(63+1), 1.98260831540444e87);
    EXPECT_REL_NEAR_F64(cephes::gamma(64+1), 1.2688693218588417e89);
    EXPECT_REL_NEAR_F64(cephes::gamma(65+1), 8.247650592082472e90);
    EXPECT_REL_NEAR_F64(cephes::gamma(66+1), 5.443449390774431e92);
    EXPECT_REL_NEAR_F64(cephes::gamma(67+1), 3.647111091818868e94);
    EXPECT_REL_NEAR_F64(cephes::gamma(68+1), 2.4800355424368305e96);
    EXPECT_REL_NEAR_F64(cephes::gamma(69+1), 1.711224524281413e98);
    EXPECT_REL_NEAR_F64(cephes::gamma(70+1), 1.1978571669969892e100);
    EXPECT_REL_NEAR_F64(cephes::gamma(71+1), 8.504785885678623e101);
    EXPECT_REL_NEAR_F64(cephes::gamma(72+1), 6.1234458376886085e103);
    EXPECT_REL_NEAR_F64(cephes::gamma(73+1), 4.4701154615126844e105);
    EXPECT_REL_NEAR_F64(cephes::gamma(74+1), 3.307885441519386e107);
    EXPECT_REL_NEAR_F64(cephes::gamma(75+1), 2.48091408113954e109);
    EXPECT_REL_NEAR_F64(cephes::gamma(76+1), 1.8854947016660504e111);
    EXPECT_REL_NEAR_F64(cephes::gamma(77+1), 1.4518309202828587e113);
    EXPECT_REL_NEAR_F64(cephes::gamma(78+1), 1.1324281178206297e115);
    EXPECT_REL_NEAR_F64(cephes::gamma(79+1), 8.946182130782976e116);
    EXPECT_REL_NEAR_F64(cephes::gamma(80+1), 7.156945704626381e118);
    EXPECT_REL_NEAR_F64(cephes::gamma(81+1), 5.797126020747368e120);
    EXPECT_REL_NEAR_F64(cephes::gamma(82+1), 4.753643337012842e122);
    EXPECT_REL_NEAR_F64(cephes::gamma(83+1), 3.945523969720659e124);
    EXPECT_REL_NEAR_F64(cephes::gamma(84+1), 3.314240134565353e126);
    EXPECT_REL_NEAR_F64(cephes::gamma(85+1), 2.81710411438055e128);
    EXPECT_REL_NEAR_F64(cephes::gamma(86+1), 2.4227095383672734e130);
    EXPECT_REL_NEAR_F64(cephes::gamma(87+1), 2.107757298379528e132);
    EXPECT_REL_NEAR_F64(cephes::gamma(88+1), 1.8548264225739844e134);
    EXPECT_REL_NEAR_F64(cephes::gamma(89+1), 1.650795516090846e136);
    EXPECT_REL_NEAR_F64(cephes::gamma(90+1), 1.4857159644817615e138);
    EXPECT_REL_NEAR_F64(cephes::gamma(91+1), 1.352001527678403e140);
    EXPECT_REL_NEAR_F64(cephes::gamma(92+1), 1.2438414054641308e142);
    EXPECT_REL_NEAR_F64(cephes::gamma(93+1), 1.1567725070816416e144);
    EXPECT_REL_NEAR_F64(cephes::gamma(94+1), 1.087366156656743e146);
    EXPECT_REL_NEAR_F64(cephes::gamma(95+1), 1.032997848823906e148);
    EXPECT_REL_NEAR_F64(cephes::gamma(96+1), 9.916779348709496e149);
    EXPECT_REL_NEAR_F64(cephes::gamma(97+1), 9.619275968248212e151);
    EXPECT_REL_NEAR_F64(cephes::gamma(98+1), 9.426890448883248e153);
    EXPECT_REL_NEAR_F64(cephes::gamma(99+1), 9.332621544394415e155);
    EXPECT_REL_NEAR_F64(cephes::gamma(100+1), 9.332621544394415e157);
}

/* Julia + SpecialFunctions (MPFR 4.2.0)
```jl
using SpecialFunctions
for i in 100:10:200
    gam = gamma(BigInt(i+1))
    f64 = Float64(gam)
    println("EXPECT_REL_NEAR_F64(cephes::gamma($i+1), $f64);")
end
```
*/
// TABLE 3.3 Gamma Function for Large Integers
TEST(Gamma, CoSF_Table_3p3) {
    EXPECT_REL_NEAR_F64(cephes::gamma(100+1), 9.332621544394415e157);
    EXPECT_REL_NEAR_F64(cephes::gamma(110+1), 1.588245541522743e178);
    EXPECT_REL_NEAR_F64(cephes::gamma(120+1), 6.689502913449127e198);
    EXPECT_REL_NEAR_F64(cephes::gamma(130+1), 6.466855489220474e219);
    EXPECT_REL_NEAR_F64(cephes::gamma(140+1), 1.3462012475717526e241);
    EXPECT_REL_NEAR_F64(cephes::gamma(150+1), 5.713383956445855e262);
    EXPECT_REL_NEAR_F64(cephes::gamma(160+1), 4.7147236359920616e284);
    EXPECT_REL_NEAR_F64(cephes::gamma(170+1), 7.257415615307999e306);
    // EXPECT_REL_NEAR_F64(cephes::gamma(180+1), Inf);
}
