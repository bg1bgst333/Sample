import java.util.function.Supplier;

// テストクラス
public class TestClass {
	// フィールド
	Supplier<Integer> s = null;
	// メソッド
	public void method1(Supplier<Integer> s){
		this.s = s;	// メンバにセット.
	}
	public int run(){
		return s.get();	// s.getの戻り値をそのまま返す.
	}
}