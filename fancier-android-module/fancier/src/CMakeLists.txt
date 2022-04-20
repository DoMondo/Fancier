cmake_minimum_required(VERSION 3.0.0)
project("fancier")
set(native_path ../../../native)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # -fPIC
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-dangling-else")

add_library(OpenCL
            SHARED
            ${native_path}/core/src/CL/cl_egl.c
            ${native_path}/core/src/CL/cl_ext_intel.c
            ${native_path}/core/src/CL/cl_ext.c
            ${native_path}/core/src/CL/cl_gl.c
            ${native_path}/core/src/CL/cl.c
        )

add_library(fancier
            SHARED
            ${native_path}/core/src/array.c
            ${native_path}/core/src/color.c
            ${native_path}/core/src/exception.c
            ${native_path}/core/src/image.c
            ${native_path}/core/src/java.c
            ${native_path}/core/src/log.c
            ${native_path}/core/src/math.c
            ${native_path}/core/src/ocl.c
            ${native_path}/core/src/fancier.cpp
            ${native_path}/core/src/utils.c
            ${native_path}/core/src/vector_array.c
            ${native_path}/core/src/vector.c
            ${native_path}/core/src/fancier.cpp
        )

add_library(fancier_tiling
            SHARED
            ${native_path}/plugin/tiling/src/tiling.cpp
            ${native_path}/plugin/tiling/src/data_entry.cpp
        )



target_include_directories(OpenCL PUBLIC ${native_path}/core/include/)
target_include_directories(fancier PUBLIC ${native_path}/core/include/)
target_include_directories(fancier_tiling PUBLIC ${native_path}/plugin/tiling/include/)

find_library(log-lib log)
find_library(android-lib android)
find_library(jnigraphics-lib jnigraphics)

target_link_libraries(fancier ${android-lib} ${log-lib} ${jnigraphics-lib} OpenCL)
target_link_libraries(fancier_tiling fancier ${android-lib} ${log-lib} ${jnigraphics-lib} OpenCL)
