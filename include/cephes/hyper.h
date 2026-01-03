#ifndef CEPHES_HYPER_H
/** @file hyper.h
 * Cephes: Hypergeometric Functions
 *
 * Source: `cephes/bessel`
 * Provides:
 * - Gauss hypergeometric function:  hyp2f1
 * - Confluent hypergeometric function:  hyperg
 */
#define CEPHES_HYPER_H

namespace cephes {
#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @brief Computes the Confluent hypergeometric function `1F1(a,b;x)` (`M(a,b,x)`)
 *
 * @param a
 * @param b, b must not be a negative integer or zero, unless a is an integer with `0 >= a > b`
 * @param x
 * @return double
 */
double hyperg(double a, double b, double x);

/**
 * @brief Computes the Gauss hypergeometric function `2F1(a,b;c;x)`
 *
 * @param a
 * @param b
 * @param c
 * @param x, |x| > 1 is rejected.
 * @return double
 */
double hyp2f1(double a, double b, double c, double x);

// TODO:  hyp2f0f, onef2f, threef0f

#if defined(__cplusplus)
} // extern "C"
#endif
}; // namespace cephes

#endif // CEPHES_HYPER_H
