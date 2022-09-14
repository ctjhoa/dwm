# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>

pkgname=dwm
pkgver=6.3
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="https://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
options=(zipman)
depends=('libx11' 'libxinerama' 'libxft' 'freetype2' 'st' 'dmenu')
install=dwm.install
source=(dwm.desktop
        https://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
	config.h
	shiftview.c)
md5sums=('939f403a71b6e85261d09fc3412269ee'
         'ed3aa40b97e29dbbe7d7d3f296bc2fcc'
         '8b86d6f2ac4408e22ab583677eb83dd6'
         '3e003bbd4448b127af639b12d83b9c94')

prepare() {
  cd "$srcdir/$pkgname-$pkgver"
  cp "$srcdir/config.h" config.h
  cp "$srcdir/shiftview.c" shiftview.c
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
