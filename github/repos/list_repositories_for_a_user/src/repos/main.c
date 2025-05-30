/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <curl/curl.h> /* curl */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  CURL *curl; /* CURL構造体curl. */

  /* 初期化 */
  curl = curl_easy_init(); /* curl_easy_initで初期化. */

  /* URLのセット. */
  curl_easy_setopt(curl, CURLOPT_URL, "https://api.github.com/users/bg1bgst333/repos"); /* curl_easy_setoptでURLに"https://api.github.com/users/bg1bgst333/repos"をセット. */

  /* ユーザエージェントのセット. */
  curl_easy_setopt(curl, CURLOPT_USERAGENT, "bgst"); /* CURLOPT_USERAGENTでユーザエージェントをセット.(ユーザエージェント自体は適当でもいい模様.) */

  /* 実行 */
  curl_easy_perform(curl); /* curl_easy_performで実行. */

  /* 後始末 */
  curl_easy_cleanup(curl); /* curl_easy_cleanupで破棄. */

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
