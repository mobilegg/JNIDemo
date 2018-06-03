package com.mobilegg.jnidemo;

public class JNIUtil {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native void testJString(String input);
    public native void testJIntArray(int[] input);
    public native void testJObjectArray(Object[] input);
    public native void testComplexObject(Student input);
}
