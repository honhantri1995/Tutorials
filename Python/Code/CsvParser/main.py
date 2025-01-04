from csv_parser_image import CsvParser_Image, Image
import util

csv = CsvParser_Image()

csv.clear()
print('Clear CSV file')

images = csv.read()
print(f'First read file: {util.objects_to_dicts(images)}')

image_1 = Image('image1', 'path/to/image1', 'this is image 1')
csv.add(image_1)
print(f'Add Image1 to file, and read file: {util.objects_to_dicts(csv.read())}')

image_2 = Image('image2', 'path/to/image2', 'this is image 2')
csv.add(image_2)
print(f'Add Image2 to file, and read file: {util.objects_to_dicts(csv.read())}')

image_2 = csv.get('image2')
print(f'Image2 signal: {util.object_to_dict(image_2)}')

csv.remove('image2')
print(f'Remove Image2 from file, and read file: {util.objects_to_dicts(csv.read())}')

image_3 = Image('image3', 'path/to/image3', 'this is image 3')
csv.add(image_3)
print(f'Add Image3 to file, and read file: {util.objects_to_dicts(csv.read())}')

image_1.desc = 'no desc'
csv.update('image1', image_1)
print(f'Update desc of Image1, and read file: {util.objects_to_dicts(csv.read())}')