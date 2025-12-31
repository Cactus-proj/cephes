# mconf.h
include_directories(${CMAKE_SOURCE_DIR}/cephes)

# --- Module: cmath ---
# file(GLOB src_cmath "cmath/*.c")
# list(REMOVE_ITEM src_cmath
#     "${CMAKE_CURRENT_SOURCE_DIR}/cmath/mtst.c"
#     "${CMAKE_CURRENT_SOURCE_DIR}/cmath/dtestvec.c"
#     "${CMAKE_CURRENT_SOURCE_DIR}/cmath/mod2pi.c"
# )
set(cmath_srcs
    "const.c"
    "asin.c"
    "atan.c"
    "cosh.c"
    "exp.c"
    "floor.c"
    "isnan.c"  # isnan, signbit, isfinite
    "log.c"
    "pow.c"
    "powi.c"
    "round.c"
    "sin.c"
    "sinh.c"
    "sqrt.c"
    "tan.c"
    "tanh.c"
    "unity.c"  # log1p
)
list(TRANSFORM cmath_srcs PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/cmath/")
list(APPEND src_cmath ${cmath_srcs})
add_library(cephes_cmath OBJECT ${src_cmath})

# --- Module: bessel ---
file(GLOB src_bessel "bessel/*.c")
add_library(cephes_bessel OBJECT ${src_bessel})

# --- Module: cprob ---
file(GLOB src_cprob "cprob/*.c")
add_library(cephes_cprob OBJECT ${src_cprob})

# --- Module: ellf ---
file(GLOB src_ellf "ellf/*.c")
list(REMOVE_ITEM src_ellf
    "${CMAKE_CURRENT_SOURCE_DIR}/ellf/ellf.c"  # tests
)
add_library(cephes_ellf OBJECT ${src_ellf})

# --- Module: misc ---
file(GLOB src_misc "misc/*.c")
list(REMOVE_ITEM src_misc
    "${CMAKE_CURRENT_SOURCE_DIR}/misc/simpsn.c"  # not use
)
add_library(cephes_misc OBJECT ${src_misc})

# --- Module: polyn ---
# file(GLOB src_polyn "polyn/*.c")
list(APPEND src_polyn
    "${CMAKE_CURRENT_SOURCE_DIR}/polyn/chbevl.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/polyn/polevl.c"
)
add_library(cephes_polyn OBJECT ${src_polyn})

# --- Module: single ---
file(GLOB src_single "single/*.c")
# note: single/ is not compiled because it conflicts
#   with many functions in cmath and cprob :(
# add_library(cephes_single OBJECT ${src_single})

# --- Main Library ---
add_library(cephes SHARED 
    "torch_mtherr.c"
    $<TARGET_OBJECTS:cephes_cmath>
    $<TARGET_OBJECTS:cephes_bessel>
    $<TARGET_OBJECTS:cephes_cprob>
    $<TARGET_OBJECTS:cephes_ellf>
    $<TARGET_OBJECTS:cephes_misc>
    $<TARGET_OBJECTS:cephes_polyn>
    # $<TARGET_OBJECTS:cephes_single>
)

# libcephes.[so|dll|dylib]
set_target_properties(cephes PROPERTIES
    OUTPUT_NAME "cephes"
    PREFIX "lib"
    WINDOWS_EXPORT_ALL_SYMBOLS ON
)
