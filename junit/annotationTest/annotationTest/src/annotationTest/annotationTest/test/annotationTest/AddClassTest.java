// annotationTestパッケージ.
package annotationTest;	// annotationTestパッケージとしておく.

import static org.junit.Assert.*;

import org.junit.Test;

// AddClassのテストクラス.
public class AddClassTest {

	// テストメソッド.
	@Test
	public void testAdd(){
		int addOp = 10 + 20;	// 10と20を足す.
		AddClass addObj = new AddClass();	// addObj生成.
		int result = addObj.add(10, 20);	// 10と20をaddObj.addで計算.
		assertEquals(addOp, result);	// addOpとresultが等しければ, テスト成功.
	}

}