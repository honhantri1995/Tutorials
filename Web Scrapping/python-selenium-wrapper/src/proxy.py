import random

from proxy_checker import ProxyChecker

import constants

class ProxyManager:
    def __init__(self):
        self.proxies = []
        self.proxy_checker = ProxyChecker()

    def load_proxies(self):
        with open(constants.PROXIES_PATH, 'r', encoding='utf-8') as file:
            for line in file.readlines():
                self.proxies.append(line.strip().rstrip('\n'))

    def get_random_proxy(self):
        if not self.proxies:
            print('[ERROR] No proxy loaded. You need to load them first')
            return ''

        if len(self.proxies) == 1:
            return self.proxies[0]

        return random.choice(self.proxies)

    def is_valid_proxy(self, proxy):
        if not self.proxy_checker.check_proxy(proxy):
            print(f'Invalid proxy: {proxy}')
            return False

        print(f'Valid proxy: {proxy}')
        return True