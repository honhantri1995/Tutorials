import sys

from PySide6.QtWidgets import QApplication, QDialog, QMainWindow, QPushButton, QDialogButtonBox, QVBoxLayout, QLabel

class CustomDialog(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)

        QBtn = (
            QDialogButtonBox.Ok | QDialogButtonBox.Cancel
        )

        self.buttonBox = QDialogButtonBox(QBtn)
        self.buttonBox.accepted.connect(self.accept)
        self.buttonBox.rejected.connect(self.reject)

        layout = QVBoxLayout()
        message = QLabel("Something happened, is that OK?")
        layout.addWidget(message)
        layout.addWidget(self.buttonBox)
        self.setLayout(layout)

    def accept(self):
        print('Accept')

    def reject(self):
        print('Reject')
        # Hide the dialog so that we can interact with the main window
        self.hide()

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("My App")

        button = QPushButton("Press me for a dialog!")
        button.clicked.connect(self.on_button_clicked)
        self.setCentralWidget(button)

    def on_button_clicked(self, s):
        print("Click", s)

        dialog = CustomDialog(self)
        dialog.setWindowTitle("Info")

        # The QDialog completely blocks the app execution.
        # Without multithreads, do not expect anything else to happen anywhere else in your app after starting the dialog.
        if dialog.exec():
            print("Success!")
        else:
            print("Cancel!")

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()