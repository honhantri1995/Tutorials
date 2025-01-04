from typing import List

from csv_parser import CsvParser

class Image():
    def __init__(self, id: str, path: str, desc: str):
        self.id = id
        self.path = path
        self.desc = desc

class CsvParser_Image(CsvParser):
    def __init__(self, *args, **kwargs):
        fieldnames = ['id', 'path', 'desc']
        super(CsvParser_Image, self).__init__('images.csv', *args, **kwargs, fieldnames=fieldnames)

    def read(self) -> List[Image]:     # Note: Explicitly override this function to help IntelliSense able to autocomplete object items
        return super(CsvParser_Image, self).read()

    def get(self, id) -> Image:        # Note: Explicitly override this function to help IntelliSense able to autocomplete object items
        return super(CsvParser_Image, self).get(id)