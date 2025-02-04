import sys
from PySide6 import QtWidgets

from window import Ui_MainWindow

class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)  # trigger the setup of the interface

app = QtWidgets.QApplication(sys.argv)

window = MainWindow()
window.show()
app.exec()