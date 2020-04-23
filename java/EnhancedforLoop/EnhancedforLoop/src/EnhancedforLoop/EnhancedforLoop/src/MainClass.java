import java.util.ArrayList;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// for文で配列を出力.
		String strArray[] = new String[3];	// 要素数3のString配列strArray.
		strArray[0] = "ABC";	// "ABC"を格納.
		strArray[1] = "DEF";	// "DEF"を格納.
		strArray[2] = "GHI";	// "GHI"を格納.
		for (int i = 0; i < 3; i++){	// 3個繰り返す.
			System.out.println(strArray[i]);	// strArray[i]を出力.
		}

		// 拡張for文で配列を出力.
		for (String s : strArray){	// strArrayから要素を取り出してsに格納.
			System.out.println(s);	// sを出力.
		}

		// 拡張for文でArrayList<String>を出力.
		ArrayList<String> strArrayList = new ArrayList<String>();	// ArrayList<String>のstrArrayList.
		strArrayList.add("abc");	// "abc"を追加.
		strArrayList.add("def");	// "def"を追加.
		strArrayList.add("ghi");	// "ghi"を追加.
		for (String e : strArrayList){	// strArrayListから要素を取り出してeに格納.
			System.out.println(e);	// eを出力.
		}

	}

}