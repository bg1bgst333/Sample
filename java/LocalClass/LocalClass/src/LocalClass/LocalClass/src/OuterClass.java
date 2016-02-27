// 外部クラス
class OuterClass {	// OuterClassクラスの定義

	// 外部クラスのメンバフィールド
	int outerInt;	// ローカルクラスからアクセス可.

	// 外部クラスのメンバメソッド
	void methodOuterClass(){	// methodOuterClassの定義

		// 外部クラスのメンバメソッド内のローカルフィールド.
		final int localInt = 2;	// final(変更不可)ならローカルクラスからアクセス可.

		// "methodOuterClass"の出力.
		System.out.println("methodOuterClass");	// System.out.printlnで"methodOuterClass"を出力.

		// ローカルクラス
		class LocalClass {	// LocalClassクラスの定義

			// ローカルクラスのメンバメソッド
			void methodLocalClass(){	// methodLocalClassの定義

				// "methodLocalClass"の出力.
				System.out.println("methodLocalClass");	// System.out.printlnで"methodLocalClass"を出力.

				// 外部クラスのメンバフィールドアクセス.
				outerInt = 1;	// 代入可.
				System.out.println("outerInt = " + outerInt);	// 参照可.

				// 外部クラスのメンバメソッド内のローカルフィールドアクセス.
				System.out.println("localInt = " + localInt);	// 参照のみ可.

			}

		}

		// LocalClassのオブジェクトlocalの生成と"methodLocalClass"の出力.
		LocalClass local = new LocalClass();	// LocalClassオブジェクトを生成し, localに格納.
		local.methodLocalClass();	// local.methodLocalClassを呼ぶ.

	}

}
