from json_parser_signal import JsonParser_Signal, Signal
import utils

json_parser = JsonParser_Signal('signal.json')

json_parser.clear()
print('Clear JSON file')

signals = json_parser.read()
print(f'First read file: {utils.object_list_to_dict(signals)}')

signal_btc = Signal('btcusdt', 'long', 10)
json_parser.add(signal_btc)
print(f'Add BTC to file, and read file: {utils.object_list_to_dict(json_parser.read())}')

signal_eth = Signal('ethusdt', 'short', 50)
json_parser.add(signal_eth)
print(f'Add ETH to file, and read file: {utils.object_list_to_dict(json_parser.read())}')

signal_eth = json_parser.get('ethusdt')
print(f'ETH signal: {utils.object_to_dict(signal_eth)}')

json_parser.remove('ethusdt')
print(f'Remove ETH from file, and read file: {utils.object_list_to_dict(json_parser.read())}')

signal_xrp = Signal('xrpusdt', 'long', 20)
json_parser.add(signal_xrp)
print(f'Add XRP to file, and read file: {utils.object_list_to_dict(json_parser.read())}')

signal_btc.leverage = 5
json_parser.update('btcusdt', signal_btc)
print(f'Update leverage of BTC, and read file: {utils.object_list_to_dict(json_parser.read())}')