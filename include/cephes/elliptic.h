#ifndef CEPHES_ELLIPTIC_H
/** Cephes double precision special functions suite
 * 
 * cephes/bessel
 */
#define CEPHES_ELLIPTIC_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/** Elliptic Functions */
/* ellf/ellpk.c */
double ellpk(double x);
/* ellf/ellik.c */
double ellik(double phi, double m);
/* ellf/ellpe.c */
double ellpe(double x);
/* ellf/ellie.c */
double ellie(double phi, double m);

/* ellf/ellpj.c */
int ellpj(double u, double m, double *sn, double *cn, double *dn, double *ph);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // ::cephes

#endif // CEPHES_ELLIPTIC_H