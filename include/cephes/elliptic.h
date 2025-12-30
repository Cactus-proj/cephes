#ifndef CEPHES_ELLIPTIC_H
/** @file elliptic.h
 * Cephes double-precision elliptic integrals and Jacobian elliptic functions (interfaces)
 *
 * Source: `cephes/ellf`
 * Provides:
 * - Elliptic integrals:  ellpk, ellik, ellpe, ellie
 * - Jacobian elliptic functions:  ellpj
 */
#define CEPHES_ELLIPTIC_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/* Elliptic Functions */
/**
 * @brief Complete elliptic integral of the first kind
 *
 * @param m1 parameter `m1 = 1 - m`, in `[0, 1]`
 * @return double `K(m)`.
 *  Returns 0.0 if m1 is outside [0,1]; 
 *  returns MAXNUM at the singularity m1 == 0
 */
double ellpk(double m1);
/**
 * @brief Incomplete elliptic integral of the first kind F(phi|m)
 *
 * @param phi amplitude, [-pi/2, pi/2]
 * @param m modulus m in [0, 1]
 * @return double F(phi|m).
 */
double ellik(double phi, double m);
/**
 * @brief Complete elliptic integral of the second kind
 *
 * @param m1 parameter m1 = 1 - m, in [0, 1]
 * @return double E(m). Returns 1.0 when m1 == 0; returns 0.0 if m1 is outside [0,1]
 * @note If you have modulus m, call ellpe(1.0 - m)
 */
double ellpe(double m1);
/**
 * @brief Incomplete elliptic integral of the second kind E(phi|m)
 *
 * @param phi amplitude, [-pi/2, pi/2]
 * @param m modulus m in [0, 1]
 * @return double E(phi|m)
 */
double ellie(double phi, double m);

/**
 * @brief Jacobian elliptic functions sn(u|m), cn(u|m), dn(u|m) and amplitude phi
 *
 * @param[in] u real argument u
 * @param[in] m modulus m in [0, 1]
 * @param[out] sn sn(u|m) in [-1, 1]
 * @param[out] cn cn(u|m) in [-1, 1]
 * @param[out] dn dn(u|m) in (0, 1]
 * @param[out] phi amplitude; if u = ellik(phi, m), then sn = sin(phi), cn = cos(phi)
 * @return int 0 on success; returns -1 if m is outside [0,1]
 * @note Quarter period on the real axis is ellpk(1.0 - m)
 */
int ellpj(double u, double m, double *sn, double *cn, double *dn, double *phi);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // namespace cephes

#endif // CEPHES_ELLIPTIC_H
