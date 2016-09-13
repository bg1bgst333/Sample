package com.bgstation0.android.sample.fragmenttransaction_;

import android.app.Fragment;
import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;

// MainFragmentクラスの定義.
public class MainFragment extends Fragment {

	// フラグメントのビュー生成時.
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		
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
	
}
