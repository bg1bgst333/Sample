// ボディクラス
class Body {

	// 名前
	private String name;
	public String getName(){
		return name;
	}
	public void setName(String name){
		this.name = name;
	}

	// 年齢
	private int age;
	public int getAge(){
		return age;
	}
	public void setAge(int age){
		this.age = age;
	}

	// 身長
	private int height;
	public int getHeight(){
		return height;
	}
	public void setHeight(int height){
		this.height = height;
	}

	// 体重
	private int weight;
	public int getWeight(){
		return weight;
	}
	public void setWeight(int weight){
		this.weight = weight;
	}

	// コンストラクタ
	public Body(String name, int age, int height, int weight){

		// 引数をメンバにセット.
		this.name = name;
		this.age = age;
		this.height = height;
		this.weight = weight;

	}

}