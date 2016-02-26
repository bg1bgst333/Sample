// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// OuterClassオブジェクトouterの生成.
		OuterClass outer = new OuterClass();	// OuterClassオブジェクトを生成し, outerに格納.

		// outerのメンバメソッドを呼ぶ.
		outer.methodOuterClass();	// outerのメンバメソッドmethodOuterClassで"methodOuterClass"を出力.

		// outerのメンバメソッドを経由して, memberInnerのメンバメソッドを呼ぶ.
		outer.callInnerClassMethod();	// outerのメンバメソッドcallInnerClassMethodを呼ぶことで"methodMemberInnerClass"が出力される.

	}

}