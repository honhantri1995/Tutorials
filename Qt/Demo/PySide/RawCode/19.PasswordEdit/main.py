from PySide6 import QtCore, QtGui, QtWidgets
from qtwidgets import PasswordEdit

class Window(QtWidgets.QMainWindow):

    def __init__(self):
        super().__init__()

        password = PasswordEdit()
        self.setCentralWidget(password)

app = QtWidgets.QApplication([])
w = Window()
w.show()
app.exec()