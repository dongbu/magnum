#ifndef Magnum_Physics_Test_AbstractShapeTest_h
#define Magnum_Physics_Test_AbstractShapeTest_h
/*
    Copyright © 2010, 2011, 2012 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include <QtTest/QTest>

#include "Magnum.h"

namespace Magnum { namespace Physics { namespace Test {

class AbstractShapeTest: public QObject {
    protected:
        template<class T> void randomTransformation(T& shape) {
            shape.applyTransformation(Matrix4::translation(Vector3(7.0f, 8.0f, -9.0f)));
        }
};

#define VERIFY_COLLIDES(a, b)                                               \
    QVERIFY(a % b);                                                         \
    QVERIFY(b % a);                                                         \
    QVERIFY(a.collides(&b));                                                \
    QVERIFY(b.collides(&a));

#define VERIFY_NOT_COLLIDES(a, b)                                           \
    QVERIFY(!(a % b));                                                      \
    QVERIFY(!(b % a));                                                      \
    QVERIFY(!(a.collides(&b)));                                             \
    QVERIFY(!(b.collides(&a)));

}}}

#endif
