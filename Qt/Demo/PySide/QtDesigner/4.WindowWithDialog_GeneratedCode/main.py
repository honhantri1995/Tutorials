from PySide6.QtWidgets import QApplication, QMainWindow, QDialog

from ui_MainWindow import Ui_MainWindow
from ui_Dialog import Ui_Dialog

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

    def on_launch_dialog(self):
        dialog = Dialog()
        result = dialog.exec()
        if result:
            print("Success!")
        else:
            print("Cancelled.")

class Dialog(QDialog, Ui_Dialog):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

app = QApplication()
mainwindow = MainWindow()
mainwindow.show()
app.exec()