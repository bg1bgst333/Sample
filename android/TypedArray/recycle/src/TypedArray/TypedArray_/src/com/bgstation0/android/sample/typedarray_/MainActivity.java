package com.bgstation0.android.sample.typedarray_;

import android.app.Activity;
import android.content.res.Resources;
import android.content.res.TypedArray;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

//���C���A�N�e�B�r�e�B�N���XMainActivity�̒�`.
public class MainActivity extends Activity {

    // �����o�t�B�[���h�̒�`
    static final String TAG = "MainActivity";	// TAG��"MainActivity"�ŏ�����.

    // �A�N�e�B�r�e�B������
    @Override
    protected void onCreate(Bundle savedInstanceState) {
	
        // ����̏���
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
      
        // �^�t���z��̎擾.
        Resources res = getResources();	// res���擾.
        TypedArray mixedarray = res.obtainTypedArray(R.array.mixedarray);	// mixedarray�̎擾.
        int i = mixedarray.getInt(0, -1);	// mixedarray.getInt��0�Ԗڂ̐������擾.
        Log.d(TAG, "i = " + i);	// i���o��.
        String s = mixedarray.getString(1);	// mixedarray.getString��1�Ԗڂ̕�������擾.
        Log.d(TAG, "s = " + s);	// s���o��.
        int c = mixedarray.getColor(2, -1);	// mixedarray.getColor��2�Ԗڂ̐F�R�[�h���擾.
        Log.d(TAG, "c = " + c);	// c���o��.
        TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
        textview1.setTextColor(c);	// textview1.setTextColor��c���Z�b�g.
        Log.d(TAG, "recycle.before");	// before
        mixedarray.recycle();	// mixedarray.recycle�ŏI������.
        Log.d(TAG, "recycle.after");	// array
        
    }
  
}
