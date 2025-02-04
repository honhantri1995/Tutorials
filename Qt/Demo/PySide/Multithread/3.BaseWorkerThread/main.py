from PySide6.QtWidgets import QVBoxLayout, QLabel, QPushButton, QWidget, QMainWindow, QApplication
from PySide6.QtCore import QTimer, QRunnable, Slot, QThreadPool

import time

class Worker(QRunnable):
    def __init__(self, fn, *args, **kwargs):
            super().__init__()
            self.fn = fn
            self.args = args
            self.kwargs = kwargs

    @Slot()         # QtCore.Slot
    def run(self):
        self.fn(*self.args, **self.kwargs)

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

        self.timer = QTimer()
        self.timer.setInterval(1000)
        self.timer.timeout.connect(self.recurring_timer)
        self.timer.start()

        self.threadpool = QThreadPool()

    def on_sleep(self):
        worker = Worker(self.sleep)
        self.threadpool.start(worker)
        print(f"{self.threadpool.activeThreadCount()} out of {self.threadpool.maxThreadCount()} possible threads active")

    def sleep(self):
        time.sleep(5)

    def recurring_timer(self):
        self.counter +=1
        self.label.setText(f"Counter: {self.counter}")

app = QApplication()
window = MainWindow()
app.exec()