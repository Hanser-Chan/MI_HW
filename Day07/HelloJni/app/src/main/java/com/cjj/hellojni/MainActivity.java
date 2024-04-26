package com.cjj.hellojni;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.cjj.hellocpp.JNITest;
import com.cjj.hellojni.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'hellojni' library on application startup.
    static {
        System.loadLibrary("hellojni");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        //binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
//        TextView tv = binding.sampleText;
        Log.d("111", JNITest.stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'hellojni' native library,
     * which is packaged with this application.
     */
    //public native String stringFromJNI();
}