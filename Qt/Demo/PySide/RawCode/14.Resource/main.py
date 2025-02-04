from PySide6 import QtGui, QtWidgets
import resources_rc

class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Hello World")
        self.button = QtWidgets.QPushButton("Turn me into a monkey")

        icon = QtGui.QIcon(":/icons/penguin")
        self.button.setIcon(icon)
        self.button.clicked.connect(self.on_change_icon)

        self.setCentralWidget(self.button)

        self.show()

    def on_change_icon(self):
        icon = QtGui.QIcon(":/icons/monkey")
        self.button.setIcon(icon)


app = QtWidgets.QApplication()
w = MainWindow()
app.exec()