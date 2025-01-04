import os
import time

from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.common.exceptions import TimeoutException

from conf import Conf

class Chrome:
    def __init__(self, proxy=''):
        self.proxy = proxy

        self.driver = None
        self.options = webdriver.ChromeOptions()
        self.main_tab_handle = None

        self.conf = Conf()

    def configure(self):
        # Use headless mode
        self.options.add_argument('--headless')
        # Set windows to full screen
        self.options.add_argument('start-maximized')
        # Disable all extensions
        self.options.add_argument('--disable-extensions')
        # Load cookies from profile (for login)
        self.options.add_argument(f'user-data-dir={os.path.join(os.getenv("LOCALAPPDATA"), "/Google/Chrome/User Data")}')
        # Keep openning the browser window after the script is completed
        self.options.add_experimental_option('detach', True)
        # Click Block on Show Notifications popup (1: Allow, 2: Block)
        self.options.add_experimental_option('prefs', {'profile.default_content_setting_values.notifications': 2})
        # Disable Chrome is being controlled by automated test software'
        self.options.add_experimental_option('excludeSwitches', ['enable-automation'])
        # Disable installing Chrome extensions
        self.options.add_experimental_option('useAutomationExtension', False)
        # Prevent Selenium detection

        self.options.add_argument('--disable-blink-features=AutomationControlled')
        # Set default useragent to prevent being block by some websites (especially in headless mode)
        useragent = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.54 Safari/537.36'

        self.options.add_argument('user-agent={0}'.format(useragent))
        # Set proxy
        if self.proxy:
            self.options.add_argument('--proxy-server={}'.format(self.proxy))

    def open(self):
        ''' Open Chrome webdriver.
            Note: If you want to delete cookies or set useragent, do it right after calling this method
        '''
        self.configure()
        self.driver = webdriver.Chrome(executable_path=self.conf.get_webdriver_path(), options=self.options)

    def close(self):
        self.driver.quit()

    def set_useragent(self, useragent: str):
        useragent_dict = {}
        useragent_dict["userAgent"] = useragent
        self.driver.execute_cdp_cmd('Network.setUserAgentOverride', useragent_dict)

    def delete_cookies(self):
        self.driver.execute_cdp_cmd('Network.clearBrowserCookies', {})
        self.driver.execute_cdp_cmd('Network.clearBrowserCache', {})

    def open_page(self, url):
        self.driver.get(url)
        print(f'Openned {url}')

    def set_main_tab_handle(self):
        self.main_tab_handle = self.driver.current_window_handle

    def is_on_main_tab(self):
        return bool(self.main_tab_handle == self.driver.current_window_handle)

    def close_other_tabs(self):
        for handle in self.driver.window_handles:
            if handle != self.main_tab_handle:
                self.driver.switch_to_window(handle)
                self.driver.close()
                time.sleep(1)       # Make sure tab is closed

        self.driver.switch_to_window(self.main_tab_handle)

    def find_element_by_xpath(self, xpath):
        ''' Better alternative for "element = self.driver.find_element_by_xpath(xpath)"
        '''
        while True:
            try:
                timeout = 10
                element = WebDriverWait(self.driver, timeout).until(
                    EC.presence_of_element_located((By.XPATH, xpath))
                )
                break
            except TimeoutException:
                print('[ERROR] Unabled to locate element')
                time.sleep(5)
                self.driver.refresh()
        return element