import java.net.URI;
import java.net.URISyntaxException;

// メインクラス
public class MainClass {	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// URIオブジェクトの作成.
		URI uri = null;	// URIオブジェクトuriをnullで初期化.
		try {	// tryで囲む.
			uri = new URI("http://bgstation0.com");	// "http://bgstation0.com"を基にしたURIをuriに格納.
		} catch (URISyntaxException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}

		// ホスト名出力.
		System.out.println(uri.getHost());	// uri.getHostでホスト名出力.

	}

}