package es.ull.pcg.hpc.fancier.vector.array;

import es.ull.pcg.hpc.fancier.vector.Int3;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;


public class Int3Array implements AutoCloseable {
  private long nativeInstancePtr = 0L;

  private Int3Array(long nativePtr) {
    initNative(nativePtr);
  }

  public Int3Array(int n) {
    initNative(n);
  }

  public Int3Array(int[] v) {
    initNative(v);
  }

  public Int3Array(Int3Array array) {
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

  public static Int3 getBuffer(ByteBuffer buffer, int index) {
    final int baseIndex = index * Integer.BYTES * 4;
    return new Int3(buffer.getInt(baseIndex + 0 * Integer.BYTES), buffer.getInt(baseIndex + 1 * Integer.BYTES), buffer.getInt(baseIndex + 2 * Integer.BYTES));
  }

  public static void getBuffer(ByteBuffer buffer, int index, Int3 result) {
    final int baseIndex = index * Integer.BYTES * 4;
    result.x = buffer.getInt(baseIndex + 0 * Integer.BYTES);
    result.y = buffer.getInt(baseIndex + 1 * Integer.BYTES);
    result.z = buffer.getInt(baseIndex + 2 * Integer.BYTES);
  }

  public static void setBuffer(ByteBuffer buffer, int index, Int3 a) {
    final int baseIndex = index * Integer.BYTES * 4;
    buffer.putInt(baseIndex + 0 * Integer.BYTES, a.x);
    buffer.putInt(baseIndex + 1 * Integer.BYTES, a.y);
    buffer.putInt(baseIndex + 2 * Integer.BYTES, a.z);
  }

  private native void initNative(long nativePtr);
  private native void initNative(int n);
  private native void initNative(int[] v);
  private native void initNative(Int3Array array);
  private native void releaseNative();
  private native void releaseNativeRef();

  public native Int3 get(int i);
  public native void set(int i, Int3 x);
  public native long length();

  public native int[] getArray();
  public native void setArray(int[] v);
  public native void setCopy(Int3Array array);
  private native ByteBuffer getBufferImpl();
  public native void setBuffer(ByteBuffer v);

  public native void syncToNative();
  public native void syncToOCL();
}
