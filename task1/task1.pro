TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    BinaryExpression.cpp \
    Expression.cpp \
    ParserUtils.cpp \
    unaryexpression.cpp \
    conjunction.cpp \
    disjunction.cpp \
    implication.cpp \
    negation.cpp \
    variable.cpp

HEADERS += \
    BinaryExpression.h \
    Expression.h \
    ParserUtils.h \
    unaryexpression.h \
    conjunction.h \
    disjunction.h \
    implication.h \
    negation.h \
    variable.h

