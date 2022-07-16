import requests
from bs4 import BeautifulSoup
import csv
import pprint

url = "https://www.jra.go.jp/datafile/seiseki/replay/2022/jyusyo.html"
response = requests.get(url)
response.encoding = response.apparent_encoding
soup = BeautifulSoup(response.text, "html.parser")

f = open('jyusyo.csv', 'w', encoding='utf-8_sig')
# get a table data
table = soup.find_all('tbody', class_='td_left')

for i in table:
    print(i.text)
    print("\n")
    
for i in table:
    
    f.write(i.text)
f.close()