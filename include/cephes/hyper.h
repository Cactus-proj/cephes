#ifndef CEPHES_HYPER_H
/** Cephes: Hypergeometric Functions
 *
 */
#define CEPHES_HYPER_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @brief Computes the gauss hypergeometric function `2F1(a,b;c;x)`
 *
 * @param a
 * @param b
 * @param c
 * @param x, |x| > 1 is rejected.
 * @return double
 */
double hyp2f1(double a, double b, double c, double x);

/**
 * @brief Computes the confluent hypergeometric function `1F1(a,b;x)` (`M(a,b,x)`)
 *
 * @param a
 * @param b, b must not be a negative integer or zero, unless a is an integer with `0 >= a > b`
 * @param x
 * @return double
 */
double hyperg(double a, double b, double x);

#if defined(__cplusplus)
} // extern "C"
#endif
}; // namespace cephes

#endif // CEPHES_HYPER_H
