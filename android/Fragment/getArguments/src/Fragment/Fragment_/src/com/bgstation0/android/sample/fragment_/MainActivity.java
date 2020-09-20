package com.bgstation0.android.sample.fragment_;

import android.app.Activity;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

//���C���A�N�e�B�r�e�B
public class MainActivity extends Activity implements OnClickListener{

	// ������
	@Override
	protected void onCreate(Bundle savedInstanceState) {
 	
		// ����̏���.
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
     
		// Button1�̏���.
		Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
		button1.setOnClickListener(this);	// ���X�i�[�Ƃ���this���Z�b�g.
     
	}
 
	// �N���b�N��
	public void onClick(View v){
 	
		// FragmentManager, fragmentTransaction�̎擾.
		FragmentManager fragmentManager = getFragmentManager();	// fragmentManager�̎擾.
		FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransaction�̎擾.
 	
		// Button���Ƃɕ�����.
		int id = v.getId();	// v.getId��id���擾.
		if (id == R.id.button1){	// button1�Ȃ�.
			Fragment1 fragment1 = new Fragment1();	// fragment1�𐶐�.
			Bundle args = new Bundle();	// args���쐬.
			args.putString(Fragment1.KEY, "ABCDE");	// "ABCDE"��o�^.
			fragment1.setArguments(args);	// fragment1.setArguments��args���Z�b�g.
			fragmentTransaction.replace(R.id.framelayout1, fragment1);	// fragment1�ɒu��.
			fragmentTransaction.commit();	// �R�~�b�g.
		}
		
	}
 
}