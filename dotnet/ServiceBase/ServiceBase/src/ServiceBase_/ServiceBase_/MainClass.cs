// 名前空間の登録
using System.ServiceProcess;    // サービスプロセスクラス(System.ServiceProcess名前空間)
using System.Diagnostics;   // システムプロセスやイベントログとの対話するためのクラス.(System.Diagnostics名前空間)

// メインクラス
class MainClass : ServiceBase   // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // イベントログに書き込む.
        EventLog.WriteEntry("ServiceBase_", "Run before");   // EventLogのスタティックメソッドWriteEntryで"ServiceBase_"というソースで"Run before"と書き込む.

        // サービス開始.
        ServiceBase.Run(new MainClass()); //  ServiceBase.RunにMainClassオブジェクトインスタンスを渡してサービス起動.

        // イベントログに書き込む.
        EventLog.WriteEntry("ServiceBase_", "Run after");   // EventLogのスタティックメソッドWriteEntryで"ServiceBase_"というソースで"Run after"と書き込む.

    }

    // コンストラクタ
    public MainClass()
    {

        // サービスの初期化.
        CanStop = true; // 停止可能にする.
        ServiceName = "ServiceBase_";   // サービス名は"ServiceBase_".

    }

    // サービス開始時
    protected override void OnStart(string[] args){
        
        // イベントログに書き込む.
        EventLog.WriteEntry("ServiceBase_", "OnStart");   // EventLogのスタティックメソッドWriteEntryで"ServiceBase_"というソースで"OnStart"と書き込む.

    }

    // サービス停止時
    protected override void OnStop()
    {

        // イベントログに書き込む.
        EventLog.WriteEntry("ServiceBase_", "OnStop");   // EventLogのスタティックメソッドWriteEntryで"ServiceBase_"というソースで"OnStop"と書き込む.

    }

}