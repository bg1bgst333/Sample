package com.bgstation0.android.sample.textview_;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // TextView�I�u�W�F�N�g�̃C���X�^���X���쐬��, "TextView.setText"�ƃe�L�X�g���Z�b�g��, ������r���[�ɃZ�b�g.
        //setContentView(R.layout.activity_main);	// ���̕����̓R�����g�A�E�g.
        TextView tv = new TextView(this);	// TextView�I�u�W�F�N�g�̃C���X�^���X��tv�Ɋi�[.
        tv.setTextColor(Color.RED);	// tv.setTextColor��Color.RED���Z�b�g.
        tv.setText("TextView.setText");	// tv.setText��"TextView.setText"���Z�b�g.
        setContentView(tv);	// setContentView�Ńr���[��tv���Z�b�g.
    }
}
