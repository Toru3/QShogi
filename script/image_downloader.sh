#!/bin/sh -eu
dl_prog='wget -nv'
root_url='http://mucho.girly.jp/bona'
mkcd(){
    mkdir -p $1
    cd $1
}
cd ..
mkcd image
root_dir=`pwd`

i=focus
cd $root_dir
mkcd $i
url=$root_url/$i/
for j in thin trpt bold; do
    for k in b g r y; do
        $dl_prog $url/${i}_${j}_${k}.png
        sleep 1
    done
done
$dl_prog $url/${i}_bold_o.png

i=koma
for j in kinki kinki_torafu ryoko ryoko_torafu dirty; do
    cd $root_dir
    mkcd ${i}/${i}_${j}
    url=$root_url/$i/${i}_${j}
    for k in G S; do
        for l in fu to kyo kei nkei gin ngin kin ou hi ryu kaku uma; do
            $dl_prog $url/$k$l.png
            sleep 1
        done
    done
done

i=ban
cd $root_dir
mkcd $i
url=$root_url/$i/
for j in kaya_a kaya_b kaya_c kaya_d gohan oritatami dirty paper stripe muji; do
    $dl_prog $url/${i}_${j}.png
    sleep 1
done

i=masu
cd $root_dir
mkcd $i
url=$root_url/$i/
for j in dot nodot dot_xy nodot_xy handwriting; do
    $dl_prog $url/${i}_${j}.png
    sleep 1
done

