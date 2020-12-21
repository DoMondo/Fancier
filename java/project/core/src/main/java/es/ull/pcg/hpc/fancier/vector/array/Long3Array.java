package es.ull.pcg.hpc.fancier.vector.array;

import es.ull.pcg.hpc.fancier.vector.Long3;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;


public class Long3Array implements AutoCloseable {
  private long nativeInstancePtr = 0L;

  private Long3Array(long nativePtr) {
    initNative(nativePtr);
  }

  public Long3Array(int n) {
    initNative(n);
  }

  public Long3Array(long[] v) {
    initNative(v);
  }

  public Long3Array(Long3Array array) {
    initNative(array);
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

  public static Long3 getBuffer(ByteBuffer buffer, int index) {
    final int baseIndex = index * Long.BYTES * 4;
    return new Long3(buffer.getLong(baseIndex + 0 * Long.BYTES), buffer.getLong(baseIndex + 1 * Long.BYTES), buffer.getLong(baseIndex + 2 * Long.BYTES));
  }

  public static void getBuffer(ByteBuffer buffer, int index, Long3 result) {
    final int baseIndex = index * Long.BYTES * 4;
    result.x = buffer.getLong(baseIndex + 0 * Long.BYTES);
    result.y = buffer.getLong(baseIndex + 1 * Long.BYTES);
    result.z = buffer.getLong(baseIndex + 2 * Long.BYTES);
  }

  public static void setBuffer(ByteBuffer buffer, int index, Long3 a) {
    final int baseIndex = index * Long.BYTES * 4;
    buffer.putLong(baseIndex + 0 * Long.BYTES, a.x);
    buffer.putLong(baseIndex + 1 * Long.BYTES, a.y);
    buffer.putLong(baseIndex + 2 * Long.BYTES, a.z);
  }

  private native void initNative(long nativePtr);
  private native void initNative(int n);
  private native void initNative(long[] v);
  private native void initNative(Long3Array array);
  private native void releaseNative();
  private native void releaseNativeRef();

  public native Long3 get(int i);
  public native void set(int i, Long3 x);
  public native long length();

  public native long[] getArray();
  public native void setArray(long[] v);
  public native void setCopy(Long3Array array);
  private native ByteBuffer getBufferImpl();
  public native void setBuffer(ByteBuffer v);

  public native void syncToNative();
  public native void syncToOCL();
}
