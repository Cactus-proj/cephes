# Cephes Mathematical Functions Library

[![Build](https://github.com/Cactus-proj/cephes/actions/workflows/build.yml/badge.svg)](https://github.com/Cactus-proj/cephes/actions/workflows/build.yml)
[![codecov](https://codecov.io/gh/Cactus-proj/cephes/graph/badge.svg?token=HwxPgtj3kO)](https://codecov.io/gh/Cactus-proj/cephes)

> See the [master branch](https://github.com/Cactus-proj/cephes/tree/master)
> for the original google-deepmind/torch-cephes.

This project was used only to obtain the original Cephes Math Library reference output.
Therefore, contributions regarding precision and error-related contributions are not accepted.

> [!TIP]
>
> For general use please use [scipy/xsf](https://github.com/scipy/xsf) instead,
> which is a header-only library containing a modernized (C++17) refactoring of
> the classic `AMOS/SPECFUN/Cephes/...` special function implementations.


## Docs

[List of Cephes functions](docs/index.md)

- [Exponential integral](docs/exp_int.md)
- [Gamma functions](docs/gamma.md)
- [Error functions](docs/gamma.md)
- [Bessel functions](docs/bessel.md)
- [Hypergeometric functions](docs/hyper.md)
- [Elliptic functions](docs/elliptic.md)
- [Probability functions](docs/prob.md)
- [Miscellaneous functions](docs/misc.md)

## Features

- [Bug? Features!](docs/features.md)

## Test

```sh
# On Linux
# Coverage
cmake -S . -B build  -DCMAKE_BUILD_TYPE=Coverage -DBUILD_TESTS=ON
cmake --build build --parallel 8 && ctest --test-dir build -j8 && cmake --build build --target coverage_html
ctest --test-dir build --rerun-failed --output-on-failure

# Release
cmake -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./build/install_test
cmake --build build --parallel 8
cmake --install build
```


## License

Using a `BSD-3-Clause` like [LICENSE](LICENSE.txt).

See also email communication with the original author: [License request email](License-request-email.txt)
