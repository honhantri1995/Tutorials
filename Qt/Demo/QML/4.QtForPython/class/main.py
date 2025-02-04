import sys
import random

from PySide6.QtGui import QGuiApplication
from PySide6.QtQml import QQmlApplicationEngine, qmlRegisterType
from PySide6.QtCore import QUrl

from PySide6.QtCore import QObject, Signal, Slot

class NumberGenerator(QObject):
    def __init__(self):
        QObject.__init__(self)

    nextNumber = Signal(int)

    @Slot()
    def giveNumber(self):
        self.nextNumber.emit(random.randint(0, 99))

if __name__ == '__main__':
    app = QGuiApplication(sys.argv)
    engine = QQmlApplicationEngine()

    # 1st: A reference to the class
    # 2nd: A module name
    # 3rd: A module version consisting of a major and minor number in format "<major>.<minor>"
    # 4th: The QML name of the class
    qmlRegisterType(NumberGenerator, 'Generators', 1, 0, 'NumberGenerator')

    engine.load(QUrl("main.qml"))
    
    if not engine.rootObjects():
        sys.exit(-1)    

    sys.exit(app.exec())
