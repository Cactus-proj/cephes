# Features

## Bessel functions

- `j1`: neg input: [Fixed j1 for negative numbers < -5 on windows · scipy/scipy@4c04ef1](https://github.com/scipy/scipy/commit/4c04ef11918253afe1d170429c05758a6b56623f)
- `jv`: larget eps
    - [cephes: correct jv for small values of x. Fixes #221 · scipy/scipy@c578408](https://github.com/scipy/scipy/commit/c578408812d8d2503357dbbbd47520ad7539cee1#diff-ae8ab23ad9d8cc84c8fe7873e417c311f32f22b89dff07a73d32e6d4a227b313)
    - [History for scipy/special/cephes/jv.c - scipy/scipy](https://github.com/scipy/scipy/commits/7a74d2f94929e472519d4fbb0db27e5721bb728e/scipy/special/cephes/jv.c)
- `yv`: when x is negative, the result is complex.

## Misc

- `polylog`: NaN input, inf loop
