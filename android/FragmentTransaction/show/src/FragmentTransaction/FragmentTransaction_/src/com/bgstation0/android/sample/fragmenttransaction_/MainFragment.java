package com.bgstation0.android.sample.fragmenttransaction_;

import android.app.Fragment;
import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

// MainFragmentクラスの定義.
public class MainFragment extends Fragment {

	// メンバフィールドの定義
	int count = 0;	// int型countを0に初期化.
	
	// フラグメントの生成時.
	@Override
    public void onCreate(Bundle savedInstanceState) {
		// Toastを表示
		MainActivity mainActivity = (MainActivity)getActivity();	// getActivityでmainActivityを取得.
		Toast.makeText(mainActivity, "onCreate()", Toast.LENGTH_LONG).show();	// Toast.makeText.showで"onCreate()"を表示.
        super.onCreate(savedInstanceState);
	}
	
	// フラグメントのビュー生成時.
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		
		// Toastを表示
        MainActivity mainActivity = (MainActivity)getActivity();	// getActivityでmainActivityを取得.
        Toast.makeText(mainActivity, "onCreateView()", Toast.LENGTH_LONG).show();	// Toast.makeText.showで"onCreateView()"を表示.
        
		// MainFragmentのリソースをベースにレイアウトを作成.
		View fragmentView = inflater.inflate(R.layout.fragment_main, null);	// inflater.inflaceでR.layout.fragment_mainをベースにレイアウト作成し, fragmentViewに格納.
		
		// パラメータを取得.
		Bundle args = getArguments();	// getArgumentsでBundle型argsを取得.
		String text = args.getString("text");	// キーが"text"の値を取得.
		String color = args.getString("color");	// キーが"color"の値を取得.

		// textをTextViewにセット.
		TextView textView = (TextView)fragmentView.findViewById(R.id.fragment_main_textview);	// fragmentView.findViewByIdでtextViewを取得.
		textView.setText(text);	// textView.setTextでtextをセット.
		
		// colorごとにfragmentViewの背景をカスタマイズ.
		LinearLayout linearLayout = (LinearLayout)fragmentView.findViewById(R.id.fragment_main_linearlayout);	// fragmentView.findViewByIdでLinearLayoutを取得.
		if (color.equals("red")){	// "red"なら.
			linearLayout.setBackgroundColor(Color.RED);	// linearLayout.setBackgroundColorでColor.REDを指定.
		}
		else if (color.equals("green")){	// "green"なら.
			linearLayout.setBackgroundColor(Color.GREEN);	// linearLayout.setBackgroundColorでColor.GREENを指定.
		}
		else if (color.equals("blue")){	// "blue"なら.
			linearLayout.setBackgroundColor(Color.BLUE);	// linearLayout.setBackgroundColorでColor.BLUEを指定.
		}
				
		// Viewを返す.
		return fragmentView;	// fragmentViewを返す.
		
	}
	
	// フラグメントの開始時
	@Override
    public void onStart(){
        super.onStart();
        // Toastを表示
        MainActivity mainActivity = (MainActivity)getActivity();	// getActivityでmainActivityを取得.
        Toast.makeText(mainActivity, "onStart()", Toast.LENGTH_LONG).show();	// Toast.makeText.showで"onStart()"を表示.
    }
	
	// フラグメントの復帰時
	@Override
    public void onResume(){
		super.onResume();
		// Toastを表示
        MainActivity mainActivity = (MainActivity)getActivity();	// getActivityでmainActivityを取得.
        Toast.makeText(mainActivity, "onResume()", Toast.LENGTH_LONG).show();	// Toast.makeText.showで"onResume()"を表示.   
        count++;	// countを増やす.
        Toast.makeText(mainActivity, "count = " + Integer.toString(count), Toast.LENGTH_LONG).show();	// Toast.makeText.showでcountを表示.
    }
	
	// フラグメントの一時停止時
	@Override
	public void onPause(){
		super.onPause();
		// Toastを表示
	    MainActivity mainActivity = (MainActivity)getActivity();	// getActivityでmainActivityを取得.
	    Toast.makeText(mainActivity, "onPause()", Toast.LENGTH_LONG).show();	// Toast.makeText.showで"onPause()"を表示.
	}
		
	// フラグメントの停止時
	@Override
    public void onStop(){
		super.onStop();
		// Toastを表示
        MainActivity mainActivity = (MainActivity)getActivity();	// getActivityでmainActivityを取得.
        Toast.makeText(mainActivity, "onStop()", Toast.LENGTH_LONG).show();	// Toast.makeText.showで"onStop()"を表示.
    }
	
	// フラグメントのビュー破棄時
	@Override
    public void onDestroyView() {
		// Toastを表示
        MainActivity mainActivity = (MainActivity)getActivity();	// getActivityでmainActivityを取得.
        Toast.makeText(mainActivity, "onDestroyView()", Toast.LENGTH_LONG).show();	// Toast.makeText.showで"onDestroyView()"を表示.
        super.onDestroyView();
    }
	
	// フラグメントの破棄時
	@Override
    public void onDestroy(){
		// Toastを表示
		MainActivity mainActivity = (MainActivity)getActivity();	// getActivityでmainActivityを取得.
		Toast.makeText(mainActivity, "onDestroy()", Toast.LENGTH_LONG).show();	// Toast.makeText.showで"onDestroy()"を表示.
        super.onDestroy();
    }
	
}
