package com.bgstation0.android.sample.view_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

//���C���A�N�e�B�r�e�B
public class MainActivity extends Activity implements OnClickListener{

	// �A�N�e�B�r�e�B������
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        
    	// ����̏���.
    	super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1�̏�����
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        button1.setOnClickListener(this);	// this���Z�b�g.
        
    }
    
    // �N���b�N���ꂽ��.
 	@Override
 	public void onClick(View v) {
 		
 		// TODO Auto-generated method stub
 		// CustomView�ɕ�������Z�b�g.
 		CustomView customView1 = (CustomView)findViewById(R.id.customview1);	// customView1���擾.
 		customView1.mStr1 = "ABCDE";	// mStr1��"ABCDE"���Z�b�g.
 		customView1.mStr2 = "FGHIJ";	// mStr2��"FGHIJ"���Z�b�g.
 		customView1.mStr3 = "KLMNO";	// mStr3��"KLMNO"���Z�b�g.
 		customView1.invalidate();	// customView1.invalidate�ōĕ`��.
 		
 	}
    
}