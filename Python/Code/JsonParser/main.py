from json_parser_signal import JsonParser_Signal, Signal
import util

json_parser = JsonParser_Signal('signal.json')

json_parser.clear()
print('Clear JSON file')

signals = json_parser.read()
print(f'First read file: {util.objects_to_dicts(signals)}')

signal_btc = Signal('btcusdt', 'long', 10)
json_parser.add(signal_btc)
print(f'Add BTC to file, and read file: {util.objects_to_dicts(json_parser.read())}')

signal_eth = Signal('ethusdt', 'short', 50)
json_parser.add(signal_eth)
print(f'Add ETH to file, and read file: {util.objects_to_dicts(json_parser.read())}')

signal_eth = json_parser.get('ethusdt')
print(f'ETH signal: {util.object_to_dict(signal_eth)}')

json_parser.remove('ethusdt')
print(f'Remove ETH from file, and read file: {util.objects_to_dicts(json_parser.read())}')

signal_xrp = Signal('xrpusdt', 'long', 20)
json_parser.add(signal_xrp)
print(f'Add XRP to file, and read file: {util.objects_to_dicts(json_parser.read())}')

signal_btc.leverage = 5
json_parser.update(signal_btc)
print(f'Update leverage of BTC, and read file: {util.objects_to_dicts(json_parser.read())}')