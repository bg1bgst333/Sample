package com.bgstation0.android.sample.listfragment_;

import android.app.ListFragment;
import android.os.Bundle;
import android.widget.ArrayAdapter;

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
	
}