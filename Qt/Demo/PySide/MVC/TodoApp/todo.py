import sys
import json
from PySide6 import QtCore, QtGui, QtWidgets

from ui_mainwindow import Ui_MainWindow

tick = QtGui.QImage('tick.png')

class TodoModel(QtCore.QAbstractListModel):
    def __init__(self, *args, todos=None, **kwargs):
        super(TodoModel, self).__init__(*args, **kwargs)
        self.todos = todos or []

    def data(self, index, role):
        if role == QtCore.Qt.DisplayRole:
            _, text = self.todos[index.row()]
            return text
        if role == QtCore.Qt.DecorationRole:
            status, _ = self.todos[index.row()]
            if status:
                return tick
        return None

    def rowCount(self, index):
        return len(self.todos)

class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        QtWidgets.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)

        self.model = TodoModel()

        self.addButton.pressed.connect(self.add)
        self.deleteButton.pressed.connect(self.delete)
        self.completeButton.pressed.connect(self.complete)

        self.load()
        self.todoView.setModel(self.model)

    def add(self):
        text = self.todoEdit.text()
        if text:
            self.model.todos.append((False, text))
            self.model.layoutChanged.emit()     # refresh
            self.todoEdit.setText("")
            self.save()

    def delete(self):
        indexes = self.todoView.selectedIndexes()
        if indexes:
            index = indexes[0]
            del self.model.todos[index.row()]
            self.model.layoutChanged.emit()     # refresh
            self.todoView.clearSelection()
            self.save()

    def complete(self):
        indexes = self.todoView.selectedIndexes()
        if indexes:
            index = indexes[0]
            _, text = self.model.todos[index.row()]
            self.model.todos[index.row()] = (True, text)
            self.model.dataChanged.emit(index, index)
            self.todoView.clearSelection()
            self.save()

    def load(self):
        try:
            with open('data.db', 'r', encoding='utf-8') as f:
                self.model.todos = json.load(f)
        except Exception:
            pass

    def save(self):
        with open('data.db', 'w', encoding='utf-8') as f:
            json.dump(self.model.todos, f)

app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
