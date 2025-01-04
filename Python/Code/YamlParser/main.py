from yaml_parser import YamlParser
import util

yaml = YamlParser('testcase.yaml')
datas = yaml.read()
print(f'Read file: {util.objects_to_dicts(datas)}')