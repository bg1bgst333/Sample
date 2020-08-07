package com.bgstation0.android.sample.view.basesavedstate_;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.os.Parcelable;
import android.util.AttributeSet;
import android.view.View;

//カスタムビュークラスCustomViewの定義
public class CustomView extends View {

	// メンバフィールドの定義
	private Paint mPaint = null;	// PaintオブジェクトmPaintをnullで初期化.
	private Context mContext = null;	// ContextオブジェクトmContextをnullで初期化.
	public String mStr1 = "";	// mStr1を""で初期化.
	public String mStr2 = "";	// mStr2を""で初期化.
	public String mStr3 = "";	// mStr3を""で初期化.
	
	// コンストラクタの定義
	public CustomView(Context context){
		
		// 既定の初期化.
		super(context);	// 親クラスのコンストラクタにcontextを渡す.
		mPaint = new Paint();	// Paintオブジェクトを生成し, mPaintに格納.
		mContext = context;	// mContextにcontextを格納.
		
	}
	
	// コンストラクタの定義(CustomViewをレイアウトXMLで指定する場合.)
	public CustomView(Context context, AttributeSet attrs){
		
		// 既定の初期化.
		super(context, attrs);	// 親クラスのコンストラクタにcontextを渡す.
		mPaint = new Paint();	// Paintオブジェクトを生成し, mPaintに格納.
		mContext = context;	// mContextにcontextを格納.
		
	}
	
	// 描画時
	@Override
	protected void onDraw(Canvas canvas){
		
		// mStr1からmStr3までの描画.
		canvas.drawText(mStr1, 50, 50, mPaint);	// canvas.drawTextで(50, 50)の位置にmStr1を描画.
		canvas.drawText(mStr2, 50, 100, mPaint);	// canvas.drawTextで(50, 100)の位置にmStr2を描画.
		canvas.drawText(mStr3, 50, 150, mPaint);	// canvas.drawTextで(50, 150)の位置にmStr3を描画.
		
	}
	
	// 状態保存
	@Override
	protected Parcelable onSaveInstanceState(){
		
		// CustomSavedStateに保存.
		Parcelable superState = super.onSaveInstanceState();	// 親クラスのメソッドからsuperStateを取得.
		CustomSavedState css = new CustomSavedState(superState);	// superStateからCustomSavedStateを生成.
		css.mStr1 = mStr1;	// css.mStr1にmStr1を格納.
		css.mStr2 = mStr2;	// css.mStr2にmStr2を格納.
		css.mStr3 = mStr3;	// css.mStr3にmStr3を格納.
		return css;	// cssを返す.
		
	}
	
	// 状態復元
	@Override
	protected void onRestoreInstanceState(Parcelable state){

		// CustomSavedStateから復元.
		CustomSavedState css = (CustomSavedState)state;	// stateをcssにキャスト.
		super.onRestoreInstanceState(css.getSuperState());	// 親クラスのメソッドにcss.getSuperState()を渡す.
		mStr1 = css.mStr1;	// mStr1にcss.mStr1を渡す.
		mStr2 = css.mStr2;	// mStr2にcss.mStr2を渡す.
		mStr3 = css.mStr3;	// mStr3にcss.mStr3を渡す.
		invalidate();	// invalidateで再描画.
		
	}
	
}