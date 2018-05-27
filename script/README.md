### `build.sh`
カレントディレクトリに`build`ディレクトリを作成し,
その中でビルドを実行します.

### `image_downloader.sh`
[将棋アプリ用クリエイティブコモンズ画像](http://mucho.girly.jp/bona)から
画像の取得を行います.

### `setup.sh`
`./QShogi`で実行が出来るようにセットアップします.
具体的には`build.sh`, `image_downloader.sh`を実行し,
ビルドされた`QShogi`をカレントディレクトリにコピーします.
