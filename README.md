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

[List of Cephes functions](doc/markdown/index.md)

- [bessel](doc/markdown/bessel.md)
- [exp_int](doc/markdown/exp_int.md)


## Test

```sh
# On Linux
cmake -DCMAKE_BUILD_TYPE=Coverage -S . -B build && cmake --build build
cd build/ && ctest && make coverage_html
```

## License

Using a `BSD-3-Clause` like [LICENSE](LICENSE.txt).

See also email communication with the original author: [License request email](License-request-email.txt)
