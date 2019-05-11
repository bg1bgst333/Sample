// パッケージ・クラスのインポート
import java.applet.Applet;	// Appletクラス(java.appletパッケージ)
import java.awt.Graphics;	// Graphicsクラス(java.awtパッケージ)

// メインアプレットクラス
public class MainApplet extends Applet {	// MainAppletの定義

	// 描画
	public void paint(Graphics g){

		// Graphicsクラスオブジェクトのインスタンスがどうなっているか確認.
		String str = g.toString();	// g.toStringで文字列として取得.
		g.drawString(str, 50, 50);	// g.drawStringでstrを(50, 50)の位置に描画

	}

}