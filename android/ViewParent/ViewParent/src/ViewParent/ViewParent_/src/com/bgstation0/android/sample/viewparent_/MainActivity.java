package com.bgstation0.android.sample.viewparent_;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewParent;
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
		
		// textview1�̐e�̐e��View���擾.
        TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
        ViewParent viewParent1 = textview1.getParent();	// �e��viewParent1���擾.
        if (viewParent1 != null){	// null�łȂ�.
        	View view1 = (View)viewParent1;	// View��view1�ɃL���X�g.
        	if (view1.getId() == R.id.layout_sub){	// ID��layout_sub�Ȃ�.
        		Log.d(TAG, "layout_sub!");	// "layout_sub!"�ƃ��O�o��.
        		ViewParent viewParent2 = viewParent1.getParent();	// ����ɐe��viewParent2���擾.
        		if (viewParent2 != null){	// null�łȂ�.
        			View view2 = (View)viewParent2;	// view2���擾.
        			if (view2.getId() == R.id.layout_main){	// ID��layout_main�Ȃ�.
        				Log.d(TAG, "layout_main!");	// "layout_main!"�ƃ��O�o��.
        			}
        		}
        	}
        }
        
	}
    
}
