// 外部クラス
class OuterClass {	// OuterClassクラスの定義

	// 外部クラスのメンバメソッド
	void methodOuterClass(){	// methodouterClassの定義

		// "methodOuterClass"の出力.
		System.out.println("methodOuterClass");	// System.out.printlnで"methodOuterClass"を出力.

	}

	// 外部クラス内に定義した静的内部クラス.
	public static class StaticInnerClass{	// StaticInnerClassクラスの定義

		// 静的内部クラスのメンバメソッド
		void methodStaticInnerClass(){	// methodStaticInnerClassの定義

			// "methodStaticInnerClass"と出力.
			System.out.println("methodStaticInnerClass");	// System.out.printlnで"methodStaticInnerClass"を出力.

		}

	}

}