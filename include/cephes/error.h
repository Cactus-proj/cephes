#ifndef CEPHES_ERROR_H
/** @file error.h
 * Cephes double precision special functions suite
 *
 * Source: `cephes/cprob, cephes/misc`
 * Provides:
 * - Error functions:  erf, erfc
 * - Dawson integral:  dawsn
 * - Fresnel integrals:  fresnl
 */
#define CEPHES_ERROR_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/* Error Functions */
/* cprob/ndtr.c */
/**
 * @brief Error function
 * 
 * @param x 
 * @return double `erf(x)`
 */
double erf(double x);
/**
 * @brief Complementary error function
 * 
 * @param a 
 * @return double `erfc(a)`
 */
double erfc(double a);

/* misc/dawsn.c */
/**
 * @brief Dawson's Integral
 * 
 * @param x 
 * @return double `dawsn(x)`
 */
double dawsn(double x);

/* misc/fresnl.c */
/**
 * @brief Fresnel integrals
 * 
 * @param[in] x 
 * @param[out] ss Fresnel integrals `S(x)`
 * @param[out] cc Fresnel integrals `C(x)`
 * @return int 0 for success
 */
int fresnl(double x, double *ss, double *cc);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // namespace cephes

#endif // CEPHES_ERROR_H
