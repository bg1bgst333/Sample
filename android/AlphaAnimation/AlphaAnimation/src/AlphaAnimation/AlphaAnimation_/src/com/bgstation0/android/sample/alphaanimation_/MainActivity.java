package com.bgstation0.android.sample.alphaanimation_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.animation.AlphaAnimation;
import android.widget.Button;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // �A�j���[�V����
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        AlphaAnimation alphaAnimation = new AlphaAnimation(0.1f, 0.9f);	// alphaAnimation����.(�A���t�@�l0.1����A���t�@�l0.9�܂�.)
        alphaAnimation.setDuration(5000);	// 5�b�A�j���[�V����.
        button1.setAnimation(alphaAnimation);	// button1��alphaAnimation���Z�b�g.
        
    }
    
}
