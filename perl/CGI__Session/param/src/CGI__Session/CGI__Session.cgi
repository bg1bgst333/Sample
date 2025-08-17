#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI
use CGI::Session; # Session.

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# セッション生成.
if ($q->request_method eq 'POST'){ # 'POST'の時.

  # ユーザー名とパスワードを取得.
  my $username = $q->param('username');
  my $userpass = $q->param('userpass');

  # 合っているか確認.
  if ($username eq 'taro' and $userpass eq 'testpass'){ # ログイン成功.
    # CGIセッション作成.
    my $session = CGI::Session->new();
    # パラメータセット.
    $session->param('logged_in', 1); # ログイン状態.
    $session->param('user', $username); # ユーザー名.
    # クッキー登録.
    my $cookie = $q->cookie(-name => 'CGISESSID', -value => $session->id, -expires => '+5m');
    # リダイレクト
    print $q->redirect(-url => "/cgi-bin/secret.cgi", -cookie => $cookie); # secret.cgiに遷移.
  }
  else{ # ログイン失敗.
    print $q->redirect(-url => "/login.html"); # login.htmlに差し戻し.
  }

}
