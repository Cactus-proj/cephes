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

/* Binomial distribution
    cprob/bdtr.c */
double bdtr(int k, int n, double p);
double bdtrc(int k, int n, double p);
double bdtri(int k, int n, double y);

/* Beta distribution
    cprob/btdtr.c */
double btdtr(double a, double b, double x);

/* Chi-square distribution
    cprob/chdtr.c */
double chdtr(double df, double x);
double chdtrc(double df, double x);
double chdtri(double df, double y);

/* F distribution
    cprob/fdtr.c */
double fdtr(int ia, int ib, double x);
double fdtrc(int ia, int ib, double x);
double fdtri(int ia, int ib, double y);

/* Gamma distribution
    cprob/gdtr.c */
double gdtr(double a, double b, double x);
double gdtrc(double a, double b, double x);

/* Kolmogorov's limiting distribution */
double kolmogorov(double y);
double kolmogi(double p);

/* Smirnov distribution */
double smirnov(int n, double e);
double smirnovi(int n, double p);

/* Negative binomial distribution
    cprob/nbdtr.c */
double nbdtr(int k, int n, double p);
double nbdtrc(int k, int n, double p);
double nbdtri(int k, int n, double p);

/* Normal distribution
    cprob/ndtr.c;ndtri.c  */
double ndtr(double a);
double ndtri(double y0_);

/* Poisson distribution
    cprob/pdtr.c */
double pdtr(int k, double m);
double pdtrc(int k, double m);
double pdtri(int k, double y);

/* Student's t distribution
    cprob/stdtr.c */
double stdtr(int k, double t);
double stdtri(int k, double p);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // namespace cephes

#endif // CEPHES_PROB_H
