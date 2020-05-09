import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// tryで囲む
		try {

			// リクエストの作成.
			Request request = new Request.Builder().url("http://bgstation0.com").get().build();	// requestを作成.

			// クライアントの作成.
			OkHttpClient client = new OkHttpClient();	// clientを作成.

			// レスポンスの取得.
			Response response = client.newCall(request).execute();	// requestを投げて, responseの取得.

			// レスポンスの出力.
			System.out.println(response.body().string());	// response文字列を出力.

		}
		catch (Exception ex) {	// 例外をキャッチ.
			System.out.println(ex.getMessage());	// 例外文字列を出力.
		}

	}

}