#!/usr/bin/perl

# 変数, 配列, ハッシュでの値の初期化.
$type_glob = "ABCDE"; # $type_globに"ABCDE"を代入.
print $type_glob."\n"; # $type_globを出力.
@type_glob = (1, 2, 3); # @type_globを初期化.
print '('.$type_glob[0].','.$type_glob[1].','.$type_glob[2].')'."\n"; # @type_globを出力.
%type_glob = ('key1' => 'value1',
              'key2' => 'value2'); # %type_globを初期化.
print '{'.$type_glob{'key1'}.",".$type_glob{'key2'}.'}'."\n"; # %type_globを出力.

# 型ブログの取得.
print *type_glob."\n"; # 型ブログの出力.

# エイリアス
*new_name = *type_glob; # type_globの内容をnew_nameが引き継ぐ.
print $new_name."\n"; # $new_nameを出力.
print '('.$new_name[0].','.$new_name[1].','.$new_name[2].')'."\n"; # @new_nameを出力.
print '{'.$new_name{'key1'}.",".$new_name{'key2'}.'}'."\n"; # %new_nameを出力.
print *new_name."\n"; # 型ブログの出力.(type_globになっている.)
