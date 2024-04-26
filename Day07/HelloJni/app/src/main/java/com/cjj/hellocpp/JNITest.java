package com.cjj.hellocpp;

public class JNITest {

    static {
        System.loadLibrary("hellocpp");
    }

    public native static String stringFromJNI();
    public native static int add(int a, int b);


}
