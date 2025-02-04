from PySide6.QtWidgets import QApplication, QMainWindow, QPushButton, QDialog
from PySide6.QtUiTools import QUiLoader

loader = QUiLoader()

def main_window(self: QMainWindow):
    self.setCentralWidget(self.pushButton)

    def on_launch_dialog():
        result = self.exec()
        if result:
            print("Success!")
        else:
            print("Cancelled.")

def dialog(self: QDialog):
    pass





class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        main_window = loader.load("MainWindow.ui", None)
        self.setCentralWidget(main_window.pushButton)
        # main_window.pushButton.released.connect(self.on_launch_dialog)
        main_window.show()

    def on_launch_dialog(self):
        dialog = loader.load("Dialog.ui", None)
        result = dialog.exec()
        if result:
            print("Success!")
        else:
            print("Cancelled.")

app = QApplication()

main_window(loader.load('MainWindow.ui'))
dialog(loader.load('Dialog.ui'))

app.exec()