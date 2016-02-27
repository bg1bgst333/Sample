// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// OuterClassオブジェクトouterの生成.
		OuterClass outer = new OuterClass();	// OuterClassオブジェクトを作成し, outerに格納.

		// methodOuterClassを呼ぶ.
		outer.methodOuterClass();	// outer.mothoedOuterClassを呼ぶ.

	}

}