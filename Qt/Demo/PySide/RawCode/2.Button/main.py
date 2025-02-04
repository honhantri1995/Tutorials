import sys

from PySide6.QtCore import QSize
from PySide6.QtWidgets import QApplication, QMainWindow, QPushButton

class MainWindow(QMainWindow):
    def __init__(self):
        # When you subclass a Qt class, you must always inherit the QMainWindow's ctor to allow Qt to set up the object.
        # Otherwise, you'll get error: RuntimeError: '__init__' method of object's base class (MainWindow) not called.
        super().__init__()

        # Variables
        self.is_button_checked = False

        self.setWindowTitle("My App")

        # The default window is very small, so let's expand its size a little bit
        self.setFixedSize(QSize(400, 300))

        self.init_button()

    def init_button(self):
        button = QPushButton("Press Me!")

        # Set button as the central widget of the window
        self.setCentralWidget(button)

        # Connect signal clicked with a slot
        button.clicked.connect(self.on_button_clicked)

        # Connect signal toggled with a slot. But first, need to enable checkable
        button.setCheckable(True)
        button.clicked.connect(self.on_button_toggled)

        # Set an initial value for check
        button.setChecked(self.is_button_checked)

    def on_button_clicked(self):
        print("Clicked!")

    def on_button_toggled(self, checked):
        print("Checked #1?", checked)

        # If you need, you can store the 
        self.is_button_checked = checked
        print("Checked #2?", self.is_button_checked)

app = QApplication(sys.argv)

window = MainWindow()
window.show()

app.exec()