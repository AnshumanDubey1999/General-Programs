import time
from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By


driver = webdriver.Chrome('C:\\Users\\anshu\\Downloads\\chromedriver.exe')
driver.get('https://web.whatsapp.com/');
wait = WebDriverWait(driver,600)

msg = "This message was sent using a python script."
again = True
while(again):
	print("Enter the message : ", end = "")
	msg = input()
	msg_box = driver.find_element_by_class_name('_13mgZ')
	
	for i in range(len(msg)+1):
	#while(True):
		msg_box.send_keys(msg[:i]+Keys.ENTER)
		time.sleep(0.5)

	print("Enter 0 to exit : ", end = "")
	if(input()=="0"):
		again = False
driver.quit()
#<div tabindex="-1" class="_3FeAD _1PRhq"><div class="wjdTm" style="visibility: visible;">Type a message</div><div class="_3u328 copyable-text selectable-text" contenteditable="true" data-tab="1" dir="ltr" spellcheck="true"></div></div>