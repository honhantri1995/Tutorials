from configparser import ConfigParser

from constants import CONFIG_PATH

class Conf:
    def __init__(self):
        self.conf = ConfigParser()
        self.conf.read(CONFIG_PATH)

    def get_webdriver_path(self):
        return self.conf.get('PATH', 'WEBDRIVER')