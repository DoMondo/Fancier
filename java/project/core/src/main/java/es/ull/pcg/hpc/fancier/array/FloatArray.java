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

package es.ull.pcg.hpc.fancier.array;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;

public class FloatArray implements AutoCloseable {
  private long nativeInstancePtr = 0L;

  private FloatArray(long nativePtr) {
    initNative(nativePtr);
  }

  public FloatArray(int n) {
    initNative(n);
  }

  public FloatArray(float[] v) {
    initNative(v);
  }

  public FloatArray(FloatArray array) {
    initNative(array);
  }

  public FloatArray(FloatBuffer buffer) {
    initNative(buffer);
  }

  /**
   * Release native buffers belonging to this class.
   *
   * This must be called in order to avoid memory leaks.
   */
  public void release() {
    if (nativeInstancePtr != 0L)
      releaseNative();
  }

  @Override
  public void close() {
    release();
  }

  @Override
  public void finalize() throws Throwable {
    if (nativeInstancePtr != 0L)
      releaseNativeRef();

    super.finalize();
  }

  public ByteBuffer getBuffer() {
    return getBufferImpl().order(ByteOrder.nativeOrder());
  }

  public static float getBuffer(ByteBuffer buffer, int index) {
    return buffer.getFloat(index * Float.BYTES);
  }

  public static void setBuffer(ByteBuffer buffer, int index, float x) {
    buffer.putFloat(index * Float.BYTES, x);
  }

  private native void initNative(long nativePtr);
  private native void initNative(int n);
  private native void initNative(float[] v);
  private native void initNative(FloatArray array);
  private native void initNative(FloatBuffer buffer);
  private native void releaseNative();
  private native void releaseNativeRef();

  public native float get(int i);
  public native void set(int i, float x);
  public native long length();

  public native float[] getArray();
  public native void setArray(float[] v);
  public native void setCopy(FloatArray array);
  private native ByteBuffer getBufferImpl();
  public native void setBuffer(ByteBuffer buffer);

  public native void syncToNative();
  public native void syncToOCL();
}
