# Cephes Mathematical Functions Library

[![Build](https://github.com/Cactus-proj/cephes/actions/workflows/build.yml/badge.svg)](https://github.com/Cactus-proj/cephes/actions/workflows/build.yml)
[![codecov](https://codecov.io/gh/Cactus-proj/cephes/graph/badge.svg?token=HwxPgtj3kO)](https://codecov.io/gh/Cactus-proj/cephes)

This project serves solely to generate reference outputs from the original/scipy Cephes Math Library.
Consequently, contributions addressing precision or error corrections may not be accepted.
We recommend submitting such improvements to the [scipy/xsf](https://github.com/scipy/xsf) project instead.

NOTE: This project currently focuses on *special functions*.

> [!TIP]
>
> For general applications, we recommend [scipy/xsf](https://github.com/scipy/xsf).
> It provides a modernized (C++17), header-only refactoring of classic special function implementations,
> including `AMOS`, `SPECFUN`, and `Cephes`.


## Features

- [Bug? Features!](docs/features.md)

## Docs

[`cephes/*.h` Headers](include/cephes)

> By default, Cephes **does not signal any error** (domain, singularity, overflow, underflow, precision).
> It is as non-intrusive as possible and tries to return a value which is hopefully usable: it might be NaN, it might be inf.

[List of Cephes functions](docs/doubldoc.md)

- [Exponential integral](docs/exp_int.md)
- [Gamma functions](docs/gamma.md)
- [Error functions](docs/error.md)
- [Bessel functions](docs/bessel.md)
- [Hypergeometric functions](docs/hyper.md)
- [Elliptic functions](docs/elliptic.md)
- [Probability functions](docs/prob.md)
- [Miscellaneous functions](docs/misc.md)


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


## License

This project is licensed under a `BSD-3-Clause` style license.
See [LICENSE](LICENSE.txt) for details.

[Cephes mathematical library](http://www.netlib.org/cephes/),
developed by [Stephen L. Moshier](http://www.moshier.net).

For historical context, see the email communication with the original author:
[License request email](License-request-email.txt).
