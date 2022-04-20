/*
 * Fancier: Unified Java, JNI and OpenCL Integration High-Performance GPGPU API.
 * Copyright (C) 2021 Universidad de La Laguna.
 *
 * Fancier is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Fancier is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Fancier.  If not, see <https://www.gnu.org/licenses/>.
 */

/*
 * DO NOT MANUALLY EDIT THIS FILE!
 * This file has been automatically generated, any modifications will be lost
 * when generating the Fancier library. Any modifications to this file must be
 * done via the corresponding template.
 */

#ifndef _FANCIER_ARRAY_H_
#define _FANCIER_ARRAY_H_

#include <fancier/platform.h>

// clang-format off
/// Current possible memory locations for the updated array data.
typedef enum {
  FC_ARRAY_LOCATION_NONE,
  FC_ARRAY_LOCATION_NATIVE,
  FC_ARRAY_LOCATION_OPENCL,
} fcArrayLocation;
// clang-format on

// Global Java References

extern jclass fcByteArray_class;
extern jmethodID fcByteArray_constructor;

extern jclass fcShortArray_class;
extern jmethodID fcShortArray_constructor;

extern jclass fcIntArray_class;
extern jmethodID fcIntArray_constructor;

extern jclass fcLongArray_class;
extern jmethodID fcLongArray_constructor;

extern jclass fcFloatArray_class;
extern jmethodID fcFloatArray_constructor;

extern jclass fcDoubleArray_class;
extern jmethodID fcDoubleArray_constructor;


// Native Definitions

/// Native representation of an array of elements of type `byte`.
typedef struct {
  /// Reference counter for the buffer inside.
  ///
  /// Multiple pointers to the same object can be created, and a reference counter must be
  /// created in order to only free the contents when there are no more references to it.
  fcInt ref_count;

  /// Number of elements in the array.
  fcInt len;

  /// Pointer to native elements. Only valid when `location = FC_ARRAY_LOCATION_NATIVE`.
  fcByte* c;

  /// OpenCL buffer to array elements. Only valid when `location = FC_ARRAY_LOCATION_OPENCL`.
  cl_mem ocl;

  /// Current location of the array data.
  int location;
} fcByteArray;

/// Native representation of an array of elements of type `short`.
typedef struct {
  /// Reference counter for the buffer inside.
  ///
  /// Multiple pointers to the same object can be created, and a reference counter must be
  /// created in order to only free the contents when there are no more references to it.
  fcInt ref_count;

  /// Number of elements in the array.
  fcInt len;

  /// Pointer to native elements. Only valid when `location = FC_ARRAY_LOCATION_NATIVE`.
  fcShort* c;

  /// OpenCL buffer to array elements. Only valid when `location = FC_ARRAY_LOCATION_OPENCL`.
  cl_mem ocl;

  /// Current location of the array data.
  int location;
} fcShortArray;

/// Native representation of an array of elements of type `int`.
typedef struct {
  /// Reference counter for the buffer inside.
  ///
  /// Multiple pointers to the same object can be created, and a reference counter must be
  /// created in order to only free the contents when there are no more references to it.
  fcInt ref_count;

  /// Number of elements in the array.
  fcInt len;

  /// Pointer to native elements. Only valid when `location = FC_ARRAY_LOCATION_NATIVE`.
  fcInt* c;

  /// OpenCL buffer to array elements. Only valid when `location = FC_ARRAY_LOCATION_OPENCL`.
  cl_mem ocl;

  /// Current location of the array data.
  int location;
} fcIntArray;

/// Native representation of an array of elements of type `long`.
typedef struct {
  /// Reference counter for the buffer inside.
  ///
  /// Multiple pointers to the same object can be created, and a reference counter must be
  /// created in order to only free the contents when there are no more references to it.
  fcInt ref_count;

  /// Number of elements in the array.
  fcInt len;

  /// Pointer to native elements. Only valid when `location = FC_ARRAY_LOCATION_NATIVE`.
  fcLong* c;

  /// OpenCL buffer to array elements. Only valid when `location = FC_ARRAY_LOCATION_OPENCL`.
  cl_mem ocl;

  /// Current location of the array data.
  int location;
} fcLongArray;

