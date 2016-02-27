// メインクラス
public class MainClass {	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// フレームの生成
		MainFrame mainFrame = new MainFrame();	// MainFrameオブジェクトを生成し, インスタンスをmainFrameに格納.

		// フレームの表示
		mainFrame.setVisible(true);	// mainFrame.setVisibleでtrueにする.

		// ウィンドウリスナーの設定
		MainFrameWindowListener listener = new MainFrameWindowListener();	// MainFrameWindowListenerオブジェクトを生成し, インスタンスをlistenerに格納.
		mainFrame.addWindowListener(listener);	// mainFrame.addWindowListenerでlistenerをセット.

	}

}