import java.util.ArrayList;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// ArrayListにアイテムを追加する.
		ArrayList arrayList = new ArrayList();	// arrayListを生成.
		arrayList.add(1);	// arrayList.addで1を追加.
		arrayList.add(2.5f);	// arrayList.addで2.5fを追加.
		arrayList.add("ABC");	// arrayList.addで"ABC"を追加.

		// arrayListからアイテムを取り出す.
		int val = (int)arrayList.get(0);	// 0番目をvalに代入.
		float fval = (float)arrayList.get(1);	// 1番目をfvalに代入.
		String str = (String)arrayList.get(2);	// 2番目をstrに代入.

		// 取得したアイテムの出力.
		System.out.println(val);	// valを出力.
		System.out.println(fval);	// fvalを出力.
		System.out.println(str);	// strを出力.

		// ArrayList<String>にアイテムを追加する.(ジェネリクス版)
		ArrayList<String> strList = new ArrayList<String>();	// strListを生成.
		strList.add("AAA");	// "AAA"を追加.
		strList.add("BBB");	// "BBB"を追加.
		strList.add("CCC");	// "CCC"を追加.

		// アイテムを出力.
		for (int i = 0; i < 3; i++){	// 3回繰り返す.
			System.out.println(strList.get(i));	// i番目を出力.
		}

	}

}