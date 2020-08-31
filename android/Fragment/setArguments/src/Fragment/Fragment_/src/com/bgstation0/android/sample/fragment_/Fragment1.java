package com.bgstation0.android.sample.fragment_;

import android.app.Activity;
import android.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewParent;
import android.widget.EditText;

//フラグメント1
public class Fragment1 extends Fragment {

	// メンバフィールド
	static final String TAG = "Fragment1";	// TAGを"Fragment1"で初期化.
	public static final String KEY = "key";	// 渡す引数のキーを"key"とする.
	
	// コンストラクタ
	public Fragment1(){
		
	}
	
	// ファクトリメソッド
	public static Fragment1 newInstance(String value){
		
		// Fragment1オブジェクトの生成.
		Fragment1 fragment1 = new Fragment1();	// fragment1を生成.
		Bundle args = new Bundle();	// argsを作成.
		args.putString(Fragment1.KEY, value);	// valueを登録.
		fragment1.setArguments(args);	// fragment1.setArgumentsにargsをセット.
		return fragment1;	// fragment1を返す.
		
	}
	
	// フラグメント生成時
	@Override
	public void onCreate(Bundle savedInstanceState){
		
		// 既定の処理.
		super.onCreate(savedInstanceState);	// 親クラスのonCreateを呼ぶ.
		
		// ログを残す.
		Log.d(TAG, "Fragment1.onCreate");	// "Fragment1.onCreate"とログに残す.
		
		// 引数を取得.
		Bundle args = getArguments();	// getArgumentsでargsを取得.
		if (args != null){	// nullでなければ.
			
			// argsの中身を取得.
			String value = args.getString(KEY);	// valueを取得.
		
			// ログを残す.
			Log.d(TAG, "value = " + value);	// valueをログ出力.
		
		}
		
	}
	
	// フラグメント破棄時
	@Override
	public void onDestroy(){
		
		// ログを残す.
		Log.d(TAG, "Fragment1.onDestroy");	// "Fragment1.onDestroy"とログに残す.
		
		// 既定の処理.
		super.onDestroy();	// 親クラスのonDestroyを呼ぶ.
		
	}
	
	// ビュー生成時
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		
		// ログを残す.
		Log.d(TAG, "Fragment1.onCreateView");	// "Fragment1.onCreateView"とログに残す.
		
		// 既定の処理.
		super.onCreateView(inflater, container, savedInstanceState);
		
		// MainActivityのEditTextの内容を取得.
		Activity mainActivity = getActivity();	// mainActivityを取得.
		EditText activityEdittext1 = (EditText)mainActivity.findViewById(R.id.activityedittext1);	// activityEdittext1を取得.
		Log.d(TAG, "activityEdittext1 = " + activityEdittext1.getText().toString());	// activityEdittext1をログ出力.
		
		// Fragment1のEditTextを取得.
		View view = inflater.inflate(R.layout.fragment1_main, null);	// inflater.inflateでR.layout.fragment1_mainからビューを作成.
		ViewParent viewParent = view.getParent();	// viewParentの取得.
		if (viewParent == null){	// nullなら.
			Log.d(TAG, "viewParent = null");	// "viewParent = null"をログ出力.
		}
		else{	// nullでなければ.
			Log.d(TAG, "viewParent = " + viewParent.getClass().getName());	// viewParentを出力.
		}
		EditText fragmentEdittext1 = (EditText)view.findViewById(R.id.fragmentedittext1);	// fragmentEdittext1を取得.
		Log.d(TAG, "fragmentEdittext1 = " + fragmentEdittext1.getText().toString());	// fragmentEdittext1をログ出力.
		return view;	// viewを返す.
		
	}
	
	// ビュー生成完了時.
	@Override
	public void onViewCreated(View view, Bundle savedInstanceState){
	
		// ログを残す.
		Log.d(TAG, "Fragment1.onViewCreated");	// "Fragment1.onViewCreated"とログに残す.
				
		// 既定の処理.
		super.onViewCreated(view, savedInstanceState);
		
		// viewParentの取得.
		ViewParent viewParent = view.getParent();	// viewParentの取得.
		if (viewParent == null){	// nullなら.
			Log.d(TAG, "viewParent = null");	// "viewParent = null"をログ出力.
		}
		else{	// nullでなければ.
			Log.d(TAG, "viewParent = " + viewParent.getClass().getName());	// viewParentを出力.
		}
		
	}
	
	// アクティビティ生成完了時
	@Override
	public void onActivityCreated(Bundle savedInstanceState){
			
		// ログを残す.
		Log.d(TAG, "Fragment1.onActivityCreated");	// "Fragment1.onActivityCreated"とログに残す.
					
		// 既定の処理.
		super.onActivityCreated(savedInstanceState);
			
		// MainActivityのEditTextの内容を取得.
		Activity mainActivity = getActivity();	// mainActivityを取得.
		EditText activityEdittext1 = (EditText)mainActivity.findViewById(R.id.activityedittext1);	// activityEdittext1を取得.
		Log.d(TAG, "activityEdittext1 = " + activityEdittext1.getText().toString());	// activityEdittext1をログ出力.
		
		// Fragment1のEditTextの内容を取得.
		View view = getView();	// getViewでviewを取得.
		EditText fragmentEdittext1 = (EditText)view.findViewById(R.id.fragmentedittext1);	// fragmentEdittext1を取得.
		Log.d(TAG, "fragmentEdittext1 = " + fragmentEdittext1.getText().toString());	// fragmentEdittext1をログ出力.
		
	}
	
	// 開始時
	@Override
	public void onStart(){
		
		// ログを残す.
		Log.d(TAG, "Fragment1.onStart");	// "Fragment1.onStart"とログに残す.
							
		// 既定の処理.
		super.onStart();
		
		// MainActivityのEditTextの内容を取得.
		Activity mainActivity = getActivity();	// mainActivityを取得.
		EditText activityEdittext1 = (EditText)mainActivity.findViewById(R.id.activityedittext1);	// activityEdittext1を取得.
		Log.d(TAG, "activityEdittext1 = " + activityEdittext1.getText().toString());	// activityEdittext1をログ出力.
				
		// Fragment1のEditTextの内容を取得.
		View view = getView();	// getViewでviewを取得.
		EditText fragmentEdittext1 = (EditText)view.findViewById(R.id.fragmentedittext1);	// fragmentEdittext1を取得.
		Log.d(TAG, "fragmentEdittext1 = " + fragmentEdittext1.getText().toString());	// fragmentEdittext1をログ出力.
				
	}
	
	// 再開時
	@Override
	public void onResume(){
		
		// ログを残す.
		Log.d(TAG, "Fragment1.onResume");	// "Fragment1.onResume"とログに残す.
									
		// 既定の処理.
		super.onResume();
		
		// MainActivityのEditTextの内容を取得.
		Activity mainActivity = getActivity();	// mainActivityを取得.
		EditText activityEdittext1 = (EditText)mainActivity.findViewById(R.id.activityedittext1);	// activityEdittext1を取得.
		Log.d(TAG, "activityEdittext1 = " + activityEdittext1.getText().toString());	// activityEdittext1をログ出力.
						
		// Fragment1のEditTextの内容を取得.
		View view = getView();	// getViewでviewを取得.
		EditText fragmentEdittext1 = (EditText)view.findViewById(R.id.fragmentedittext1);	// fragmentEdittext1を取得.
		Log.d(TAG, "fragmentEdittext1 = " + fragmentEdittext1.getText().toString());	// fragmentEdittext1をログ出力.		
				
	}
	
}
