package com.bgstation0.android.sample.view_;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.Style;
import android.os.Parcelable;
import android.util.AttributeSet;
import android.view.View;
import android.widget.Toast;

// �J�X�^���r���[�N���XCustomView�̒�`
public class CustomView extends View {

	// �����o�t�B�[���h�̒�`
	Paint mPaint = null;	// Paint�I�u�W�F�N�gmPaint��null�ŏ�����.
	Context mContext = null;	// Context�I�u�W�F�N�gmContext��null�ŏ�����.
	
	// �R���X�g���N�^�̒�`
	public CustomView(Context context){
		
		// ����̏�����.
		super(context);	// �e�N���X�̃R���X�g���N�^��context��n��.
		mPaint = new Paint();	// Paint�I�u�W�F�N�g�𐶐���, mPaint�Ɋi�[.
		mContext = context;	// mContext��context���i�[.
		
	}
	
	// �R���X�g���N�^�̒�`(CustomView�����C�A�E�gXML�Ŏw�肷��ꍇ.)
	public CustomView(Context context, AttributeSet attrs){
		
		// ����̏�����.
		super(context, attrs);	// �e�N���X�̃R���X�g���N�^��context��n��.
		mPaint = new Paint();	// Paint�I�u�W�F�N�g�𐶐���, mPaint�Ɋi�[.
		mContext = context;	// mContext��context���i�[.
		
	}
	
	// �`�掞
	@Override
	protected void onDraw(Canvas canvas){

		// �����̑傫����ݒ�.
		mPaint.setTextSize(20.0f);	// mPaint.setTextSize�ő傫����20.0�ɂ���.

		// �e�L�X�g"ABCDE"��`��.
		canvas.drawText("ABCDE", 50, 50, mPaint);	// canvas.drawText��(50, 50)�̈ʒu��"ABCDE"��`��.
		
		// ��`�̐F��ݒ�.
		mPaint.setColor(Color.RED);	// mPaint.setColor�ŐԂ��w��.
		
		// ��`��`��.
		canvas.drawRect(100,  100,  150,  150, mPaint);	// canvas.drawRect��(100, 100)�̈ʒu�ɋ�`��`��.
		
		// �`��X�^�C����ݒ�.
		mPaint.setStyle(Style.STROKE);	// mPaint.setStyle�ŗ֊s��������`�悷��.
		
		// �~��`��.
		canvas.drawCircle(200, 200, 30, mPaint);	// canvas.drawCircle��(200, 200)�̈ʒu�ɉ~��`��.
		
	}
	
	// ��ԕۑ�
	@Override
	protected Parcelable onSaveInstanceState(){
		
		// ����̏���
		super.onSaveInstanceState();	// �e�N���X�̃��\�b�h���Ă�.
		
		// �����ɗ������Ƃ�ʒm����g�[�X�g�\��.
		Toast.makeText(mContext, "CustomView.onSaveInstanceState", Toast.LENGTH_LONG).show();	// "CustomView.onSaveInstanceState"�ƕ\��.
		
		// �߂�l��null.
		return null;	// return��null��Ԃ�.
		
	}
	
}