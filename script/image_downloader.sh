#!/bin/sh -eu
umask 0022
export LC_ALL='C' PATH="$(command -p getconf PATH):$PATH"

if command -v wget >/dev/null; then
    dl(){
        if [ ! -e $2 ]; then
            wget -nv $1/$2 -O $2
            sleep 1
        fi
    }
elif command -v curl >/dev/null; then
    dl(){
        if [ ! -e $2 ]; then
            curl $1/$2 -o $2
            sleep 1
        fi
    }
else
    echo "wget or curl is required."
    exit 1
fi

root_url='http://mucho.girly.jp/bona'
mkcd(){
    mkdir -p $1
    cd $1
}

mkcd image

i=focus
mkcd $i
url=$root_url/$i
for j in thin trpt bold; do
    for k in b g r y; do
        dl $url ${i}_${j}_${k}.png
    done
done
dl $url ${i}_bold_o.png
cd ..

i=koma
for j in kinki kinki_torafu ryoko ryoko_torafu dirty; do
    mkcd ${i}/${i}_${j}
    url=$root_url/$i/${i}_${j}
    for k in G S; do
        for l in fu to kyo nkyo kei nkei gin ngin kin ou hi ryu kaku uma; do
            dl $url $k$l.png
        done
    done
    cd ../..
done

i=ban
mkcd $i
url=$root_url/$i
for j in kaya_a kaya_b kaya_c kaya_d gohan oritatami dirty paper stripe muji; do
    dl $url ${i}_${j}.png
done
cd ..

i=masu
mkcd $i
url=$root_url/$i
for j in dot nodot dot_xy nodot_xy handwriting; do
    dl $url ${i}_${j}.png
done
cd ..

