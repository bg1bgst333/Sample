package com.bgstation0.android.sample.view_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListener������.

	// �����o�t�B�[���h�̒�`.
	private static final String TAG_BUTTON_1 = "tag_button_1";	// TAG_BUTTON_1��"tag_button_1"�ƒ�`.
	private static final String TAG_BUTTON_2 = "tag_button_2";	// TAG_BUTTON_2��"tag_button_2"�ƒ�`.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
        button1.setOnClickListener(this);	// button1.setOnClickListener��this(���g)���Z�b�g.
        button1.setTag(TAG_BUTTON_1);	// TAG_BUTTON_1���Z�b�g.
        
        // button2�𗘗p��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button2 = (Button)findViewById(R.id.button2);	// findViewById��R.id.button2���擾.
        button2.setOnClickListener(this);	// button2.setOnClickListener��this(���g)���Z�b�g.
        button2.setTag(TAG_BUTTON_2);	// TAG_BUTTON_2���Z�b�g.
        
    }
    
    // View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.
    
    	// �^�O�ŐU�蕪��.
    	String tag = (String)v.getTag();	// tag���擾.
    	if (tag != null){	// tag��null�łȂ���.
        	if (tag.equals(TAG_BUTTON_1)){	// TAG_BUTTON_1
        		Toast.makeText(this, "Button1", Toast.LENGTH_LONG).show();	// "Button1"���g�[�X�g�\��.
    	    }
    	    else if (tag.equals(TAG_BUTTON_2)){	// TAG_BUTTON_2
    		    Toast.makeText(this, "Button2", Toast.LENGTH_LONG).show();	// "Button2"���g�[�X�g�\��.
    	    }
        }
    
    }

}