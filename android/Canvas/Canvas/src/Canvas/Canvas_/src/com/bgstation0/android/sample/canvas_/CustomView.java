package com.bgstation0.android.sample.canvas_;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.view.View;

// �J�X�^���r���[�N���XCustomView�̒�`
public class CustomView extends View {

	// �����o�t�B�[���h�̒�`
	Paint mPaint = null;	// Paint�I�u�W�F�N�gmPaint��null�ŏ�����.
	
	// �R���X�g���N�^�̒�`
	public CustomView(Context context){
		
		// ����̏�����.
		super(context);	// �e�N���X�̃R���X�g���N�^��context��n��.
		mPaint = new Paint();	// Paint�I�u�W�F�N�g�𐶐���, mPaint�Ɋi�[.
		
	}
	
	// �`�掞
	@Override
	protected void onDraw(Canvas canvas){

		// �e�L�X�g"ABCDE"��`��.
		canvas.drawText("ABCDE", 50, 50, mPaint);	// canvas.drawText��(50, 50)�̈ʒu��"ABCDE"��`��.
		
		// ��`��`��.
		canvas.drawRect(100,  100,  150,  150, mPaint);	// canvas.drawRect��(100, 100)�̈ʒu�ɋ�`��`��.
		
		// �~��`��.
		canvas.drawCircle(200, 200, 30, mPaint);	// canvas.drawCircle��(200, 200)�̈ʒu�ɉ~��`��.
		
	}
	
}