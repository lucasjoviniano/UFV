import os
import subprocess
import json
import csv
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.chrome.options import Options
import time
from datetime import datetime

def bit_to_mb(bits):
    bt = float(bits)

    return str(bits * (10 ** -6))

def get_speedtest():
    dt = datetime.now()
    start = dt.strftime("%H:%M")
    day = dt.strftime("%d-%m-%Y")

    result = subprocess.run(['speedtest-cli', '--json'], stdout=subprocess.PIPE)
    js = json.loads(result.stdout.decode('UTF-8'))

    #print(js)

    return day, start, bit_to_mb(js['download']), bit_to_mb(js['upload']), js['client']['isp']

def get_fast():
    dt = datetime.now()
    start = dt.strftime("%H:%M")
    day = dt.strftime("%d-%m-%Y")
    result = subprocess.run(["fast", "--upload", "--json"], stdout=subprocess.PIPE)
    js = json.loads(result.stdout.decode('UTF-8'))

    #print(js)

    return day, start, js['downloadSpeed'], js['uploadSpeed']

def get_bbl():
    chrome_options = Options()
    chrome_options.add_argument('--headless')
    chrome_options.add_argument('--no-sandbox')
    
    driver = webdriver.Chrome(options=chrome_options)
    
    print("Conectando à página")
    driver.get("https://www.brasilbandalarga.com.br/bbl")
    print("Página aberta")
    
    print("Encontrando botão.")
    button = driver.find_element(By.ID, 'btnIniciar')
    driver.execute_script("arguments[0].scrollIntoView()", button)
    action = ActionChains(driver)
    action.move_to_element(button).click(on_element = button).perform()
    print("Botão clicado.")

    dt = datetime.now()
    start = dt.strftime("%H:%M")
    day = dt.strftime("%d-%m-%Y")
    
    is_finished = driver.find_element(By.TAG_NAME, 'tspan')
    
    while is_finished.text != 'Teste Finalizado':
        time.sleep(30)
        is_finished = driver.find_element(By.TAG_NAME, 'tspan')
    
    print(is_finished.text)
    
    results = driver.find_elements(By.CLASS_NAME, 'textao')
    d = results[0].text
    u = results[1].text
    
    #print("Download: ", results[0].text)
    #print("Upload: ", results[1].text)
    
    driver.close()

    return day, start, d, u 

def get_times():
    print("Começando Speedtest")
    speedtest = get_speedtest()
    print("Speedtest concluído")
    print("Começando Fast")
    fast = get_fast()
    print("Fast Concluído")
    print("Começando Brasil Banda Larga")
    bbl = get_bbl()
    print("Brasil Banda Larga concluído")

    print(type(speedtest))
    print(type(fast))
    print(type(bbl))

    with open('measures.csv', 'a') as file:
        out = csv.writer(file)
        out.writerow(("Speedtest",) + speedtest)
        out.writerow(("Fast",) + fast + (speedtest[4],))
        out.writerow(("Brasil Banda Larga",) + bbl + (speedtest[4],))


with open('measures.csv', 'rb') as file:
    if len(file.readlines()) <= 1:
        get_times()
    else:
        try:
            file.seek(-2, os.SEEK_END)
            while file.read(1) != b'\n':
                file.seek(-2, os.SEEK_CUR)
        except OSError:
            file.seek(0)
        last_line = file.readline().decode()

        last_line = last_line.split(',')

        now = datetime.now()
        last = datetime.strptime(last_line[2] + " " + last_line[1], '%H:%M %d-%m-%Y')

        if (last - now).total_seconds() >= (30 * 60):
            get_times()

while True:
    get_times()
    time.sleep(60 * 30)