/// Native representation of an array of elements of type `float`.
typedef struct {
  /// Reference counter for the buffer inside.
  ///
  /// Multiple pointers to the same object can be created, and a reference counter must be
  /// created in order to only free the contents when there are no more references to it.
  fcInt ref_count;

  /// Number of elements in the array.
  fcInt len;

  /// Pointer to native elements. Only valid when `location = FC_ARRAY_LOCATION_NATIVE`.
  fcFloat* c;

  /// OpenCL buffer to array elements. Only valid when `location = FC_ARRAY_LOCATION_OPENCL`.
  cl_mem ocl;

  /// Current location of the array data.
  int location;
} fcFloatArray;

/// Native representation of an array of elements of type `double`.
typedef struct {
  /// Reference counter for the buffer inside.
  ///
  /// Multiple pointers to the same object can be created, and a reference counter must be
  /// created in order to only free the contents when there are no more references to it.
  fcInt ref_count;

  /// Number of elements in the array.
  fcInt len;

  /// Pointer to native elements. Only valid when `location = FC_ARRAY_LOCATION_NATIVE`.
  fcDouble* c;

  /// OpenCL buffer to array elements. Only valid when `location = FC_ARRAY_LOCATION_OPENCL`.
  cl_mem ocl;

  /// Current location of the array data.
  int location;
} fcDoubleArray;


// Native Interface

FANCIER_API jint fcArray_initJNI(JNIEnv* env);
FANCIER_API void fcArray_releaseJNI(JNIEnv* env);

FANCIER_API fcByteArray* fcByteArray_getJava(JNIEnv* env, jobject obj);
FANCIER_API fcError fcByteArray_createRef(fcByteArray* array);
FANCIER_API fcError fcByteArray_releaseRef(fcByteArray* array);

FANCIER_API fcError fcByteArray_init(fcByteArray* self);
FANCIER_API fcError fcByteArray_initSize(fcByteArray* self, fcInt n);
FANCIER_API fcError fcByteArray_initArray(fcByteArray* self, fcInt len, const fcByte* v);
FANCIER_API fcError fcByteArray_initCopy(fcByteArray* self, const fcByteArray* array);
FANCIER_API fcError fcByteArray_initPtr(fcByteArray* self, void * ptr, fcInt len);
FANCIER_API fcError fcByteArray_release(fcByteArray* self);

FANCIER_API fcByte fcByteArray_get(fcByteArray* self, fcInt i, fcError* err);
FANCIER_API fcError fcByteArray_set(fcByteArray* self, fcInt i, fcByte x);

FANCIER_API fcError fcByteArray_setArray(fcByteArray* self, fcInt len, const fcByte* v);
FANCIER_API fcError fcByteArray_setCopy(fcByteArray* self, const fcByteArray* array);
FANCIER_API fcError fcByteArray_setBuffer(fcByteArray* self, fcLong len, const void* v);

FANCIER_API fcError fcByteArray_syncToNative(fcByteArray* self);
FANCIER_API fcError fcByteArray_syncToOCL(fcByteArray* self);
FANCIER_API fcBool fcByteArray_valid(const fcByteArray* self);

FANCIER_API fcShortArray* fcShortArray_getJava(JNIEnv* env, jobject obj);
FANCIER_API fcError fcShortArray_createRef(fcShortArray* array);
FANCIER_API fcError fcShortArray_releaseRef(fcShortArray* array);

FANCIER_API fcError fcShortArray_init(fcShortArray* self);
FANCIER_API fcError fcShortArray_initSize(fcShortArray* self, fcInt n);
FANCIER_API fcError fcShortArray_initArray(fcShortArray* self, fcInt len, const fcShort* v);
FANCIER_API fcError fcShortArray_initCopy(fcShortArray* self, const fcShortArray* array);
FANCIER_API fcError fcShortArray_initPtr(fcShortArray* self, void * ptr, fcInt len);
FANCIER_API fcError fcShortArray_release(fcShortArray* self);

