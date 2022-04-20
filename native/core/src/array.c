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

#include <fancier/array.h>

#include <fancier/exception.h>
#include <fancier/java.h>
#include <fancier/ocl.h>

#include <string.h>

#include <fancier/internal/snippets.inc>


//
// Global Java References
//

jclass fcByteArray_class = NULL;
jmethodID fcByteArray_constructor = NULL;
jclass fcShortArray_class = NULL;
jmethodID fcShortArray_constructor = NULL;
jclass fcIntArray_class = NULL;
jmethodID fcIntArray_constructor = NULL;
jclass fcLongArray_class = NULL;
jmethodID fcLongArray_constructor = NULL;
jclass fcFloatArray_class = NULL;
jmethodID fcFloatArray_constructor = NULL;
jclass fcDoubleArray_class = NULL;
jmethodID fcDoubleArray_constructor = NULL;

//
// Global Java Initialization / Destruction
//

jint fcArray_initJNI(JNIEnv* env) {
  FC_INIT_CLASS_REF(env, "es/ull/pcg/hpc/fancier/array/ByteArray", fcByteArray_class,
                    "fcArray_initJNI", FC_EXCEPTION_OTHER);
  FC_INIT_CONSTRUCTOR(env, fcByteArray_constructor, fcByteArray_class, "J", "fcArray_initJNI",
                      FC_EXCEPTION_METHOD_NOT_FOUND);
  FC_INIT_CLASS_REF(env, "es/ull/pcg/hpc/fancier/array/ShortArray", fcShortArray_class,
                    "fcArray_initJNI", FC_EXCEPTION_OTHER);
  FC_INIT_CONSTRUCTOR(env, fcShortArray_constructor, fcShortArray_class, "J", "fcArray_initJNI",
                      FC_EXCEPTION_METHOD_NOT_FOUND);
  FC_INIT_CLASS_REF(env, "es/ull/pcg/hpc/fancier/array/IntArray", fcIntArray_class,
                    "fcArray_initJNI", FC_EXCEPTION_OTHER);
  FC_INIT_CONSTRUCTOR(env, fcIntArray_constructor, fcIntArray_class, "J", "fcArray_initJNI",
                      FC_EXCEPTION_METHOD_NOT_FOUND);
  FC_INIT_CLASS_REF(env, "es/ull/pcg/hpc/fancier/array/LongArray", fcLongArray_class,
                    "fcArray_initJNI", FC_EXCEPTION_OTHER);
  FC_INIT_CONSTRUCTOR(env, fcLongArray_constructor, fcLongArray_class, "J", "fcArray_initJNI",
                      FC_EXCEPTION_METHOD_NOT_FOUND);
  FC_INIT_CLASS_REF(env, "es/ull/pcg/hpc/fancier/array/FloatArray", fcFloatArray_class,
                    "fcArray_initJNI", FC_EXCEPTION_OTHER);
  FC_INIT_CONSTRUCTOR(env, fcFloatArray_constructor, fcFloatArray_class, "J", "fcArray_initJNI",
                      FC_EXCEPTION_METHOD_NOT_FOUND);
  FC_INIT_CLASS_REF(env, "es/ull/pcg/hpc/fancier/array/DoubleArray", fcDoubleArray_class,
                    "fcArray_initJNI", FC_EXCEPTION_OTHER);
  FC_INIT_CONSTRUCTOR(env, fcDoubleArray_constructor, fcDoubleArray_class, "J", "fcArray_initJNI",
                      FC_EXCEPTION_METHOD_NOT_FOUND);

  return FC_EXCEPTION_SUCCESS;
}

void fcArray_releaseJNI(JNIEnv* env) {
  FC_FREE_CLASS_REF(env, fcByteArray_class);
  fcByteArray_constructor = NULL;
  FC_FREE_CLASS_REF(env, fcShortArray_class);
  fcShortArray_constructor = NULL;
  FC_FREE_CLASS_REF(env, fcIntArray_class);
  fcIntArray_constructor = NULL;
  FC_FREE_CLASS_REF(env, fcLongArray_class);
  fcLongArray_constructor = NULL;
  FC_FREE_CLASS_REF(env, fcFloatArray_class);
  fcFloatArray_constructor = NULL;
  FC_FREE_CLASS_REF(env, fcDoubleArray_class);
  fcDoubleArray_constructor = NULL;
}

int release_ocl(cl_mem ocl) {
   void * host_ptr;
   clGetMemObjectInfo(ocl, CL_MEM_HOST_PTR,sizeof(void*), &host_ptr, NULL);
   if (host_ptr != NULL)
      return 0;
    int err = clReleaseMemObject(ocl);
    return err;
}


//
// fcByteArray
//

FC_JAVA_INSTANCE_HANDLERS(fcByteArray);

