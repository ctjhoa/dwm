# Maintainer: Neptune <neptune650@proton.me>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>

pkgname=dwm
pkgver=6.4
pkgrel=2
pkgdesc="A dynamic window manager for X"
url="https://dwm.suckless.org"
arch=('i686' 'x86_64' 'arm' 'armv7h' 'armv6h' 'aarch64')
license=('MIT')
options=(zipman)
depends=('libx11' 'libxinerama' 'libxft' 'freetype2')
install=dwm.install
source=(dwm.desktop
        https://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
	config.h
	shiftview.c)
md5sums=('939f403a71b6e85261d09fc3412269ee'
         '008da068c3884ae675f65b9458b43c02'
         '8b86d6f2ac4408e22ab583677eb83dd6'
         '3e003bbd4448b127af639b12d83b9c94')

prepare() {
  cd "$srcdir/$pkgname-$pkgver"
  if [[ -f "$srcdir/config.h" ]]; then
    cp -fv "$srcdir/config.h" config.h
  fi
  if [[ -f "$srcdir/shiftview.c" ]]; then
    cp -fv "$srcdir/shiftview.c" shiftview.c
  fi
}

build() {
  cd "$srcdir/$pkgname-$pkgver"
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11 FREETYPEINC=/usr/include/freetype2
}

package() {
  cd "$srcdir/$pkgname-$pkgver"
  make PREFIX=/usr DESTDIR="$pkgdir" install
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
  install -Dm644 README "$pkgdir/usr/share/doc/$pkgname/README"
  install -Dm644 "$srcdir/dwm.desktop" "$pkgdir/usr/share/xsessions/dwm.desktop"
}
