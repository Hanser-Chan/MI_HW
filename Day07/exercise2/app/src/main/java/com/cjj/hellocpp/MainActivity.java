package com.cjj.hellocpp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.cjj.hellocpp.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'hellocpp' library on application startup.
    static {
        System.loadLibrary("hellocpp");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(JNITest.stringFromJNI() + JNITest.add(8,9));    //静态函数才可以用类名调用，非静态需要用类对象调用

    }

    /**
     * A native method that is implemented by the 'hellocpp' native library,
     * which is packaged with this application.
     */
//    public native static String stringFromJNI();
//
//    public native static int add(int a, int b);
}