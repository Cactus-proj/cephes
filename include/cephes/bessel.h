#ifndef CEPHES_BESSEL_H
/** Cephes double precision special functions suite
 *
 * src: `cephes/bessel`
 *
 * - Airy Functions:  `airy`
 * - Bessel functions:  `j0`, `j1`, `jn`, `jv`
 * - Modified Bessel functions:  `i0`, `i0e`, `i1`, `i1e`, `iv`
 * - Modified Bessel functions - second kind: `y0`, `y1`, `yn`, `yv`
 * - Modified Bessel functions - third kind:  `k0`, `k0e`, `k1`, `k1e`, `kn`
 */
#define CEPHES_BESSEL_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/* Airy Functions */
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

/** Modified Bessel functions */
double i0(double x);
double i0e(double x);
double i1(double x);
double i1e(double x);
double iv(double v, double x);

/* Modified Bessel functions - second kind */
/**
 * @brief 
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

/** Modified Bessel functions - third kind */
double k0(double x);
double k0e(double x);
double k1(double x);
double k1e(double x);
double kn(int nn, double x);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // namespace cephes

#endif // CEPHES_BESSEL_H
