# Cephes Mathematical Functions Library

[![Build](https://github.com/Cactus-proj/cephes/actions/workflows/build.yml/badge.svg)](https://github.com/Cactus-proj/cephes/actions/workflows/build.yml)
[![codecov](https://codecov.io/gh/Cactus-proj/cephes/graph/badge.svg?token=HwxPgtj3kO)](https://codecov.io/gh/Cactus-proj/cephes)

This project serves solely to generate reference outputs from the original/scipy Cephes Math Library.
Consequently, contributions addressing precision or error corrections may not be accepted.
We recommend submitting such improvements to the [scipy/xsf](https://github.com/scipy/xsf) project instead.

NOTE: This project currently focuses on *special functions* with double precision.

> [!TIP]
>
> For general applications, we recommend [scipy/xsf](https://github.com/scipy/xsf).
> It provides a modernized (C++17), header-only refactoring of classic special function implementations,
> including `AMOS`, `SPECFUN`, and `Cephes`.


## Build and Test

```sh
# Generate Coverage Report
cmake -S . -B build -DCMAKE_BUILD_TYPE=Coverage -DBUILD_TESTS=ON
cmake --build build --parallel 8 && ctest --test-dir build -j8 && cmake --build build --target coverage_html
ctest --test-dir build --rerun-failed --output-on-failure

# Release Build
cmake -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./build/install_test
cmake --build build --parallel 8
cmake --install build
```


## Features

- [Bug? Features!](docs/features.md)

## Docs

> NOTE: Only functions listed in public headers are treated as public API.

[`cephes/*.h` Headers](include/cephes)

> By default, Cephes **does not signal any error** (domain, singularity, overflow, underflow, precision).
> It is as non-intrusive as possible and tries to return a value which is hopefully usable: it might be NaN, it might be inf.

[List of All Cephes functions](docs/doubldoc.md)

### Exponential integral

- **ei**,     [Exponential Integral](doubldoc.md#ei)
- **expn**,   [Exponential integral En](doubldoc.md#expn)
- **sici**,   [Sine and cosine integrals](doubldoc.md#sici)
- **shichi**, [Hyperbolic sine and cosine integrals](doubldoc.md#shichi)

### Gamma Functions

- **fac**,    [Factorial function](doubldoc.md#fac)
- **gamma**,  [Gamma function](doubldoc.md#gamma)
- **lgam**,   [Natural logarithm of gamma function](doubldoc.md#lgam)
- **igam**,   [Incomplete gamma integral](doubldoc.md#igam)
- **igamc**,  [Complemented incomplete gamma integral](doubldoc.md#igamc)
- **igami**,  [Inverse of complemented incomplete gamma integral](doubldoc.md#igami)
- **psi**,    [Psi (digamma) function](doubldoc.md#psi)
- **rgamma**, [Reciprocal gamma function](doubldoc.md#rgamma)

#### Beta Functions

- **beta**,   [Beta function](doubldoc.md#beta)
- **incbet**, [Incomplete beta integral](doubldoc.md#incbet)
- **incbi**,  [Inverse of incomplete beta integral](doubldoc.md#incbi)

### Error Functions

- **erf**,    [Error function](doubldoc.md#erf)
- **erfc**,   [Complementary error function](doubldoc.md#erfc)
- **dawsn**,  [Dawson's Integral](doubldoc.md#dawsn)
- **fresnl**, [Fresnel integral](doubldoc.md#fresnl)

### Bessel functions

#### Airy Functions

- **airy**, [Airy functions](doubldoc.md#airy)

#### Bessel function

- **j0**, [Bessel function of order zero](doubldoc.md#j0)
- **j1**, [Bessel function of order one](doubldoc.md#j1)
- **jn**, [Bessel function of integer order](doubldoc.md#jn)
- **jv**, [Bessel function of noninteger order](doubldoc.md#jv)

#### Modified Bessel functions - second kind

- **y0**, [Bessel function of the second kind, order zero](doubldoc.md#y0)
- **y1**, [Bessel function of the second kind, order one](doubldoc.md#y1)
- **yn**, [Bessel function of second kind of integer order](doubldoc.md#yn)
- **yv**, Bessel function of noninteger order

#### Modified Bessel functions

- **i0**,   [Modified Bessel function of order zero](doubldoc.md#i0)
- **i0e**,  [Exponentially scaled modified Bessel function of order zero](doubldoc.md#i0e)
- **i1**,   [Modified Bessel function of order one](doubldoc.md#i1)
- **i1e**,  [Exponentially scaled modified Bessel function of order one](doubldoc.md#i1e)
- **iv**,   [Modified Bessel function of noninteger order](doubldoc.md#iv)

#### Modified Bessel functions - third kind

- **k0**,   [Modified Bessel function, third kind, order zero](doubldoc.md#k0)
- **k0e**,  [Modified Bessel function, third kind, order zero, exponentially scaled](doubldoc.md#k0e)
- **k1**,   [Modified Bessel function, third kind, order one](doubldoc.md#k1)
- **k1e**,  [Modified Bessel function, third kind, order one, exponentially scaled](doubldoc.md#k1e)
- **kn**,   [Modified Bessel function, third kind, integer order](doubldoc.md#kn)

### Hypergeometric Functions

- **hyperg**, [Confluent hypergeometric function](doubldoc.md#hyperg)
- **hyp2f1**, [Gauss hypergeometric function](doubldoc.md#hyp2f1)

### Elliptic Functions

- **ellpk**, [Complete elliptic integral of the first kind](doubldoc.md#ellpk)
- **ellik**, [Incomplete elliptic integral of the first kind](doubldoc.md#ellik)
- **ellpe**, [Complete elliptic integral of the second kind](doubldoc.md#ellpe)
- **ellie**, [Incomplete elliptic integral of the second kind](doubldoc.md#ellie)
- **ellpj**, [Jacobian elliptic functions](doubldoc.md#ellpj)

### Probability Functions

#### Binomial distribution

- **bdtr**, [Binomial distribution](doubldoc.md#bdtr)
- **bdtrc**, [Complemented binomial distribution](doubldoc.md#bdtrc)
- **bdtri**, [Inverse binomial distribution](doubldoc.md#bdtri)

#### Beta distribution

- **btdtr**, [Beta distribution](doubldoc.md#btdtr)

#### Chi-square distribution

- **chdtr**, [Chi-square distribution](doubldoc.md#chdtr)
- **chdtrc**, [Complemented Chi-square distribution](doubldoc.md#chdtrc)
- **chdtri**, [Inverse of complemented Chi-square distribution](doubldoc.md#chdtri)

#### F distribution

- **fdtr**, [F distribution](doubldoc.md#fdtr)
- **fdtrc**, [Complemented F distribution](doubldoc.md#fdtrc)
- **fdtri**, [Inverse of complemented F distribution](doubldoc.md#fdtri)

#### Gamma distribution

- **gdtr**, [Gamma distribution function](doubldoc.md#gdtr)
- **gdtrc**, [Complemented gamma distribution function](doubldoc.md#gdtrc)

#### Negative binomial distribution

- **nbdtr**, [Negative binomial distribution](doubldoc.md#nbdtr)
- **nbdtrc**, [Complemented negative binomial distribution](doubldoc.md#nbdtrc)
- **nbdtri**, [Functional inverse of negative binomial distribution](doubldoc.md#nbdtri)

#### Normal distribution

- **ndtr**, [Normal distribution function](doubldoc.md#ndtr)
- **ndtri**, [Inverse of normal distribution function](doubldoc.md#ndtri)

#### Poisson distribution

- **pdtr**, [Poisson distribution function](doubldoc.md#pdtr)
- **pdtrc**, [Complemented Poisson distribution function](doubldoc.md#pdtrc)
- **pdtri**, [Inverse of Poisson distribution function](doubldoc.md#pdtri)

#### Student's t distribution

- **stdtr**, [Student's t distribution](doubldoc.md#stdtr)
- **stdtri**, [Functional inverse of Student's t distribution](doubldoc.md#stdtri)

### Miscellaneous functions

- **spence**, [Dilogarithm](doubldoc.md#spence)
- **zeta**, [Zeta function of two arguments](doubldoc.md#zeta)
- **zetac**, [Riemann zeta function of two arguments](doubldoc.md#zetac)
- **struve**, [Struve function](doubldoc.md#struve)
- **polylog**, [Polylogarithms](doubldoc.md#polylog)
- **plancki**, [Integral of Planck's black body radiation formula](doubldoc.md#planck)


## License

This project is licensed under a `BSD-3-Clause` style license.
See [LICENSE](LICENSE.txt) for details.

[Cephes mathematical library](http://www.netlib.org/cephes/),
developed by [Stephen L. Moshier](http://www.moshier.net).

For historical context, see the email communication with the original author:
[License request email](License-request-email.txt).
