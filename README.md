# Fancier High-Performance API
[![Release](https://jitpack.io/v/DoMondo/Fancier.svg)](https://jitpack.io/#DoMondo/Fancier)

## Introduction

The _Fancier_ High-Performance API (from Uni**f**ied J**a**va, J**N**I and Open**C**L
**i**nt**e**g**r**ation High-Performance GPGPU API) provides a consistent API for Java, C/C++ and
mixed (Java + C/C++ through JNI) applications that enables their use of OpenCL's fixed-width vector
data types and math libraries.

This API provides a set of Java high-performance array and image classes that seamlessly integrate
Java and OpenCL execution minimizing data transfers and exploiting shared CPU/Accelerator memory in
architectures that support it, as well. Most OpenCL and JNI boilerplate is hidden from application
developers, so they can focus on their application domain.

It is primarily focused on the simple integration of Android applications with high-performance
OpenCL execution on multicore CPUs, GPUs, or DSPs present in modern Systems-on-Chip. Our design pays
special attention to ease of use and efficiency, and it is based on the OpenCL standard version 1.1.

## Code Generation

This section refers to the contents of the "_gen_" directory.

C/C++ and Java source files for the different fixed-size vector data types, as well as math
functions over these data types are generated through templates and updated by running the
`./generate.sh` script.

Any permanent changes to these automatically-generated files must be added to the corresponding
template file, and after these changes the final source files must be updated before committing to
the repository.

As a prerequisite to run the `generate.sh` script, it is necessary that the `python` command points
to a working Python 3 installation, and to run `pip install -r requirements.txt` once in order to
install the necessary dependencies.

```
$ virtualenv --python=python3.6 .env
$ source .env/bin/activate
(.env) $ python --version
Python 3.6.9

(.env) $ pip install -r requirements.txt
(.env) $ ./generate.sh
Template: "/path/to/fancier/gen/template/src/array.mako"
Output:   "/path/to/fancier/gen/../native/core/src/array.c"
Format:
...
```

## Building

### Java

This section refers to the contents of the "_java_" directory.

The Java library containing the various wrapper classes for C/C++ defined data types and fixed-size
vector data types is compiled using Gradle.

There are two main versions of the _Fancier_ Java library. One is intended for Android
applications, while the other can be used on any Linux system. They are compiled as follows:

- `fancier-jre-1.0.jar`: Built by the command `gradle :fancier-jre:build`, producing the output
library in "_project/jre/build/libs_".
- `fancier-android-1.0.jar`: Built by the command `gradle :fancier-android:build`, producing the
output library in "_project/android/build/libs_".

### C/C++

This section refers to the contents of the "_native_" directory.

Native libraries are built using different methods if they are to be executed in an Android system
or a regular Linux one.

For Linux, the `make all plugins` command should be enough to build the core and plugins into the
"_build_" and "_build/plugin_" directories, respectively. For that to work, a development version of
the Java Development Kit (JDK) version 1.8 or more recent must be installed in the system, and the
environment variable `JAVA_HOME` must be set.

For Android, the `Android.mk`, `AndroidPlugin.mk` and `Application.mk` makefiles are used instead,
which are configured to work with the `ndk-build` program, provided with the Android Native
Development Kit (NDK). In this case, the commands for compiling the core and plugin libraries are:
```
$ ndk-build NDK_PROJECT_PATH=build/android/core APP_BUILD_SCRIPT=Android.mk NDK_APPLICATION_MK=Application.mk
$ ndk-build NDK_PROJECT_PATH=build/android/plugin APP_BUILD_SCRIPT=AndroidPlugin.mk NDK_APPLICATION_MK=Application.mk
```

The libraries generated are `libfancier.so`, `libOpenCL.so` and one `libfancier_<plugin>.so` for
each plugin defined within the "_plugin_" directory. When building with `ndk-build`, there will be
a "_build/android/{core|plugin}/libs_" directory containing one subdirectory for each supported
Application Binary Interface (ABI) with each of these libraries. When building with `make`, the
resulting libraries will be found in the "_build/linux_" and "_build/linux/plugin_" directories.

`libOpenCL.so` is only a library of stubs that allows compiling in systems where the actual OpenCL
library is not installed and, most importantly, it allows Android applications to be compiled
without including it in the resulting `.apk` file, so at runtime a vendor-provided `libOpenCL.so`
can be used instead. This is necessary to circumvent Android's lack of official OpenCL support,
although some vendors do provide this high-performance library that can allow great increases in
performance.

Source code documentation in HTML format can be generated using Doxygen, by running the command:
```
$ make docs
```

The resulting documentation can be found in the "_docs_" directory.

## Usage

In order to make your _Fancier_ application, you must include its native headers and shared
libraries, and the corresponding `.jar` file, produced by building the _Fancier_ Java and Native
modules, to your Java project.

You can use the _Fancier_ Java API to use fixed-size vector and Math functions defined by the
OpenCL standard within Java. The _Fancier_ C/C++ API provides the same set of objects and functions
as the Java API, and utilities to deal with arrays of primitive and vector data types.

The use of _Fancier_ array types makes use of the OpenCL API, so that by simply ensuring its
contents are currently synced to OpenCL's target device, it is possible to use them as inputs and
outputs of accelerated OpenCL kernels. On modern SoCs where main memory is shared among all
computing processors, memory copies are avoided and performance gains can be achieved. Memory
copies to exchange data from Java's garbage collector-managed memory and _Fancier_ arrays are
unavoidable, so it is recommended that calls to `get`, `set` and `getContents` on _Fancier_ arrays
should be kept to a minimum, by reducing the interleaving of execution over these arrays between
Java and C/C++/OpenCL. It is best to `getContents` before processing a _Fancier_ array in Java
rather than use `get` and `set` if the amount of work to do on the array is substantial.

## Test applications

The "_test_" directory includes test applications showing the intended usage and configuration of
the _Fancier_ API. The `copy_libs.sh` script copies the already-compiled `.jar` and `.so` files from
their build directories into the paths where these test applications expect them to be placed in
order to be able to link and run their code.

## Publishing the android module
See [fancier-android-module/PUBLISHING.md](fancier-android-module/PUBLISHING.md)

## Using the Android module

### Step 1
Add it in your root build.gradle at the end of repositories:
```groovy
allprojects {
	repositories {
		...
		maven { url 'https://jitpack.io' }
	}
}
```
### Step 2
Add the dependency.
```
dependencies {
        implementation 'com.github.DoMondo:Fancier:Tag'
}
```

## License

See [COPYING](COPYING.txt) and [COPYING.LESSER](COPYING.LESSER.txt).

This project uses third-party software distributed under their own terms. See
[LICENSE-3RD-PARTY](LICENSE-3RD-PARTY.txt).