//
// Java Interface Implementation
//

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_initNative__J(JNIEnv* env, jobject obj, jlong nativePtr) {
  // Create reference
  fcByteArray* self = (fcByteArray*) nativePtr;
  jint err = fcByteArray_createRef(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_createRef", FC_VOID_EXPR);

  // Store native pointer on the Java object
  fcByteArray_setJava(env, obj, nativePtr);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_initNative__I(JNIEnv* env, jobject obj, jint n) {
  // Allocate instance
  fcByteArray* self = fcByteArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_allocJava", FC_VOID_EXPR);

  // Initialize array
  jint err = fcByteArray_initSize(self, n);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_initSize", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_initNative___3B(JNIEnv* env, jobject obj, jbyteArray v) {
  // Allocate instance
  fcByteArray* self = fcByteArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_allocJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcByteArray_initNative__[B:v", FC_VOID_EXPR);

  // Initialize array
  jsize __tmp_len = FC_JNI_CALL(env, GetArrayLength, v);
  jbyte* __tmp_elems_v = FC_JNI_CALL(env, GetByteArrayElements, v, NULL);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcByteArray_initNative__[B:v", FC_VOID_EXPR);

  jint err = fcByteArray_initArray(self, __tmp_len, __tmp_elems_v);

  // Free temporary native array reference
  FC_JNI_CALL(env, ReleaseByteArrayElements, v, __tmp_elems_v, JNI_ABORT);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_initArray", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_initNative__Les_ull_pcg_hpc_fancier_array_ByteArray_2(JNIEnv* env, jobject obj, jobject array) {
  // Allocate instance
  fcByteArray* self = fcByteArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_allocJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, array, FC_EXCEPTION_BAD_PARAMETER, "fcByteArray_initNative__Les_ull_pcg_hpc_fancier_vector_array_ByteArray;:array", FC_VOID_EXPR);

  // Initialize array
  fcByteArray* __tmp_array = fcByteArray_getJava(env, array);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_array, FC_EXCEPTION_BAD_PARAMETER, "fcByteArray_getJava:array", FC_VOID_EXPR);

  jint err = fcByteArray_initCopy(self, __tmp_array);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_initCopy", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_initNative__Ljava_nio_ByteBuffer_2(JNIEnv* env, jobject obj, jobject buffer) {
  void *buff = (*env)->GetDirectBufferAddress(env, buffer);
  jlong size = (*env)->GetDirectBufferCapacity(env, buffer);

  // Allocate instance
  fcByteArray* self = fcByteArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_allocJava", FC_VOID_EXPR);

  // Store the pointer to array
  jint err = fcByteArray_initPtr(self, buff, size);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_initPtr", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_releaseNative(JNIEnv* env, jobject obj) {
  fcByteArray* self = fcByteArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_getJava", FC_VOID_EXPR);

  // Release memory buffers and decrease the reference count to the instance object
  jint err = fcByteArray_release(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_release", FC_VOID_EXPR);

  fcByteArray_setJava(env, obj, 0L);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_releaseNativeRef(JNIEnv* env, jobject obj) {
  fcByteArray* self = fcByteArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_getJava", FC_VOID_EXPR);

  // Release the reference to the instance object and only release the buffers in it as well if this was the
  // only remaining reference to that object
  jint err = fcByteArray_releaseRef(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_releaseRef", FC_VOID_EXPR);

  fcByteArray_setJava(env, obj, 0L);
}

JNIEXPORT jbyte JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_get__I(JNIEnv* env, jobject obj, jint i) {
  fcByteArray* self = fcByteArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_getJava", '\0');

  jint err;
  fcByte __tmp_ret = fcByteArray_get(self, i, &err);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_get", '\0');

  return __tmp_ret;
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_set__IB(JNIEnv* env, jobject obj, jint i, jbyte x) {
  fcByteArray* self = fcByteArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_getJava", FC_VOID_EXPR);

  jint err = fcByteArray_set(self, i, x);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_set", FC_VOID_EXPR);
}

JNIEXPORT jlong JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_length(JNIEnv* env, jobject obj) {
  fcByteArray* self = fcByteArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_getJava", 0L);

  if (!fcByteArray_valid(self))
    FC_EXCEPTION_HANDLE_ERROR(env, FC_EXCEPTION_INVALID_STATE, "fcByteArray_length", 0L);

  return (jlong) self->len;
}

JNIEXPORT jbyteArray JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_getArray(JNIEnv* env, jobject obj) {
  fcByteArray* self = fcByteArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_getJava", NULL);

  // Ensure native array is synced
  jint err = fcByteArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_syncToNative", NULL);

  // Create Java array and populate it
  jbyteArray __tmp_ret = FC_JNI_CALL(env, NewByteArray, self->len);
  FC_EXCEPTION_HANDLE_PENDING(env, !__tmp_ret, "fcByteArray_getArray", NULL);

  FC_JNI_CALL(env, SetByteArrayRegion, __tmp_ret, 0, self->len, self->c);
  FC_EXCEPTION_HANDLE_PENDING(env, FC_FALSE, "fcByteArray_getArray", __tmp_ret);

  return __tmp_ret;
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_setArray(JNIEnv* env, jobject obj, jbyteArray v) {
  fcByteArray* self = fcByteArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcByteArray_setArray:v", FC_VOID_EXPR);

  // Get array elements and length
  jsize __tmp_len = FC_JNI_CALL(env, GetArrayLength, v);
  jbyte* __tmp_elems_v = FC_JNI_CALL(env, GetByteArrayElements, v, NULL);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcByteArray_setArray:v", FC_VOID_EXPR);

  jint err = fcByteArray_setArray(self, __tmp_len, __tmp_elems_v);

  // Free temporary native array reference
  FC_JNI_CALL(env, ReleaseByteArrayElements, v, __tmp_elems_v, JNI_ABORT);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_setArray", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_setCopy(JNIEnv* env, jobject obj, jobject array) {
  fcByteArray* self = fcByteArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, array, FC_EXCEPTION_BAD_PARAMETER, "fcByteArray_setCopy:array", FC_VOID_EXPR);

  // Get array elements and length
  fcByteArray* __tmp_array = fcByteArray_getJava(env, array);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_array, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcByteArray_setCopy:array", FC_VOID_EXPR);

  jint err = fcByteArray_setCopy(self, __tmp_array);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_setCopy", FC_VOID_EXPR);
}

JNIEXPORT jobject JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_getBufferImpl(JNIEnv* env, jobject obj) {
  fcByteArray* self = fcByteArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_getJava", NULL);

  // Ensure native array is synced
  jint err = fcByteArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_syncToNative", NULL);

  // Create and return direct byte buffer pointing to the native data
  return FC_JNI_CALL(env, NewDirectByteBuffer, self->c, self->len * sizeof(fcByte));
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_setBuffer(JNIEnv* env, jobject obj, jobject v) {
  fcByteArray* self = fcByteArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcByteArray_setBuffer:v", FC_VOID_EXPR);

  // Get buffer size and pointer
  jlong __tmp_len = FC_JNI_CALL(env, GetDirectBufferCapacity, v);
  void* __tmp_elems_v = FC_JNI_CALL(env, GetDirectBufferAddress, v);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcByteArray_setBuffer:v", FC_VOID_EXPR);

  jint err = fcByteArray_setBuffer(self, __tmp_len, __tmp_elems_v);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_setBuffer", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_syncToNative(JNIEnv* env, jobject obj) {
  fcByteArray* self = fcByteArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_getJava", FC_VOID_EXPR);

  jint err = fcByteArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_syncToNative", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ByteArray_syncToOCL(JNIEnv* env, jobject obj) {
  fcByteArray* self = fcByteArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcByteArray_getJava", FC_VOID_EXPR);

  jint err = fcByteArray_syncToOCL(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcByteArray_syncToOCL", FC_VOID_EXPR);
}

//
// Native Interface Implementation
//

fcError fcByteArray_createRef(fcByteArray* array) {
  if (array == NULL || array->location == FC_ARRAY_LOCATION_NONE)
    return FC_EXCEPTION_BAD_PARAMETER;

  ++array->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcByteArray_releaseRef(fcByteArray* array) {
  if (array == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  if (array->ref_count <= 1)
    return fcByteArray_release(array);

  --array->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcByteArray_init(fcByteArray* self) {
  if (self->location != FC_ARRAY_LOCATION_NONE)
    return FC_EXCEPTION_INVALID_STATE;

  ++self->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcByteArray_initSize(fcByteArray* self, fcInt n) {
  fcError err;

  // Check parameters
  if (n <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  err = fcByteArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = n;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcByte), NULL, &err);
  if (err) return err;

  // Update location
  self->location = FC_ARRAY_LOCATION_OPENCL;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcByteArray_initArray(fcByteArray* self, fcInt len, const fcByte* v) {
  fcError err;

  // Check parameters
  if (len <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (v == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcByteArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcByte), NULL, &err);
  if (err) return err;

  // Initialize array
  self->location = FC_ARRAY_LOCATION_OPENCL;
  err = fcByteArray_setArray(self, len, v);

  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
    return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcByteArray_initPtr(fcByteArray* self, void * ptr, fcInt len) {
  fcError err;

  // Check parameters
  if (len <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (ptr == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcByteArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, self->len * sizeof(fcByte), ptr, &err);
  if (err) return err;

  // Initialize array
  self->location = FC_ARRAY_LOCATION_OPENCL;
  self->c = ptr;

  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
    return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcByteArray_initCopy(fcByteArray* self, const fcByteArray* array) {
  fcError err;

  // Check parameters
  if (array == NULL || !fcByteArray_valid(array))
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcByteArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = array->len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcByte), NULL, &err);
  if (err) return err;

  // Copy array data
  self->location = FC_ARRAY_LOCATION_OPENCL;
  err = fcByteArray_setCopy(self, array);
  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
  }

  return err;
}

fcError fcByteArray_release(fcByteArray* self) {
  --self->ref_count;

  // If it has already been released, only decrease the reference count
  if (self->location != FC_ARRAY_LOCATION_NONE) {
    fcError err = 0;

    if (self->c != NULL) {
      if (self->location != FC_ARRAY_LOCATION_OPENCL) {
        if (self->ocl == NULL) {
          ++self->ref_count;
          return FC_EXCEPTION_INVALID_STATE;
        }
        err = clEnqueueUnmapMemObject(fcOpenCL_rt.queue, self->ocl, self->c, 0, NULL, NULL);
      }

      self->c = NULL;
      if (err) {
        ++self->ref_count; // Release did not succeed, so restore the ref count
        return err;
      }
    }

    if (self->ocl != NULL) {
      err = release_ocl(self->ocl);

      self->ocl = NULL;
      if (err) {
        ++self->ref_count; // Release did not succeed, so restore the ref count
        return err;
      }
    }

    // Mark the object as deleted
    self->location = FC_ARRAY_LOCATION_NONE;
  }

  // Release the instance object if there are no other references to it elsewhere
  if (self->ref_count <= 0)
    free(self);

  return FC_EXCEPTION_SUCCESS;
}

fcByte fcByteArray_get(fcByteArray* self, fcInt i, fcError* err) {
  fcError __tmp_err;
  if (err == NULL) err = &__tmp_err;

  fcByte __tmp_ret = '\0';
  if (!fcByteArray_valid(self)) {
    *err = FC_EXCEPTION_INVALID_STATE;
    return __tmp_ret;
  }

  if (i < 0 || i >= self->len) {
    *err = FC_EXCEPTION_BAD_PARAMETER;
    return __tmp_ret;
  }

  // Set location to native in order to access the array data
  *err = fcByteArray_syncToNative(self);
  if (*err) return __tmp_ret;

  return self->c[i];
}

fcError fcByteArray_set(fcByteArray* self, fcInt i, fcByte x) {
  if (!fcByteArray_valid(self)) return FC_EXCEPTION_INVALID_STATE;
  if (i < 0 || i >= self->len) return FC_EXCEPTION_BAD_PARAMETER;

  // Set location to native in order to access the array data
  fcError err = fcByteArray_syncToNative(self);
  if (err)
    return err;

  self->c[i] = x;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcByteArray_setArray(fcByteArray* self, fcInt len, const fcByte* v) {
  // No alignment issues, so we can just call setBuffer
  return fcByteArray_setBuffer(self, len * sizeof(fcByte), v);
}

fcError fcByteArray_setCopy(fcByteArray* self, const fcByteArray* array) {
  if (!fcByteArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  // Check parameters
  if (array == NULL || !fcByteArray_valid(array) || self->len != array->len)
    return FC_EXCEPTION_BAD_PARAMETER;

  // Copy array data
  fcError err;
  fcLong size = self->len * sizeof(fcByte);

  if (self->location == FC_ARRAY_LOCATION_OPENCL) {
    if (array->location == FC_ARRAY_LOCATION_OPENCL)
      err = clEnqueueCopyBuffer(fcOpenCL_rt.queue, array->ocl, self->ocl, 0, 0, size, 0, NULL, NULL);
    else /* array:FC_ARRAY_LOCATION_NATIVE */
      err = clEnqueueWriteBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, 0, size, array->c, 0, NULL, NULL);
  } else /* self:FC_ARRAY_LOCATION_NATIVE */ {
    if (array->location == FC_ARRAY_LOCATION_OPENCL)
      err = clEnqueueReadBuffer(fcOpenCL_rt.queue, array->ocl, CL_TRUE, 0, size, self->c, 0, NULL, NULL);
    else /* array:FC_ARRAY_LOCATION_NATIVE */
      err = memcpy(self->c, array->c, size) != NULL? FC_EXCEPTION_SUCCESS : FC_EXCEPTION_FAILED_COPY;
  }

  return err;
}

fcError fcByteArray_setBuffer(fcByteArray* self, fcLong len, const void* v) {
  if (!fcByteArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  // Check parameters
  if (len <= 0 || len % sizeof(fcByte) != 0 || len / sizeof(fcByte) != self->len)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (v == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  // Copy buffer
  fcError err;
  if (self->location == FC_ARRAY_LOCATION_OPENCL) {
    err = clEnqueueWriteBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, 0, len, v, 0, NULL, NULL);
    if (err) return err;
  }
  else /* self->location == FC_ARRAY_LOCATION_NATIVE */ {
    err = (memcpy(self->c, v, len) != NULL? FC_EXCEPTION_SUCCESS : FC_EXCEPTION_FAILED_COPY);
    if (err) return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcByteArray_syncToNative(fcByteArray* self) {
  if (!fcByteArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  fcError err = FC_EXCEPTION_SUCCESS;

  if (self->location == FC_ARRAY_LOCATION_OPENCL)
    self->c = clEnqueueMapBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, self->len * sizeof(fcByte), 0, NULL, NULL, &err);

  if (!err)
    self->location = FC_ARRAY_LOCATION_NATIVE;

  return err;
}

fcError fcByteArray_syncToOCL(fcByteArray* self) {
  if (!fcByteArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  fcError err = FC_EXCEPTION_SUCCESS;

  if (self->location == FC_ARRAY_LOCATION_NATIVE)
    err = clEnqueueUnmapMemObject(fcOpenCL_rt.queue, self->ocl, self->c, 0, NULL, NULL);

  if (!err)
    self->location = FC_ARRAY_LOCATION_OPENCL;

  return FC_EXCEPTION_SUCCESS;
}

fcBool fcByteArray_valid(const fcByteArray* self) {
  return self->len > 0 &&
    ((self->location == FC_ARRAY_LOCATION_NATIVE && self->c != NULL) ||
     (self->location == FC_ARRAY_LOCATION_OPENCL && self->ocl != NULL));
}


//
// fcShortArray
//

FC_JAVA_INSTANCE_HANDLERS(fcShortArray);

//
// Java Interface Implementation
//

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_initNative__J(JNIEnv* env, jobject obj, jlong nativePtr) {
  // Create reference
  fcShortArray* self = (fcShortArray*) nativePtr;
  jint err = fcShortArray_createRef(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_createRef", FC_VOID_EXPR);

  // Store native pointer on the Java object
  fcShortArray_setJava(env, obj, nativePtr);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_initNative__I(JNIEnv* env, jobject obj, jint n) {
  // Allocate instance
  fcShortArray* self = fcShortArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_allocJava", FC_VOID_EXPR);

  // Initialize array
  jint err = fcShortArray_initSize(self, n);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_initSize", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_initNative___3S(JNIEnv* env, jobject obj, jshortArray v) {
  // Allocate instance
  fcShortArray* self = fcShortArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_allocJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcShortArray_initNative__[S:v", FC_VOID_EXPR);

  // Initialize array
  jsize __tmp_len = FC_JNI_CALL(env, GetArrayLength, v);
  jshort* __tmp_elems_v = FC_JNI_CALL(env, GetShortArrayElements, v, NULL);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcShortArray_initNative__[S:v", FC_VOID_EXPR);

  jint err = fcShortArray_initArray(self, __tmp_len, __tmp_elems_v);

  // Free temporary native array reference
  FC_JNI_CALL(env, ReleaseShortArrayElements, v, __tmp_elems_v, JNI_ABORT);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_initArray", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_initNative__Les_ull_pcg_hpc_fancier_array_ShortArray_2(JNIEnv* env, jobject obj, jobject array) {
  // Allocate instance
  fcShortArray* self = fcShortArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_allocJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, array, FC_EXCEPTION_BAD_PARAMETER, "fcShortArray_initNative__Les_ull_pcg_hpc_fancier_vector_array_ShortArray;:array", FC_VOID_EXPR);

  // Initialize array
  fcShortArray* __tmp_array = fcShortArray_getJava(env, array);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_array, FC_EXCEPTION_BAD_PARAMETER, "fcShortArray_getJava:array", FC_VOID_EXPR);

  jint err = fcShortArray_initCopy(self, __tmp_array);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_initCopy", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_initNative__Ljava_nio_ShortBuffer_2(JNIEnv* env, jobject obj, jobject buffer) {
  void *buff = (*env)->GetDirectBufferAddress(env, buffer);
  jlong size = (*env)->GetDirectBufferCapacity(env, buffer);

  // Allocate instance
  fcShortArray* self = fcShortArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_allocJava", FC_VOID_EXPR);

  // Store the pointer to array
  jint err = fcShortArray_initPtr(self, buff, size);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_initPtr", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_releaseNative(JNIEnv* env, jobject obj) {
  fcShortArray* self = fcShortArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_getJava", FC_VOID_EXPR);

  // Release memory buffers and decrease the reference count to the instance object
  jint err = fcShortArray_release(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_release", FC_VOID_EXPR);

  fcShortArray_setJava(env, obj, 0L);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_releaseNativeRef(JNIEnv* env, jobject obj) {
  fcShortArray* self = fcShortArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_getJava", FC_VOID_EXPR);

  // Release the reference to the instance object and only release the buffers in it as well if this was the
  // only remaining reference to that object
  jint err = fcShortArray_releaseRef(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_releaseRef", FC_VOID_EXPR);

  fcShortArray_setJava(env, obj, 0L);
}

JNIEXPORT jshort JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_get__I(JNIEnv* env, jobject obj, jint i) {
  fcShortArray* self = fcShortArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_getJava", 0);

  jint err;
  fcShort __tmp_ret = fcShortArray_get(self, i, &err);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_get", 0);

  return __tmp_ret;
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_set__IS(JNIEnv* env, jobject obj, jint i, jshort x) {
  fcShortArray* self = fcShortArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_getJava", FC_VOID_EXPR);

  jint err = fcShortArray_set(self, i, x);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_set", FC_VOID_EXPR);
}

JNIEXPORT jlong JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_length(JNIEnv* env, jobject obj) {
  fcShortArray* self = fcShortArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_getJava", 0L);

  if (!fcShortArray_valid(self))
    FC_EXCEPTION_HANDLE_ERROR(env, FC_EXCEPTION_INVALID_STATE, "fcShortArray_length", 0L);

  return (jlong) self->len;
}

JNIEXPORT jshortArray JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_getArray(JNIEnv* env, jobject obj) {
  fcShortArray* self = fcShortArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_getJava", NULL);

  // Ensure native array is synced
  jint err = fcShortArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_syncToNative", NULL);

  // Create Java array and populate it
  jshortArray __tmp_ret = FC_JNI_CALL(env, NewShortArray, self->len);
  FC_EXCEPTION_HANDLE_PENDING(env, !__tmp_ret, "fcShortArray_getArray", NULL);

  FC_JNI_CALL(env, SetShortArrayRegion, __tmp_ret, 0, self->len, self->c);
  FC_EXCEPTION_HANDLE_PENDING(env, FC_FALSE, "fcShortArray_getArray", __tmp_ret);

  return __tmp_ret;
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_setArray(JNIEnv* env, jobject obj, jshortArray v) {
  fcShortArray* self = fcShortArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcShortArray_setArray:v", FC_VOID_EXPR);

  // Get array elements and length
  jsize __tmp_len = FC_JNI_CALL(env, GetArrayLength, v);
  jshort* __tmp_elems_v = FC_JNI_CALL(env, GetShortArrayElements, v, NULL);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcShortArray_setArray:v", FC_VOID_EXPR);

  jint err = fcShortArray_setArray(self, __tmp_len, __tmp_elems_v);

  // Free temporary native array reference
  FC_JNI_CALL(env, ReleaseShortArrayElements, v, __tmp_elems_v, JNI_ABORT);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_setArray", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_setCopy(JNIEnv* env, jobject obj, jobject array) {
  fcShortArray* self = fcShortArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, array, FC_EXCEPTION_BAD_PARAMETER, "fcShortArray_setCopy:array", FC_VOID_EXPR);

  // Get array elements and length
  fcShortArray* __tmp_array = fcShortArray_getJava(env, array);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_array, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcShortArray_setCopy:array", FC_VOID_EXPR);

  jint err = fcShortArray_setCopy(self, __tmp_array);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_setCopy", FC_VOID_EXPR);
}

JNIEXPORT jobject JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_getBufferImpl(JNIEnv* env, jobject obj) {
  fcShortArray* self = fcShortArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_getJava", NULL);

  // Ensure native array is synced
  jint err = fcShortArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_syncToNative", NULL);

  // Create and return direct byte buffer pointing to the native data
  return FC_JNI_CALL(env, NewDirectByteBuffer, self->c, self->len * sizeof(fcShort));
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_setBuffer(JNIEnv* env, jobject obj, jobject v) {
  fcShortArray* self = fcShortArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcShortArray_setBuffer:v", FC_VOID_EXPR);

  // Get buffer size and pointer
  jlong __tmp_len = FC_JNI_CALL(env, GetDirectBufferCapacity, v);
  void* __tmp_elems_v = FC_JNI_CALL(env, GetDirectBufferAddress, v);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcShortArray_setBuffer:v", FC_VOID_EXPR);

  jint err = fcShortArray_setBuffer(self, __tmp_len, __tmp_elems_v);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_setBuffer", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_syncToNative(JNIEnv* env, jobject obj) {
  fcShortArray* self = fcShortArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_getJava", FC_VOID_EXPR);

  jint err = fcShortArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_syncToNative", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_ShortArray_syncToOCL(JNIEnv* env, jobject obj) {
  fcShortArray* self = fcShortArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcShortArray_getJava", FC_VOID_EXPR);

  jint err = fcShortArray_syncToOCL(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcShortArray_syncToOCL", FC_VOID_EXPR);
}

//
// Native Interface Implementation
//

fcError fcShortArray_createRef(fcShortArray* array) {
  if (array == NULL || array->location == FC_ARRAY_LOCATION_NONE)
    return FC_EXCEPTION_BAD_PARAMETER;

  ++array->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcShortArray_releaseRef(fcShortArray* array) {
  if (array == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  if (array->ref_count <= 1)
    return fcShortArray_release(array);

  --array->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcShortArray_init(fcShortArray* self) {
  if (self->location != FC_ARRAY_LOCATION_NONE)
    return FC_EXCEPTION_INVALID_STATE;

  ++self->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcShortArray_initSize(fcShortArray* self, fcInt n) {
  fcError err;

  // Check parameters
  if (n <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  err = fcShortArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = n;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcShort), NULL, &err);
  if (err) return err;

  // Update location
  self->location = FC_ARRAY_LOCATION_OPENCL;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcShortArray_initArray(fcShortArray* self, fcInt len, const fcShort* v) {
  fcError err;

  // Check parameters
  if (len <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (v == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcShortArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcShort), NULL, &err);
  if (err) return err;

  // Initialize array
  self->location = FC_ARRAY_LOCATION_OPENCL;
  err = fcShortArray_setArray(self, len, v);

  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
    return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcShortArray_initPtr(fcShortArray* self, void * ptr, fcInt len) {
  fcError err;

  // Check parameters
  if (len <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (ptr == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcShortArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, self->len * sizeof(fcShort), ptr, &err);
  if (err) return err;

  // Initialize array
  self->location = FC_ARRAY_LOCATION_OPENCL;
  self->c = ptr;

  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
    return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcShortArray_initCopy(fcShortArray* self, const fcShortArray* array) {
  fcError err;

  // Check parameters
  if (array == NULL || !fcShortArray_valid(array))
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcShortArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = array->len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcShort), NULL, &err);
  if (err) return err;

  // Copy array data
  self->location = FC_ARRAY_LOCATION_OPENCL;
  err = fcShortArray_setCopy(self, array);
  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
  }

  return err;
}

fcError fcShortArray_release(fcShortArray* self) {
  --self->ref_count;

  // If it has already been released, only decrease the reference count
  if (self->location != FC_ARRAY_LOCATION_NONE) {
    fcError err = 0;

    if (self->c != NULL) {
      if (self->location != FC_ARRAY_LOCATION_OPENCL) {
        if (self->ocl == NULL) {
          ++self->ref_count;
          return FC_EXCEPTION_INVALID_STATE;
        }
        err = clEnqueueUnmapMemObject(fcOpenCL_rt.queue, self->ocl, self->c, 0, NULL, NULL);
      }

      self->c = NULL;
      if (err) {
        ++self->ref_count; // Release did not succeed, so restore the ref count
        return err;
      }
    }

    if (self->ocl != NULL) {
      err = release_ocl(self->ocl);

      self->ocl = NULL;
      if (err) {
        ++self->ref_count; // Release did not succeed, so restore the ref count
        return err;
      }
    }

    // Mark the object as deleted
    self->location = FC_ARRAY_LOCATION_NONE;
  }

  // Release the instance object if there are no other references to it elsewhere
  if (self->ref_count <= 0)
    free(self);

  return FC_EXCEPTION_SUCCESS;
}

fcShort fcShortArray_get(fcShortArray* self, fcInt i, fcError* err) {
  fcError __tmp_err;
  if (err == NULL) err = &__tmp_err;

  fcShort __tmp_ret = 0;
  if (!fcShortArray_valid(self)) {
    *err = FC_EXCEPTION_INVALID_STATE;
    return __tmp_ret;
  }

  if (i < 0 || i >= self->len) {
    *err = FC_EXCEPTION_BAD_PARAMETER;
    return __tmp_ret;
  }

  // Set location to native in order to access the array data
  *err = fcShortArray_syncToNative(self);
  if (*err) return __tmp_ret;

  return self->c[i];
}

fcError fcShortArray_set(fcShortArray* self, fcInt i, fcShort x) {
  if (!fcShortArray_valid(self)) return FC_EXCEPTION_INVALID_STATE;
  if (i < 0 || i >= self->len) return FC_EXCEPTION_BAD_PARAMETER;

  // Set location to native in order to access the array data
  fcError err = fcShortArray_syncToNative(self);
  if (err)
    return err;

  self->c[i] = x;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcShortArray_setArray(fcShortArray* self, fcInt len, const fcShort* v) {
  // No alignment issues, so we can just call setBuffer
  return fcShortArray_setBuffer(self, len * sizeof(fcShort), v);
}

fcError fcShortArray_setCopy(fcShortArray* self, const fcShortArray* array) {
  if (!fcShortArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  // Check parameters
  if (array == NULL || !fcShortArray_valid(array) || self->len != array->len)
    return FC_EXCEPTION_BAD_PARAMETER;

  // Copy array data
  fcError err;
  fcLong size = self->len * sizeof(fcShort);

  if (self->location == FC_ARRAY_LOCATION_OPENCL) {
    if (array->location == FC_ARRAY_LOCATION_OPENCL)
      err = clEnqueueCopyBuffer(fcOpenCL_rt.queue, array->ocl, self->ocl, 0, 0, size, 0, NULL, NULL);
    else /* array:FC_ARRAY_LOCATION_NATIVE */
      err = clEnqueueWriteBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, 0, size, array->c, 0, NULL, NULL);
  } else /* self:FC_ARRAY_LOCATION_NATIVE */ {
    if (array->location == FC_ARRAY_LOCATION_OPENCL)
      err = clEnqueueReadBuffer(fcOpenCL_rt.queue, array->ocl, CL_TRUE, 0, size, self->c, 0, NULL, NULL);
    else /* array:FC_ARRAY_LOCATION_NATIVE */
      err = memcpy(self->c, array->c, size) != NULL? FC_EXCEPTION_SUCCESS : FC_EXCEPTION_FAILED_COPY;
  }

  return err;
}

fcError fcShortArray_setBuffer(fcShortArray* self, fcLong len, const void* v) {
  if (!fcShortArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  // Check parameters
  if (len <= 0 || len % sizeof(fcShort) != 0 || len / sizeof(fcShort) != self->len)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (v == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  // Copy buffer
  fcError err;
  if (self->location == FC_ARRAY_LOCATION_OPENCL) {
    err = clEnqueueWriteBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, 0, len, v, 0, NULL, NULL);
    if (err) return err;
  }
  else /* self->location == FC_ARRAY_LOCATION_NATIVE */ {
    err = (memcpy(self->c, v, len) != NULL? FC_EXCEPTION_SUCCESS : FC_EXCEPTION_FAILED_COPY);
    if (err) return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcShortArray_syncToNative(fcShortArray* self) {
  if (!fcShortArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  fcError err = FC_EXCEPTION_SUCCESS;

  if (self->location == FC_ARRAY_LOCATION_OPENCL)
    self->c = clEnqueueMapBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, self->len * sizeof(fcShort), 0, NULL, NULL, &err);

  if (!err)
    self->location = FC_ARRAY_LOCATION_NATIVE;

  return err;
}

fcError fcShortArray_syncToOCL(fcShortArray* self) {
  if (!fcShortArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  fcError err = FC_EXCEPTION_SUCCESS;

  if (self->location == FC_ARRAY_LOCATION_NATIVE)
    err = clEnqueueUnmapMemObject(fcOpenCL_rt.queue, self->ocl, self->c, 0, NULL, NULL);

  if (!err)
    self->location = FC_ARRAY_LOCATION_OPENCL;

  return FC_EXCEPTION_SUCCESS;
}

fcBool fcShortArray_valid(const fcShortArray* self) {
  return self->len > 0 &&
    ((self->location == FC_ARRAY_LOCATION_NATIVE && self->c != NULL) ||
     (self->location == FC_ARRAY_LOCATION_OPENCL && self->ocl != NULL));
}


//
// fcIntArray
//

FC_JAVA_INSTANCE_HANDLERS(fcIntArray);

//
// Java Interface Implementation
//

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_initNative__J(JNIEnv* env, jobject obj, jlong nativePtr) {
  // Create reference
  fcIntArray* self = (fcIntArray*) nativePtr;
  jint err = fcIntArray_createRef(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_createRef", FC_VOID_EXPR);

  // Store native pointer on the Java object
  fcIntArray_setJava(env, obj, nativePtr);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_initNative__I(JNIEnv* env, jobject obj, jint n) {
  // Allocate instance
  fcIntArray* self = fcIntArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_allocJava", FC_VOID_EXPR);

  // Initialize array
  jint err = fcIntArray_initSize(self, n);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_initSize", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_initNative___3I(JNIEnv* env, jobject obj, jintArray v) {
  // Allocate instance
  fcIntArray* self = fcIntArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_allocJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcIntArray_initNative__[I:v", FC_VOID_EXPR);

  // Initialize array
  jsize __tmp_len = FC_JNI_CALL(env, GetArrayLength, v);
  jint* __tmp_elems_v = FC_JNI_CALL(env, GetIntArrayElements, v, NULL);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcIntArray_initNative__[I:v", FC_VOID_EXPR);

  jint err = fcIntArray_initArray(self, __tmp_len, __tmp_elems_v);

  // Free temporary native array reference
  FC_JNI_CALL(env, ReleaseIntArrayElements, v, __tmp_elems_v, JNI_ABORT);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_initArray", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_initNative__Les_ull_pcg_hpc_fancier_array_IntArray_2(JNIEnv* env, jobject obj, jobject array) {
  // Allocate instance
  fcIntArray* self = fcIntArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_allocJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, array, FC_EXCEPTION_BAD_PARAMETER, "fcIntArray_initNative__Les_ull_pcg_hpc_fancier_vector_array_IntArray;:array", FC_VOID_EXPR);

  // Initialize array
  fcIntArray* __tmp_array = fcIntArray_getJava(env, array);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_array, FC_EXCEPTION_BAD_PARAMETER, "fcIntArray_getJava:array", FC_VOID_EXPR);

  jint err = fcIntArray_initCopy(self, __tmp_array);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_initCopy", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_initNative__Ljava_nio_IntBuffer_2(JNIEnv* env, jobject obj, jobject buffer) {
  void *buff = (*env)->GetDirectBufferAddress(env, buffer);
  jlong size = (*env)->GetDirectBufferCapacity(env, buffer);

  // Allocate instance
  fcIntArray* self = fcIntArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_allocJava", FC_VOID_EXPR);

  // Store the pointer to array
  jint err = fcIntArray_initPtr(self, buff, size);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_initPtr", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_releaseNative(JNIEnv* env, jobject obj) {
  fcIntArray* self = fcIntArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_getJava", FC_VOID_EXPR);

  // Release memory buffers and decrease the reference count to the instance object
  jint err = fcIntArray_release(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_release", FC_VOID_EXPR);

  fcIntArray_setJava(env, obj, 0L);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_releaseNativeRef(JNIEnv* env, jobject obj) {
  fcIntArray* self = fcIntArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_getJava", FC_VOID_EXPR);

  // Release the reference to the instance object and only release the buffers in it as well if this was the
  // only remaining reference to that object
  jint err = fcIntArray_releaseRef(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_releaseRef", FC_VOID_EXPR);

  fcIntArray_setJava(env, obj, 0L);
}

JNIEXPORT jint JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_get__I(JNIEnv* env, jobject obj, jint i) {
  fcIntArray* self = fcIntArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_getJava", 0);

  jint err;
  fcInt __tmp_ret = fcIntArray_get(self, i, &err);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_get", 0);

  return __tmp_ret;
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_set__II(JNIEnv* env, jobject obj, jint i, jint x) {
  fcIntArray* self = fcIntArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_getJava", FC_VOID_EXPR);

  jint err = fcIntArray_set(self, i, x);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_set", FC_VOID_EXPR);
}

JNIEXPORT jlong JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_length(JNIEnv* env, jobject obj) {
  fcIntArray* self = fcIntArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_getJava", 0L);

  if (!fcIntArray_valid(self))
    FC_EXCEPTION_HANDLE_ERROR(env, FC_EXCEPTION_INVALID_STATE, "fcIntArray_length", 0L);

  return (jlong) self->len;
}

JNIEXPORT jintArray JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_getArray(JNIEnv* env, jobject obj) {
  fcIntArray* self = fcIntArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_getJava", NULL);

  // Ensure native array is synced
  jint err = fcIntArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_syncToNative", NULL);

  // Create Java array and populate it
  jintArray __tmp_ret = FC_JNI_CALL(env, NewIntArray, self->len);
  FC_EXCEPTION_HANDLE_PENDING(env, !__tmp_ret, "fcIntArray_getArray", NULL);

  FC_JNI_CALL(env, SetIntArrayRegion, __tmp_ret, 0, self->len, self->c);
  FC_EXCEPTION_HANDLE_PENDING(env, FC_FALSE, "fcIntArray_getArray", __tmp_ret);

  return __tmp_ret;
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_setArray(JNIEnv* env, jobject obj, jintArray v) {
  fcIntArray* self = fcIntArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcIntArray_setArray:v", FC_VOID_EXPR);

  // Get array elements and length
  jsize __tmp_len = FC_JNI_CALL(env, GetArrayLength, v);
  jint* __tmp_elems_v = FC_JNI_CALL(env, GetIntArrayElements, v, NULL);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcIntArray_setArray:v", FC_VOID_EXPR);

  jint err = fcIntArray_setArray(self, __tmp_len, __tmp_elems_v);

  // Free temporary native array reference
  FC_JNI_CALL(env, ReleaseIntArrayElements, v, __tmp_elems_v, JNI_ABORT);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_setArray", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_setCopy(JNIEnv* env, jobject obj, jobject array) {
  fcIntArray* self = fcIntArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, array, FC_EXCEPTION_BAD_PARAMETER, "fcIntArray_setCopy:array", FC_VOID_EXPR);

  // Get array elements and length
  fcIntArray* __tmp_array = fcIntArray_getJava(env, array);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_array, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcIntArray_setCopy:array", FC_VOID_EXPR);

  jint err = fcIntArray_setCopy(self, __tmp_array);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_setCopy", FC_VOID_EXPR);
}

JNIEXPORT jobject JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_getBufferImpl(JNIEnv* env, jobject obj) {
  fcIntArray* self = fcIntArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_getJava", NULL);

  // Ensure native array is synced
  jint err = fcIntArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_syncToNative", NULL);

  // Create and return direct byte buffer pointing to the native data
  return FC_JNI_CALL(env, NewDirectByteBuffer, self->c, self->len * sizeof(fcInt));
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_setBuffer(JNIEnv* env, jobject obj, jobject v) {
  fcIntArray* self = fcIntArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcIntArray_setBuffer:v", FC_VOID_EXPR);

  // Get buffer size and pointer
  jlong __tmp_len = FC_JNI_CALL(env, GetDirectBufferCapacity, v);
  void* __tmp_elems_v = FC_JNI_CALL(env, GetDirectBufferAddress, v);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcIntArray_setBuffer:v", FC_VOID_EXPR);

  jint err = fcIntArray_setBuffer(self, __tmp_len, __tmp_elems_v);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_setBuffer", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_syncToNative(JNIEnv* env, jobject obj) {
  fcIntArray* self = fcIntArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_getJava", FC_VOID_EXPR);

  jint err = fcIntArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_syncToNative", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_IntArray_syncToOCL(JNIEnv* env, jobject obj) {
  fcIntArray* self = fcIntArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcIntArray_getJava", FC_VOID_EXPR);

  jint err = fcIntArray_syncToOCL(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcIntArray_syncToOCL", FC_VOID_EXPR);
}

//
// Native Interface Implementation
//

fcError fcIntArray_createRef(fcIntArray* array) {
  if (array == NULL || array->location == FC_ARRAY_LOCATION_NONE)
    return FC_EXCEPTION_BAD_PARAMETER;

  ++array->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcIntArray_releaseRef(fcIntArray* array) {
  if (array == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  if (array->ref_count <= 1)
    return fcIntArray_release(array);

  --array->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcIntArray_init(fcIntArray* self) {
  if (self->location != FC_ARRAY_LOCATION_NONE)
    return FC_EXCEPTION_INVALID_STATE;

  ++self->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcIntArray_initSize(fcIntArray* self, fcInt n) {
  fcError err;

  // Check parameters
  if (n <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  err = fcIntArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = n;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcInt), NULL, &err);
  if (err) return err;

  // Update location
  self->location = FC_ARRAY_LOCATION_OPENCL;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcIntArray_initArray(fcIntArray* self, fcInt len, const fcInt* v) {
  fcError err;

  // Check parameters
  if (len <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (v == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcIntArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcInt), NULL, &err);
  if (err) return err;

  // Initialize array
  self->location = FC_ARRAY_LOCATION_OPENCL;
  err = fcIntArray_setArray(self, len, v);

  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
    return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcIntArray_initPtr(fcIntArray* self, void * ptr, fcInt len) {
  fcError err;

  // Check parameters
  if (len <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (ptr == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcIntArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, self->len * sizeof(fcInt), ptr, &err);
  if (err) return err;

  // Initialize array
  self->location = FC_ARRAY_LOCATION_OPENCL;
  self->c = ptr;

  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
    return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcIntArray_initCopy(fcIntArray* self, const fcIntArray* array) {
  fcError err;

  // Check parameters
  if (array == NULL || !fcIntArray_valid(array))
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcIntArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = array->len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcInt), NULL, &err);
  if (err) return err;

  // Copy array data
  self->location = FC_ARRAY_LOCATION_OPENCL;
  err = fcIntArray_setCopy(self, array);
  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
  }

  return err;
}

fcError fcIntArray_release(fcIntArray* self) {
  --self->ref_count;

  // If it has already been released, only decrease the reference count
  if (self->location != FC_ARRAY_LOCATION_NONE) {
    fcError err = 0;

    if (self->c != NULL) {
      if (self->location != FC_ARRAY_LOCATION_OPENCL) {
        if (self->ocl == NULL) {
          ++self->ref_count;
          return FC_EXCEPTION_INVALID_STATE;
        }
        err = clEnqueueUnmapMemObject(fcOpenCL_rt.queue, self->ocl, self->c, 0, NULL, NULL);
      }

      self->c = NULL;
      if (err) {
        ++self->ref_count; // Release did not succeed, so restore the ref count
        return err;
      }
    }

    if (self->ocl != NULL) {
      err = release_ocl(self->ocl);

      self->ocl = NULL;
      if (err) {
        ++self->ref_count; // Release did not succeed, so restore the ref count
        return err;
      }
    }

    // Mark the object as deleted
    self->location = FC_ARRAY_LOCATION_NONE;
  }

  // Release the instance object if there are no other references to it elsewhere
  if (self->ref_count <= 0)
    free(self);

  return FC_EXCEPTION_SUCCESS;
}

fcInt fcIntArray_get(fcIntArray* self, fcInt i, fcError* err) {
  fcError __tmp_err;
  if (err == NULL) err = &__tmp_err;

  fcInt __tmp_ret = 0;
  if (!fcIntArray_valid(self)) {
    *err = FC_EXCEPTION_INVALID_STATE;
    return __tmp_ret;
  }

  if (i < 0 || i >= self->len) {
    *err = FC_EXCEPTION_BAD_PARAMETER;
    return __tmp_ret;
  }

  // Set location to native in order to access the array data
  *err = fcIntArray_syncToNative(self);
  if (*err) return __tmp_ret;

  return self->c[i];
}

fcError fcIntArray_set(fcIntArray* self, fcInt i, fcInt x) {
  if (!fcIntArray_valid(self)) return FC_EXCEPTION_INVALID_STATE;
  if (i < 0 || i >= self->len) return FC_EXCEPTION_BAD_PARAMETER;

  // Set location to native in order to access the array data
  fcError err = fcIntArray_syncToNative(self);
  if (err)
    return err;

  self->c[i] = x;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcIntArray_setArray(fcIntArray* self, fcInt len, const fcInt* v) {
  // No alignment issues, so we can just call setBuffer
  return fcIntArray_setBuffer(self, len * sizeof(fcInt), v);
}

fcError fcIntArray_setCopy(fcIntArray* self, const fcIntArray* array) {
  if (!fcIntArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  // Check parameters
  if (array == NULL || !fcIntArray_valid(array) || self->len != array->len)
    return FC_EXCEPTION_BAD_PARAMETER;

  // Copy array data
  fcError err;
  fcLong size = self->len * sizeof(fcInt);

  if (self->location == FC_ARRAY_LOCATION_OPENCL) {
    if (array->location == FC_ARRAY_LOCATION_OPENCL)
      err = clEnqueueCopyBuffer(fcOpenCL_rt.queue, array->ocl, self->ocl, 0, 0, size, 0, NULL, NULL);
    else /* array:FC_ARRAY_LOCATION_NATIVE */
      err = clEnqueueWriteBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, 0, size, array->c, 0, NULL, NULL);
  } else /* self:FC_ARRAY_LOCATION_NATIVE */ {
    if (array->location == FC_ARRAY_LOCATION_OPENCL)
      err = clEnqueueReadBuffer(fcOpenCL_rt.queue, array->ocl, CL_TRUE, 0, size, self->c, 0, NULL, NULL);
    else /* array:FC_ARRAY_LOCATION_NATIVE */
      err = memcpy(self->c, array->c, size) != NULL? FC_EXCEPTION_SUCCESS : FC_EXCEPTION_FAILED_COPY;
  }

  return err;
}

fcError fcIntArray_setBuffer(fcIntArray* self, fcLong len, const void* v) {
  if (!fcIntArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  // Check parameters
  if (len <= 0 || len % sizeof(fcInt) != 0 || len / sizeof(fcInt) != self->len)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (v == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  // Copy buffer
  fcError err;
  if (self->location == FC_ARRAY_LOCATION_OPENCL) {
    err = clEnqueueWriteBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, 0, len, v, 0, NULL, NULL);
    if (err) return err;
  }
  else /* self->location == FC_ARRAY_LOCATION_NATIVE */ {
    err = (memcpy(self->c, v, len) != NULL? FC_EXCEPTION_SUCCESS : FC_EXCEPTION_FAILED_COPY);
    if (err) return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcIntArray_syncToNative(fcIntArray* self) {
  if (!fcIntArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  fcError err = FC_EXCEPTION_SUCCESS;

  if (self->location == FC_ARRAY_LOCATION_OPENCL)
    self->c = clEnqueueMapBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, self->len * sizeof(fcInt), 0, NULL, NULL, &err);

  if (!err)
    self->location = FC_ARRAY_LOCATION_NATIVE;

  return err;
}

fcError fcIntArray_syncToOCL(fcIntArray* self) {
  if (!fcIntArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  fcError err = FC_EXCEPTION_SUCCESS;

  if (self->location == FC_ARRAY_LOCATION_NATIVE)
    err = clEnqueueUnmapMemObject(fcOpenCL_rt.queue, self->ocl, self->c, 0, NULL, NULL);

  if (!err)
    self->location = FC_ARRAY_LOCATION_OPENCL;

  return FC_EXCEPTION_SUCCESS;
}

fcBool fcIntArray_valid(const fcIntArray* self) {
  return self->len > 0 &&
    ((self->location == FC_ARRAY_LOCATION_NATIVE && self->c != NULL) ||
     (self->location == FC_ARRAY_LOCATION_OPENCL && self->ocl != NULL));
}


//
// fcLongArray
//

FC_JAVA_INSTANCE_HANDLERS(fcLongArray);

//
// Java Interface Implementation
//

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_initNative__J(JNIEnv* env, jobject obj, jlong nativePtr) {
  // Create reference
  fcLongArray* self = (fcLongArray*) nativePtr;
  jint err = fcLongArray_createRef(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_createRef", FC_VOID_EXPR);

  // Store native pointer on the Java object
  fcLongArray_setJava(env, obj, nativePtr);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_initNative__I(JNIEnv* env, jobject obj, jint n) {
  // Allocate instance
  fcLongArray* self = fcLongArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_allocJava", FC_VOID_EXPR);

  // Initialize array
  jint err = fcLongArray_initSize(self, n);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_initSize", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_initNative___3J(JNIEnv* env, jobject obj, jlongArray v) {
  // Allocate instance
  fcLongArray* self = fcLongArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_allocJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcLongArray_initNative__[J:v", FC_VOID_EXPR);

  // Initialize array
  jsize __tmp_len = FC_JNI_CALL(env, GetArrayLength, v);
  jlong* __tmp_elems_v = FC_JNI_CALL(env, GetLongArrayElements, v, NULL);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcLongArray_initNative__[J:v", FC_VOID_EXPR);

  jint err = fcLongArray_initArray(self, __tmp_len, __tmp_elems_v);

  // Free temporary native array reference
  FC_JNI_CALL(env, ReleaseLongArrayElements, v, __tmp_elems_v, JNI_ABORT);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_initArray", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_initNative__Les_ull_pcg_hpc_fancier_array_LongArray_2(JNIEnv* env, jobject obj, jobject array) {
  // Allocate instance
  fcLongArray* self = fcLongArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_allocJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, array, FC_EXCEPTION_BAD_PARAMETER, "fcLongArray_initNative__Les_ull_pcg_hpc_fancier_vector_array_LongArray;:array", FC_VOID_EXPR);

  // Initialize array
  fcLongArray* __tmp_array = fcLongArray_getJava(env, array);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_array, FC_EXCEPTION_BAD_PARAMETER, "fcLongArray_getJava:array", FC_VOID_EXPR);

  jint err = fcLongArray_initCopy(self, __tmp_array);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_initCopy", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_initNative__Ljava_nio_LongBuffer_2(JNIEnv* env, jobject obj, jobject buffer) {
  void *buff = (*env)->GetDirectBufferAddress(env, buffer);
  jlong size = (*env)->GetDirectBufferCapacity(env, buffer);

  // Allocate instance
  fcLongArray* self = fcLongArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_allocJava", FC_VOID_EXPR);

  // Store the pointer to array
  jint err = fcLongArray_initPtr(self, buff, size);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_initPtr", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_releaseNative(JNIEnv* env, jobject obj) {
  fcLongArray* self = fcLongArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_getJava", FC_VOID_EXPR);

  // Release memory buffers and decrease the reference count to the instance object
  jint err = fcLongArray_release(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_release", FC_VOID_EXPR);

  fcLongArray_setJava(env, obj, 0L);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_releaseNativeRef(JNIEnv* env, jobject obj) {
  fcLongArray* self = fcLongArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_getJava", FC_VOID_EXPR);

  // Release the reference to the instance object and only release the buffers in it as well if this was the
  // only remaining reference to that object
  jint err = fcLongArray_releaseRef(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_releaseRef", FC_VOID_EXPR);

  fcLongArray_setJava(env, obj, 0L);
}

JNIEXPORT jlong JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_get__I(JNIEnv* env, jobject obj, jint i) {
  fcLongArray* self = fcLongArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_getJava", 0L);

  jint err;
  fcLong __tmp_ret = fcLongArray_get(self, i, &err);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_get", 0L);

  return __tmp_ret;
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_set__IJ(JNIEnv* env, jobject obj, jint i, jlong x) {
  fcLongArray* self = fcLongArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_getJava", FC_VOID_EXPR);

  jint err = fcLongArray_set(self, i, x);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_set", FC_VOID_EXPR);
}

JNIEXPORT jlong JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_length(JNIEnv* env, jobject obj) {
  fcLongArray* self = fcLongArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_getJava", 0L);

  if (!fcLongArray_valid(self))
    FC_EXCEPTION_HANDLE_ERROR(env, FC_EXCEPTION_INVALID_STATE, "fcLongArray_length", 0L);

  return (jlong) self->len;
}

JNIEXPORT jlongArray JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_getArray(JNIEnv* env, jobject obj) {
  fcLongArray* self = fcLongArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_getJava", NULL);

  // Ensure native array is synced
  jint err = fcLongArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_syncToNative", NULL);

  // Create Java array and populate it
  jlongArray __tmp_ret = FC_JNI_CALL(env, NewLongArray, self->len);
  FC_EXCEPTION_HANDLE_PENDING(env, !__tmp_ret, "fcLongArray_getArray", NULL);

  FC_JNI_CALL(env, SetLongArrayRegion, __tmp_ret, 0, self->len, self->c);
  FC_EXCEPTION_HANDLE_PENDING(env, FC_FALSE, "fcLongArray_getArray", __tmp_ret);

  return __tmp_ret;
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_setArray(JNIEnv* env, jobject obj, jlongArray v) {
  fcLongArray* self = fcLongArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcLongArray_setArray:v", FC_VOID_EXPR);

  // Get array elements and length
  jsize __tmp_len = FC_JNI_CALL(env, GetArrayLength, v);
  jlong* __tmp_elems_v = FC_JNI_CALL(env, GetLongArrayElements, v, NULL);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcLongArray_setArray:v", FC_VOID_EXPR);

  jint err = fcLongArray_setArray(self, __tmp_len, __tmp_elems_v);

  // Free temporary native array reference
  FC_JNI_CALL(env, ReleaseLongArrayElements, v, __tmp_elems_v, JNI_ABORT);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_setArray", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_setCopy(JNIEnv* env, jobject obj, jobject array) {
  fcLongArray* self = fcLongArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, array, FC_EXCEPTION_BAD_PARAMETER, "fcLongArray_setCopy:array", FC_VOID_EXPR);

  // Get array elements and length
  fcLongArray* __tmp_array = fcLongArray_getJava(env, array);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_array, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcLongArray_setCopy:array", FC_VOID_EXPR);

  jint err = fcLongArray_setCopy(self, __tmp_array);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_setCopy", FC_VOID_EXPR);
}

JNIEXPORT jobject JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_getBufferImpl(JNIEnv* env, jobject obj) {
  fcLongArray* self = fcLongArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_getJava", NULL);

  // Ensure native array is synced
  jint err = fcLongArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_syncToNative", NULL);

  // Create and return direct byte buffer pointing to the native data
  return FC_JNI_CALL(env, NewDirectByteBuffer, self->c, self->len * sizeof(fcLong));
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_setBuffer(JNIEnv* env, jobject obj, jobject v) {
  fcLongArray* self = fcLongArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcLongArray_setBuffer:v", FC_VOID_EXPR);

  // Get buffer size and pointer
  jlong __tmp_len = FC_JNI_CALL(env, GetDirectBufferCapacity, v);
  void* __tmp_elems_v = FC_JNI_CALL(env, GetDirectBufferAddress, v);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcLongArray_setBuffer:v", FC_VOID_EXPR);

  jint err = fcLongArray_setBuffer(self, __tmp_len, __tmp_elems_v);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_setBuffer", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_syncToNative(JNIEnv* env, jobject obj) {
  fcLongArray* self = fcLongArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_getJava", FC_VOID_EXPR);

  jint err = fcLongArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_syncToNative", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_LongArray_syncToOCL(JNIEnv* env, jobject obj) {
  fcLongArray* self = fcLongArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcLongArray_getJava", FC_VOID_EXPR);

  jint err = fcLongArray_syncToOCL(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcLongArray_syncToOCL", FC_VOID_EXPR);
}

//
// Native Interface Implementation
//

fcError fcLongArray_createRef(fcLongArray* array) {
  if (array == NULL || array->location == FC_ARRAY_LOCATION_NONE)
    return FC_EXCEPTION_BAD_PARAMETER;

  ++array->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcLongArray_releaseRef(fcLongArray* array) {
  if (array == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  if (array->ref_count <= 1)
    return fcLongArray_release(array);

  --array->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcLongArray_init(fcLongArray* self) {
  if (self->location != FC_ARRAY_LOCATION_NONE)
    return FC_EXCEPTION_INVALID_STATE;

  ++self->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcLongArray_initSize(fcLongArray* self, fcInt n) {
  fcError err;

  // Check parameters
  if (n <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  err = fcLongArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = n;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcLong), NULL, &err);
  if (err) return err;

  // Update location
  self->location = FC_ARRAY_LOCATION_OPENCL;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcLongArray_initArray(fcLongArray* self, fcInt len, const fcLong* v) {
  fcError err;

  // Check parameters
  if (len <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (v == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcLongArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcLong), NULL, &err);
  if (err) return err;

  // Initialize array
  self->location = FC_ARRAY_LOCATION_OPENCL;
  err = fcLongArray_setArray(self, len, v);

  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
    return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcLongArray_initPtr(fcLongArray* self, void * ptr, fcInt len) {
  fcError err;

  // Check parameters
  if (len <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (ptr == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcLongArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, self->len * sizeof(fcLong), ptr, &err);
  if (err) return err;

  // Initialize array
  self->location = FC_ARRAY_LOCATION_OPENCL;
  self->c = ptr;

  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
    return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcLongArray_initCopy(fcLongArray* self, const fcLongArray* array) {
  fcError err;

  // Check parameters
  if (array == NULL || !fcLongArray_valid(array))
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcLongArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = array->len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcLong), NULL, &err);
  if (err) return err;

  // Copy array data
  self->location = FC_ARRAY_LOCATION_OPENCL;
  err = fcLongArray_setCopy(self, array);
  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
  }

  return err;
}

fcError fcLongArray_release(fcLongArray* self) {
  --self->ref_count;

  // If it has already been released, only decrease the reference count
  if (self->location != FC_ARRAY_LOCATION_NONE) {
    fcError err = 0;

    if (self->c != NULL) {
      if (self->location != FC_ARRAY_LOCATION_OPENCL) {
        if (self->ocl == NULL) {
          ++self->ref_count;
          return FC_EXCEPTION_INVALID_STATE;
        }
        err = clEnqueueUnmapMemObject(fcOpenCL_rt.queue, self->ocl, self->c, 0, NULL, NULL);
      }

      self->c = NULL;
      if (err) {
        ++self->ref_count; // Release did not succeed, so restore the ref count
        return err;
      }
    }

    if (self->ocl != NULL) {
      err = release_ocl(self->ocl);

      self->ocl = NULL;
      if (err) {
        ++self->ref_count; // Release did not succeed, so restore the ref count
        return err;
      }
    }

    // Mark the object as deleted
    self->location = FC_ARRAY_LOCATION_NONE;
  }

  // Release the instance object if there are no other references to it elsewhere
  if (self->ref_count <= 0)
    free(self);

  return FC_EXCEPTION_SUCCESS;
}

fcLong fcLongArray_get(fcLongArray* self, fcInt i, fcError* err) {
  fcError __tmp_err;
  if (err == NULL) err = &__tmp_err;

  fcLong __tmp_ret = 0L;
  if (!fcLongArray_valid(self)) {
    *err = FC_EXCEPTION_INVALID_STATE;
    return __tmp_ret;
  }

  if (i < 0 || i >= self->len) {
    *err = FC_EXCEPTION_BAD_PARAMETER;
    return __tmp_ret;
  }

  // Set location to native in order to access the array data
  *err = fcLongArray_syncToNative(self);
  if (*err) return __tmp_ret;

  return self->c[i];
}

fcError fcLongArray_set(fcLongArray* self, fcInt i, fcLong x) {
  if (!fcLongArray_valid(self)) return FC_EXCEPTION_INVALID_STATE;
  if (i < 0 || i >= self->len) return FC_EXCEPTION_BAD_PARAMETER;

  // Set location to native in order to access the array data
  fcError err = fcLongArray_syncToNative(self);
  if (err)
    return err;

  self->c[i] = x;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcLongArray_setArray(fcLongArray* self, fcInt len, const fcLong* v) {
  // No alignment issues, so we can just call setBuffer
  return fcLongArray_setBuffer(self, len * sizeof(fcLong), v);
}

fcError fcLongArray_setCopy(fcLongArray* self, const fcLongArray* array) {
  if (!fcLongArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  // Check parameters
  if (array == NULL || !fcLongArray_valid(array) || self->len != array->len)
    return FC_EXCEPTION_BAD_PARAMETER;

  // Copy array data
  fcError err;
  fcLong size = self->len * sizeof(fcLong);

  if (self->location == FC_ARRAY_LOCATION_OPENCL) {
    if (array->location == FC_ARRAY_LOCATION_OPENCL)
      err = clEnqueueCopyBuffer(fcOpenCL_rt.queue, array->ocl, self->ocl, 0, 0, size, 0, NULL, NULL);
    else /* array:FC_ARRAY_LOCATION_NATIVE */
      err = clEnqueueWriteBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, 0, size, array->c, 0, NULL, NULL);
  } else /* self:FC_ARRAY_LOCATION_NATIVE */ {
    if (array->location == FC_ARRAY_LOCATION_OPENCL)
      err = clEnqueueReadBuffer(fcOpenCL_rt.queue, array->ocl, CL_TRUE, 0, size, self->c, 0, NULL, NULL);
    else /* array:FC_ARRAY_LOCATION_NATIVE */
      err = memcpy(self->c, array->c, size) != NULL? FC_EXCEPTION_SUCCESS : FC_EXCEPTION_FAILED_COPY;
  }

  return err;
}

fcError fcLongArray_setBuffer(fcLongArray* self, fcLong len, const void* v) {
  if (!fcLongArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  // Check parameters
  if (len <= 0 || len % sizeof(fcLong) != 0 || len / sizeof(fcLong) != self->len)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (v == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  // Copy buffer
  fcError err;
  if (self->location == FC_ARRAY_LOCATION_OPENCL) {
    err = clEnqueueWriteBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, 0, len, v, 0, NULL, NULL);
    if (err) return err;
  }
  else /* self->location == FC_ARRAY_LOCATION_NATIVE */ {
    err = (memcpy(self->c, v, len) != NULL? FC_EXCEPTION_SUCCESS : FC_EXCEPTION_FAILED_COPY);
    if (err) return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcLongArray_syncToNative(fcLongArray* self) {
  if (!fcLongArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  fcError err = FC_EXCEPTION_SUCCESS;

  if (self->location == FC_ARRAY_LOCATION_OPENCL)
    self->c = clEnqueueMapBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, self->len * sizeof(fcLong), 0, NULL, NULL, &err);

  if (!err)
    self->location = FC_ARRAY_LOCATION_NATIVE;

  return err;
}

fcError fcLongArray_syncToOCL(fcLongArray* self) {
  if (!fcLongArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  fcError err = FC_EXCEPTION_SUCCESS;

  if (self->location == FC_ARRAY_LOCATION_NATIVE)
    err = clEnqueueUnmapMemObject(fcOpenCL_rt.queue, self->ocl, self->c, 0, NULL, NULL);

  if (!err)
    self->location = FC_ARRAY_LOCATION_OPENCL;

  return FC_EXCEPTION_SUCCESS;
}

fcBool fcLongArray_valid(const fcLongArray* self) {
  return self->len > 0 &&
    ((self->location == FC_ARRAY_LOCATION_NATIVE && self->c != NULL) ||
     (self->location == FC_ARRAY_LOCATION_OPENCL && self->ocl != NULL));
}


//
// fcFloatArray
//

FC_JAVA_INSTANCE_HANDLERS(fcFloatArray);

//
// Java Interface Implementation
//

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_initNative__J(JNIEnv* env, jobject obj, jlong nativePtr) {
  // Create reference
  fcFloatArray* self = (fcFloatArray*) nativePtr;
  jint err = fcFloatArray_createRef(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_createRef", FC_VOID_EXPR);

  // Store native pointer on the Java object
  fcFloatArray_setJava(env, obj, nativePtr);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_initNative__I(JNIEnv* env, jobject obj, jint n) {
  // Allocate instance
  fcFloatArray* self = fcFloatArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_allocJava", FC_VOID_EXPR);

  // Initialize array
  jint err = fcFloatArray_initSize(self, n);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_initSize", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_initNative___3F(JNIEnv* env, jobject obj, jfloatArray v) {
  // Allocate instance
  fcFloatArray* self = fcFloatArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_allocJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcFloatArray_initNative__[F:v", FC_VOID_EXPR);

  // Initialize array
  jsize __tmp_len = FC_JNI_CALL(env, GetArrayLength, v);
  jfloat* __tmp_elems_v = FC_JNI_CALL(env, GetFloatArrayElements, v, NULL);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcFloatArray_initNative__[F:v", FC_VOID_EXPR);

  jint err = fcFloatArray_initArray(self, __tmp_len, __tmp_elems_v);

  // Free temporary native array reference
  FC_JNI_CALL(env, ReleaseFloatArrayElements, v, __tmp_elems_v, JNI_ABORT);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_initArray", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_initNative__Les_ull_pcg_hpc_fancier_array_FloatArray_2(JNIEnv* env, jobject obj, jobject array) {
  // Allocate instance
  fcFloatArray* self = fcFloatArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_allocJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, array, FC_EXCEPTION_BAD_PARAMETER, "fcFloatArray_initNative__Les_ull_pcg_hpc_fancier_vector_array_FloatArray;:array", FC_VOID_EXPR);

  // Initialize array
  fcFloatArray* __tmp_array = fcFloatArray_getJava(env, array);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_array, FC_EXCEPTION_BAD_PARAMETER, "fcFloatArray_getJava:array", FC_VOID_EXPR);

  jint err = fcFloatArray_initCopy(self, __tmp_array);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_initCopy", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_initNative__Ljava_nio_FloatBuffer_2(JNIEnv* env, jobject obj, jobject buffer) {
  void *buff = (*env)->GetDirectBufferAddress(env, buffer);
  jlong size = (*env)->GetDirectBufferCapacity(env, buffer);

  // Allocate instance
  fcFloatArray* self = fcFloatArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_allocJava", FC_VOID_EXPR);

  // Store the pointer to array
  jint err = fcFloatArray_initPtr(self, buff, size);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_initPtr", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_releaseNative(JNIEnv* env, jobject obj) {
  fcFloatArray* self = fcFloatArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_getJava", FC_VOID_EXPR);

  // Release memory buffers and decrease the reference count to the instance object
  jint err = fcFloatArray_release(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_release", FC_VOID_EXPR);

  fcFloatArray_setJava(env, obj, 0L);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_releaseNativeRef(JNIEnv* env, jobject obj) {
  fcFloatArray* self = fcFloatArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_getJava", FC_VOID_EXPR);

  // Release the reference to the instance object and only release the buffers in it as well if this was the
  // only remaining reference to that object
  jint err = fcFloatArray_releaseRef(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_releaseRef", FC_VOID_EXPR);

  fcFloatArray_setJava(env, obj, 0L);
}

JNIEXPORT jfloat JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_get__I(JNIEnv* env, jobject obj, jint i) {
  fcFloatArray* self = fcFloatArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_getJava", 0.0f);

  jint err;
  fcFloat __tmp_ret = fcFloatArray_get(self, i, &err);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_get", 0.0f);

  return __tmp_ret;
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_set__IF(JNIEnv* env, jobject obj, jint i, jfloat x) {
  fcFloatArray* self = fcFloatArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_getJava", FC_VOID_EXPR);

  jint err = fcFloatArray_set(self, i, x);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_set", FC_VOID_EXPR);
}

JNIEXPORT jlong JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_length(JNIEnv* env, jobject obj) {
  fcFloatArray* self = fcFloatArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_getJava", 0L);

  if (!fcFloatArray_valid(self))
    FC_EXCEPTION_HANDLE_ERROR(env, FC_EXCEPTION_INVALID_STATE, "fcFloatArray_length", 0L);

  return (jlong) self->len;
}

JNIEXPORT jfloatArray JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_getArray(JNIEnv* env, jobject obj) {
  fcFloatArray* self = fcFloatArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_getJava", NULL);

  // Ensure native array is synced
  jint err = fcFloatArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_syncToNative", NULL);

  // Create Java array and populate it
  jfloatArray __tmp_ret = FC_JNI_CALL(env, NewFloatArray, self->len);
  FC_EXCEPTION_HANDLE_PENDING(env, !__tmp_ret, "fcFloatArray_getArray", NULL);

  FC_JNI_CALL(env, SetFloatArrayRegion, __tmp_ret, 0, self->len, self->c);
  FC_EXCEPTION_HANDLE_PENDING(env, FC_FALSE, "fcFloatArray_getArray", __tmp_ret);

  return __tmp_ret;
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_setArray(JNIEnv* env, jobject obj, jfloatArray v) {
  fcFloatArray* self = fcFloatArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcFloatArray_setArray:v", FC_VOID_EXPR);

  // Get array elements and length
  jsize __tmp_len = FC_JNI_CALL(env, GetArrayLength, v);
  jfloat* __tmp_elems_v = FC_JNI_CALL(env, GetFloatArrayElements, v, NULL);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcFloatArray_setArray:v", FC_VOID_EXPR);

  jint err = fcFloatArray_setArray(self, __tmp_len, __tmp_elems_v);

  // Free temporary native array reference
  FC_JNI_CALL(env, ReleaseFloatArrayElements, v, __tmp_elems_v, JNI_ABORT);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_setArray", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_setCopy(JNIEnv* env, jobject obj, jobject array) {
  fcFloatArray* self = fcFloatArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, array, FC_EXCEPTION_BAD_PARAMETER, "fcFloatArray_setCopy:array", FC_VOID_EXPR);

  // Get array elements and length
  fcFloatArray* __tmp_array = fcFloatArray_getJava(env, array);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_array, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcFloatArray_setCopy:array", FC_VOID_EXPR);

  jint err = fcFloatArray_setCopy(self, __tmp_array);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_setCopy", FC_VOID_EXPR);
}

JNIEXPORT jobject JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_getBufferImpl(JNIEnv* env, jobject obj) {
  fcFloatArray* self = fcFloatArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_getJava", NULL);

  // Ensure native array is synced
  jint err = fcFloatArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_syncToNative", NULL);

  // Create and return direct byte buffer pointing to the native data
  return FC_JNI_CALL(env, NewDirectByteBuffer, self->c, self->len * sizeof(fcFloat));
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_setBuffer(JNIEnv* env, jobject obj, jobject v) {
  fcFloatArray* self = fcFloatArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcFloatArray_setBuffer:v", FC_VOID_EXPR);

  // Get buffer size and pointer
  jlong __tmp_len = FC_JNI_CALL(env, GetDirectBufferCapacity, v);
  void* __tmp_elems_v = FC_JNI_CALL(env, GetDirectBufferAddress, v);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcFloatArray_setBuffer:v", FC_VOID_EXPR);

  jint err = fcFloatArray_setBuffer(self, __tmp_len, __tmp_elems_v);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_setBuffer", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_syncToNative(JNIEnv* env, jobject obj) {
  fcFloatArray* self = fcFloatArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_getJava", FC_VOID_EXPR);

  jint err = fcFloatArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_syncToNative", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_FloatArray_syncToOCL(JNIEnv* env, jobject obj) {
  fcFloatArray* self = fcFloatArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcFloatArray_getJava", FC_VOID_EXPR);

  jint err = fcFloatArray_syncToOCL(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcFloatArray_syncToOCL", FC_VOID_EXPR);
}

//
// Native Interface Implementation
//

fcError fcFloatArray_createRef(fcFloatArray* array) {
  if (array == NULL || array->location == FC_ARRAY_LOCATION_NONE)
    return FC_EXCEPTION_BAD_PARAMETER;

  ++array->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcFloatArray_releaseRef(fcFloatArray* array) {
  if (array == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  if (array->ref_count <= 1)
    return fcFloatArray_release(array);

  --array->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcFloatArray_init(fcFloatArray* self) {
  if (self->location != FC_ARRAY_LOCATION_NONE)
    return FC_EXCEPTION_INVALID_STATE;

  ++self->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcFloatArray_initSize(fcFloatArray* self, fcInt n) {
  fcError err;

  // Check parameters
  if (n <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  err = fcFloatArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = n;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcFloat), NULL, &err);
  if (err) return err;

  // Update location
  self->location = FC_ARRAY_LOCATION_OPENCL;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcFloatArray_initArray(fcFloatArray* self, fcInt len, const fcFloat* v) {
  fcError err;

  // Check parameters
  if (len <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (v == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcFloatArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcFloat), NULL, &err);
  if (err) return err;

  // Initialize array
  self->location = FC_ARRAY_LOCATION_OPENCL;
  err = fcFloatArray_setArray(self, len, v);

  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
    return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcFloatArray_initPtr(fcFloatArray* self, void * ptr, fcInt len) {
  fcError err;

  // Check parameters
  if (len <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (ptr == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcFloatArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, self->len * sizeof(fcFloat), ptr, &err);
  if (err) return err;

  // Initialize array
  self->location = FC_ARRAY_LOCATION_OPENCL;
  self->c = ptr;

  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
    return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcFloatArray_initCopy(fcFloatArray* self, const fcFloatArray* array) {
  fcError err;

  // Check parameters
  if (array == NULL || !fcFloatArray_valid(array))
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcFloatArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = array->len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcFloat), NULL, &err);
  if (err) return err;

  // Copy array data
  self->location = FC_ARRAY_LOCATION_OPENCL;
  err = fcFloatArray_setCopy(self, array);
  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
  }

  return err;
}

fcError fcFloatArray_release(fcFloatArray* self) {
  --self->ref_count;

  // If it has already been released, only decrease the reference count
  if (self->location != FC_ARRAY_LOCATION_NONE) {
    fcError err = 0;

    if (self->c != NULL) {
      if (self->location != FC_ARRAY_LOCATION_OPENCL) {
        if (self->ocl == NULL) {
          ++self->ref_count;
          return FC_EXCEPTION_INVALID_STATE;
        }
        err = clEnqueueUnmapMemObject(fcOpenCL_rt.queue, self->ocl, self->c, 0, NULL, NULL);
      }

      self->c = NULL;
      if (err) {
        ++self->ref_count; // Release did not succeed, so restore the ref count
        return err;
      }
    }

    if (self->ocl != NULL) {
      err = release_ocl(self->ocl);

      self->ocl = NULL;
      if (err) {
        ++self->ref_count; // Release did not succeed, so restore the ref count
        return err;
      }
    }

    // Mark the object as deleted
    self->location = FC_ARRAY_LOCATION_NONE;
  }

  // Release the instance object if there are no other references to it elsewhere
  if (self->ref_count <= 0)
    free(self);

  return FC_EXCEPTION_SUCCESS;
}

fcFloat fcFloatArray_get(fcFloatArray* self, fcInt i, fcError* err) {
  fcError __tmp_err;
  if (err == NULL) err = &__tmp_err;

  fcFloat __tmp_ret = 0.0f;
  if (!fcFloatArray_valid(self)) {
    *err = FC_EXCEPTION_INVALID_STATE;
    return __tmp_ret;
  }

  if (i < 0 || i >= self->len) {
    *err = FC_EXCEPTION_BAD_PARAMETER;
    return __tmp_ret;
  }

  // Set location to native in order to access the array data
  *err = fcFloatArray_syncToNative(self);
  if (*err) return __tmp_ret;

  return self->c[i];
}

fcError fcFloatArray_set(fcFloatArray* self, fcInt i, fcFloat x) {
  if (!fcFloatArray_valid(self)) return FC_EXCEPTION_INVALID_STATE;
  if (i < 0 || i >= self->len) return FC_EXCEPTION_BAD_PARAMETER;

  // Set location to native in order to access the array data
  fcError err = fcFloatArray_syncToNative(self);
  if (err)
    return err;

  self->c[i] = x;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcFloatArray_setArray(fcFloatArray* self, fcInt len, const fcFloat* v) {
  // No alignment issues, so we can just call setBuffer
  return fcFloatArray_setBuffer(self, len * sizeof(fcFloat), v);
}

fcError fcFloatArray_setCopy(fcFloatArray* self, const fcFloatArray* array) {
  if (!fcFloatArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  // Check parameters
  if (array == NULL || !fcFloatArray_valid(array) || self->len != array->len)
    return FC_EXCEPTION_BAD_PARAMETER;

  // Copy array data
  fcError err;
  fcLong size = self->len * sizeof(fcFloat);

  if (self->location == FC_ARRAY_LOCATION_OPENCL) {
    if (array->location == FC_ARRAY_LOCATION_OPENCL)
      err = clEnqueueCopyBuffer(fcOpenCL_rt.queue, array->ocl, self->ocl, 0, 0, size, 0, NULL, NULL);
    else /* array:FC_ARRAY_LOCATION_NATIVE */
      err = clEnqueueWriteBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, 0, size, array->c, 0, NULL, NULL);
  } else /* self:FC_ARRAY_LOCATION_NATIVE */ {
    if (array->location == FC_ARRAY_LOCATION_OPENCL)
      err = clEnqueueReadBuffer(fcOpenCL_rt.queue, array->ocl, CL_TRUE, 0, size, self->c, 0, NULL, NULL);
    else /* array:FC_ARRAY_LOCATION_NATIVE */
      err = memcpy(self->c, array->c, size) != NULL? FC_EXCEPTION_SUCCESS : FC_EXCEPTION_FAILED_COPY;
  }

  return err;
}

fcError fcFloatArray_setBuffer(fcFloatArray* self, fcLong len, const void* v) {
  if (!fcFloatArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  // Check parameters
  if (len <= 0 || len % sizeof(fcFloat) != 0 || len / sizeof(fcFloat) != self->len)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (v == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  // Copy buffer
  fcError err;
  if (self->location == FC_ARRAY_LOCATION_OPENCL) {
    err = clEnqueueWriteBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, 0, len, v, 0, NULL, NULL);
    if (err) return err;
  }
  else /* self->location == FC_ARRAY_LOCATION_NATIVE */ {
    err = (memcpy(self->c, v, len) != NULL? FC_EXCEPTION_SUCCESS : FC_EXCEPTION_FAILED_COPY);
    if (err) return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcFloatArray_syncToNative(fcFloatArray* self) {
  if (!fcFloatArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  fcError err = FC_EXCEPTION_SUCCESS;

  if (self->location == FC_ARRAY_LOCATION_OPENCL)
    self->c = clEnqueueMapBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, self->len * sizeof(fcFloat), 0, NULL, NULL, &err);

  if (!err)
    self->location = FC_ARRAY_LOCATION_NATIVE;

  return err;
}

fcError fcFloatArray_syncToOCL(fcFloatArray* self) {
  if (!fcFloatArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  fcError err = FC_EXCEPTION_SUCCESS;

  if (self->location == FC_ARRAY_LOCATION_NATIVE)
    err = clEnqueueUnmapMemObject(fcOpenCL_rt.queue, self->ocl, self->c, 0, NULL, NULL);

  if (!err)
    self->location = FC_ARRAY_LOCATION_OPENCL;

  return FC_EXCEPTION_SUCCESS;
}

fcBool fcFloatArray_valid(const fcFloatArray* self) {
  return self->len > 0 &&
    ((self->location == FC_ARRAY_LOCATION_NATIVE && self->c != NULL) ||
     (self->location == FC_ARRAY_LOCATION_OPENCL && self->ocl != NULL));
}


//
// fcDoubleArray
//

FC_JAVA_INSTANCE_HANDLERS(fcDoubleArray);

//
// Java Interface Implementation
//

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_initNative__J(JNIEnv* env, jobject obj, jlong nativePtr) {
  // Create reference
  fcDoubleArray* self = (fcDoubleArray*) nativePtr;
  jint err = fcDoubleArray_createRef(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_createRef", FC_VOID_EXPR);

  // Store native pointer on the Java object
  fcDoubleArray_setJava(env, obj, nativePtr);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_initNative__I(JNIEnv* env, jobject obj, jint n) {
  // Allocate instance
  fcDoubleArray* self = fcDoubleArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_allocJava", FC_VOID_EXPR);

  // Initialize array
  jint err = fcDoubleArray_initSize(self, n);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_initSize", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_initNative___3D(JNIEnv* env, jobject obj, jdoubleArray v) {
  // Allocate instance
  fcDoubleArray* self = fcDoubleArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_allocJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcDoubleArray_initNative__[D:v", FC_VOID_EXPR);

  // Initialize array
  jsize __tmp_len = FC_JNI_CALL(env, GetArrayLength, v);
  jdouble* __tmp_elems_v = FC_JNI_CALL(env, GetDoubleArrayElements, v, NULL);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcDoubleArray_initNative__[D:v", FC_VOID_EXPR);

  jint err = fcDoubleArray_initArray(self, __tmp_len, __tmp_elems_v);

  // Free temporary native array reference
  FC_JNI_CALL(env, ReleaseDoubleArrayElements, v, __tmp_elems_v, JNI_ABORT);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_initArray", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_initNative__Les_ull_pcg_hpc_fancier_array_DoubleArray_2(JNIEnv* env, jobject obj, jobject array) {
  // Allocate instance
  fcDoubleArray* self = fcDoubleArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_allocJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, array, FC_EXCEPTION_BAD_PARAMETER, "fcDoubleArray_initNative__Les_ull_pcg_hpc_fancier_vector_array_DoubleArray;:array", FC_VOID_EXPR);

  // Initialize array
  fcDoubleArray* __tmp_array = fcDoubleArray_getJava(env, array);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_array, FC_EXCEPTION_BAD_PARAMETER, "fcDoubleArray_getJava:array", FC_VOID_EXPR);

  jint err = fcDoubleArray_initCopy(self, __tmp_array);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_initCopy", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_initNative__Ljava_nio_DoubleBuffer_2(JNIEnv* env, jobject obj, jobject buffer) {
  void *buff = (*env)->GetDirectBufferAddress(env, buffer);
  jlong size = (*env)->GetDirectBufferCapacity(env, buffer);

  // Allocate instance
  fcDoubleArray* self = fcDoubleArray_allocJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_allocJava", FC_VOID_EXPR);

  // Store the pointer to array
  jint err = fcDoubleArray_initPtr(self, buff, size);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_initPtr", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_releaseNative(JNIEnv* env, jobject obj) {
  fcDoubleArray* self = fcDoubleArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_getJava", FC_VOID_EXPR);

  // Release memory buffers and decrease the reference count to the instance object
  jint err = fcDoubleArray_release(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_release", FC_VOID_EXPR);

  fcDoubleArray_setJava(env, obj, 0L);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_releaseNativeRef(JNIEnv* env, jobject obj) {
  fcDoubleArray* self = fcDoubleArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_getJava", FC_VOID_EXPR);

  // Release the reference to the instance object and only release the buffers in it as well if this was the
  // only remaining reference to that object
  jint err = fcDoubleArray_releaseRef(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_releaseRef", FC_VOID_EXPR);

  fcDoubleArray_setJava(env, obj, 0L);
}

JNIEXPORT jdouble JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_get__I(JNIEnv* env, jobject obj, jint i) {
  fcDoubleArray* self = fcDoubleArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_getJava", 0.0);

  jint err;
  fcDouble __tmp_ret = fcDoubleArray_get(self, i, &err);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_get", 0.0);

  return __tmp_ret;
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_set__ID(JNIEnv* env, jobject obj, jint i, jdouble x) {
  fcDoubleArray* self = fcDoubleArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_getJava", FC_VOID_EXPR);

  jint err = fcDoubleArray_set(self, i, x);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_set", FC_VOID_EXPR);
}

JNIEXPORT jlong JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_length(JNIEnv* env, jobject obj) {
  fcDoubleArray* self = fcDoubleArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_getJava", 0L);

  if (!fcDoubleArray_valid(self))
    FC_EXCEPTION_HANDLE_ERROR(env, FC_EXCEPTION_INVALID_STATE, "fcDoubleArray_length", 0L);

  return (jlong) self->len;
}

JNIEXPORT jdoubleArray JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_getArray(JNIEnv* env, jobject obj) {
  fcDoubleArray* self = fcDoubleArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_getJava", NULL);

  // Ensure native array is synced
  jint err = fcDoubleArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_syncToNative", NULL);

  // Create Java array and populate it
  jdoubleArray __tmp_ret = FC_JNI_CALL(env, NewDoubleArray, self->len);
  FC_EXCEPTION_HANDLE_PENDING(env, !__tmp_ret, "fcDoubleArray_getArray", NULL);

  FC_JNI_CALL(env, SetDoubleArrayRegion, __tmp_ret, 0, self->len, self->c);
  FC_EXCEPTION_HANDLE_PENDING(env, FC_FALSE, "fcDoubleArray_getArray", __tmp_ret);

  return __tmp_ret;
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_setArray(JNIEnv* env, jobject obj, jdoubleArray v) {
  fcDoubleArray* self = fcDoubleArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcDoubleArray_setArray:v", FC_VOID_EXPR);

  // Get array elements and length
  jsize __tmp_len = FC_JNI_CALL(env, GetArrayLength, v);
  jdouble* __tmp_elems_v = FC_JNI_CALL(env, GetDoubleArrayElements, v, NULL);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcDoubleArray_setArray:v", FC_VOID_EXPR);

  jint err = fcDoubleArray_setArray(self, __tmp_len, __tmp_elems_v);

  // Free temporary native array reference
  FC_JNI_CALL(env, ReleaseDoubleArrayElements, v, __tmp_elems_v, JNI_ABORT);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_setArray", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_setCopy(JNIEnv* env, jobject obj, jobject array) {
  fcDoubleArray* self = fcDoubleArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, array, FC_EXCEPTION_BAD_PARAMETER, "fcDoubleArray_setCopy:array", FC_VOID_EXPR);

  // Get array elements and length
  fcDoubleArray* __tmp_array = fcDoubleArray_getJava(env, array);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_array, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcDoubleArray_setCopy:array", FC_VOID_EXPR);

  jint err = fcDoubleArray_setCopy(self, __tmp_array);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_setCopy", FC_VOID_EXPR);
}

JNIEXPORT jobject JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_getBufferImpl(JNIEnv* env, jobject obj) {
  fcDoubleArray* self = fcDoubleArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_getJava", NULL);

  // Ensure native array is synced
  jint err = fcDoubleArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_syncToNative", NULL);

  // Create and return direct byte buffer pointing to the native data
  return FC_JNI_CALL(env, NewDirectByteBuffer, self->c, self->len * sizeof(fcDouble));
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_setBuffer(JNIEnv* env, jobject obj, jobject v) {
  fcDoubleArray* self = fcDoubleArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_getJava", FC_VOID_EXPR);

  FC_EXCEPTION_HANDLE_NULL(env, v, FC_EXCEPTION_BAD_PARAMETER, "fcDoubleArray_setBuffer:v", FC_VOID_EXPR);

  // Get buffer size and pointer
  jlong __tmp_len = FC_JNI_CALL(env, GetDirectBufferCapacity, v);
  void* __tmp_elems_v = FC_JNI_CALL(env, GetDirectBufferAddress, v);
  FC_EXCEPTION_HANDLE_NULL(env, __tmp_elems_v, FC_EXCEPTION_ARRAY_GET_ELEMENTS, "fcDoubleArray_setBuffer:v", FC_VOID_EXPR);

  jint err = fcDoubleArray_setBuffer(self, __tmp_len, __tmp_elems_v);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_setBuffer", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_syncToNative(JNIEnv* env, jobject obj) {
  fcDoubleArray* self = fcDoubleArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_getJava", FC_VOID_EXPR);

  jint err = fcDoubleArray_syncToNative(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_syncToNative", FC_VOID_EXPR);
}

JNIEXPORT void JNICALL
Java_es_ull_pcg_hpc_fancier_array_DoubleArray_syncToOCL(JNIEnv* env, jobject obj) {
  fcDoubleArray* self = fcDoubleArray_getJava(env, obj);
  FC_EXCEPTION_HANDLE_NULL(env, self, FC_EXCEPTION_INVALID_THIS, "fcDoubleArray_getJava", FC_VOID_EXPR);

  jint err = fcDoubleArray_syncToOCL(self);
  FC_EXCEPTION_HANDLE_ERROR(env, err, "fcDoubleArray_syncToOCL", FC_VOID_EXPR);
}

//
// Native Interface Implementation
//

fcError fcDoubleArray_createRef(fcDoubleArray* array) {
  if (array == NULL || array->location == FC_ARRAY_LOCATION_NONE)
    return FC_EXCEPTION_BAD_PARAMETER;

  ++array->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcDoubleArray_releaseRef(fcDoubleArray* array) {
  if (array == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  if (array->ref_count <= 1)
    return fcDoubleArray_release(array);

  --array->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcDoubleArray_init(fcDoubleArray* self) {
  if (self->location != FC_ARRAY_LOCATION_NONE)
    return FC_EXCEPTION_INVALID_STATE;

  ++self->ref_count;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcDoubleArray_initSize(fcDoubleArray* self, fcInt n) {
  fcError err;

  // Check parameters
  if (n <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  err = fcDoubleArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = n;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcDouble), NULL, &err);
  if (err) return err;

  // Update location
  self->location = FC_ARRAY_LOCATION_OPENCL;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcDoubleArray_initArray(fcDoubleArray* self, fcInt len, const fcDouble* v) {
  fcError err;

  // Check parameters
  if (len <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (v == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcDoubleArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcDouble), NULL, &err);
  if (err) return err;

  // Initialize array
  self->location = FC_ARRAY_LOCATION_OPENCL;
  err = fcDoubleArray_setArray(self, len, v);

  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
    return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcDoubleArray_initPtr(fcDoubleArray* self, void * ptr, fcInt len) {
  fcError err;

  // Check parameters
  if (len <= 0)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (ptr == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcDoubleArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, self->len * sizeof(fcDouble), ptr, &err);
  if (err) return err;

  // Initialize array
  self->location = FC_ARRAY_LOCATION_OPENCL;
  self->c = ptr;

  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
    return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcDoubleArray_initCopy(fcDoubleArray* self, const fcDoubleArray* array) {
  fcError err;

  // Check parameters
  if (array == NULL || !fcDoubleArray_valid(array))
    return FC_EXCEPTION_BAD_PARAMETER;

  err = fcDoubleArray_init(self);
  if (err) return err;

  // Initialize length
  self->len = array->len;

  // Allocate array
  self->ocl = clCreateBuffer(fcOpenCL_rt.context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, self->len * sizeof(fcDouble), NULL, &err);
  if (err) return err;

  // Copy array data
  self->location = FC_ARRAY_LOCATION_OPENCL;
  err = fcDoubleArray_setCopy(self, array);
  if (err) {
    self->location = FC_ARRAY_LOCATION_NONE;
    release_ocl(self->ocl);
    self->ocl = NULL;
  }

  return err;
}

fcError fcDoubleArray_release(fcDoubleArray* self) {
  --self->ref_count;

  // If it has already been released, only decrease the reference count
  if (self->location != FC_ARRAY_LOCATION_NONE) {
    fcError err = 0;

    if (self->c != NULL) {
      if (self->location != FC_ARRAY_LOCATION_OPENCL) {
        if (self->ocl == NULL) {
          ++self->ref_count;
          return FC_EXCEPTION_INVALID_STATE;
        }
        err = clEnqueueUnmapMemObject(fcOpenCL_rt.queue, self->ocl, self->c, 0, NULL, NULL);
      }

      self->c = NULL;
      if (err) {
        ++self->ref_count; // Release did not succeed, so restore the ref count
        return err;
      }
    }

    if (self->ocl != NULL) {
      err = release_ocl(self->ocl);

      self->ocl = NULL;
      if (err) {
        ++self->ref_count; // Release did not succeed, so restore the ref count
        return err;
      }
    }

    // Mark the object as deleted
    self->location = FC_ARRAY_LOCATION_NONE;
  }

  // Release the instance object if there are no other references to it elsewhere
  if (self->ref_count <= 0)
    free(self);

  return FC_EXCEPTION_SUCCESS;
}

fcDouble fcDoubleArray_get(fcDoubleArray* self, fcInt i, fcError* err) {
  fcError __tmp_err;
  if (err == NULL) err = &__tmp_err;

  fcDouble __tmp_ret = 0.0;
  if (!fcDoubleArray_valid(self)) {
    *err = FC_EXCEPTION_INVALID_STATE;
    return __tmp_ret;
  }

  if (i < 0 || i >= self->len) {
    *err = FC_EXCEPTION_BAD_PARAMETER;
    return __tmp_ret;
  }

  // Set location to native in order to access the array data
  *err = fcDoubleArray_syncToNative(self);
  if (*err) return __tmp_ret;

  return self->c[i];
}

fcError fcDoubleArray_set(fcDoubleArray* self, fcInt i, fcDouble x) {
  if (!fcDoubleArray_valid(self)) return FC_EXCEPTION_INVALID_STATE;
  if (i < 0 || i >= self->len) return FC_EXCEPTION_BAD_PARAMETER;

  // Set location to native in order to access the array data
  fcError err = fcDoubleArray_syncToNative(self);
  if (err)
    return err;

  self->c[i] = x;
  return FC_EXCEPTION_SUCCESS;
}

fcError fcDoubleArray_setArray(fcDoubleArray* self, fcInt len, const fcDouble* v) {
  // No alignment issues, so we can just call setBuffer
  return fcDoubleArray_setBuffer(self, len * sizeof(fcDouble), v);
}

fcError fcDoubleArray_setCopy(fcDoubleArray* self, const fcDoubleArray* array) {
  if (!fcDoubleArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  // Check parameters
  if (array == NULL || !fcDoubleArray_valid(array) || self->len != array->len)
    return FC_EXCEPTION_BAD_PARAMETER;

  // Copy array data
  fcError err;
  fcLong size = self->len * sizeof(fcDouble);

  if (self->location == FC_ARRAY_LOCATION_OPENCL) {
    if (array->location == FC_ARRAY_LOCATION_OPENCL)
      err = clEnqueueCopyBuffer(fcOpenCL_rt.queue, array->ocl, self->ocl, 0, 0, size, 0, NULL, NULL);
    else /* array:FC_ARRAY_LOCATION_NATIVE */
      err = clEnqueueWriteBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, 0, size, array->c, 0, NULL, NULL);
  } else /* self:FC_ARRAY_LOCATION_NATIVE */ {
    if (array->location == FC_ARRAY_LOCATION_OPENCL)
      err = clEnqueueReadBuffer(fcOpenCL_rt.queue, array->ocl, CL_TRUE, 0, size, self->c, 0, NULL, NULL);
    else /* array:FC_ARRAY_LOCATION_NATIVE */
      err = memcpy(self->c, array->c, size) != NULL? FC_EXCEPTION_SUCCESS : FC_EXCEPTION_FAILED_COPY;
  }

  return err;
}

fcError fcDoubleArray_setBuffer(fcDoubleArray* self, fcLong len, const void* v) {
  if (!fcDoubleArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  // Check parameters
  if (len <= 0 || len % sizeof(fcDouble) != 0 || len / sizeof(fcDouble) != self->len)
    return FC_EXCEPTION_ARRAY_BAD_LENGTH;

  if (v == NULL)
    return FC_EXCEPTION_BAD_PARAMETER;

  // Copy buffer
  fcError err;
  if (self->location == FC_ARRAY_LOCATION_OPENCL) {
    err = clEnqueueWriteBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, 0, len, v, 0, NULL, NULL);
    if (err) return err;
  }
  else /* self->location == FC_ARRAY_LOCATION_NATIVE */ {
    err = (memcpy(self->c, v, len) != NULL? FC_EXCEPTION_SUCCESS : FC_EXCEPTION_FAILED_COPY);
    if (err) return err;
  }

  return FC_EXCEPTION_SUCCESS;
}

fcError fcDoubleArray_syncToNative(fcDoubleArray* self) {
  if (!fcDoubleArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  fcError err = FC_EXCEPTION_SUCCESS;

  if (self->location == FC_ARRAY_LOCATION_OPENCL)
    self->c = clEnqueueMapBuffer(fcOpenCL_rt.queue, self->ocl, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, self->len * sizeof(fcDouble), 0, NULL, NULL, &err);

  if (!err)
    self->location = FC_ARRAY_LOCATION_NATIVE;

  return err;
}

fcError fcDoubleArray_syncToOCL(fcDoubleArray* self) {
  if (!fcDoubleArray_valid(self))
    return FC_EXCEPTION_INVALID_STATE;

  fcError err = FC_EXCEPTION_SUCCESS;

  if (self->location == FC_ARRAY_LOCATION_NATIVE)
    err = clEnqueueUnmapMemObject(fcOpenCL_rt.queue, self->ocl, self->c, 0, NULL, NULL);

  if (!err)
    self->location = FC_ARRAY_LOCATION_OPENCL;

  return FC_EXCEPTION_SUCCESS;
}

fcBool fcDoubleArray_valid(const fcDoubleArray* self) {
  return self->len > 0 &&
    ((self->location == FC_ARRAY_LOCATION_NATIVE && self->c != NULL) ||
     (self->location == FC_ARRAY_LOCATION_OPENCL && self->ocl != NULL));
}


