// ヘッダのインクルード
#include <opencv2/opencv.hpp> // OpenCV2のOpenCV標準

// main関数
int main(void){

  // 画像の読み込み
  cv::Mat input_image = cv::imread("test.bmp"); // imreadで"test.bmp"を読み込み, input_imageに格納.

  // 画像の表示
  cv::imshow("test", input_image); // imshowで"test"というウィンドウ名でinput_imageを表示.

  // キー入力待ち
  cv::waitKey(0); // waitKeyでキー入力されるまで待つ.

  // ウィンドウの破棄
  cv::destroyAllWindows(); // destroyAllWindowsですべてのウィンドウを破棄.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
