#ifndef CEPHES_DOUBLE_H
/** Cephes double precision special functions suite */
#define CEPHES_DOUBLE_H

#if defined(__cplusplus)
extern "C" {
#endif

/** cephes/bessel */

int airy(double x, double *ai, double *aip, double *bi, double *bip);

double hyp2f1(double a, double b, double c, double x);
double hyperg(double a, double b, double x);
double hyp2f0(double a, double b, double x, int type, double *err);

double i0(double x);
double i0e(double x);
double i1(double x);
double i1e(double x);
double iv(double v, double x);

double j0(double x);
double y0(double x);
double j1(double x);
double y1(double x);
double jn(int n, double x);
double jv(double n, double x);

double k0(double x);
double k0e(double x);
double k1(double x);
double k1e(double x);
double kn(int nn, double x);

double psi(double x);

double onef2(double a, double b, double c, double x, double *err);
double threef0(double a, double b, double c, double x, double *err);
double struve(double v, double x);
double yv(double v, double x);

double yn(int n, double x);

#if defined(__cplusplus)
}
#endif
#endif // CEPHES_DOUBLE_H