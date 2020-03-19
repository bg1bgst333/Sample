/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <libxml/xmlreader.h> /* xmlreader */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  xmlTextReaderPtr reader; /* XMLリーダreader */
  int ret; /* 戻り値を格納するint型変数ret. */

  /* XMLファイルを読み込み, XMLリーダを作成. */
  reader = xmlNewTextReaderFilename("test.xml"); /* xmlNewTextReaderFilenameでtest.xmlを読み込み. */
  if (reader != NULL){ /* 作成成功 */
    printf("reader = 0x%08x\n", reader); /* readerのアドレスを出力. */
    ret = xmlTextReaderRead(reader); /* xmlTextReaderReadでreaderを次のノードに移動させる. */
    while (ret == 1){ /* retが1なら移動成功. */
      printf("Move Next Node!\n"); /* "Move Next Node!"と出力. */
      ret = xmlTextReaderRead(reader); /* xmlTextReaderReadでreaderを次のノードに移動させる. */
    }
    printf("End of move!\n"); /* "End of move!"と出力. */
    xmlFreeTextReader(reader); /* xmlFreeTextReaderでリソース解放. */
  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
