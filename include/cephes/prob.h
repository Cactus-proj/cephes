#ifndef CEPHES_PROB_H
/** Cephes double precision special functions suite
 *
 * probability
 */
#define CEPHES_PROB_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/* cprob/bdtr.c */
double bdtr(int k, int n, double p);
double bdtrc(int k, int n, double p);
double bdtri(int k, int n, double y);

/* cprob/btdtr.c */
double btdtr(double a, double b, double x);

/* cprob/chdtr.c */
double chdtr(double df, double x);
double chdtrc(double df, double x);
double chdtri(double df, double y);

/* cprob/fdtr.c */
double fdtr(int ia, int ib, double x);
double fdtrc(int ia, int ib, double x);
double fdtri(int ia, int ib, double y);

/* cprob/gdtr.c */
double gdtr(double a, double b, double x);
double gdtrc(double a, double b, double x);

/* cprob/nbdtr.c */
double nbdtr(int k, int n, double p);
double nbdtrc(int k, int n, double p);
double nbdtri(int k, int n, double p);

/* cprob/ndtr.c */
double ndtr(double a);
/* cprob/ndtri.c */
double ndtri(double y0_);

/* cprob/pdtr.c */
double pdtr(int k, double m);
double pdtrc(int k, double m);
double pdtri(int k, double y);

/* cprob/stdtr.c */
double stdtr(int k, double t);
double stdtri(int k, double p);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // namespace cephes

#endif // CEPHES_PROB_H
