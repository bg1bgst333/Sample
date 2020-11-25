package com.bgstation0.android.sample.view_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // アニメーション
        TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1を取得.
        Animation animation = new AlphaAnimation(0.1f, 0.9f);	// Animationオブジェクトanimationに格納.
        animation.setDuration(1000);	// 1秒アニメーション.
        View v = textview1;	// textview1をvに格納.
        v.setAnimation(animation);	// vにanimationをセット.
        
    }
    
}