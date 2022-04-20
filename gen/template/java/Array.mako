## Fancier: Unified Java, JNI and OpenCL Integration High-Performance GPGPU API.
## Copyright (C) 2021 Universidad de La Laguna.
##
## Fancier is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## Fancier is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with Fancier.  If not, see <https://www.gnu.org/licenses/>.
##
<%include file="/license.txt"/>
<%include file="/auto-gen.txt"/>
package es.ull.pcg.hpc.fancier.array;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.${type|c}Buffer;

public class ${type|c}Array implements AutoCloseable {
  private long nativeInstancePtr = 0L;

  private ${type|c}Array(long nativePtr) {
    initNative(nativePtr);
  }

  public ${type|c}Array(int n) {
    initNative(n);
  }

  public ${type|c}Array(${type|l}[] v) {
    initNative(v);
  }

  public ${type|c}Array(${type|c}Array array) {
    initNative(array);
  }

  public ${type|c}Array(${type|c}Buffer buffer) {
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

<%
  bytes_expr = ('Integer' if type.lower() == 'int' else type.capitalize()) + '.BYTES'
  buffer_get = f'get{type.capitalize()}' if type.lower() != 'byte' else 'get'
  buffer_put = f'put{type.capitalize()}' if type.lower() != 'byte' else 'put'
%>\
  public static ${type|l} getBuffer(ByteBuffer buffer, int index) {
    return buffer.${buffer_get}(index * ${bytes_expr});
  }

  public static void setBuffer(ByteBuffer buffer, int index, ${type|l} x) {
    buffer.${buffer_put}(index * ${bytes_expr}, x);
  }

  private native void initNative(long nativePtr);
  private native void initNative(int n);
  private native void initNative(${type|l}[] v);
  private native void initNative(${type|c}Array array);
  private native void initNative(${type|c}Buffer buffer);
  private native void releaseNative();
  private native void releaseNativeRef();

  public native ${type|l} get(int i);
  public native void set(int i, ${type|l} x);
  public native long length();

  public native ${type|l}[] getArray();
  public native void setArray(${type|l}[] v);
  public native void setCopy(${type|c}Array array);
  private native ByteBuffer getBufferImpl();
  public native void setBuffer(ByteBuffer buffer);

  public native void syncToNative();
  public native void syncToOCL();
}
