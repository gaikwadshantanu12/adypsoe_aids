import requests 
from bs4 import BeautifulSoup

def web(page, WebUrl):
   if page > 0:
        url = WebUrl
        code = requests.get(url)

        if code.status_code == 200:
            plain = code.text
            s = BeautifulSoup(plain, "html.parser")
            for link in s.findAll('a', class_='s-access-detail-page'):
                tet = link.get('title')
                if tet:
                    print(tet)
            
                tet_2 = link.get('href')
                if tet_2:
                    print(tet_2)
        else:
            print("Failed to retrieve the page. Status code : ", code.status_code)

web(1, "https://www.amazon.in/mobile-phones/b?ie=UTF8&node=1389401031&ref_=nav_shopall_sbc_mobcomp_all_mobiles")