// 外部クラス
class OuterClass {	// OuterClassクラスの定義

	// 外部クラスのメンバメソッド1
	void methodOuterClass(){	// methodOuterClassの定義

		// "methodOuterClass"と出力.
		System.out.println("methodOuterClass");	// System.out.printlnで"methodOuterClass"を出力.

	}

	// 外部クラスのメンバメソッド2
	void callInnerClassMethod(){	// callInnerClassMethodの定義

		// 内部クラスの生成.
		MemberInnerClass memberInner = new MemberInnerClass();	// MemberInnerClassオブジェクトを生成し, memberInnerに格納.

		// memberInnerのメンバメソッドを呼ぶ.
		memberInner.methodMemberInnerClass();	// memberInnerのメンバメソッドmethodMemberInnerClassで"methodMemberInnerClass"を出力.

	}

	// 外部クラス内に定義したメンバ内部クラス.
	public class MemberInnerClass {	// MemberInnerClassクラスの定義

		// メンバ内部クラスのメンバメソッド
		void methodMemberInnerClass() {	// methodMemberInnerClassの定義

			// "methodMemberInnerClass"と出力.
			System.out.println("methodMemberInnerClass");	// System.out.printlnで"methodMemberInnerClass"を出力.

		}

	}

}