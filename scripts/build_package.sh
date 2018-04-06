#! /bin/bash

PACKAGE_NAME=qtHttpRequests


DIR="$( cd "$( dirname "$0" )" && pwd )"
BUILDDIR=$DIR/../build/release
SRCDIR=$DIR/../src
DESTDIR=$DIR/$PACKAGE_NAME
DESTDIRDEV=$DIR/$PACKAGE_NAME-dev
mkdir -p $DESTDIR
mkdir -p $DESTDIR/usr/local/lib
mkdir -p $DESTDIR/DEBIAN
mkdir -p $DESTDIRDEV
mkdir -p $DESTDIRDEV/DEBIAN
mkdir -p $DESTDIRDEV/usr/local/include/$PACKAGE_NAME

cp -P $DIR/packageFiles/control $DESTDIR/DEBIAN
cp -rP $BUILDDIR/*.so* $DESTDIR/usr/local/lib
dpkg-deb --build $PACKAGE_NAME
mv ./${PACKAGE_NAME}.deb ${PACKAGE_NAME}_1.0-0.deb

cp -rP $SRCDIR/*.h $DESTDIRDEV/usr/local/include/$PACKAGE_NAME
cp -P $DIR/packageFiles/control-dev $DESTDIRDEV/DEBIAN/control
dpkg-deb --build $PACKAGE_NAME-dev
mv ./$PACKAGE_NAME-dev.deb $PACKAGE_NAME-dev_1.0-0.deb

