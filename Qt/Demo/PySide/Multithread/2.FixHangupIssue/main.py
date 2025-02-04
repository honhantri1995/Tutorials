from PySide6.QtWidgets import QVBoxLayout, QLabel, QPushButton, QWidget, QMainWindow, QApplication
from PySide6.QtCore import QTimer, QRunnable, Slot, QThreadPool

import time

class Worker(QRunnable):
    @Slot()             # QtCore.Slot
    def run(self):
        print("Thread start")
        time.sleep(5)
        print("Thread complete")

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

        self.threadpool = QThreadPool()

    # The sleep run on a separate worker thread. The label displays on the main thread. So, no more program HANGUP (frozen)
    def on_sleep(self):
        worker = Worker()
        self.threadpool.start(worker)
        print(f"{self.threadpool.activeThreadCount()} out of {self.threadpool.maxThreadCount()} possible threads active")

    def recurring_timer(self):
        self.counter +=1
        self.label.setText(f"Counter: {self.counter}")

app = QApplication()
window = MainWindow()
app.exec()