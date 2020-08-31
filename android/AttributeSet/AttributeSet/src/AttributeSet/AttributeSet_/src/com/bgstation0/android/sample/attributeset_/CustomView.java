package com.bgstation0.android.sample.attributeset_;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.Style;
import android.util.AttributeSet;
import android.util.Log;
import android.view.View;

// カスタムビュークラスCustomViewの定義
public class CustomView extends View {

	// メンバフィールドの定義
	Paint mPaint = null;	// PaintオブジェクトmPaintをnullで初期化.
	static final String TAG = "CustomView";	// TAGを"CustomView"で初期化.
	
	// コンストラクタの定義
	public CustomView(Context context){
		
		// 既定の初期化.
		super(context);	// 親クラスのコンストラクタにcontextを渡す.
		mPaint = new Paint();	// Paintオブジェクトを生成し, mPaintに格納.
		
	}
	
	// コンストラクタの定義(CustomViewをレイアウトXMLで指定する場合.)
	public CustomView(Context context, AttributeSet attrs){
		
		// 既定の初期化.
		super(context, attrs);	// 親クラスのコンストラクタにcontextを渡す.
		mPaint = new Paint();	// Paintオブジェクトを生成し, mPaintに格納.
		
		// ログを残す.
		Log.d(TAG, "attrs.getAttributeName(0) = " + attrs.getAttributeName(0));	// 0番目の属性名をログ出力.
		Log.d(TAG, "attrs.getAttributeName(1) = " + attrs.getAttributeName(1));	// 1番目の属性名をログ出力.
		Log.d(TAG, "attrs.getAttributeName(2) = " + attrs.getAttributeName(2));	// 2番目の属性名をログ出力.
		
	}
	
	// 描画時
	@Override
	protected void onDraw(Canvas canvas){

		// 文字の大きさを設定.
		mPaint.setTextSize(20.0f);	// mPaint.setTextSizeで大きさを20.0にする.

		// テキスト"ABCDE"を描画.
		canvas.drawText("ABCDE", 50, 50, mPaint);	// canvas.drawTextで(50, 50)の位置に"ABCDE"を描画.
		
		// 矩形の色を設定.
		mPaint.setColor(Color.RED);	// mPaint.setColorで赤を指定.
		
		// 矩形を描画.
		canvas.drawRect(100,  100,  150,  150, mPaint);	// canvas.drawRectで(100, 100)の位置に矩形を描画.
		
		// 描画スタイルを設定.
		mPaint.setStyle(Style.STROKE);	// mPaint.setStyleで輪郭線だけを描画する.
		
		// 円を描画.
		canvas.drawCircle(200, 200, 30, mPaint);	// canvas.drawCircleで(200, 200)の位置に円を描画.
		
	}
	
}