FANCIER_API fcShort fcShortArray_get(fcShortArray* self, fcInt i, fcError* err);
FANCIER_API fcError fcShortArray_set(fcShortArray* self, fcInt i, fcShort x);

FANCIER_API fcError fcShortArray_setArray(fcShortArray* self, fcInt len, const fcShort* v);
FANCIER_API fcError fcShortArray_setCopy(fcShortArray* self, const fcShortArray* array);
FANCIER_API fcError fcShortArray_setBuffer(fcShortArray* self, fcLong len, const void* v);

FANCIER_API fcError fcShortArray_syncToNative(fcShortArray* self);
FANCIER_API fcError fcShortArray_syncToOCL(fcShortArray* self);
FANCIER_API fcBool fcShortArray_valid(const fcShortArray* self);

FANCIER_API fcIntArray* fcIntArray_getJava(JNIEnv* env, jobject obj);
FANCIER_API fcError fcIntArray_createRef(fcIntArray* array);
FANCIER_API fcError fcIntArray_releaseRef(fcIntArray* array);

FANCIER_API fcError fcIntArray_init(fcIntArray* self);
FANCIER_API fcError fcIntArray_initSize(fcIntArray* self, fcInt n);
FANCIER_API fcError fcIntArray_initArray(fcIntArray* self, fcInt len, const fcInt* v);
FANCIER_API fcError fcIntArray_initCopy(fcIntArray* self, const fcIntArray* array);
FANCIER_API fcError fcIntArray_initPtr(fcIntArray* self, void * ptr, fcInt len);
FANCIER_API fcError fcIntArray_release(fcIntArray* self);

FANCIER_API fcInt fcIntArray_get(fcIntArray* self, fcInt i, fcError* err);
FANCIER_API fcError fcIntArray_set(fcIntArray* self, fcInt i, fcInt x);

FANCIER_API fcError fcIntArray_setArray(fcIntArray* self, fcInt len, const fcInt* v);
FANCIER_API fcError fcIntArray_setCopy(fcIntArray* self, const fcIntArray* array);
FANCIER_API fcError fcIntArray_setBuffer(fcIntArray* self, fcLong len, const void* v);

FANCIER_API fcError fcIntArray_syncToNative(fcIntArray* self);
FANCIER_API fcError fcIntArray_syncToOCL(fcIntArray* self);
FANCIER_API fcBool fcIntArray_valid(const fcIntArray* self);

FANCIER_API fcLongArray* fcLongArray_getJava(JNIEnv* env, jobject obj);
FANCIER_API fcError fcLongArray_createRef(fcLongArray* array);
FANCIER_API fcError fcLongArray_releaseRef(fcLongArray* array);

FANCIER_API fcError fcLongArray_init(fcLongArray* self);
FANCIER_API fcError fcLongArray_initSize(fcLongArray* self, fcInt n);
FANCIER_API fcError fcLongArray_initArray(fcLongArray* self, fcInt len, const fcLong* v);
FANCIER_API fcError fcLongArray_initCopy(fcLongArray* self, const fcLongArray* array);
FANCIER_API fcError fcLongArray_initPtr(fcLongArray* self, void * ptr, fcInt len);
FANCIER_API fcError fcLongArray_release(fcLongArray* self);

FANCIER_API fcLong fcLongArray_get(fcLongArray* self, fcInt i, fcError* err);
FANCIER_API fcError fcLongArray_set(fcLongArray* self, fcInt i, fcLong x);

FANCIER_API fcError fcLongArray_setArray(fcLongArray* self, fcInt len, const fcLong* v);
FANCIER_API fcError fcLongArray_setCopy(fcLongArray* self, const fcLongArray* array);
FANCIER_API fcError fcLongArray_setBuffer(fcLongArray* self, fcLong len, const void* v);

