package com.bgstation0.android.sample.view_;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;

//���C���A�N�e�B�r�e�B
public class MainActivity extends Activity {

	// �����o�t�B�[���h
	static final String TAG = "MainActivity";	// TAG��"MainActivity"�ŏ�����.
	
	// ������
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// ����̏���.
    	super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // textview1�̐e��View���擾.
        TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
        View view = (View)textview1.getParent();	// �e��view���擾.
        if (view != null){	// null�łȂ�.
        	if (view.getId() == R.id.layout_main){	// ID��layout_main�Ȃ�.
        		Log.d(TAG, "layout_main!");	// "layout_main!"�ƃ��O�o��.
        	}
        }
        
    }
    
}
