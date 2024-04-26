package com.example.test3;

import android.app.Activity;
import android.app.Application;
import android.os.Bundle;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.core.content.OnTrimMemoryProvider;

public class MyApplication extends Application {
    @Override
    public void onCreate(){
        super.onCreate();
        Log.d("Hello","myapp create");
        registerActivityLifecycleCallbacks(new ActivityLifecycleCallbacks() {
            @Override
            public void onActivityCreated(@NonNull Activity activity, @Nullable Bundle bundle) {
                Log.d("Hello",activity + "myapp create");
            }

            @Override
            public void onActivityStarted(@NonNull Activity activity) {
                Log.d("Hello",activity + "myapp start");
            }

            @Override
            public void onActivityResumed(@NonNull Activity activity) {
                Log.d("Hello",activity + "myapp resume");
            }

            @Override
            public void onActivityPaused(@NonNull Activity activity) {
                Log.d("Hello",activity + "myapp pause");
            }

            @Override
            public void onActivityStopped(@NonNull Activity activity) {
                Log.d("Hello",activity + "myapp stop");
            }

            @Override
            public void onActivitySaveInstanceState(@NonNull Activity activity, @NonNull Bundle bundle) {
                Log.d("Hello",activity + "myapp save");
            }

            @Override
            public void onActivityDestroyed(@NonNull Activity activity) {
                Log.d("Hello",activity + "myapp destroyed");
            }
        });
    }



    @Override
    public void onTrimMemory(int level){
        super.onTrimMemory(level);
    }



//    @Override
//    public void onConfigurationChanged(){
//
//    }
}
