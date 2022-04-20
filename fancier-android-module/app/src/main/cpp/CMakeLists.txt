cmake_minimum_required(VERSION 3.0.0)
project("module_test_app")

include (${ANDROID_GRADLE_NATIVE_BUNDLE_PLUGIN_MK})

add_library(module_test_app
            SHARED
            module_test_app.cpp )
find_library(log-lib log)
target_link_libraries(module_test_app ${log-lib} ${ANDROID_GRADLE_NATIVE_MODULES})
