import requests
from bs4 import BeautifulSoup


url = "https://www.jra.go.jp/datafile/seiseki/replay/2022/jyusyo.html"
response = requests.get(url)
response.encoding = response.apparent_encoding
soup = BeautifulSoup(response.text, "html.parser")


# get a table data
table = soup.find_all('tbody', class_='td_left')

for i in table:
    print(i.text)
    print("\n")