from PySide6.QtWidgets import QVBoxLayout, QLabel, QPushButton, QWidget, QMainWindow, QApplication
from PySide6.QtCore import QTimer

import time

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.counter = 0

        layout = QVBoxLayout()

        self.label = QLabel("Start")
        button = QPushButton("Sleep")
        button.pressed.connect(self.on_sleep)

        layout.addWidget(self.label)
        layout.addWidget(button)

        widget = QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)

        self.show()

        # The timer runs on a separate thread
        self.timer = QTimer()
        self.timer.setInterval(1000)
        self.timer.timeout.connect(self.recurring_timer)
        self.timer.start()

    # However, the sleep and the label display run on the same thread, which cause program HANGUP (frozen)
    def on_sleep(self):
        time.sleep(5)

    def recurring_timer(self):
        self.counter +=1
        self.label.setText(f"Counter: {self.counter}")

app = QApplication()
window = MainWindow()
app.exec()