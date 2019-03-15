// ヘッダのインクルード
#include <node.h> // Node
#include <unistd.h> // UNIX標準

// 文字列"ABC"を取得する関数get_abc()
void get_abc(const v8::FunctionCallbackInfo<v8::Value>& args){

  // isolateを取得.
  v8::Isolate* isolate = args.GetIsolate(); // args.GetIsolateでisolateを取得.

  // 5秒休止.
  sleep(5); // sleepで5秒休止.

  // "ABC"を返す.
  args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "ABC")); // args.GetReturnValue().Setで戻り値に"ABC"をセット.

}

// 初期化関数init()
void init(v8::Local<v8::Object> exports){

  // 関数を外部に公開.
  NODE_SET_METHOD(exports, "get_abc", get_abc); // NODE_SET_METHODでget_abcを"get_abc"として公開.

}

// NODE_MODULEマクロ
NODE_MODULE(native_ext, init);
