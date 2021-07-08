package com.bgstation0.android.sample.actionbar_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListener������.

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // �Ǝ��̃A�C�R�����Z�b�g.
        getActionBar().setIcon(R.drawable.icon1);	// icon1���Z�b�g.
        
        // button1���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
        button1.setOnClickListener(this);	// button1.setOnClickListener��this(���g)���Z�b�g.
        
        // button2���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button2 = (Button)findViewById(R.id.button2);	// findViewById��R.id.button2���擾.
        button2.setOnClickListener(this);	// button2.setOnClickListener��this(���g)���Z�b�g.
        
    }
    
    // View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.
    	
    	// ���\�[�XID���ƂɐU�蕪��.
    	if (v.getId() == R.id.button1){	// button1.
    		
    		// button1�������ꂽ��SubActivity���N��.
    		Intent intent = new Intent(this, SubActivity.class);	// SubActivity��ΏۂƂ���Intent�I�u�W�F�N�gintent�𐶐�.
    		startActivity(intent);	// startActivity��intent���w�肵��Activity���N��.
    	
    	}
    	else{	// button2.
    		
    		// button2�������ꂽ��ThirdActivity���N��.
    		Intent intent = new Intent(this, ThirdActivity.class);	// ThirdActivity��ΏۂƂ���Intent�I�u�W�F�N�gintent�𐶐�.
    		startActivity(intent);	// startActivity��intent���w�肵��Activity���N��.
    		
    	}
    	
    }
    
}