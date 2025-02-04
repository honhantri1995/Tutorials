from PySide6 import QtGui, QtWidgets
from ui_MainWindow import Ui_MainWindow

class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

    def on_change_icon(self):
        icon = QtGui.QIcon(":/icons/monkey")
        self.button.setIcon(icon)

app = QtWidgets.QApplication()
w = MainWindow()
w.show()
app.exec()