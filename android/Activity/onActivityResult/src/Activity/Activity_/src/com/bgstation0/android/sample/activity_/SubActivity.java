package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

//MainActivity�ɂ���ċN�������SubActivity.
public class SubActivity extends Activity implements OnClickListener{	// SubActivity�̒�`.

	// Activity���������ꂽ�Ƃ�.
	@Override
	protected void onCreate(Bundle savedInstanceState) {	// onCreate�̒�`
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_sub);
		
		// button2���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button2 = (Button)findViewById(R.id.button2);	// findViewById��R.id.button2���擾.
        button2.setOnClickListener(this);	// button1.setOnClickListener��this(���g)���Z�b�g.
	}
	
	// View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.
    	
    	// �{�^����ID���ƂɐU�蕪����.
    	switch (v.getId()){	// v.getId���ƂɐU�蕪����.
    	
    		// button2�̎�.
    		case R.id.button2:
    			
    			// R.id.button2�u���b�N
    			{
    				
    				// �f�[�^��t�����Č��̃A�N�e�B�r�e�B�ɖ߂�.
    				//Intent data = new Intent();	// data�Ƃ���Intent���쐬.
    				//data.putExtra("message", "ABCDE");	// data.putExtra��, �L�[��"message", �l��"ABCDE"�Ƃ��ď�������.
    				//setResult(RESULT_OK, data);	// ���U���g�R�[�h��RESULT_OK, �Ԃ��f�[�^�C���e���g��data�Ƃ���setResult�ŃZ�b�g.
    				setResult(RESULT_CANCELED, null);	// RESULT_CANCELED.
    				finish();	// finish�ł��̃A�N�e�B�r�e�B�͏I����, �O�̃A�N�e�B�r�e�B�ɖ߂�.
    				
    			}
    			
    	}
    	
    }
    
}
