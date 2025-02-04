import sys

from PySide6.QtWidgets import (
    QApplication,
    QCheckBox,
    QComboBox,
    QDateEdit,
    QDateTimeEdit,
    QDial,
    QDoubleSpinBox,
    QFontComboBox,
    QLabel,
    QLCDNumber,
    QLineEdit,
    QMainWindow,
    QProgressBar,
    QPushButton,
    QRadioButton,
    QSlider,
    QSpinBox,
    QTimeEdit,
    QVBoxLayout,
    QWidget,
    QListWidget
)

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Widgets App")

        layout = QVBoxLayout()
        layout.addWidget(QCheckBox())
        layout.addWidget(QRadioButton())

        button = QPushButton()
        button.setText('Push me')
        layout.addWidget(button)

        combobox = QComboBox()
        combobox.addItems([1, 2, 3])
        layout.addWidget(combobox)

        layout.addWidget(QFontComboBox())

        lineedit = QLineEdit()
        lineedit.setPlaceholderText('Type anything'),
        layout.addWidget(lineedit)

        layout.addWidget(QDateEdit())
        layout.addWidget(QDateTimeEdit())
        layout.addWidget(QTimeEdit())
        layout.addWidget(QDial())
        layout.addWidget(QSpinBox())
        layout.addWidget(QDoubleSpinBox())

        lcd = QLCDNumber()
        lcd.display(12345)
        layout.addWidget(lcd)

        label = QLabel()
        label.setText('Hello')

        layout.addWidget(label)

        progressbar = QProgressBar()
        progressbar.setMaximum(100)
        progressbar.setValue(25)
        layout.addWidget(progressbar)

        layout.addWidget(QSlider())

        listwidget = QListWidget()
        listwidget.addItems(['One', 'Two', 'Three'])
        layout.addWidget(listwidget)

        central_widget = QWidget()
        central_widget.setLayout(layout)

        self.setCentralWidget(central_widget)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()