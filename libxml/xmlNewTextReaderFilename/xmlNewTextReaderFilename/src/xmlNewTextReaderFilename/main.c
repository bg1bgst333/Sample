/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <libxml/xmlreader.h> /* xmlreader */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  xmlTextReaderPtr reader; /* XMLリーダreader */

  /* XMLファイルを読み込み, XMLリーダを作成. */
  reader = xmlNewTextReaderFilename("test.xml"); /* xmlNewTextReaderFilenameでtest.xmlを読み込み. */
  if (reader != NULL){ /* 作成成功. */
    printf("reader = 0x%08x\n", reader); /* readerのアドレスを出力. */
    xmlFreeTextReader(reader); /* xmlFreeTextReaderでリソース解放. */
  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