FANCIER_API fcError fcLongArray_syncToNative(fcLongArray* self);
FANCIER_API fcError fcLongArray_syncToOCL(fcLongArray* self);
FANCIER_API fcBool fcLongArray_valid(const fcLongArray* self);

FANCIER_API fcFloatArray* fcFloatArray_getJava(JNIEnv* env, jobject obj);
FANCIER_API fcError fcFloatArray_createRef(fcFloatArray* array);
FANCIER_API fcError fcFloatArray_releaseRef(fcFloatArray* array);

FANCIER_API fcError fcFloatArray_init(fcFloatArray* self);
FANCIER_API fcError fcFloatArray_initSize(fcFloatArray* self, fcInt n);
FANCIER_API fcError fcFloatArray_initArray(fcFloatArray* self, fcInt len, const fcFloat* v);
FANCIER_API fcError fcFloatArray_initCopy(fcFloatArray* self, const fcFloatArray* array);
FANCIER_API fcError fcFloatArray_initPtr(fcFloatArray* self, void * ptr, fcInt len);
FANCIER_API fcError fcFloatArray_release(fcFloatArray* self);

FANCIER_API fcFloat fcFloatArray_get(fcFloatArray* self, fcInt i, fcError* err);
FANCIER_API fcError fcFloatArray_set(fcFloatArray* self, fcInt i, fcFloat x);

FANCIER_API fcError fcFloatArray_setArray(fcFloatArray* self, fcInt len, const fcFloat* v);
FANCIER_API fcError fcFloatArray_setCopy(fcFloatArray* self, const fcFloatArray* array);
FANCIER_API fcError fcFloatArray_setBuffer(fcFloatArray* self, fcLong len, const void* v);

FANCIER_API fcError fcFloatArray_syncToNative(fcFloatArray* self);
FANCIER_API fcError fcFloatArray_syncToOCL(fcFloatArray* self);
FANCIER_API fcBool fcFloatArray_valid(const fcFloatArray* self);

FANCIER_API fcDoubleArray* fcDoubleArray_getJava(JNIEnv* env, jobject obj);
FANCIER_API fcError fcDoubleArray_createRef(fcDoubleArray* array);
FANCIER_API fcError fcDoubleArray_releaseRef(fcDoubleArray* array);

FANCIER_API fcError fcDoubleArray_init(fcDoubleArray* self);
FANCIER_API fcError fcDoubleArray_initSize(fcDoubleArray* self, fcInt n);
FANCIER_API fcError fcDoubleArray_initArray(fcDoubleArray* self, fcInt len, const fcDouble* v);
FANCIER_API fcError fcDoubleArray_initCopy(fcDoubleArray* self, const fcDoubleArray* array);
FANCIER_API fcError fcDoubleArray_initPtr(fcDoubleArray* self, void * ptr, fcInt len);
FANCIER_API fcError fcDoubleArray_release(fcDoubleArray* self);

FANCIER_API fcDouble fcDoubleArray_get(fcDoubleArray* self, fcInt i, fcError* err);
FANCIER_API fcError fcDoubleArray_set(fcDoubleArray* self, fcInt i, fcDouble x);

FANCIER_API fcError fcDoubleArray_setArray(fcDoubleArray* self, fcInt len, const fcDouble* v);
FANCIER_API fcError fcDoubleArray_setCopy(fcDoubleArray* self, const fcDoubleArray* array);
FANCIER_API fcError fcDoubleArray_setBuffer(fcDoubleArray* self, fcLong len, const void* v);

FANCIER_API fcError fcDoubleArray_syncToNative(fcDoubleArray* self);
FANCIER_API fcError fcDoubleArray_syncToOCL(fcDoubleArray* self);
FANCIER_API fcBool fcDoubleArray_valid(const fcDoubleArray* self);

#endif  // _FANCIER_ARRAY_H_
