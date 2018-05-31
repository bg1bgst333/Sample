import java.net.URL;

// メインクラス
public class MainClass {	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// URLオブジェクトの作成.
		URL url = null;	// URLオブジェクトurlをnullで初期化.
		try{	// tryで囲む.
			url = new URL("http://bgstation0.com");	// URLのコンストラクタに"http://bgstation0.com"を渡してurlを得る.
		}
		catch (Exception ex){
			System.out.println(ex.toString());	// exを出力.
		}

		// ホスト名を取得して出力.
		System.out.println(url.getHost());	// url.getHost()を出力.

	}

}