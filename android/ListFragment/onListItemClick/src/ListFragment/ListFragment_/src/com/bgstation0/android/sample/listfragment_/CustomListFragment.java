package com.bgstation0.android.sample.listfragment_;

import android.app.ListFragment;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

// ListFragment���p������CustomListFragment.
public class CustomListFragment extends ListFragment {

	// �����o�t�B�[���h.
	private String[] mNames = {"Taro", "Jiro", "Saburo", "Shiro", "Goro"};	// mNames�̏�����.
	
	// �A�N�e�B�r�e�B������.
	@Override
	public void onActivityCreated(Bundle savedInstanceState){
		
		// ����̏���.
		super.onActivityCreated(savedInstanceState);
		
		// ArrayAdapter�̐���.
    	ArrayAdapter<String> arrayAdapter = new ArrayAdapter<String>(getActivity(), android.R.layout.simple_list_item_1, mNames);	// �A�C�e���̃��C�A�E�g�͊����android.R.layout.simple_list_item_1���g��.
    	
    	// �A�_�v�^�̃Z�b�g.
    	setListAdapter(arrayAdapter);	// setListAdapter��arrayAdapter���Z�b�g.
		
	}
	
    // ���X�g�̃A�C�e�����N���b�N���ꂽ��.
    @Override
    public void onListItemClick(ListView l, View v, int position, long id){
    	
    	// ����̏���.
    	super.onListItemClick(l, v, position, id);	// �e�N���X��onListItemClick���Ă�.
    	
    	// �I�����ꂽ�A�C�e��(������)��\��.
    	Toast.makeText(getActivity(), (String)l.getItemAtPosition(position), Toast.LENGTH_LONG).show();	// l.getItemAtPosition(position)�őI�����ꂽ�A�C�e�����擾��, Toast�\��.
    	
    }
    
}