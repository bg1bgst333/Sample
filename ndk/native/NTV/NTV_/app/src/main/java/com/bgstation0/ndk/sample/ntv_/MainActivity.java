package com.bgstation0.ndk.sample.ntv_;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        // ToastでintFromJNIの値を返す.
        Toast.makeText(this, "intFromJNI() = " + intFromJNI(), Toast.LENGTH_LONG).show();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    // 自分でnativeメソッドを追加してみる.
    public native int intFromJNI(); // int型の数値を返すnativeメソッドintFromJNI

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
}
