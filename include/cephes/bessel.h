#ifndef CEPHES_BESSEL_H
/** Cephes double precision special functions suite
 *
 * cephes/bessel
 */
#define CEPHES_BESSEL_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/** Airy Functions */
int airy(double x, double *ai, double *aip, double *bi, double *bip);

/** Hypergeometric Functions */
double hyp2f1(double a, double b, double c, double x);
double hyperg(double a, double b, double x);

/** Bessel functions */
double j0(double x);
double j1(double x);
double jn(int n, double x);
double jv(double n, double x);

/** Modified Bessel functions */
double i0(double x);
double i0e(double x);
double i1(double x);
double i1e(double x);
double iv(double v, double x);

/** Modified Bessel functions - second kind */
double y0(double x);
double y1(double x);
double yn(int n, double x);

/** Modified Bessel functions - third kind */
double k0(double x);
double k0e(double x);
double k1(double x);
double k1e(double x);
double kn(int nn, double x);

/** Others */
double psi(double x);
double struve(double v, double x);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // namespace cephes

#endif // CEPHES_BESSEL_H
