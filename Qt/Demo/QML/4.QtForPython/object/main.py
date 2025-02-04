import sys
import random

from PySide6.QtGui import QGuiApplication
from PySide6.QtQml import QQmlApplicationEngine, qmlRegisterType
from PySide6.QtCore import QUrl
from PySide6.QtCore import QObject, Signal, Slot

class NumberGenerator(QObject):
    def __init__(self):
        QObject.__init__(self)

    # Declare a signal
    nextNumber = Signal(int)

    # Decorate the method with the @Slot() decorator, thus turning it into a slot.
    # There is no concept of invokables in Qt Python, so all callable methods must be slots.
    @Slot()
    def giveNumber(self):
        self.nextNumber.emit(random.randint(0, 99))

if __name__ == '__main__':
    app = QGuiApplication(sys.argv)
    engine = QQmlApplicationEngine()

    # expose the object to QML as a global variable under the name "numberGenerator".
    number_generator = NumberGenerator()
    engine.rootContext().setContextProperty("numberGenerator", number_generator)

    engine.load(QUrl("main.qml"))
    
    if not engine.rootObjects():
        sys.exit(-1)

    sys.exit(app.exec())
