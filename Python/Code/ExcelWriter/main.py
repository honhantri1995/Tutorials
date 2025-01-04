from excel_writer import Workbook, FORMAT

workbook = Workbook('demo.xlsx')                    # Create a new Excel file
workbook.add_worksheet('sheet1')                    # Create worksheets
workbook.add_worksheet('sheet2')
workbook.add_format(FORMAT.BOLD)                    # Add format Bold for text

worksheet1 = workbook.get_worksheet('sheet1')
worksheet1.set_column('A:A', width=20)              # Widen the first column to make the text clearer
worksheet1.write('A1', 'Hello')                     # Write some simple text
worksheet1.write(2, 0, 123)                         # Write some numbers, with row/column notation
worksheet1.write(3, 0, 123.456)

worksheet2 = workbook.get_worksheet('sheet2')
worksheet2.write('A2', 'World', workbook.get_format(FORMAT.BOLD))   # Add a bold format
worksheet2.insert_image('B5', 'images/farm.png')                    # Insert an image

workbook.get().close()