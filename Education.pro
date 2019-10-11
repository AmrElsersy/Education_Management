QT -= gui
QT += core
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    course.cpp \
    student.cpp \
    solution.cpp \
    disscusion.cpp \
    doctor.cpp \
    questions_and_answers.cpp \
    quiz.cpp \
    person.cpp \
    system_flow.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    course.h \
    node.h \
    Linked_List.h \
    student.h \
    solution.h \
    disscusion.h \
    doctor.h \
    questions_and_answers.h \
    quiz.h \
    person.h \
    system_flow.h

DISTFILES += \
    ../Desktop/Education/DymmyData.txt
