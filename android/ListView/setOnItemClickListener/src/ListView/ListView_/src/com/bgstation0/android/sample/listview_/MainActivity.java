package com.bgstation0.android.sample.listview_;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

public class MainActivity extends Activity {

	// �����o�t�B�[���h
	Context mContext = null;	// mContext��null�ŏ�����.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // �t�B�[���h�̏�����.
        mContext = this;	// mContext��this���Z�b�g.
        
        // String�z��Œǉ�����v�f���`.
        String[] items = new String[3];	// String�z��items(�v�f��3)
        items[0] = "item1";	// item1
        items[1] = "item2";	// item2
        items[2] = "item3";	// item3
        
        // ListView�I�u�W�F�N�g���擾.
        ListView listview1 = (ListView)findViewById(R.id.listview1);	// findViewById��listview1���擾.
        
        // ArrayAdapter<String>��adapter�𐶐�����, listview1��adapter��items��R�t����.
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, R.layout.list_item, items);	// ArrayAdapter<String>�R���X�g���N�^��ListView�̃A�C�e���e���v���[�g��list_item�ƃ��X�g�f�[�^��items���Z�b�g.(list_item�͒P�̂�TextView����Ȃ��Ƃ����Ȃ����Ƃɒ���.)
        listview1.setAdapter(adapter);	// listview1.setAdapter��adapter���Z�b�g����, ListView��Adapter��R�t����.
        
        // �A�C�e�����N���b�N���ꂽ���̃n���h�����Z�b�g.
        listview1.setOnItemClickListener(new AdapterView.OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View view,
					int position, long id) {
				// TODO Auto-generated method stub
				// �I�����ꂽ�ʒuposition��\��.
				Toast.makeText(mContext, "position = " + position, Toast.LENGTH_LONG).show();	// position��Toast�\��.
			}
			
		});
        
    }
}
