#pragma once
#include <type_traits>
#include <cmath>
#include <limits>
#include <gtest/gtest.h>

/**
 * @param _y_expr   Your `expr` to be evalute
 * @param _ref_expr Reference value
 * @param _rel_tol  Rel Tolence
 * 
 * - When `_ref_expr == 0`, `abs_tol = _rel_tol`
 * - else: `abs_tol = _rel_tol * abs(_ref_expr)`
 */
#define EXPECT_REL_NEAR_F64_(_y_expr, _ref_expr, _rel_tol) \
    do { \
        double __xtest_y_ref__ = (_ref_expr); \
        double __xtest_y_level = (__xtest_y_ref__==0) ? 1.0 : std::abs(__xtest_y_ref__); \
        double __xtest_abs_tol = (_rel_tol) * __xtest_y_level; \
        EXPECT_NEAR((_y_expr), __xtest_y_ref__, __xtest_abs_tol) \
            << "rel_tol = " << _rel_tol; \
    } while (0);
#define EXPECT_REL_NEAR_F64(_y_expr, _ref_expr) \
    EXPECT_REL_NEAR_F64_(_y_expr, _ref_expr, xtest::RelTolF64)

/**
 * Need local var: `x`, `VAR`, `VAR_ref`
 */
#define XTEST_ISAPPROX_F64(_var_name) \
    do { \
        EXPECT_TRUE(xtest::isapprox<double>(_var_name ## _ref, _var_name)) \
            << "x = " << x \
            << "\n Want ref = " << _var_name ## _ref \
            << "\n Got  y   = " << _var_name; \
    } while (0);
// END define XTEST_ISAPPROX


namespace xtest {

// Constant
constexpr float Inf32 = std::numeric_limits<float>::infinity();
constexpr float NaN32 = std::numeric_limits<float>::quiet_NaN();
constexpr double Inf64 = std::numeric_limits<double>::infinity();
constexpr double NaN64 = std::numeric_limits<double>::quiet_NaN();

/*
copy form: julia's isapprox:
    https://github.com/JuliaLang/julia/blob/af9e6e3167f7e444140c81326a2c3cf058ddba1a/base/floatfuncs.jl#L220
*/

// Floating-point types
template <typename T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
constexpr T rel_tol_default() {
    return std::sqrt(std::numeric_limits<T>::epsilon());
};
// Real (non-floating-point) types
template <typename T, std::enable_if_t<std::is_integral_v<T>, int> = 0>
constexpr T rel_tol_default() { return 0; };

/** Default relative tolerance for `float` type */
const double RelTolF32 = rel_tol_default<float>();
/** Default relative tolerance for `double` type */
const double RelTolF64 = rel_tol_default<double>();

template <typename T>
bool isapprox(T x, T y, T rel_tol=rel_tol_default<T>()) {
    assert(rel_tol >= 0);
    return (x == y)
        // rel_error <= rel_tol
        || std::abs(x - y) <= (rel_tol * std::max(std::abs(x), std::abs(y)))
        // NaN == x == y
        || std::isnan(x) && std::isnan(y);
}

} // xtest