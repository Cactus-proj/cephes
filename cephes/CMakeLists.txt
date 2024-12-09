# mconf.h
include_directories(${CMAKE_SOURCE_DIR}/cephes)

# locate all cephes subfolders to process
FILE(GLOB src
    "cmath/*.c"
    "bessel/*.c"
    "cprob/*.c"
    "ellf/*.c"
    "misc/*.c"
    "polyn/*.c"
    "torch_mtherr.c"
    )
# note: single/ is not compiled because it conflicts
# with many functions in cmath and cprob :(

# ignore files which have a main() 
LIST(REMOVE_ITEM src
    "${CMAKE_CURRENT_SOURCE_DIR}/cmath/mtst.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmath/dtestvec.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmath/mod2pi.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/ellf/ellf.c")

# ignore files who are exact duplicates of cmath
LIST(REMOVE_ITEM src
    "${CMAKE_CURRENT_SOURCE_DIR}/cprob/unity.c"
    )

# ignore rational polynomials of polyr.c,
# because it conflict with the simpler polynomials of polyn.c
LIST(REMOVE_ITEM src
    "${CMAKE_CURRENT_SOURCE_DIR}/polyn/polyr.c"
    )

add_library(cephes SHARED 
    ${src}
)
