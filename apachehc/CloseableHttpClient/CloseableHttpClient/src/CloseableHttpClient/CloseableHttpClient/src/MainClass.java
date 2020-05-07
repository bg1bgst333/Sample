import java.nio.charset.StandardCharsets;

import org.apache.http.HttpStatus;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// HttpClientの作成.
		CloseableHttpClient httpClient = HttpClients.createDefault();	// HttpClients.createDefaultで作成.

		// HttpGetリクエストの作成.
		HttpGet httpGetRequest = new HttpGet("http://bgstation0.com");	// "http://bgstation0.com"へのリクエスト作成.

		// HttpResponseの初期化.
		CloseableHttpResponse httpResponse = null;	// httpResponseをnullで初期化.

		// tryで囲む
		try{

			// リクエスト送信実行.
			httpResponse = httpClient.execute(httpGetRequest);	// executeで実行.

			// ステータスコードの取得.
			if (httpResponse.getStatusLine().getStatusCode() == HttpStatus.SC_OK){	// OK(200)なら.
				String responseStr = EntityUtils.toString(httpResponse.getEntity(), StandardCharsets.UTF_8);	// responseStrを取得.
				System.out.println(responseStr);	// responseStrを出力.
			}
			else{	// OK(200)以外.
				System.out.println("NG");	// "NG"と出力.
			}

		}
		catch (Exception ex){	// 例外をキャッチ.
			System.out.println(ex.getMessage());	// 例外メッセージ出力.
		}
		finally{	// 終了処理.

			// tryで囲む.
			try{
				// httpResponseが残っていたら閉じる.
				if (httpResponse != null){
					httpResponse.close();	// 閉じる.
				}
				// httpClientが残っていたら閉じる.
				if (httpClient != null){
					httpClient.close();	// 閉じる.
				}
			}
			catch (Exception e){	// 例外をキャッチ.
				System.out.println(e.getMessage());	// 例外メッセージ出力.
			}

		}

	}

}