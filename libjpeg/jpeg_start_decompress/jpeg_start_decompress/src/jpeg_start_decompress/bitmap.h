/* 二重インクルードの防止 */
#ifndef BITMAP_H
#define BITMAP_H

/* ワード境界を一時的に2にする. */
#pragma pack(2)

/* ビットマップファイルヘッダ構造体 */
typedef struct tag_bitmap_file_header{
  unsigned short type; /* タイプ */
  unsigned int size; /* ファイルサイズ */
  unsigned short reserved1; /* 予約済み */
  unsigned short reserved2; /* 予約済み */
  unsigned int off_bits; /* ビット配列までのオフセット */ 
} bitmap_file_header_t;

/* ワード境界を元に戻す. */
#pragma pack()

/* ビットマップ情報ヘッダ構造体 */
typedef struct tag_bitmap_info_header{
  unsigned int size; /* 構造体サイズ */ 
  int width; /* 幅 */
  int height; /* 高さ */
  unsigned short planes; /* プレーンの数 */
  unsigned short bit_count; /* ピクセルあたりの色数 */
  unsigned int compression; /* 圧縮方式 */
  unsigned int size_image; /* ビットマップのサイズ */
  int x_pels_per_meter; /* 水平解像度 */
  int y_pels_per_meter; /* 垂直解像度 */
  unsigned int clr_used; /* イメージで使われている色数 */
  unsigned int clr_important; /* 重要な色の数 */
} bitmap_info_header_t;

/* カラーテーブル構造体(今回は24bitビットマップのみ扱うので使わない.) */
typedef struct tag_rgb_quad{
  unsigned char blue; /* 青 */
  unsigned char green; /* 緑 */
  unsigned char red; /* 赤 */
  unsigned char reserved; /* 予約済み */
} rgb_quad_t;

/* ビットマップ(今回はカラーテーブルを含まない.) */
typedef struct tag_bitmap{
  bitmap_file_header_t file_header; /* ビットマップファイルヘッダ */
  bitmap_info_header_t info_header; /* ピットマップ情報ヘッダ */
  unsigned char *buf; /* ピクセルバッファへのポインタ */
} bitmap_t;

/* 関数のプロトタイプ宣言 */
int load_bitmap(const char *filename, bitmap_t *bitmap_ptr); /* ビットマップのロード */
int save_bitmap(const char *filename, bitmap_t *bitmap_ptr, int buf_size); /* ビットマップのセーブ */
void destroy_bitmap(bitmap_t *bitmap_ptr); /* ビットマップの破棄 */

#endif
