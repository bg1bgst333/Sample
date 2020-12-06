/* ヘッダファイルのインクルード. */
#include <linux/module.h> /* モジュール	*/

/* 初期化 */
static int custom_module_init(void){
	printk("custom_module_init called!\n");
	return 0;
}

/* 終了処理 */
static void custom_module_exit(void){
	printk("custom_module_exit called!\n");
}

/* 登録 */
module_init(custom_module_init);
module_exit(custom_module_exit);
