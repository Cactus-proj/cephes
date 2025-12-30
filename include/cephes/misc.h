#ifndef CEPHES_MISC_H
/** Cephes double precision special functions suite
 *
 * cephes/misc
 */
#define CEPHES_MISC_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/* misc/ei.c */
double ei(double x);

/* misc/polylog.c */
double polylog(int n, double x);

/* misc/spence.c */
double spence(double x);

/* misc/zeta.c */
double zeta(double x, double q);
/* misc/zetac.c */
double zetac(double x);

/**
 * @brief Struve function of order `v`.
 * 
 * @param v order
 * @param x Negative x is rejected unless v is an integer.
 * @return double `Hv(x)`
 * @note `bessel/struve.c`
 */
double struve(double v, double x);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // namespace cephes

#endif // CEPHES_MISC_H
