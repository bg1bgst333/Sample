import java.util.ArrayList;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// ArrayList<String>に要素を追加..
		ArrayList<String> strArrayList = new ArrayList<String>();	// ArrayList<String>のstrArrayList.
		strArrayList.add("ABC");	// "ABC"を追加.
		strArrayList.add("DEF");	// "DEF"を追加.
		strArrayList.add("GHI");	// "GHI"を追加.

		// Iterable<String>にして, 拡張for文で出力.
		Iterable<String> iterable = strArrayList;	// iterableに渡す.
		for (String s : iterable){	// iterableの最後まで繰り返し要素を取り出してsに格納.
			System.out.println(s);	// sを出力.
		}

	}

}