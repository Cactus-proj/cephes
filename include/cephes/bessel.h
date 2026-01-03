#ifndef CEPHES_BESSEL_H
/** Cephes double precision special functions suite
 *
 * src: `cephes/bessel`
 *
 * - Airy Functions:  `airy`
 * - Bessel functions, (First Kind):  `j0`, `j1`, `jn`, `jv`
 * - Bessel functions, Second Kind:   `y0`, `y1`, `yn`, `yv`
 * - Modified Bessel functions, first kind:   `i0`, `i0e`, `i1`, `i1e`, `iv`
 * - Modified Bessel functions, second kind (third kind):  `k0`, `k0e`, `k1`, `k1e`, `kn`
 */
#define CEPHES_BESSEL_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/* ---- Airy Functions ---- */
/**
 * @brief Airy functions
 * 
 * @param[in] x 
 * @param[out] ai   `Ai(x)`
 * @param[out] aip  `Ai'(x)`
 * @param[out] bi   `Bi(x)`
 * @param[out] bip  `Bi'(x)`
 * @return int  0=success; others=error
 */
int airy(const double x, double *ai, double *aip, double *bi, double *bip);

/* Bessel functions */
/**
 * @brief Bessel function of the first kind of order zero.
 * 
 * @param[in] x 
 * @return double `J_0(x)`
 */
double j0(double x);
/**
 * @brief Bessel function of the first kind of order one.
 * 
 * @param[in] x
 * @return double `J_1(x)`
 * @note `J_1(x)` is `Inf` for `x <= 0.0` (xsf fixed this).
 */
double j1(double x);
/**
 * @brief Bessel function of the first kind of integer order `n`.
 * 
 * @param[in] n integer order
 * @param[in] x 
 * @return double `J_n(x)`
 */
double jn(int n, double x);
/**
 * @brief Bessel function of the first kind of real order `v`.
 * 
 * @param[in] v real order
 * @param[in] x Negative `x` is allowed if `v` is an integer.
 * @return double `J_v(x)`
 */ 
double jv(double v, double x);

/* ---- Bessel functions - second kind ---- */
/**
 * @brief Bessel function of the second kind of order zero.
 * 
 * @param[in] x 
 * @return double `Y_0(x)`
 */
double y0(double x);
/**
 * @brief Bessel function of the second kind of order one.
 * 
 * @param[in] x 
 * @return double `Y_1(x)`
 */
double y1(double x);
/**
 * @brief Bessel function of the second kind of integer order `n`.
 * 
 * @param[in] n integer order
 * @param[in] x 
 * @return double `Y_n(x)`
 */
double yn(int n, double x);
/**
 * @brief Bessel function of the second kind of real order `v`.
 * 
 * @param[in] v real order
 * @param[in] x 
 * @return double `Y_v(x)`
 */
double yv(double v, double x);

/* ---- Modified Bessel functions ---- */
/**
 * @brief Modified Bessel function of the first kind of order zero.
 * 
 * @param[in] x 
 * @return double `I_0(x)`
 */
double i0(double x);
/**
 * @brief Modified Bessel function of the first kind of order zero, exponentially scaled.
 * 
 * @param[in] x 
 * @return double `I_0e(x)`
 */
double i0e(double x);
/**
 * @brief Modified Bessel function of the first kind of order one.
 * 
 * @param[in] x 
 * @return double `I_1(x)`
 */
double i1(double x);
/**
 * @brief Modified Bessel function of the first kind of order one, exponentially scaled.
 * 
 * @param[in] x 
 * @return double `I_1e(x)`
 */
double i1e(double x);
/**
 * @brief Modified Bessel function of the first kind of real order `v`.
 * 
 * @param[in] v real order
 * @param[in] x If `x` is negative, `v` must be integer valued.
 * @return double `I_v(x)`
 */
double iv(double v, double x);

/* ---- Modified Bessel functions - second kind (third kind)

  ## ref
  - [DLMF: §10.25 Modified Bessel Functions](https://dlmf.nist.gov/10.25)
  - [Modified Bessel Function of the Third Kind -- from Wolfram MathWorld](https://mathworld.wolfram.com/ModifiedBesselFunctionoftheThirdKind.html)
  - [Modified Bessel Function of the Second Kind -- from Wolfram MathWorld](https://mathworld.wolfram.com/ModifiedBesselFunctionoftheSecondKind.html)
 */
/**
 * @brief Modified Bessel function of the second kind of order zero.
 * 
 * @param[in] x non-negative
 * @return double `K_0(x)`
 */
double k0(double x);
/**
 * @brief Modified Bessel function of the second kind of order zero, exponentially scaled.
 * 
 * @param[in] x non-negative
 * @return double `K_0e(x) = exp(x)*K_0(x)`
 */
double k0e(double x);
/**
 * @brief Modified Bessel function of the second kind of order one.
 * 
 * @param[in] x non-negative
 * @return double `K_1(x)`
 */
double k1(double x);
/**
 * @brief Modified Bessel function of the second kind of order one, exponentially scaled.
 * 
 * @param[in] x non-negative
 * @return double `K_1e(x) = exp(x)*K_1(x)`
 */
double k1e(double x);
/**
 * @brief Modified Bessel function of the second kind of integer order `n`.
 * 
 * @param[in] n integer order
 * @param[in] x non-negative
 * @return double `K_n(x)`
 */
double kn(int n, double x);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // namespace cephes

#endif // CEPHES_BESSEL_H
