package com.bgstation0.android.sample.dialog_;

import android.app.Activity;
import android.app.Dialog;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

// ���C���A�N�e�B�r�e�B.
public class MainActivity extends Activity implements OnClickListener{

	// �����o�t�B�[���h.
	private final int DIALOG_ID_1 = 1;	// DIALOG_ID_1��1�ɂ���.
	
	// �A�N�e�B�r�e�B������.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// ����̏���.
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
        button1.setOnClickListener(this);	// button1.setOnClickListener��this(���g)���Z�b�g.
      
    }
    
    // onCreateDialog�Ń_�C�A���O�쐬.
    @Override
    protected Dialog onCreateDialog(int id){
    	//�@Dialog�̐���.
    	Dialog dialog = new Dialog(this);	// Dialog�I�u�W�F�N�gdialog�𐶐�.
    	return dialog;	// dialog��Ԃ�.
    }

    // �N���b�N��.
	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		// �_�C�A���O�̕\��.
		showDialog(DIALOG_ID_1);	// showDialog��DIALOG_ID_1�̃_�C�A���O��\��.
	}
	
}