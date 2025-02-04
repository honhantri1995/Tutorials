import sys
import random

from PySide6.QtGui import QGuiApplication
from PySide6.QtQml import QQmlApplicationEngine
from PySide6.QtCore import QUrl

from PySide6.QtCore import QObject, Signal, Slot, Property

class NumberGenerator(QObject):
    def __init__(self):
        QObject.__init__(self)
        self.__number = 0
    
    # Declare a slot
    # Here we invoke in the __set_number method so that the signal is emitted when the value is changed.
    @Slot()
    def updateNumber(self):
        self.__set_number(random.randint(0, 99))

    # Declare a signal
    numberChanged = Signal(int)

    def __set_number(self, val):
        if self.__number != val:
            self.__number = val;
            self.numberChanged.emit(self.__number)

    def __get_number(self):
        return self.__number

    # Declare a read-only property holding the last random number
    number = Property(int, __get_number, notify=numberChanged)


if __name__ == '__main__':
    app = QGuiApplication(sys.argv)
    engine = QQmlApplicationEngine()

    number_generator = NumberGenerator()
    engine.rootContext().setContextProperty("numberGenerator", number_generator)

    engine.load(QUrl("main.qml"))
    
    if not engine.rootObjects():
        sys.exit(-1)    

    sys.exit(app.exec())

