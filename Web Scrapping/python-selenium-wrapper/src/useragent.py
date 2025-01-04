import random

import constants

class UseragentManager:
    def __init__(self):
        self.useragents = []

    def load_useragents(self):
        with open(constants.USERAGENTS_PATH, 'r', encoding='utf-8') as file:
            for line in file.readlines():
                self.useragents.append(line.strip().rstrip('\n'))

    def get_random_useragent(self):
        if not self.useragents:
            print('[ERROR] No useragent loaded. You need to load them first')
            return ''

        if len(self.useragents) == 1:
            return self.useragents[0]

        return random.choice(self.useragents)
