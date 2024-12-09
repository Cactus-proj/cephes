#ifndef CEPHES_ERROR_H
/** Cephes double precision special functions suite
 * 
 * cephes/bessel
 */
#define CEPHES_ERROR_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/** Error Functions */
/* cephes/ndtr.c */
double erf(double x);
double erfc(double a);
double ndtr(double a);

/* cephes/dawsn.c */
double dawsn(double xx);
/* cephes/fresnl.c */
int fresnl(double xxa, double *ssa, double *cca);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // ::cephes

#endif // CEPHES_ERROR_H