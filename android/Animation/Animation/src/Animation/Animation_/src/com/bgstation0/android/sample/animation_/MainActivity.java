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
        
        // �A�j���[�V����
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        Animation animation = new AlphaAnimation(0.1f, 0.9f);	// Animation�I�u�W�F�N�ganimation�Ɋi�[.
        animation.setDuration(5000);	// 5�b�A�j���[�V����.
        button1.setAnimation(animation);	// button1��animation���Z�b�g.
        
    }
    
}