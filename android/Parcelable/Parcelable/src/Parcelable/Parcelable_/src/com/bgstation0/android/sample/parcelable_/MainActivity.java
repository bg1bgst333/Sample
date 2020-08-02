package com.bgstation0.android.sample.parcelable_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

// ���C���A�N�e�B�r�e�B
public class MainActivity extends Activity implements OnClickListener{

	// �����o�t�B�[���h�̒�`
	final String KEY_PARCELABLE_STRING = "key_parcelable_string";	// �萔KEY_PARCELABLE_STRING���`.
	private CustomParcelable mCustomParcelable;	// CustomParcelable�I�u�W�F�N�gmCustomParcelable.
	
	// �A�N�e�B�r�e�B������
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// ����̏���
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    
        // button1�̏�����
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        button1.setOnClickListener(this);	// this���Z�b�g.
        
    }
    
    // �N���b�N���ꂽ��.
    @Override
    public void onClick(View v){
    	
    	// textview1����textview3�܂ŏ�����.
        TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
        TextView textview2 = (TextView)findViewById(R.id.textview2);	// textview2���擾.
        TextView textview3 = (TextView)findViewById(R.id.textview3);	// textview3���擾.
        textview1.setText("ABCDE");	// textview1��"ABCDE"���Z�b�g.
        textview2.setText("FGHIJ");	// textview2��"FGHIJ"���Z�b�g.
        textview3.setText("KLMNO");	// textview3��"KLMNO"���Z�b�g.
        
    }
    
    // �A�N�e�B�r�e�B�̃C���X�^���X�̈ꎞ�I�ȕێ����v�����ꂽ��.
 	@Override
 	protected void onSaveInstanceState(Bundle outState){
 		
 		// ����̏���
 		super.onSaveInstanceState(outState);	// �e�N���X�̃��\�b�h���Ă�.
 		
 		// TextView����̎擾.
 		TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
 		TextView textview2 = (TextView)findViewById(R.id.textview2);	// textview2���擾.
 		TextView textview3 = (TextView)findViewById(R.id.textview3);	// textview3���擾.
 		String str1 = (String)textview1.getText();	// �e�L�X�g��str1�Ɋi�[.
 		String str2 = (String)textview2.getText();	// �e�L�X�g��str2�Ɋi�[.
 		String str3 = (String)textview3.getText();	// �e�L�X�g��str3�Ɋi�[.
 		
 		// �J�X�^���p�[�Z���u���̐���.
 		mCustomParcelable = new CustomParcelable(str1, str2, str3);	// mCustomParcelable�ɃZ�b�g.

 		// ��Ԃ�ۑ�.
 		outState.putParcelable(KEY_PARCELABLE_STRING, mCustomParcelable);	// outState.putParcelable��mCustomParcelable��ۑ�.
 		
 	}
 	
	// �A�N�e�B�r�e�B�̃C���X�^���X�̕������v�����ꂽ��.
	@Override
	protected void onRestoreInstanceState(Bundle inState){
	
		// ����̏���
		super.onRestoreInstanceState(inState);	// �e�N���X�̃��\�b�h���Ă�.
		
		// �J�X�^���p�[�Z���u���̎擾.
		mCustomParcelable = inState.getParcelable(KEY_PARCELABLE_STRING);	// inState.getParcelable�Ŏ擾�����p�[�Z���u����mCustomParcelable�Ɋi�[.
		if (mCustomParcelable != null){	// null�łȂ����.
			
			// TextView�ւ̃Z�b�g.
			TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
			TextView textview2 = (TextView)findViewById(R.id.textview2);	// textview2���擾.
			TextView textview3 = (TextView)findViewById(R.id.textview3);	// textview3���擾.
			textview1.setText(mCustomParcelable.getStr1());	// textview1.setText��mCustomParcelable.getStr1()���Z�b�g.
			textview2.setText(mCustomParcelable.getStr2());	// textview2.setText��mCustomParcelable.getStr2()���Z�b�g.
			textview3.setText(mCustomParcelable.getStr3());	// textview3.setText��mCustomParcelable.getStr3()���Z�b�g.
			
		}
		
	}
 	
}