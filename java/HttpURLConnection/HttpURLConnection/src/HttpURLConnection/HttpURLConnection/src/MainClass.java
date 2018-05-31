import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

// メインクラス
public class MainClass {	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// 変数の初期化.
		String strUrl = "http://bgstation0.com";	// strUrlを"http://bgstation0.com"で初期化.
		HttpURLConnection httpUrlConnection = null;	// httpUrlConnectionをnullで初期化.
		InputStream is = null;	// isをnullで初期化.
		InputStreamReader isr = null;	// isrをnullで初期化.
		BufferedReader br = null;	// brをnullで初期化.
		String strLine = null;	// strLineをnullで初期化.

		// HTTPリクエスト
		try{	// tryで囲む.

			// URLの指定.
			URL url = new URL(strUrl);	// urlを取得.

			// コネクションを開く.
			httpUrlConnection = (HttpURLConnection)url.openConnection();	// url.openConnectionでコネクションを開く.

			// GETメソッド.
			httpUrlConnection.setRequestMethod("GET");	// httpUrlConnection.setRequestMethodで"GET".

			// 接続.
			httpUrlConnection.connect();	// httpUrlConnection.connectで接続.

			// HTTP_OKなら.
			int status = httpUrlConnection.getResponseCode();	// status取得.
			if (status == HttpURLConnection.HTTP_OK){	// HTTP_OK

				// ストリーム取得.
				is = httpUrlConnection.getInputStream();	// httpUrlConnection.getInputStreamでis取得.
				isr = new InputStreamReader(is);	// isからisrを取得.
				br = new BufferedReader(isr);	// isrからbrを取得.

				// 行ごとに出力.
				while ((strLine = br.readLine()) != null){	// nullでない間繰り返す.
					System.out.println(strLine);	// strLineを出力.
				}

			}

		}
		catch (Exception ex){

			// ex出力.
			System.out.println(ex.toString()); 	// ex.toStringを出力.

		}
		finally{

			// brを閉じる.
			try{
				if (br != null){
					br.close();	// br.closeで閉じる.
				}
				if (httpUrlConnection != null){
					httpUrlConnection.disconnect();	// httpUrlConnection.disconnectで切断.
				}
			}
			catch (Exception ex){
				// ex出力.
				System.out.println(ex.toString()); 	// ex.toStringを出力.
			}

		}

	}

}