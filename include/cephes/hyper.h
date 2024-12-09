#ifndef CEPHES_HYPER_H
/** Cephes double precision special functions suite
 * 
 * cephes/bessel
 */
#define CEPHES_HYPER_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/** Hypergeometric Functions */
double hyp2f1(double a, double b, double c, double x);
double hyperg(double a, double b, double x);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // ::cephes

#endif // CEPHES_HYPER_H