import sys

from PySide6.QtWidgets import QApplication, QMainWindow, QMessageBox, QPushButton, QVBoxLayout, QWidget

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("My App")

        layout = QVBoxLayout()
        button1 = QPushButton("Press me for a built-in message box!")
        button1.clicked.connect(self.on_button1_clicked)
        button2 = QPushButton("Press me for a custom message box!")
        button2.clicked.connect(self.on_button2_clicked)
        layout.addWidget(button1)
        layout.addWidget(button2)

        widget = QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)

    def on_button1_clicked(self, s):
        # All built-in messageboxes:
        #   QMessageBox.about(parent, title, message)
        #   QMessageBox.critical(parent, title, message)
        #   QMessageBox.information(parent, title, message)
        #   QMessageBox.question(parent, title, message)
        #   QMessageBox.warning(parent, title, message)
        button = QMessageBox.question(
            self,
            "Question",
            "I have a question!",
            defaultButton=QMessageBox.No,
        )
        if button == QMessageBox.Yes:
            print("Yes!")
        else:
            print("No!")

    def on_button2_clicked(self, s):
        messagebox = QMessageBox(self)
        messagebox.setWindowTitle("I have a question!")
        messagebox.setText("This is a simple dialog")
        messagebox.setStandardButtons(QMessageBox.Yes | QMessageBox.No)
        button = messagebox.exec()

        if button == QMessageBox.Yes:
            print("Yes!")
        else:
            print("No!")

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()