#ifndef CEPHES_EXP_INT_H
/** @file exp_int.h
 * Cephes double precision special functions suite
 *
 * Source: `cephes/misc`
 * Provides:
 * - Exponential integral:  expn
 * - Sine and Cosine integral:  sici
 * - Hyperbolic Sine and Cosine integral:  shichi
 */
#define CEPHES_EXP_INT_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/* Exponential integral */
/**
 * @brief Exponential integral
 * 
 * @param n non-negative
 * @param x non-negative
 * @return double `E_n(x)`
 */
double expn(int n, double x);

/* Sine and Cosine integral */
/**
 * @brief Sine and Cosine integral
 * 
 * @param[in] x 
 * @param[out] si Sine integral `Si(x)`
 * @param[out] ci Cosine integral `Ci(x)`
 * @return int 0 for success
 */
int sici(double x, double *si, double *ci);

/* Hyperbolic Sine and Cosine integral */
/**
 * @brief Hyperbolic Sine and Cosine integral
 * 
 * @param[in] x 
 * @param[out] si Hyperbolic sine integral `Shi(x)`
 * @param[out] ci Hyperbolic cosine integral `Chi(x)`
 * @return int 0 for success
 */
int shichi(double x, double *si, double *ci);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // namespace cephes
#endif // CEPHES_EXP_INT_H
