import com.google.gson.Gson;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// Profileオブジェクトの作成.
		Profile profile = new Profile("Taro", "taro@gmail.com");	// profileを作成し, "Taro"と"taro@gmail.com"をセット.

		// Gsonの生成.
		Gson gson = new Gson();	// gsonを生成.

		// JavaのProfileオブジェクトからJsonに変換して出力.
		System.out.println(gson.toJson(profile));	// gson.toJsonにprofileを渡して, 変換したものを出力.

	}

}