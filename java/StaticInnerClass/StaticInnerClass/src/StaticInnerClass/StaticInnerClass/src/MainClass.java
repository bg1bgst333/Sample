// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// OuterClassオブジェクトouterの生成.
		OuterClass outer = new OuterClass();	// OuterClassオブジェクトを生成し, outerに格納.

		// outerのメンバメソッドを呼ぶ.
		outer.methodOuterClass();	// outerのメンバメソッドmethodOuterClassで"methodOuterClass"を出力.

		// OuterClassの静的内部クラス(正確には内部クラスとは言わない.)StaticInnerClassオブジェクト生成.
		OuterClass.StaticInnerClass staticInner = new OuterClass.StaticInnerClass();	// OuterClass.StaticInnerClassのオブジェクトをstaticInnerに格納.

		// staticInnerのメソッドを呼ぶ.
		staticInner.methodStaticInnerClass();	// staticInnerのメンバメソッドmethodStaticInnerClassを呼ぶことで"methodStaticInnerClass"が出力される.

	}

}
