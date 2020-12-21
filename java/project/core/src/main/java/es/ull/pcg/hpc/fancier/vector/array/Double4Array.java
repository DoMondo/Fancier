package es.ull.pcg.hpc.fancier.vector.array;

import es.ull.pcg.hpc.fancier.vector.Double4;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;


public class Double4Array implements AutoCloseable {
  private long nativeInstancePtr = 0L;

  private Double4Array(long nativePtr) {
    initNative(nativePtr);
  }

  public Double4Array(int n) {
    initNative(n);
  }

  public Double4Array(double[] v) {
    initNative(v);
  }

  public Double4Array(Double4Array array) {
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

  public static Double4 getBuffer(ByteBuffer buffer, int index) {
    final int baseIndex = index * Double.BYTES * 4;
    return new Double4(buffer.getDouble(baseIndex + 0 * Double.BYTES), buffer.getDouble(baseIndex + 1 * Double.BYTES), buffer.getDouble(baseIndex + 2 * Double.BYTES), buffer.getDouble(baseIndex + 3 * Double.BYTES));
  }

  public static void getBuffer(ByteBuffer buffer, int index, Double4 result) {
    final int baseIndex = index * Double.BYTES * 4;
    result.x = buffer.getDouble(baseIndex + 0 * Double.BYTES);
    result.y = buffer.getDouble(baseIndex + 1 * Double.BYTES);
    result.z = buffer.getDouble(baseIndex + 2 * Double.BYTES);
    result.w = buffer.getDouble(baseIndex + 3 * Double.BYTES);
  }

  public static void setBuffer(ByteBuffer buffer, int index, Double4 a) {
    final int baseIndex = index * Double.BYTES * 4;
    buffer.putDouble(baseIndex + 0 * Double.BYTES, a.x);
    buffer.putDouble(baseIndex + 1 * Double.BYTES, a.y);
    buffer.putDouble(baseIndex + 2 * Double.BYTES, a.z);
    buffer.putDouble(baseIndex + 3 * Double.BYTES, a.w);
  }

  private native void initNative(long nativePtr);
  private native void initNative(int n);
  private native void initNative(double[] v);
  private native void initNative(Double4Array array);
  private native void releaseNative();
  private native void releaseNativeRef();

  public native Double4 get(int i);
  public native void set(int i, Double4 x);
  public native long length();

  public native double[] getArray();
  public native void setArray(double[] v);
  public native void setCopy(Double4Array array);
  private native ByteBuffer getBufferImpl();
  public native void setBuffer(ByteBuffer v);

  public native void syncToNative();
  public native void syncToOCL();
}
