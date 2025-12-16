#ifndef CEPHES_EXP_INT_H
/** Cephes double precision special functions suite
 *
 * cephes/Exponential integral
 */
#define CEPHES_EXP_INT_H

#if defined(__cplusplus)
extern "C" {
#endif

/** Exponential integral */
/* misc/expn.c */
double expn(int n, double x);

/** Sine and Cosine integral */
/* misc/sici.c */
int sici(double x, double *si, double *ci);
/** misc/shichi.c */
int shichi(double x, double *si, double *ci);

#if defined(__cplusplus)
}
#endif
#endif // CEPHES_EXP_INT_H
