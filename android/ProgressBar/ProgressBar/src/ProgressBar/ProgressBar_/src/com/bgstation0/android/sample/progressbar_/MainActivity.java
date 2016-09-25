package com.bgstation0.android.sample.progressbar_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ProgressBar;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

	// メンバフィールドの定義
	private ProgressBar progressBar = null;	// ProgressBarオブジェクトprogressBarをnullに初期化.
	private int progress = 0; // 進捗を表すint型progress.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1を取得し, OnClickListenerとして自身をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
        button1.setOnClickListener(this);	// button1.setOnClickListenerでthis(自身)をセット.
        
        // progressBarを取得し, 初期設定.
        progressBar = (ProgressBar)findViewById(R.id.progressbar);	// findViewByIdでR.id.progressbarを取得し, progressBarに格納.
        progressBar.setMax(100);	// progressBar.setMaxで最大値を100にセット.
        progress = 0;	// progressを0に初期化.
        progressBar.setProgress(0);	// progressBar.setProgressで進捗にprogressの値をセット.
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.

    	// progressを10進める.
    	if (progress < 100){	// progressが100未満なら.
    		progress += 10;	// progressを10増やす.
    	}
    	
    	// progressをprogressBarにセット.
    	progressBar.setProgress(progress);	// progressBar.setProgressでprogressをセット.
    }
}
