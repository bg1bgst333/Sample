// パッケージ・クラスのインポート
import java.applet.Applet;	// Appletクラス(java.appletパッケージ)
import java.awt.Graphics;	// Graphicsクラス(java.awtパッケージ)

// メインアプレットクラス
public class MainApplet extends Applet {	// MainAppletの定義

	// 描画
	public void paint(Graphics g){

		// Graphics.drawStringで5つの文字列を表示.
		g.drawString("abc", 50, 50);	// g.drawStringで"abc"を表示.
		String str  = "def";	// strを"def"で初期化.
		g.drawString(str, 60, 70);	// g.drawStringでstrを表示.
		int x = 70;	// xを70で初期化.
		int y = 90;	// yを90で初期化.
		g.drawString("GHI", x, y);	// g.drawStringで(x, y)に"GHI"を表示.

	}

}