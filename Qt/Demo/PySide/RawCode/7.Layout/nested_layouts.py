from PySide6.QtWidgets import QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout
from PySide6.QtGui import QPalette, QColor

class Color(QWidget):
    def __init__(self, color):
        super().__init__()
        self.setAutoFillBackground(True)

        palette = self.palette()
        palette.setColor(QPalette.Window, QColor(color))
        self.setPalette(palette)

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("My App")


        layout1 = QHBoxLayout()
        layout1.addWidget(Color('red'))
        layout1.addWidget(Color('yellow'))
        layout1.addWidget(Color('purple'))

        layout2 = QVBoxLayout()
        layout2.addLayout(layout1)
        layout2.addWidget(Color('green'))

        widget = QWidget()
        widget.setLayout(layout2)
        self.setCentralWidget(widget)

app = QApplication()

window = MainWindow()
window.show()

app.exec()