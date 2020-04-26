import java.util.function.Predicate;

// テストクラス
public class TestClass {
	// フィールド
	Predicate<Integer> s = null;
	// メソッド
	public void method1(Predicate<Integer> s){
		this.s = s;	// メンバにセット.
	}
	public boolean run(int i){
		return s.test(i);	// s.testに引数を渡して, 真偽値を返す.
	}
}