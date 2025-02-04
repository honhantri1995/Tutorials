import sys

from PySide6.QtCore import QSize, Qt
from PySide6.QtWidgets import QApplication, QMainWindow, QPushButton, QLabel, QLineEdit, QVBoxLayout, QWidget

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("My App")
        self.setFixedSize(QSize(400, 300))

        edit = QLineEdit()
        label = QLabel()

        layout = QVBoxLayout()
        layout.addWidget(edit)
        layout.addWidget(label)

        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)

        edit.textChanged.connect(label.setText)

app = QApplication(sys.argv)

window = MainWindow()
window.show()

app.exec()