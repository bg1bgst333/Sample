package com.bgstation0.android.sample.animation_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.widget.Button;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // アニメーション
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        Animation animation = new AlphaAnimation(0.1f, 0.9f);	// Animationオブジェクトanimationに格納.
        animation.setDuration(5000);	// 5秒アニメーション.
        button1.setAnimation(animation);	// button1にanimationをセット.
        
    }
    
}