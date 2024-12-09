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

/* misc/spence.c */
double spence(double x);

/* misc/zeta.c */
double zeta(double x, double q);
/* misc/zetac.c */
double zetac(double x);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // ::cephes

#endif // CEPHES_MISC_H