
import sys
import re
import os

from PyQt5 import QtCore, QtWidgets

from formatter.gui import Ui_MainWindow
from formatter import handler


class MainGui(QtWidgets.QMainWindow):
    def __init__(self):
        super(MainGui, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        self.handler = handler.FormatterHandler()
        self.opened_file = ''
        self.radio_btn_selected = False

        self.ui.btn_load_file.clicked.connect(self.load_file)
        self.ui.btn_save_header.clicked.connect(self.save_header)
        self.ui.btn_add_resource.clicked.connect(self.add_resource)
        self.ui.btn_remove_resource.clicked.connect(self.remove_resource)
        self.ui.radioBtn_image.clicked.connect(self.radio_btn_image_clicked)
        self.ui.radioBtn_raw.clicked.connect(self.radio_btn_raw_clicked)
        self.ui.lst_resources.clicked.connect(self.update_save_remove_btns)

        self.list_model = QtCore.QStringListModel()
        self.ui.lst_resources.setModel(self.list_model)

    def load_file(self):
        self.opened_file, ___ = QtWidgets.QFileDialog.getOpenFileName(
            self, 'Open File', '.', 'All Files (*)'
        )
        self.set_btn_add_resource_enabled()
        if self.opened_file:
            if len(self.opened_file) > 40:
                fn = '...' + self.opened_file[-35::]
            else:
                fn = self.opened_file
            self.ui.lbl_opened_file.setText(fn)

    def save_header(self):
        filename, ___ = QtWidgets.QFileDialog.getSaveFileName(
            self, 'Save file', '.', 'C Header File *.h'
        )
        if filename:
            self.handler.save_header(filename)
            QtWidgets.QMessageBox.information(
                self, 'Header Saved', 'Header file "{}" was saved successfully.'.format(filename)
            )

    def update_lst_resources(self, list_index=None):
        self.list_model.setStringList(self.handler.names)
        if list_index is not None:
            self.ui.lst_resources.setCurrentIndex(list_index)
        self.update_save_remove_btns()

    def add_resource(self):
        name = self.ui.txt_resource_name.text()
        if self.validate_resource_name():
            # Error
            return

        try:
            if self.ui.radioBtn_raw.isChecked():
                self.handler.add_const_from_raw(name, self.opened_file, self.ui.chbx_compress.isChecked())
            elif self.ui.radioBtn_image.isChecked():
                self.handler.add_const_from_img(name, self.opened_file,
                                                self.ui.chbx_format_img.isChecked(),
                                                self.ui.chbx_format_pal.isChecked(),
                                                self.ui.chbx_compress.isChecked())
            else:
                raise Exception('A weird error occurred...')
        except Exception as e:
            QtWidgets.QMessageBox.critical(self, type(e).__name__, str(e))
            return

        self.update_lst_resources()

    def remove_resource(self):
        index = self.ui.lst_resources.currentIndex().row()
        self.handler.remove_const(index)
        if len(self.handler.names):
            new_index = self.list_model.createIndex(
                (index, index - 1)[len(self.handler.names) - 1 < index], 0
            )
        else:
            new_index = None
        self.update_lst_resources(new_index)

    def validate_resource_name(self):
        name = self.ui.txt_resource_name.text()
        if not re.match('^[A-Za-z0-9_-]*$', name):
            QtWidgets.QMessageBox.critical(
                self, 'Invalid name', 'You may use only letters, numbers and dashes.'
            )
            return 1
        elif not len(name):
            QtWidgets.QMessageBox.critical(
                self, 'Missing name', 'No resource name was provided.'
            )
            return 1
        return 0

    def radio_btn_clicked(self):
        if not self.radio_btn_selected:
            self.radio_btn_selected = True
            self.ui.chbx_compress.setEnabled(True)
        self.set_btn_add_resource_enabled()

    def radio_btn_raw_clicked(self):
        self.ui.chbx_format_pal.setEnabled(False)
        self.ui.chbx_format_img.setEnabled(False)
        self.radio_btn_clicked()

    def radio_btn_image_clicked(self):
        self.ui.chbx_format_pal.setEnabled(True)
        self.ui.chbx_format_img.setEnabled(True)
        self.radio_btn_clicked()

    def set_btn_add_resource_enabled(self):
        self.ui.btn_add_resource.setEnabled(self.opened_file != '' and self.radio_btn_selected)

    def update_save_remove_btns(self):
        btn_state = len(self.handler.names) > 0
        self.ui.btn_remove_resource.setEnabled(
            btn_state and self.ui.lst_resources.currentIndex().row() != -1
        )
        self.ui.btn_save_header.setEnabled(btn_state)



def main():
    app = QtWidgets.QApplication(sys.argv)
    window = MainGui()
    window.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()