// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// BaseClassオブジェクトbaseの生成.
		BaseClass base = new BaseClass();	// BaseClassオブジェクトを生成し, baseに格納.

		// methodBaseClassを呼ぶ.
		base.methodBaseClass();	// base.methodBaseClassを呼ぶ.

		// BaseClassの匿名クラスを定義し生成.
		BaseClass anonymous = new BaseClass(){	// BaseClassの派生クラスを一時的に定義し, 同時にそのオブジェクトインスタンスをanonymousに格納.

			// BaseClassのメソッドのオーバーライド.
			void methodBaseClass(){	// methodBaseClassの定義

				// "Anonymous"の出力
				System.out.println("Anonymous");	// System.out.printlnで"Anonymous"と出力.

			}

		};

		// anonymousのメンバメソッドを呼ぶ.
		anonymous.methodBaseClass();	// anonymous.methodBaseClassを呼ぶ.

	}

}