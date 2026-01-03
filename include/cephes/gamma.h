#ifndef CEPHES_GAMMA_H
/** Cephes double precision special functions suite
 *
 * cephes/bessel
 */
#define CEPHES_GAMMA_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/* ---- Gamma Functions ---- */
/* misc/fac.c */
double fac(int i);

/* cprob/gamma.c */
double gamma(double x);
double lgam(double x);
/* cprob/igam.c */
double igam(double a, double x);
double igamc(double a, double x);
/* cprob/igami.c */
double igami(double a, double y0_);

/* misc/psi.c */
double psi(double x);
/* misc/rgamma.c */
double rgamma(double x);

/* ---- Beta Functions ---- */
/* misc/beta.c */
double beta(double a, double b);
double lbeta(double a, double b);
/* cprob/incbet.c */
double incbet(double aa, double bb, double xx);
/* cprob/incbi.c */
double incbi(double aa, double bb, double yy0);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // namespace cephes

#endif // CEPHES_GAMMA_H
