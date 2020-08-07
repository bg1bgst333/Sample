package com.bgstation0.android.sample.view_;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.View;

//�J�X�^���r���[�N���XCustomView�̒�`
public class CustomView extends View {

	// �����o�t�B�[���h�̒�`
	private Paint mPaint = null;	// Paint�I�u�W�F�N�gmPaint��null�ŏ�����.
	private Context mContext = null;	// Context�I�u�W�F�N�gmContext��null�ŏ�����.
	public String mStr1 = "";	// mStr1��""�ŏ�����.
	public String mStr2 = "";	// mStr2��""�ŏ�����.
	public String mStr3 = "";	// mStr3��""�ŏ�����.
	
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
		
		// mStr1����mStr3�܂ł̕`��.
		canvas.drawText(mStr1, 50, 50, mPaint);	// canvas.drawText��(50, 50)�̈ʒu��mStr1��`��.
		canvas.drawText(mStr2, 50, 100, mPaint);	// canvas.drawText��(50, 100)�̈ʒu��mStr2��`��.
		canvas.drawText(mStr3, 50, 150, mPaint);	// canvas.drawText��(50, 150)�̈ʒu��mStr3��`��.
		
	}
	
}