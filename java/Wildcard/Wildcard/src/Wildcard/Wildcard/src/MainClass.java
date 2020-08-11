import java.util.ArrayList;
import java.util.List;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){

		// 整数リストの取得.
		List<?> list1 = getList("int");	// "int"を指定してリスト取得.
		for (Object o : list1){	// Objectで受け取る.
			System.out.println(o);	// oを出力.
		}

		// 文字列リストの取得.
		List<?> list2 = getList("str");	// "str"を指定してリスト取得.
		for (Object o : list2){	// Objectで受け取る.
			System.out.println(o);	// oを出力.
		}

		// 浮動小数リストの取得.
		List<?> list3 = getList("hoge");	// 定義されていない"hoge"を指定してリスト取得.
		for (Object o : list3){	// Objectで受け取る.
			System.out.println(o);	// oを出力.
		}

	}

	// リストの取得関数getList
	public static List<?> getList(String typeName){
		if (typeName.equals("int")){	// "int"なら.
			List<Integer> intList = new ArrayList<Integer>();	// intList生成.
			intList.add(1);	// 1を追加.
			intList.add(2);	// 2を追加.
			intList.add(3);	// 3を追加.
			return intList;	// intListを返す.
		}
		else if (typeName.equals("str")){	// "str"なら.
			List<String> strList = new ArrayList<String>();	// strListを生成.
			strList.add("aaa");	// "aaa"を追加.
			strList.add("bbb");	// "bbb"を追加.
			strList.add("ccc");	// "ccc"を追加.
			return strList;	// strListを返す.
		}
		else{	// それ以外.
			List<Float> fList = new ArrayList<Float>();	// fListを生成.
			fList.add(1.1f);	// 1.1を追加.
			fList.add(2.2f);	// 2.2を追加.
			fList.add(3.3f);	// 3.3を追加.
			return fList;	// fListを返す.
		}
	}

}