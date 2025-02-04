from PySide6.QtWidgets import (QApplication, QMainWindow, QPushButton, QPlainTextEdit,
                                QVBoxLayout, QWidget, QProgressBar)
from PySide6.QtCore import QProcess
import sys
import re

# A regular expression, to extract the % complete.
progress_re = re.compile("Total complete: (\d+)%")

def simple_percent_parser(output):
    """
        Matches lines using the progress_re regex,
        returning a single integer for the % progress.
    """
    m = progress_re.search(output)
    if m:
        pc_complete = m.group(1)
        return int(pc_complete)

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.btn = QPushButton("Execute")
        self.btn.pressed.connect(self.on_start_process)
        self.text = QPlainTextEdit()
        self.text.setReadOnly(True)

        self.progress = QProgressBar()
        self.progress.setRange(0, 100)

        layout = QVBoxLayout()
        layout.addWidget(self.btn)
        layout.addWidget(self.progress)
        layout.addWidget(self.text)
        widget = QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)

        self.process = None

    def message(self, s):
        self.text.appendPlainText(s)

    def on_start_process(self):
        if not self.process:            # No process running
            self.message("Executing process")
            self.process = QProcess()   # Keep a reference to the QProcess (e.g. on self) while it's running. Otherwise, error "QProcess: Destroyed while process ("python3") is still running."
            self.process.readyReadStandardOutput.connect(self.on_handle_stdout)
            self.process.readyReadStandardError.connect(self.on_handle_stderr)
            self.process.stateChanged.connect(self.on_handle_state)
            self.process.finished.connect(self.on_process_finished)
            self.process.start("python", ['dummy_script.py'])

    def on_handle_stdout(self):
        data = self.process.readAllStandardOutput()
        stdout = bytes(data).decode("utf8")
        self.message(stdout)

    def on_handle_stderr(self):
        data = self.process.readAllStandardError()
        stderr = bytes(data).decode("utf8")
        self.message(stderr)

        # Extract progress if it is in the data
        progress = simple_percent_parser(stderr)
        if progress:
            self.progress.setValue(progress)

    def on_handle_state(self, state):
        states = {
            QProcess.NotRunning: 'Not running',
            QProcess.Starting: 'Starting',
            QProcess.Running: 'Running',
        }
        state_name = states[state]
        self.message(f"State changed: {state_name}")

    def on_process_finished(self):
        self.message("Process finished")
        self.process = None

app = QApplication(sys.argv)
w = MainWindow()
w.show()
app.exec()