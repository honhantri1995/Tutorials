from typing import Dict

import xlsxwriter   # pip install XlsxWriter

class FORMAT:
    BOLD = 0
    VERTICAL_CENTER = 1

class Worksheet(xlsxwriter.Workbook.worksheet_class):
    pass

class Workbook:
    def __init__(self, filepath: str):
        self.workbook = xlsxwriter.Workbook(filepath)
        self.worksheet_dict : Dict[str, Worksheet] = {}
        self.format_dict = {}

    def add_worksheet(self, sheetname: str) -> bool:
        try:
            ret = False
            worksheet = self.workbook.add_worksheet(name=sheetname)
            if worksheet:
                self.worksheet_dict[sheetname] = worksheet
                ret = True
            return ret
        except xlsxwriter.exceptions.DuplicateWorksheetName:
            print(f'[ERROR] Worksheet {sheetname} alreay exists. Cannot add more')
            return ret

    def add_format(self, fmt: FORMAT):
        try:
            ret = False
            dic = {}
            if fmt == FORMAT.BOLD:
                dic['bold'] = True
            if fmt == FORMAT.VERTICAL_CENTER:
                dic['valign'] = 'vcenter'

            if dic:
                format = self.workbook.add_format(dic)
                if format:
                    self.format_dict[fmt] = format
                    ret = True
            return ret
        except Exception as ex:
            print(f'[ERROR] Fail to add format {fmt}. Exception: {ex}')
            return ret

    def get(self):
        return self.workbook

    def get_worksheet(self, sheetname: str) -> Worksheet:
        try:
            return self.worksheet_dict[sheetname]
        except Exception:
            return None

    def get_format(self, type: str):
        try:
            return self.format_dict[type]
        except Exception:
            return None
