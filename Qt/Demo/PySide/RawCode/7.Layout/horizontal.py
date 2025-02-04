from PySide6.QtWidgets import QApplication, QMainWindow, QWidget, QHBoxLayout
from PySide6.QtGui import QPalette, QColor

class Color(QWidget):
    ''' Custom widget
    '''
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

        layout = QHBoxLayout()

        layout.addWidget(Color('red'))
        layout.addWidget(Color('green'))
        layout.addWidget(Color('blue'))

        widget = QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)

app = QApplication()

window = MainWindow()
window.show()

app.exec()