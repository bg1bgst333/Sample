// appとBrowserWindowの取得.
const {app, BrowserWindow} = require('electron'); // 'electron'モジュールからappとBrowserWindowを取得.

// mainWindowの初期化.
let mainWindow = null; // letでmainWindowにnullをセット.

// 準備完了
app.on('ready', function(){

  // mainWindowの作成.
  mainWindow = new BrowserWindow({width: 800, height: 600}); // BrowserWindowオブジェクトを(800, 600)で作成し, mainWindowに格納.

  // index.htmlのロード.
  mainWindow.loadFile('index.html'); // mainWindow.loadFileで'index.html'をロード.

  // ウィンドウが閉じられた時の処理.
  mainWindow.on('closed', function(){
    mainWindow = null; // mainWindowにnullをセット.
  });

});
  
// ウィンドウが全て閉じられた時の処理.
app.on('window-all-closed', function(){
  app.quit(); // appを終了.
});
