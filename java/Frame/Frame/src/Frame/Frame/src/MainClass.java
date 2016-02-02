// パッケージ・クラスのインポート
import java.awt.Frame;	// Frameクラス(java.awtパッケージ)

// メインクラス
public class MainClass {

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// Frameのインスタンス作成.
		Frame f = new Frame();	// Frameクラスのインスタンスをfに格納.
		f.setSize(320, 240);	// setSizeでFrameのサイズを(320, 240)にセット.
		f.setVisible(true);		// setVisibleで表示状態は"表示"にセット.

	}

}